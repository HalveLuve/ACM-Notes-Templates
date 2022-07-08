#include <iostream>
using namespace std;
typedef long long ll;

ll quick_power(ll a, ll n, ll p) {
    ll ans = 1;
    while (n != 0) {
        if(n & 1)
            ans = ans * a % p;
        a = a * a % p;
        n >>= 1;
    }
    return ans;
}

int main() {
    ll a, n, p;
    cin >> a >> n >> p;
    cout << a << '^' << n << " mod " << p << "=" << quick_power(a, n, p) << endl;
    return 0;
}