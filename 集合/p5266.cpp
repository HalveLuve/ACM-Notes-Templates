#include <iostream>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;
    map<string, int> mp;
    while(n--) {
        int type;
        cin >> type;
        if(type == 1) {
            string name;
            int score;
            cin >> name >> score;
            mp[name] = score;
            cout << "OK" << endl;
        }
        if(type == 2) {
            string name;
            cin >> name;
            if(mp.find(name) != mp.end()) {
                cout << mp[name] << endl;
            }
            else {
                cout << "Not found" << endl;
            }
        }
        if(type == 3) {
            string name;
            cin >> name;
            if(mp.find(name) != mp.end()) {
                mp.erase(mp.find(name));
                cout << "Deleted successfully" << endl;
            }
            else {
                cout << "Not found" << endl;
            }
        }
        if(type == 4) {
            cout << mp.size() << endl;
        }
    }
    return 0;
}