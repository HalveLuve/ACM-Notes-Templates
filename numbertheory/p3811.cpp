#include <iostream>
using namespace std;
typedef long long ll;
const int maxn = 3e6 + 1;
ll inv[maxn];
int n, p;

inline int read() {
    int f = 1, x = 0;
    char ch;
    do {ch = getchar(); if(ch == '-') f = -1;}while(ch < '0' || ch > '9');
    do {x = x * 10 + ch - '0'; ch = getchar();}while(ch >= '0' && ch <= '9');
    return f * x;
}

// void sieve_inv(int n) {
//     inv[1] = 1;
//     for(int i = 2; i <= n; i++) {
//         inv[i] = (ll)(p - p / i) * inv[p % i] % p;
//         cout << inv[i] << endl;
//     }
// }

int main() {
    n = read();
    p = read();
    // sieve_inv(n);
    inv[1] = 1;
    puts("1");
    for(int i = 2; i <= n; i++) {
        inv[i] = (ll)(p - p / i) * inv[p % i] % p;
        printf("%d\n", inv[i]);
    }
    return 0;
}