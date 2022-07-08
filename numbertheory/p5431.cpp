#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
const int maxn = 5e6 + 1;
ll a[maxn], inv[maxn], pre[maxn], suf[maxn];
int n, p, k, ans = 0;

inline int read() {
    int f = 1, x = 0;
    char ch;
    do {ch = getchar(); if(ch == '-') f = -1;}while(ch < '0' || ch > '9');
    do {x = x * 10 + ch - '0'; ch = getchar();}while(ch >= '0' && ch <= '9');
    return f * x;
}

inline int sieve_inv(const int n) {
    if(n == 1) return 1;
    return ((ll)(p - p / n) * sieve_inv(p % n) % p);
}

int main() {
    n = read(), p = read(), k = read();
    for(register int i = *pre = suf[n+1] = 1; i <= n; i++) {
        pre[i] = (ll)pre[i-1] * (a[i] = read()) % p;
    }
    for(register int i = n; i; i--) {
        suf[i] = (ll)suf[i+1] * a[i] % p;
    }
    for(register int i = 1, j = k; i <= n; i++, j =(ll)j * k % p) {
        ans = (ans + (ll)j * pre[i-1] % p * suf[i+1]) % p;
    }
    // sieve_inv(n);
    printf("%lld\n", ans * (ll)sieve_inv(pre[n]) % p);
    return 0;
}