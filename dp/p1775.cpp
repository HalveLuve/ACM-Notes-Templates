#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 301;
int a[maxn], sum[maxn], dp[maxn][maxn];

int main() {
    int n;
    memset(dp, 0x3f3f3f3f, sizeof(dp));
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        dp[i][i] = 0;
        sum[i] = sum[i-1] + a[i];
    }
    int ans = -1;
    for(int i = 2; i <= n; i++) { // 枚举区间长度
        for(int j = 1; j <= n - i + 1; j++) { // 枚举左端点
            int r = j + i - 1;
            for(int k = j; k < r; k++) {
                dp[j][r] = min(dp[j][r], dp[j][k] + dp[k+1][r]);
            }
            dp[j][r] += sum[r] - sum[j - 1];
        }
    }
    // dp(i, j) = min{dp(i, j), dp(i, k) + dp(k+1, j)}
    cout << dp[1][n] << endl;
    return 0;
}