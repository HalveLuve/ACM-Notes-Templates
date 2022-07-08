#include <iostream>
using namespace std;
const int maxn = 1e4 + 1;
int parent[maxn];

int find(int v) {
    if(v == parent[v]) {
        return v;
    }
    return parent[v] = find(parent[v]);
}

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        parent[i] = i;
    }
    int type, a, b;
    while(m--) {
        cin >> type >> a >> b;
        a = find(a);
        b = find(b);
        if(type == 1) {
            // cin >> a >> b;
            parent[b] = a;
        }
        if(type == 2) {
            if(a == b) {
                cout << 'Y' << endl;
            }
            else {
                cout << 'N' << endl;
            }
        }
    }
    return 0;
}