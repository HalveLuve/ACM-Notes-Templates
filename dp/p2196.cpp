#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 21;
int trace[maxn];

void dfs(int x) {
    if(trace[x]) 
        dfs(trace[x]);
    cout << x << " ";
}

int main() {
    int n, a[maxn], dp[maxn], link[maxn][maxn];
    // int trace[maxn];
    // node no[maxn];
    cin >> n;
    for(int i = 1; i <= n; i++) {
        // cin >> no[i].num;
        cin >> a[i];
    }
    for(int i = 1; i <= n - 1; i++) {
        for(int j = i + 1; j <= n; j++) {
            cin >> link[i][j];
        }
    }
    int sum = 0, pos;
    for(int i = 1; i <= n; i++) {
        dp[i] = a[i];
        for(int j = i - 1; j > 0; j--) {
            if(link[j][i] && dp[i] < dp[j] + a[i]){
                dp[i] = dp[j] + a[i];
                trace[i] = j;
            }
        }
        if(sum < dp[i]) {
            sum = dp[i];
            pos = i;
        }
    }
    // dfs(pos);
    vector<int> path;
    while(pos) {
        path.push_back(pos);
        pos = trace[pos];
    }
    reverse(path.begin(), path.end());
    for(auto it = path.begin(); it != path.end(); it++) {
        cout << *it << " ";
    }
    cout << endl << sum << endl;
    return 0;
}