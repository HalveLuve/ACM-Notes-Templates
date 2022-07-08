#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
const int maxn = 1001;

struct node {
    int u, step;
};

vector<int> g[maxn];
int siz[maxn], wgt[maxn], vis[maxn], d[maxn], w[maxn], minn = 1e9, ans, n, sum = 0;
queue<node> q;
ll dist;

void dfs(int v, int p) { // 树的重心: 点权版
    siz[v] = w[v]; // 1
    wgt[v] = 0;
    for(auto i:g[v]) {
        int to = i;
        if(to == p) continue;
        dfs(to, v);
        siz[v] += siz[to];
        wgt[v] = max(wgt[v], siz[to]);
    }
    wgt[v] = max(wgt[v], sum - siz[v]);
    if(wgt[v] < minn || (wgt[v] == minn && ans > v)) {
        minn = wgt[v];
        ans = v;
    }
}

void bfs(int v) {
    int cnt = 1;
    node tmp = {v, 0};
    q.push(tmp);
    while(!q.empty()) {
        // int tmp = q.front().u;
        node now = q.front();
        q.pop();
        vis[now.u] = 1;
        dist += d[now.u];
        for(auto i:g[now.u]) {
            if(!vis[i]) {
                // q.push(i);
                node next = {i, now.step + 1};
                q.push(next);
                d[i] = next.step * w[i];
            }
        }
        // cnt++;
    }
}

int main() {
    int n;
    cin >> n;
    for(int i = 1, a, b, c; i <= n; i++) {
        cin >> a >> b >> c;
        w[i] = a;
        sum += a;
        if(b) {
            g[i].push_back(b);
            g[b].push_back(i);
        }
        if(c) {
            g[i].push_back(c);
            g[c].push_back(i);
        }
    }
    dfs(1, 0);
    bfs(ans);
    // cout << ans << endl;
    cout << dist << endl;
    return 0;
}