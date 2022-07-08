#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 2e5 + 1;
typedef long long ll;
ll a[maxn];

int main() {
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    int mid = n / 2 + 1;
    int cnt = 0;
    for(int i = mid; i <= n;) {
        int tmp = a[i];
        while(a[i] == tmp) {
            ++cnt;
            ++i;
        }
        if(i > n)
            break;
        ll sum = (a[i] - tmp) * cnt;
        if(k > sum)
            k -= sum;
        else {
            cout << k / cnt + tmp << endl;
            return 0;
        }
    }
    cout << a[n] + k / cnt << endl; // 扫完了
    return 0;
}