#include <iostream>
#include <map>
using namespace std;

int main() {
    int n, ans = 0;
    map<string, int> mp;
    cin >> n;
    while(n--) {
        string a, b;
        cin >> a >> b;
        a = a.substr(0, 2);
        if(a != b) {
            ans += mp[a + b];
        }
        mp[b + a]++;
    }
    cout << ans << endl;
    return 0;
}