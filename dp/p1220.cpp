#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 101;
int place[maxn], p[maxn], sum[maxn], n, c;
int f[maxn][maxn][2];
 
int main() {
    cin >> n >> c;
    for (int i = 1; i <= n; i++) {
        cin >> place[i] >> p[i];
    }
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + p[i];
    }
    memset(f, 1, sizeof(f));
    f[c][c][0] = f[c][c][1] = 0;
    for (int p = 1; p < n; p++) {
        for (int i = 1, j = i + p; i <= n && j <= n; i++, j++) {
            f[i][j][0] = min(f[i + 1][j][0] + (place[i + 1] - place[i]) * (sum[n] - sum[j] + sum[i]), f[i + 1][j][1] + (place[j] - place[i]) * (sum[n] - sum[j] + sum[i]));
            //用小区间更新大区间 
            //place[i + 1] - place[i] -> 意思是走的秒数
            //sum[n] - sum[j] + sum[i] -> 计算能量消耗
            f[i][j][1] = min(f[i][j - 1][1] + (place[j] - place[j - 1]) * (sum[n] - sum[j - 1] + sum[i - 1]), f[i][j - 1][0] + (place[j] - place[i]) * (sum[n] - sum[j - 1] + sum[i - 1]));
        }
    }
    cout << min(f[1][n][0], f[1][n][1]) << endl;
    //最后的状态不知道哪边更小 比一下
    return 0;
}