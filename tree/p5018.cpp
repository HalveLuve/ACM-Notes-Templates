#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
const int maxn = 1e7 + 1;

struct root {
    int l, r, wgt, child_size;
}rt[maxn];

void dfs(int v, int p) {
    if(v <= 0) return;
    rt[v].child_size = 1;
    dfs(rt[v].l, v);
    dfs(rt[v].r, v);
    rt[p].child_size += rt[v].child_size;
}

bool symmetric(int l, int r) {
    if(l < 0 && r < 0) return true;
    return l > 0 && r > 0 && rt[l].wgt == rt[r].wgt && symmetric(rt[l].l, rt[r].r) && symmetric(rt[l].r, rt[r].l);
}

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> rt[i].wgt;
    }
    for(int i = 1; i <= n; i++) {
        cin >> rt[i].l >> rt[i].r;
    }
    dfs(1, 0);
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(rt[i].child_size > ans && symmetric(rt[i].l, rt[i].r)) ans = rt[i].child_size;
    }
    cout << ans << endl;
    return 0;
}