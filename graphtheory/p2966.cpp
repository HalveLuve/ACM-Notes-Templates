#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1e4 + 1;
int n, m, q, dist[maxn][maxn], ans[maxn][maxn];

struct node {
    int wgt, dis;
}no[maxn];

bool cmp(node x, node y) {
    return x.wgt < y.wgt;
}

int main() {
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++) {
        cin >> no[i].wgt;
        no[i].dis = i;
    }
    sort(no + 1, no + n + 1, cmp);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j) dist[i][j] = 0;
            else dist[i][j] = 0x3f3f3f3f;
        }
    }
    int u, v, w;
    for(int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        dist[v][u] = min(dist[v][u], w);
        dist[u][v] = min(dist[u][v], w);
    }
    memset(ans, 0x3f3f, sizeof(ans));
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                dist[no[i].dis][no[j].dis] = min(dist[no[i].dis][no[j].dis], dist[no[i].dis][no[k].dis] + dist[no[k].dis][no[j].dis]);
                ans[no[i].dis][no[j].dis] = min(ans[no[i].dis][no[j].dis], dist[no[i].dis][no[j].dis] + max(no[i].wgt, max(no[j].wgt, no[k].wgt)));
            }
        }
    }
    int a, b;
    while(q--) {
        cin >> a >> b;
        cout << ans[a][b] << endl;
    }
    return 0;
}