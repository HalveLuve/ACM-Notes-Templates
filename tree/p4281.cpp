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

bool cmp (pair<int, int> x, pair<int, int> y){
    return x.first < y.first;
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
    int x, y, z;
    while(q--) {
        int sum = 0, pos;
        x = read(), y = read(), z = read();
        int l1 = lca(x, y), l2 = lca(y, z), l3 = lca(z, x);
        if(l1 == l2 && l2 == l3) {
            pos = l1;
            // sum += distance(x, l1) + distance(y, l1) + distance(z, l1);
        }
        if(l1 == l3 && l1 != l2) {
            pos = l2;
        }
        if(l1 == l2 && l2 != l3) {
            pos = l3;
        }
        if(l2 == l3 && l1 != l3) {
            pos = l1;
        }
        sum += distance(x, pos) + distance(y, pos) + distance(z, pos);
        cout << pos << " " << sum << endl;
    }
    return 0;
}