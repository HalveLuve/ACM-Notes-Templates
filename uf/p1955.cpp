#include<iostream>
#include<cstring>
#include<algorithm>
const int maxn = 1e5 + 5;
using namespace std;
pair<int, int> unequal[maxn];
int n, num, sum, x[maxn], y[maxn], op[maxn], parent[maxn<<1], d[maxn<<1];

void discrete(int sum) {
	sort(d + 1, d + sum + 1);
	int m = unique(d + 1, d + sum + 1) - d - 1;
	for(int i = 1; i <= n; ++i) {
		x[i] = lower_bound(d+1, d+m+1, x[i]) - d;
		y[i] = lower_bound(d+1, d+m+1, y[i]) - d;
	}
}

int find(int x) {
	return x == parent[x] ? x : parent[x] = find(parent[x]);
}

void Merge(int x, int y) {
	x = find(x);
    y = find(y);
	if(x != y)  parent[x] = y;
}

int main() {
	int t, i;
	cin >> t;
	while(t--) {
		cin >> n;
		int num = 0, sum = 0;
		for(i = 1; i <= (n<<1); ++i)
		    parent[i] = i;
		for(i = 1; i <= n; ++i) {
            cin >> x[i] >> y[i] >> op[i];
			d[++sum] = x[i];
            d[++sum] = y[i];
		}
		discrete(sum); // 离散化
		for(i = 1; i <= n; ++i) {
			if(op[i] == 1) 
                Merge(x[i], y[i]); // 先合并所有相等条件 传递性
			else 
                unequal[++num] = make_pair(x[i], y[i]); 
		}
		for(i = 1; i <= num; ++i) { // 枚举讨论不相等条件
			int x = find(unequal[i].first);
			int y = find(unequal[i].second);
			if(x == y) {
                cout << "NO" << endl;
                goto end;
            }
		}
		cout << "YES" << endl;
        end:;
	}
	return 0;
}
