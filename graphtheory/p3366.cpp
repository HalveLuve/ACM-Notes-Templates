#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 2e5 + 5;
int n, m, ans, cnt, parent[maxn];

struct node {
    int from, to, w;
}edge[maxn<<1];

bool cmp(node &x, node &y) {
    return x.w < y.w;
}

void init() {
    for(int i = 1; i <= n; i++) {
        parent[i] = i;
    }
}

int find(int v) {
    return v == parent[v] ? v : parent[v] = find(parent[v]);
}

void kruskal() {
    sort(edge + 1, edge + m + 1, cmp);
    init();
    for(int i = 1; i <= m; i++) {
        int from = edge[i].from, to = edge[i].to, w = edge[i].w;
        from = find(from);
        to = find(to);
        if(from != to) {
            parent[from] = to;
            // ans = max(ans, w);
            ans += w;
            cnt++;
            if(cnt == n - 1) break;
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        cin >> edge[i].from >> edge[i].to >> edge[i].w;
    }
    kruskal();
    if(cnt < n - 1) cout << "orz" << endl;
    else cout << ans << endl;
    return 0;
}