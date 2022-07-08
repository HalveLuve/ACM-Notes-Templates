#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 1001;
int n, a[maxn], b[maxn], sum[maxn], dp1[maxn][maxn], dp2[maxn][maxn];

int main() {
    cin >> n;
    // memset(dp1, 0x3f3f3f3f, sizeof(dp1));
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i + n] = a[i];
        // dp1[i][i] = 0;
        // dp2[i][i] = 0;
    }
    int nn  = n << 1;
    for(int i = 1; i <= nn; i++) {
        sum[i] = sum[i-1] + a[i];
    }
    for(int i = 2; i <= n; i++) { // 枚举区间长度
        for(int j = 1; j <= nn - i + 1; j++) { // 枚举左端点
            int r = j + i - 1;
            dp1[j][r] = 0x3f3f;
            dp2[i][j] = 0;
            for(int k = j; k < r; k++) {
                dp1[j][r] = min(dp1[j][r], dp1[j][k] + dp1[k+1][r]);
                dp2[j][r] = max(dp2[j][r], dp2[j][k] + dp2[k+1][r]);
            }
            dp1[j][r] += sum[r] - sum[j - 1];
            dp2[j][r] += sum[r] - sum[j - 1];
        }
    }
    int ans1 = 0x3f3f, ans2 = 0;
    for(int i = 1; i <= n; i++) {
        ans1 = min(ans1, dp1[i][i + n - 1]);
        ans2 = max(ans2, dp2[i][i + n - 1]);
    }
    cout << ans1 << endl << ans2 << endl;
    return 0;
}