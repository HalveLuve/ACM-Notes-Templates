#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 1e6 + 1;
int n, q;
struct st {
	int l, r, sum;
}tr1[maxn<<2], tr2[maxn<<2];
int x[maxn], y[maxn];

void build(int u, int l, int r) {
	tr1[u] = {l, r, 0};
	tr2[u] = {l, r, 0};
	if (l == r) {
		tr1[u].sum = 0;
		tr2[u].sum = 0;
		return;
	}
	int mid = (l + r) >> 1;
	build(u << 1, l, mid);
	build(u << 1 | 1, mid + 1, r);
	tr1[u].sum = tr1[u << 1].sum + tr1[u << 1 | 1].sum;
	tr2[u].sum = tr2[u << 1].sum + tr2[u << 1 | 1].sum;
}

void update(int u, int l, int r, int k, st tree[]) {
	if (tree[u].l >= l && tree[u].r <= r) {
		tree[u].sum = k;
		return;
	}
	int mid = (tree[u].l + tree[u].r) >> 1;
	if (l <= mid) update(u << 1, l, r, k, tree);
	if (r > mid) update(u << 1 | 1, l, r, k, tree);
	tree[u].sum = tree[u << 1].sum + tree[u << 1 | 1].sum;
}

int query(int u, int l, int r, st tree[]) {
	if (tree[u].l >= l && tree[u].r <= r) return tree[u].sum;
	int res = 0;
	int mid = (tree[u].l + tree[u].r) >> 1;
	if (l <= mid) res += query(u << 1, l, r, tree);
	if (r > mid) res += query(u << 1 | 1, l, r, tree);
	return res;
}

int main() {
	scanf("%d%d", &n, &q);
	build(1, 1, n);
	while (q--) {
		int t;
		scanf("%d", &t);
		int x1, y1, x2, y2;
		scanf("%d%d", &x1, &y1);
		if (t == 1) {
			if (x[x1] == 0) update(1, x1, x1, 1, tr1);
			if (y[y1] == 0) update(1, y1, y1, 1, tr2);
			x[x1]++;
			y[y1]++;
		}
		if (t == 2) {
			if (x[x1] == 1) update(1, x1, x1, -1, tr1);
			if (y[y1] == 1) update(1, y1, y1, -1, tr2);
			x[x1]--;
			y[y1]--;

		}
		else if (t == 3) {
			scanf("%d%d", &x2, &y2);
			if (query(1, x1, x2, tr1) == x2 - x1 + 1 || query(1, y1, y2, tr2) == y2 - y1 + 1) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}
}
