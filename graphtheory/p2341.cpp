#include <iostream>
#include <cstring>
#include <stack>
#include <vector>
using namespace std;
const int maxn = 1e6 + 10;
int low[maxn], dfn[maxn], timestamp = 0, num = 0, bl[maxn], nums[maxn], head[maxn], out[maxn], ans = 0, tot = 0;
stack<int> s;
bool instk[maxn];

struct Edge {
    int from, to, next;
}e[maxn];

void add_edge(int u, int v) {
    e[++tot].from = u;
    e[tot].to = v;
    e[tot].next = head[u];
    head[u] = tot;
}

int read() {
	char ch = getchar();
	int f = 1 , x = 0;
	while(ch > '9' || ch < '0') {
		if(ch == '-')  f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		x = x * 10 + ch - '0';
		ch = getchar(); 
	}
	return x * f;
}

void tarjan(int now) {
	dfn[now] = low[now] = ++timestamp;
	s.push(now);
	instk[now] = true;
	for(int i = head[now]; i; i = e[i].next) {
		int next = e[i].to; 
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
    n = read(), m = read();
    for(int i = 1, u, v; i <= m; i++) {
        u = read(), v = read();
        add_edge(u, v);
    }
    for(int i = 1; i <= n; i++) {
        if(dfn[i] == 0)
            tarjan(i);
    }
    for(int i = 1; i <= m; i++) {
        if(bl[e[i].from] != bl[e[i].to]) {
            out[bl[e[i].from]]++;
        }
    }
    int sum = 0;
    for(int i = 1; i <= num; i++) {
        if(out[i] == 0) {
            ans = nums[i];
            sum++;
        }
    }
    if(sum >= 2) cout << 0 << endl;
    else cout << ans << endl;
    return 0;
}