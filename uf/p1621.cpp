#include <iostream>
#include <vector>
using namespace std;
const int maxn = 1e6 + 1;
int parent[maxn];
vector<int> prime;
bool is_prime[maxn];

int find_set(int v) {
    return (v == parent[v]) ? v : parent[v] = find_set(parent[v]);
}

void union_set(int x, int y) {
    x = find_set(x);
    y = find_set(y);
    if(x != y) {
        parent[y] = x;
    }
}

int esieve(int n) {
    int p = 0;
    for(int i = 1; i <= n; i++) is_prime[i] = true;
    is_prime[1] = false;
    for(int i = 2; i <= n; i++) {
        if(is_prime[i]) {
            // prime[p++] = i;
            prime.push_back(i);
            p++;
            for(int j = 2 * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return p;
}

int main() {
    int a, b, p;
    cin >> a >> b >> p;
    // cout << esieve(b) << endl;
    esieve(b);
    for(int i = a; i <= b; i++) {
        parent[i] = i;
    }
    while(!prime.empty() && prime.back() >= p) {
        int pr = prime.back(), cnt = 1;
        while(pr * cnt < a) cnt++;
        while(pr * (cnt + 1) <= b) {
            union_set(pr * cnt, pr * cnt + pr);
            cnt++;
        }
        prime.pop_back();
    }
    int ans = 0;
    for(int i = a; i <= b; i++) {
        if(parent[i] == i) ans++;
    }
    cout << ans << endl;
    return 0;
}