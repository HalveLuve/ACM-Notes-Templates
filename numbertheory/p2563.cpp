#include <iostream>
using namespace std;
const int maxn = 201;
int prime[maxn], dp[maxn];
bool is_prime[maxn];

int esieve(int n) {
    int p = 0;
    for(int i = 1; i <= n; i++) is_prime[i] = true;
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i <= n; i++) {
        if(is_prime[i]) {
            prime[++p] = i;
            for(int j = 2 * i; j <= n; j += i) is_prime[j] = false;
        }
    }
    return p;
}

int main() {
    int n;
    // cin >> n;
    int cnt = esieve(200);
    dp[0] = 1;
    for(int i = 1; i <= cnt; i++) {
        for(int j = prime[i]; j <= 200; j++) {
            dp[j] += dp[j - prime[i]]; // 一个数j拆成若干素数之和的方案数=所有该数j减去一个素数之差的方案数之和
        }
    }
    while(cin >> n) {
        cout << dp[n] << endl;
    }
    return 0;
}