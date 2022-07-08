#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
const int maxn = 5e5 + 5;

vector<int> G[maxn];
int siz[maxn], wgt[maxn], vis[maxn], d[maxn], minn = 1e9, ans, n;
queue<int> q;
ll dist;

void dfs(int v, int p) { // 树的重心: 朴素版
    siz[v] = 1;
    wgt[v] = 0;
    for(auto i:G[v]) {
        int to = i;
        if(to == p) continue;
        dfs(to, v);
        siz[v] += siz[to];
        wgt[v] = max(wgt[v], siz[to]);
    }
    wgt[v] = max(wgt[v], n - siz[v]);
    if(wgt[v] < minn || (wgt[v] == minn && ans > v)) {
        minn = wgt[v];
        ans = v;
    }
}

void bfs(int v) {
    q.push(v);
    while(!q.empty()) {
        int tmp = q.front();
        q.pop();
        vis[tmp] = 1;
        dist += d[tmp];
        for(auto u:G[tmp]) {
            if(!vis[u]) {
                q.push(u);
                d[u] = d[tmp] + 1;
            }
        }
    }
}

int main() {
    cin >> n;
    int a, b;
    for(int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);   
    }
    dfs(1, 0);
    bfs(ans);
    cout << ans << " " << dist << endl;
    return 0;
}