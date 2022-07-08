#include <iostream>
using namespace std;
const int maxn = 1e5 + 10;
typedef long long ll;
struct tree{
    ll lz_add, lz_mul, sum;
}tr[maxn<<2];
int p, a[maxn];

void pushup(int u){
    tr[u].sum = (tr[u<<1].sum + tr[u<<1|1].sum)%p;
}

void pushdown(int u, int l, int r){
    if(tr[u].lz_mul != 1){
        //更新子节点
        tr[u<<1].sum = tr[u<<1].sum*tr[u].lz_mul%p;
        tr[u<<1|1].sum = tr[u<<1|1].sum*tr[u].lz_mul%p;
        //下传标记
        tr[u<<1].lz_mul = tr[u<<1].lz_mul*tr[u].lz_mul%p;
        tr[u<<1|1].lz_mul = tr[u<<1|1].lz_mul*tr[u].lz_mul%p;
        tr[u<<1].lz_add = tr[u<<1].lz_add*tr[u].lz_mul%p;
        tr[u<<1|1].lz_add = tr[u<<1|1].lz_add*tr[u].lz_mul%p;
        //清除标记
        tr[u].lz_mul = 1;
    }
    if(tr[u].lz_add){
        int mid = (l + r)>>1;
        //下传标记
        tr[u<<1].lz_add = (tr[u<<1].lz_add + tr[u].lz_add)%p;
        tr[u<<1|1].lz_add = (tr[u<<1|1].lz_add + tr[u].lz_add)%p;
        //更新
        tr[u<<1].sum = (tr[u<<1].sum + (ll)tr[u].lz_add*(mid-l + 1)%p)%p;
        tr[u<<1|1].sum = (tr[u<<1|1].sum + (ll)tr[u].lz_add*(r-mid)%p)%p;
        //清除
        tr[u].lz_add = 0;
    }
}

void build (int u, int l, int r){
    tr[u].lz_add = 0;
    tr[u].lz_mul = 1;
    if(l == r){
        tr[u].sum = a[l];
        return;
    }
    int mid = (l + r)>>1;
    build(u<<1, l, mid);
    build(u<<1|1, mid + 1, r);
    pushup(u);
}

void modify(int u, int l, int r, int L, int R, int add, int mul){
    if(L <= l && r <= R){
        //修改节点
        tr[u].sum = tr[u].sum * mul%p;
        tr[u].sum = (tr[u].sum + (r - l + 1) * add)%p;
        //打上标记
        tr[u].lz_add = tr[u].lz_add * mul%p;  
        tr[u].lz_mul = tr[u].lz_mul * mul%p;
        tr[u].lz_add = (tr[u].lz_add + add)%p;
        return;
    }
    pushdown(u, l, r);
    int mid = (l + r)>>1;
    if(L <= mid)
    modify(u<<1, l, mid, L, R, add, mul);
    if(mid<R)
    modify(u<<1|1, mid + 1, r, L, R, add, mul);
    pushup(u);
}

ll query(int u, int l, int r, int L, int R){
    if(L <= l && r <= R)
    return tr[u].sum;
    pushdown(u, l, r);
    int mid = (l + r)>>1;
    ll res = 0;
    if(L <= mid)
        res = (res + query(u<<1, l, mid, L, R))%p;
    if(mid<R)
        res = (res + query(u<<1|1, mid + 1, r, L, R))%p;
    return res;
}

int main(){
    int n, m;
    cin >> n >> m >> p;
    for(int i = 1; i <= n; i++ ){
        cin >> a[i];
    }
    build(1, 1, n);
    while(m--){
        int op;
        cin >> op;
        if(op == 1){
            int a, b, c;
            cin >> a >> b >> c;
            modify(1, 1, n, a, b, 0, c);
        }
        else if(op == 2){
            int a, b, c;
            cin >> a >> b >> c;
            modify(1, 1, n, a, b, c, 1);
        }
        else{
            int a, b;
            cin >> a >> b;
            ll ans = query(1, 1, n, a, b) % p;
            cout << ans << endl;
        }
    }
    return 0;
}
