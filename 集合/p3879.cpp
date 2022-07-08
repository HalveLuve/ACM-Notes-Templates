#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;
const int maxn = 1e3 + 1;

int main() {
    int n;
    // vector<vector<string>> s;
    map<string, set<int>> mp;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int words;
        cin >> words;
        // vector<string> str;
        for(int j = 0; j < words; j++) {
            string tmp;
            cin >> tmp;
            // str.push_back(tmp);
            mp[tmp].insert(i);
        }
        // s.push_back(str);
    }
    int m;
    cin >> m;
    while(m--) {
        string word;
        cin >> word;
        for(auto it = mp[word].begin(); it != mp[word].end(); it++) {
            cout << *it + 1 << " ";
        }
        cout << endl;
        // for(int i = 0; i < n; i++) {
        //     int flag = 0;
        //     for(int j = 0; j < s[i].size(); j++) {
        //         if(s[i][j] == word) {
        //             flag = 1;
        //             break;
        //         }
        //     }
        //     if(flag)
        //         cout << i + 1 << " ";
        // }
        // cout << endl;
    }
    return 0;
}
