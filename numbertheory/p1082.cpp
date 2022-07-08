#include <iostream>
using namespace std;
typedef long long ll;

inline int read() {
    int f = 1, x = 0;
    char ch;
    do {ch = getchar(); if(ch == '-') f = -1;}while(ch < '0' || ch > '9');
    do {x = x * 10 + ch - '0'; ch = getchar();}while(ch >= '0' && ch <= '9');
    return f * x;
}

void exgcd(ll a, ll b, ll &x0, ll &y0, ll &d) {
    if(b == 0) {
        x0 = 1, y0 = 0, d = a;
        return ;
    }
    ll x1, y1;
    exgcd(b, a % b, x1, y1, d);
    x0 = y1, y0 = x1 - (a / b) * y1;
}

ll mul_inv(ll a, ll p) {
    ll x, y, d;
    exgcd(a, p, x, y, d);
    if(d != 1) return -1;
    return (x % p + p) % p;
}

// ll crt(ll a[], ll m[], ll k) {
//     ll ans = 0;
//     for(int i = 1; i <= k; i++) {
//         ans = (ans + m[i] * mul_inv(M / a[i], a[i]) * (M / a[i])) % M;
//     }
//     return (ans % M + M) % M;
//     // return ans;
// }

int main() {
    ll a = read(), b = read();
    ll c = mul_inv(a, b);
    printf("%lld\n", c);
    return 0;
}