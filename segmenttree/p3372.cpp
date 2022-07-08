#include <iostream>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 5;
ll tr[maxn<<2], lz[maxn], a[maxn], n, m;

void push_up(int u){
    tr[u] = tr[u<<1] + tr[u<<1|1];
}

void push_down(int u, int l, int r){
    if(lz[u]){
        int mid = (l + r) >> 1;
        //下传标记
        lz[u<<1] += lz[u];
        lz[u<<1|1] += lz[u];
        //修改子区间
        tr[u<<1] += (mid - l + 1) * lz[u];
        tr[u<<1|1] += (r - mid) * lz[u];
        //清除标记
        lz[u] = 0;
    }
}

void build(int u, int l, int r){
    //u: 节点下标，l，r：该节点对应的区间
    if(l == r){
        tr[u] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(u<<1, l, mid);
    build(u<<1|1, mid+1, r);
    push_up(u);
}

ll query(int u, int l, int r, int L, int R){
    //u: 节点下标，l，r：该节点对应的区间，L，R：查询区间
    if(L<=l && r<=R){
        return tr[u];
    }
    push_down(u, l, r);
    int mid = (l + r) >> 1;
    ll res = 0;
    if(mid >= L) res += query(u<<1, l, mid, L, R);
    if(mid < R) res += query(u<<1|1, mid+1, r, L, R);
    return res;
}

void modify(int u, int l, int r, int x, int k){
    //u: 节点下标，l，r：该节点对应的区间，x：要修改的点a[x]，k：修改为a[x]+k
    if(l==r){
        tr[u] += k;
        return;
    }
    int mid = (l + r) >> 1;
    if(mid >= x) modify(u<<1, l, mid, x, k);
    else modify(u<<1|1, mid+1, r, x, k);
    push_up(u);
}

void interval_modify(int u, int l, int r, int L, int R, ll k){
    //给区间[L, R]中每个值加k
    if(L <= l && r <= R){
        tr[u] += k*(r - l + 1);
        lz[u] += k;
        return;
    }
    push_down(u ,l, r);
    int mid = (l + r) >> 1;
    if(mid >= L) interval_modify(u<<1, l, mid, L, R, k);
    if(mid < R) interval_modify(u<<1|1, mid+1, r, L, R, k);
    push_up(u);
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1, 1, n);
    int op, x, y;
    ll k;
    while(m--) {
        cin >> op >> x >> y;
        if(op == 1) {
            cin >> k;
            interval_modify(1, 1, n, x, y, k);
        }
        else cout << query(1, 1, n, x, y) << endl;
    }
    return 0;
}