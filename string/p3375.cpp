#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
const int maxn = 1e6 + 6;
int fail[maxn];
char s1[maxn], s2[maxn];
vector<int> pos;

void get_fail(char *p, int *fail) {
    int n = strlen(p), i = 0, j = -1;//注意j的初值，j是当前前缀。
    fail[0] = -1;//这是为了直接失配比较方便转移。
    while(i < n) {
        while(j >= 0 && p[i] != p[j]) j = fail[j];
        i++;
        j++;
        fail[i] = j;
    }
}

int kmp(char *p, char *t) {
    get_fail(p, fail);
    int n = strlen(p), m = strlen(t);
    int i = 0, j = 0, cnt = 0;
    while(i < m) {
        while(j >= 0 && p[j] != t[i]) j = fail[j];
        i++;
        j++;
        if(j == n) {
            cnt++;
            j = fail[j];
            pos.push_back(i+1-n);
        }
    }
    return cnt;
}

int main() {
    cin >> s1 >> s2;
    kmp(s2, s1);
    for(auto i:pos) {
        cout << i << endl;
    }
    // cout << kmp(s2, s1) << endl;
    for(int i = 1; i <= strlen(s2); i++) {
        cout << fail[i] << " ";
    }
    cout << endl;
    return 0;
}