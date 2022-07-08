#include <iostream>
using namespace std;
const int maxn = 10001;
int parent[maxn], enemy[maxn];

int find_set(int v) {
    return v == parent[v] ? v : parent[v] = find_set(parent[v]);
}

void union_set(int x, int y) {
    x = find_set(x);
    y = find_set(y);
    if(x == y) return;
    parent[y] = x;
}

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        parent[i] = i;
    }
    char ch;
    int a, b;
    while(m--) {
        cin >> ch;
        cin >> a >> b;
        if(ch == 'F') {
            // int x = find_set(a);
            // int y = find_set(b);
            // if(x != y) {
            //     parent[y] = x;
            // }
            union_set(a, b);
        }
        if(ch == 'E') {
            if(enemy[a] == 0) enemy[a] = find_set(b);
            else union_set(b, enemy[a]);
            if(enemy[b] == 0) enemy[b] = find_set(a);
            else union_set(a, enemy[b]);
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(parent[i] == i) ans++;
    }
    cout << ans << endl;
    return 0;
}