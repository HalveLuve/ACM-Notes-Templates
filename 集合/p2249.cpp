#include <iostream>
using namespace std;
const int maxn = 1e6 + 1;
int a[maxn], key[maxn];

int left_binary_search(int l, int r, int key) {
    while(l <= r) {
        int mid = (r + l) >> 1;
        if(a[mid] < key) l = mid + 1;
        else r = mid - 1;
    }
    return a[l] == key ? l + 1 : -1;
}

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < m; i++) {
        cin >> key[i];
        cout << left_binary_search(0, n - 1, key[i]) << " ";
    }
    return 0;
}