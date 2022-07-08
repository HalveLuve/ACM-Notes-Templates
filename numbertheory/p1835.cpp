#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 1;
bool is_prime[maxn];
int prime[maxn];

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
    ll l, r;
    cin >> l >> r;
    int pc = esieve(ceil(sqrt(pow(2, 31))));
    ll ans = 0;
    int flag = 1;
    for(unsigned int i = l; i <= r; i++) {
        if(i == 1) continue;
        flag = 1;
        for(int j = 1; j <= pc && prime[j] * prime[j] <= i; j++) {
            if(i % prime[j] == 0 && i != prime[j]) {
                flag = 0;
                break;
            }
        }
        if(flag) ans++;
    }
    cout << ans << endl;
    return 0;
}