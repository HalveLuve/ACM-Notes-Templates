#include <iostream>
using namespace std;
const int maxn = 5e5+5;
int parent[maxn];

int find_set(int v) {
    return (v == parent[v]) ? v : parent[v] = find_set(parent[v]);
}

void union_set(int x, int y) {
    x = find_set(x);
    y = find_set(y);
    if(x != y) {
        parent[x] = y;
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= 3 * n; i++) { // 1: 自身/同类 2: 自身的猎物 3: 自身的天敌
        parent[i] = i;
    }
    int cnt = 0, type, x, y;
    while(k--) {
        cin >> type >> x >> y;
        if(x > n || y > n) {
            cnt++;
            continue;
        }
        if(type == 1) {
            if(find_set(x + n) == find_set(y) || find_set(x + 2 * n) == find_set(y)) {
                cnt++; // 同类是猎物或天敌
                continue;
            }
            else {
                union_set(x, y);
                union_set(x + n, y + n);
                union_set(x + 2 * n, y + 2 * n);
            }
        }
        else {
            if(x == y || find_set(x) == find_set(y) || find_set(x + 2 * n) == find_set(y)) {
                cnt++; // x等于y x和y是同类 y是x的天敌
                continue;
            }
            else {
                union_set(x, y + 2 * n);
                union_set(x + n, y);
                union_set(x + 2 * n, y + n);
            }
        }
        /*
        if(x > n || y > n) cnt++;
        else if(type == 2) {
            if(find_set(x, p2) == find_set(y, p2) || x == y) cnt++; // 前面说过x和y是同类
            else if(find_set(y, p1) == find_set(x, p2)) cnt++; // 前面说过y吃x
            else {
                union_set(x, y, p1); // x吃y
            }
        }
        else if(type == 1) {
            if(x != y && (find_set(x, p1) == find_set(y, p2) || find_set(y, p1))) cnt++; // 前面说过x吃y或者y吃x
            else {
                union_set(x, y, p2);
            }
        }
        */
    }
    cout << cnt << endl;
    return 0;
}