#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
const int maxn = 4e4 + 4;
int c[maxn<<1];

int sieve(int n) {
    int cnt = n * n;
    for(int i = n; i > 1; i--) {
        c[i] = (n/i) * (n/i); // 第i列和第i行共有(n/i) * (n/i)个理论上可以筛掉的点，其中可能包含前面筛过的
        for(int j = 2*i; j <= n; j += i) c[i] -= c[j]; // 筛掉已经筛过的
        cnt -= c[i];
    }
    return cnt + 2;
}

int main() {
    int n;
    cin >> n;
    if(n == 1) {
        cout << 0 << endl;
        return 0;
    }
    cout << sieve(n-1) << endl;
    return 0;
}