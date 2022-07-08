#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
// const int maxn = 1e5 + 1;
// int wood[maxn];
vector<int> v;

int left_binary_search(int l, int r, int key) {
    while(l <= r) {
        int mid = (r + l) >> 1;
        if(v[mid] < key) l = mid + 1;
        else r = mid - 1;
    }
    return l + 1;
}

int main() {
    int n;
    cin >> n;
    int cnt = 0, type;
    // vector<int> v;
    while(n--) {
        cin >> type;
        if(type == 1) {
            int tmp;
            cin >> tmp;
            if(find(v.begin(), v.end(), tmp) == v.end()) {
                // a[cnt] = tmp
                v.push_back(tmp);
                cnt++;
            }
            else {
                cout << "Already Exist" << endl;
            }
        }
        if(type == 2) {
            int key;
            cin >> key;
            if(v.empty()) {
                cout << "Empty" << endl;
            }
            else {
                int maxn = 0x3f3f3f3f, num, t;
                for(int i = 0; i < v.size(); i++) {
                    if(abs(key - v[i]) < maxn) {
                        maxn = abs(key - v[i]);
                        num = v[i];
                        t = i;
                    }
                    if(abs(key - v[i] == maxn && v[i] < num)) {
                        num = v[i];
                        t = i;
                    }
                    // v.erase(v.begin() + t);
                    // cout << num << endl;
                }
                v.erase(v.begin() + t);
                cout << num << endl;
            }
        }
    }
    return 0;
}