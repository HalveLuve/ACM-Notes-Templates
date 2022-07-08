#include <iostream>
using namespace std;
const int maxn = 1e8 + 1;
bool is_prime[maxn];
int prime[maxn];

int eular_sieve(int n) {
    int p = 0;
    for(int i = 0; i <= n; i++) is_prime[i] = true;
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i <= n; i++) {
        if(is_prime[i]) prime[++p] = i;
        for(int j = 1; j <= p; j++) {
            if(i * prime[j] > n) break;
            is_prime[i * prime[j]] = false;
            if(i % prime[j] == 0) break;
        }
    } 
    return p;
}
 
int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    eular_sieve(n);
    int o;
    while(q--) {
        scanf("%d", &o);
        printf("%d\n", prime[o]);
    }
    return 0;
}