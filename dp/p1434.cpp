#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 101;
int r, c, a[maxn][maxn], dp[maxn][maxn];
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

int search(int x, int y) {
    if(dp[x][y]) return dp[x][y];
    int ans = 0;
    for(int i = 0; i < 4; i++) {
        int xx = x + dx[i], yy = y + dy[i];
        if(xx > 0 && xx <= r && yy > 0 && yy <= c && a[x][y] > a[xx][yy]) {
            ans = max(ans, search(xx, yy));
        }
    }
    dp[x][y] = ans + 1;
    return dp[x][y];
}

int main() {
    cin >> r >> c;
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            cin >> a[i][j];
        }
    }
    // vis[marki][markj] = 1;
    int length = 0;
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            if(!dp[i][j]) dp[i][j] = search(i, j);
            length = max(length, dp[i][j]);
        }
    }
    cout << length << endl;
    return 0;
}