#include <iostream>
#include <algorithm>
using namespace std;
#define pii pair<int, int>
const int maxn = 1e5 + 1;
int parent[maxn];

typedef struct node {
    int a, b, c;
};

int find_set(int v) {
    return v == parent[v] ? v : parent[v] = find_set(parent[v]);
}

bool cmp(const node &x, const node &y) {
    return x.c > y.c;
}

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n * 2; i++) {
        parent[i] = i;
    }
    node no[maxn];
    for(int i = 1; i <= m; i++) {
        cin >> no[i].a >> no[i].b >> no[i].c;
    }
    sort(no + 1, no + m + 1, cmp);
    for(int i = 1; i <= m; i++) {
        int a = find_set(no[i].a);
        int b = find_set(no[i].b);
        if(a == b) {
            cout << no[i].c << endl;
            return 0;
        }
        parent[b] = find_set(no[i].a + n);
        parent[a] = find_set(no[i].b + n);
    }
    cout << 0 << endl;
    return 0;
}