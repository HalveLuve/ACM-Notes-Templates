#include <iostream>
using namespace std;
const int maxn = 5005;
int parent[maxn];

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

int main() {
    int n, m, p;
    cin >> n >> m >> p;
    for(int i = 1; i <= n; i++) {
        parent[i] = i;
    }
    int a, b;
    while(m--) {
        cin >> a >> b;
        union_set(a, b);
    }
    while(p--) {
        cin >> a >> b;
        if(find_set(a) != find_set(b)) {
            cout << "No" << endl;
        }
        else cout << "Yes" << endl;
    }
    return 0;
}