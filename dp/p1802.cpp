#include <iostream>
using namespace std;
const int maxn = 1e3 + 1;
typedef long long ll;
ll lose[maxn], win[maxn], use[maxn], dp[maxn][maxn];

int main() {
    int n, x;
    cin >> n >> x;
    for(int i = 1; i <= n; i++) {
        cin >> lose[i] >> win[i] >> use[i];
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= x; j++) {
            dp[i][j] = dp[i - 1][j] + lose[i];
            if(j >= use[i]) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - use[i]] + win[i]);
            }
        }
    }
    cout << (long long)5 * dp[n][x] << endl;
    return 0;
}