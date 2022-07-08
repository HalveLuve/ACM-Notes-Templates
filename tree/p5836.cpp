#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
const int maxn = 1e5 + 5;

int l, timer = 0, tl[maxn], tr[maxn], up[maxn][20], h[maxn], g[maxn];
vector<int> G[maxn];
vector<char> cows;

void dfs(int v, int p) {
    h[v] = h[p] + (cows[v-1] == 'H');
    g[v] = g[p] + (cows[v-1] == 'G');
    tl[v] = ++timer;
    up[v][0] = p;
    for(int i = 1; i <= l ; ++i) up[v][i] = up[up[v][i-1]][i-1];
    for(auto u:G[v]) if(u != p) dfs(u, v);
    tr[v] = ++timer;
}

bool ao(int u, int v) {
    return tl[u] <= tl[v] && tr[u] >= tr[v];
}

int lca(int u, int v) {
    if(ao(u, v)) return u;
    if(ao(u, v)) return v;
    for(int i = l; i >= 0; i--) 
        if(!ao(up[u][i], v)) u = up[u][i];
    return up[u][0];
}

int main() {
    int n, m;
    cin >> n >> m;
    l = ceil(log2(n));
    char ch;
    for(int i = 1; i <= n; i++) {
        cin >> ch;
        cows.push_back(ch);
    }
    for(int i = 0, a, b; i < n - 1; i++) {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(1, 1);
    int x, y;
    char tmp;
    while(m--) {
        cin >> x >> y >> tmp;
        int anc = lca(x, y);
        if(tmp == 'H') {
            if(cows[anc - 1] == tmp || (h[x] != h[anc] || h[y] != h[anc])) {
                cout << 1;
                continue;
            }
            else cout << 0;
        }
        else {
            if(cows[anc - 1] == tmp || (g[x] != g[anc] || g[y] != g[anc])) {
                cout << 1;
                continue;
            }
            else cout << 0;
        }
    }
    cout << endl;
    return 0;
}