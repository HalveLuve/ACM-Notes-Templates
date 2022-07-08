#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn = 1e5 + 1;
int a[maxn], b[maxn];

int left_binary_search(int l, int r, int key) {
    while(l <= r) {
        int mid = (r + l) >> 1;
        if(a[mid] < key) l = mid + 1;
        else r = mid - 1;
    }
    return l;
}

int main() {
    int m, n, ans = 0;
    cin >> m >> n;
    for(int i = 0; i < m; i++) {
        cin >> a[i];
    }
    sort(a, a + m);
    for(int i = 0; i < n; i++) {
        cin >> b[i];
        int mark = left_binary_search(0, m - 1, b[i]);
        if(b[i] <= a[0]) {
            ans += a[0] - b[i];
        }
        else
            ans += min(abs(a[mark - 1] - b[i]), abs(a[mark] - b[i]));
    }
    cout << ans << endl;
    return 0;
}