#include <iostream>
#include <map>
using namespace std;
const int maxn = 5e4 + 1;
map<string, string> parent;

string find_set(string v) {
    return (v == parent[v]) ? v : parent[v] = find_set(parent[v]);
}

int main() {
    char ch;
    string str;
    cin >> ch;
    while(ch != '$') {
        if(ch == '#') {
            cin >> str;
            if(!parent.count(str))
                parent[str] = str;
        }
        if(ch == '+') {
            string s;
            cin >> s;
            parent[s] = str;
            s = find_set(s);
            str = find_set(str);
            if(s != str)
                parent[s] = str;
        }
        if(ch == '?') {
            string tmp;
            cin >> tmp;
            cout << tmp << " " << find_set(tmp) << endl;
        }
        cin >> ch;
    }
    return 0;
}