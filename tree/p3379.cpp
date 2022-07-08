#include <iostream>
#include <vector>
#include <cctype>
#include <cmath>
using namespace std;
typedef long long ll;

const int maxn = 5e5 + 5;
int l, timer = 0, tl[maxn], tr[maxn], up[maxn][20];
vector<int> G[maxn];

void dfs(int v, int p) { // v, p都是根
    tl[v] = ++timer;
    up[v][0] = p;
    for(int i = 1; i <= l; ++i) up[v][i] = up[up[v][i-1]][i-1];
    for(auto u:G[v]) if(u != p) dfs(u, v);
    tr[v] = ++timer;
}

bool ao(int u, int v) {
    return tl[u] <= tl[v] && tr[u] >= tr[v];
}

int lca(int u, int v) {
    if(ao(u, v)) return u;
    if(ao(v, u)) return v;
    for(int i = l; i >= 0; --i) if(!ao(up[u][i], v)) u = up[u][i]; // 从最早祖先开始遍历u的祖先
    return up[u][0];
}

inline ll read(){
   ll s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}

int main() {
    int n = read();
    int m = read();
    int s = read()-1;
    l = ceil(log2(n));
    for(int i=1;i<n;i++) {
        int u=read()-1;
        int v=read()-1;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(s,s);
    for(int i=1;i<=m;i++) {
        int u=read()-1;
        int v=read()-1;
        cout << 1+lca(u,v) << endl;
    }
}

