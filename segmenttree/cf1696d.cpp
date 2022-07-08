#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn = 5e5 + 10;
int a[maxn], n, m;
struct Node {
    int l, r, minv, maxv;
}tr[maxn<<2];
int pos[maxn];

void pushup(int u) {
    tr[u].minv = min(tr[u<<1].minv, tr[u<<1|1].minv);
    tr[u].maxv = max(tr[u<<1].maxv, tr[u<<1|1].maxv);
}

void build(int u, int l, int r) {
    if(l == r) tr[u] = {l, r, a[l], a[r]};
    else {
        tr[u] = {l, r};
        int mid = (l + r) >> 1;
        build(u<<1, l, mid);
        build(u<<1|1, mid + 1, r);
        pushup(u);
    }
}

// 找区间内的最大最小值并返回其数值，通过pos[maxv]、pos[minv]确定下标
int query_min(int u, int l, int r) {
    if(l <= tr[u].l && r >= tr[u].r) {
        return tr[u].minv;
    }
    else {
        int mid = (tr[u].l + tr[u].r) >> 1;
        int res = 1e9;
        if(l <= mid) res = min(res, query_min(u<<1, l, r));
        if(r > mid) res = min(res, query_min(u<<1|1, l, r));
        return res;
    }
}

int query_max(int u, int l, int r) {
    if(l <= tr[u].l && r >= tr[u].r) {
        return tr[u].maxv;
    }
    else {
        int mid = (tr[u].l + tr[u].r) >> 1;
        int res = -1;
        if(l <= mid) res = max(res, query_max(u<<1, l, r));
        if(r > mid) res = max(res, query_max(u<<1|1, l, r));
        return res;
    }
}

// solve(1, n)即1到n的最短距离
int solve(int l, int r){
    if (l + 1 == r) return 1; // 相邻结点连边距离为1
    if (l >= r) return 0;
    int maxv = query_max(1, l, r);
    int minv = query_min(1, l, r);
    int L = pos[maxv], R = pos[minv];
    if (L > R) swap(L, R); // 最大最小端点位置可交换
    return solve(l, L) + 1 + solve(R, r); // 将区间[l, r]划分成[l, L]、[R, r]
    /*
    对序列a[l:r]，找最大最小值位置L、R(L>=l, R<=r)
    区间[L, R]满足最大最小值位于端点，等价于solve(L, R) = 1，所以中间要+1
    然后递归分别找区间[l, L]、[R, r]的最大最小值位置...直到区间[l, r]满足只包括1个或2个相邻点时结束递归
    */
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 1; i <= n; i ++ ) {
            cin >> a[i];
            pos[a[i]] = i;
        }
        if(n == 1)  {
            cout << 0 << endl;
            continue;
        }
        build(1, 1, n);
        cout << solve(1, n) << endl;
    }
    return 0;
}