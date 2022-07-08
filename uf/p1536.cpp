#include <iostream>
using namespace std;
const int maxn = 1001;
int parent[maxn], n, m;

int find_set(int v) {
    return (v == parent[v]) ? v : parent[v] = find_set(parent[v]);
}

int main() {
    cin >> n >> m;
    while(n) {
        // cin >> n >> m;
        for(int i = 1; i <= n; i++) {
            parent[i] = i;
        }
        int a, b, ans = n - 1;
        while(m--) {
            cin >> a >> b;
            a = find_set(a);
            b = find_set(b);
            if(a == b) continue;
            parent[a] = b;
            ans--;
        }
        // cout << (ans <= 0 ? 0 : ans) << endl;
        cout << ans << endl;
        cin >> n >> m;
    }
    return 0;
}