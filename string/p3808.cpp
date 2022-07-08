#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
const int maxn = 1e6 + 6;
using namespace std;
queue<int> q;	
struct Aho_Corasick_Automaton { //C是trie树   value是单词个数  fail是指针  cnt是trie中第几个点 
	int c[maxn][26], val[maxn], fail[maxn], cnt;

	void ins(char *s) { //trie建树
		int len = strlen(s);
		int now = 0;
		for(int i = 0; i < len; i++) {
			int v = s[i] - 'a';
			if(!c[now][v]) c[now][v] = ++cnt;
			now = c[now][v];
		}
		val[now]++;//以这个点结束的单词数量++ 
	}

	void build() {
		for(int i = 0; i < 26; i++) 
			if(c[0][i]) {
				fail[c[0][i]] = 0;
                q.push(c[0][i]);//将所有的根入队列 
            }
		while(!q.empty()) {//建立AC自动机的核心代码 
			int u = q.front();//当前的点的序号 
			q.pop();
			for(int i = 0; i < 26; i++)//对这个点的这一层进行遍历 
				if(c[u][i]) {//如果这个点存在这个字符，这个点的fail指针指向父节点的这个字母(虽然父节点的这个字母可能不存在) 
					fail[c[u][i]] = c[fail[u]][i];
                    q.push(c[u][i]); //将这个点入队 
                }
				else c[u][i] = c[fail[u]][i];//不存在这个字符，这个字符指向父亲节点的这个字符 
		}
	}

	int query(char *s) {
		int len = strlen(s);
		int now = 0, ans = 0;
		for(int i = 0; i < len; i++) {//对母串进行遍历 
			now = c[now][s[i]-'a'];//KMP思想   
			for(int t = now; t && ~val[t]; t = fail[t]) {//如果这个节点不是根节点  没有被访问过  加上  然后返回它的父节点的其他值加上 
				ans += val[t];
                val[t] = -1; 
            }
		}
		return ans;
	}
} AC;
int n;
char p[maxn];

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
        scanf("%s", p);
        AC.ins(p); //输入一个字符串并且建树
    }
	AC.build();//建立自动机
	scanf("%s", p);
	int ans = AC.query(p);
	printf("%d\n", ans);
	return 0;
}