#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

inline int read() {
    int w = 1, q = 0;
    char ch = ' ';
    while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
    if (ch == '-') w = -1, ch = getchar();
    while (ch >= '0' && ch <= '9') q = q * 10 + ch - '0', ch = getchar();
    return w * q;
}

int main() {
    int t;
    t = read();
    while(t--) {
        int n;
        unordered_set<int> s;
        // vector<int> v;
        // cin >> n;
        n = read();
        while(n--) {
            int tmp;
            tmp = read();
            // s.insert(tmp);
            if(!s.count(tmp)) {
                cout << tmp << " ";
                s.insert(tmp);
            }
        }
        // for(auto it = s.begin(); it != s.end(); it++) {
        //     cout << *it << " ";
        // }
        // cout << endl;
        putchar('\n');
    }
    return 0;
}