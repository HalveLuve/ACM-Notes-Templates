#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn = 1e6 + 1;
vector<int> g[maxn];
int tl[maxn], tr[maxn], up[maxn][20], dist[maxn], timer = 0, l;

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

void dfs(int v, int p) {
    dist[v] = dist[p] + 1;
    tl[v] = ++timer;
    up[v][0] = p;
    for(int i = 1; i <= l ; ++i) up[v][i] = up[up[v][i-1]][i-1];
    for(auto u:g[v]) if(u != p) dfs(u, v);
    tr[v] = ++timer;
}

bool ao(int x, int y) {
    return tl[x] <= tl[y] && tr[x] >= tr[y];
}

int lca(int u, int v) {
    if(ao(u, v)) return u;
    if(ao(v, u)) return v;
    for(int i = l; i >= 0; i--) if(!ao(up[u][i], v)) u = up[u][i];
    return up[u][0];
}

int distance(int a, int b) {
    return dist[a] + dist[b] - 2 * dist[lca(a, b)];
}

int main() {
    int n = read(), q = read();
    l = ceil(log2(n));
    for(int i = 1, u, v; i < n; i++) {
        u = read(), v = read();
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 1);
    dist[1] = 1;
    int a, b, c, d;
    while(q--) {
        a = read(), b = read(), c = read(), d = read();
        if((a == c && b == d) || (a == d && c == b) || (b == c)) {
            cout << "Y" << endl;
            continue;
        }
        int cs = lca(a, b), sugar = lca(c, d);
        int ab = distance(a, b), cd = distance(c, d);
        int cs_c = distance(cs, c), cs_d = distance(cs, d), sugar_a = distance(sugar, a), sugar_b = distance(sugar, b);
        if((cs_c + cs_d == cd) || (sugar_a + sugar_b == ab) || cs == sugar) {
            cout << "Y" << endl;
        }
        else cout << "N" << endl;
    }
    return 0;
}