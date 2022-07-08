#include <iostream>
#include <cstring>
#include <stack>
#include <vector>
using namespace std;
const int maxn = 1e6 + 10;
int low[maxn], dfn[maxn], timestamp = 0, num = 0, bl[maxn], ru[maxn], nums[maxn], ans = 0;
stack<int> s;
vector<int> v[maxn];
bool instk[maxn];

/*
dfn[i]: i点的时间戳
low[i]: 表示这个点以及其子孙节点连的所有点中dfn最小的值
stack s: 表示当前所有可能能构成是强连通分量的点。
instk[i]: 表示 i 是否在栈中
nums[i]: 表示第 i 个强连通分量中有多少个点
bl[i]: 表示第 i 点在哪一个强连通分量里
*/

void tarjan(int now) {
	dfn[now] = low[now] = ++timestamp;
	s.push(now);
	instk[now] = true;
	for(auto i:v[now]) {
		int next = i; // v[now][i]
		if(dfn[next] == 0) {
			tarjan(next);
		    low[now] = min(low[now], low[next]);
		}
        else if(instk[next] == 1) {
		    low[now]  =min(low[now], dfn[next]);
	    }
	}
	if(dfn[now] == low[now]) {
		num++;
		int q;
		do {
			q = s.top();
			instk[q] = 0;
			s.pop();
			bl[q] = num; //vis
			nums[num]++; //sum
		}while(q != now);
	}
}

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 1, b, e; i <= m; i++) {
        cin >> b >> e;
        v[b].push_back(e);
    }
    memset(dfn, 0, sizeof(dfn));
    memset(instk, false, sizeof(instk));
    for(int i = 1; i <= n; i++) {
        if(dfn[i] == 0) {
            tarjan(i);
        }
    }
    for(int i = 1; i <= n; i++) {
        for(auto j:v[i]) {
            int p = j; // v[i][j]
            if(bl[i] != bl[p]) {
                ru[bl[p]] ++;
            }
        }
    }
    for(int i = 1; i <= num; i++) {
        if(ru[i] == 0) ans++;
    }
    cout << ans << endl;
    return 0;
}