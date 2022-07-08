#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
const int maxn = 1e6 + 1;
// int a[maxn];

// int left_binary_search(int l, int r, int key) {
//     while(l <= r) {
//         int mid = (r + l) >> 1;
//         if(a[mid] < key) l = mid + 1;
//         else r = mid - 1;
//     }
//     return a[l] == key ? l : 0;
// }

int main() {
    int n, m;
    cin >> n;
    map<int, int> mp;
    for(int i = 1; i <= n; i++) {
        int tmp;
        cin >> tmp;
        mp[tmp] = i;
    }
    // sort(a + 1, a + n + 1);
    cin >> m;
    while(m--) {
        int key;
        cin >> key;
        cout << mp[key] << endl;
    }
}