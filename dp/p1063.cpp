#include <iostream>
using namespace std;
typedef long long ll;
const int maxn = 1001;
int n, a[maxn], sum[maxn];
ll dp[maxn][maxn];

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i + n] = a[i];
    }
    int nn = n << 1;
    // for(int i = 1; i <= nn; i++) {
    //     sum[i] = sum[i-1] + a[i];
    // }
    for(int i = 2; i <= n; i++) {
        for(int j = 1; j <= nn - i + 1; j++) {
            int r = j + i - 1;
            dp[j][r] = 0;
            for(int k = j; k < r; k++) {
                dp[j][r] = max(dp[j][r], dp[j][k] + dp[k+1][r] + a[j] * a[k+1] * a[r+1]);
            }
            // dp[j][r] += sum[r] - sum[j - 1];
        }
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        ans = max(ans, dp[i][i + n - 1]);
    }
    cout << ans << endl;
    return 0;
}