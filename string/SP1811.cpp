#include <iostream>
#include <cstring>
#include <vector>
#define pii pair<int, int>
using namespace std;
typedef unsigned long long ull;
const int maxn = 5e5+5, maxm = 5e5+5;
int n, m;
ull base = 131, powp[maxn], a1[maxn], a2[maxn], mod = (1<<16)-1;
char s1[maxm], s2[maxn];
vector<pii> pr1, pr2;

void calhash(char s[], ull a[]) {
    int l = strlen(s);
    a[0] = 0;
    for(int i = 1; i < l; i++) {
        a[i] = (a[i-1] * base + (ull)s[i]) % mod;
    }
}

ull hashfrom0(ull a[], int l, int r) { // 计算从s[l]到s[r]的hash
    if(l == 0) return a[r];
    return ((a[r] - a[l-1] * powp[r - l + 1]) % mod + mod) % mod; // l != 0，则用两者关于0的差值补上基数的幂次
}

void subhash(ull a[], int len, vector<pii> &pr) { // 遍历得到所有子串的hash
    for(int i = 0; i < len; i++) {
        for(int j = 0; j < len; j++) {
            int hash = hashfrom0(a, i, j);
            pr.push_back({hash, j - i + 1}); // 把每个子串(s[i]~s[j])的哈希存进pr，j-i+1即子串长度
        }
    }
}

int getmax() {
    int ans = -1;
    for(auto i:pr1) {
        for(auto j:pr2) {
            if(i.first == j.first) ans = max(ans, i.second); // 维护最大长度
        }
    }
    return ans;
}

int main() {
    powp[0] = 1;
    int n = 2;
    cin >> s1;
    cin >> s2;
    for(int i = 1; i <= max(strlen(s1), strlen(s2)); i++) {
        powp[i] = (powp[i-1] * base) % mod;
    }
    calhash(s1, a1);
    calhash(s2, a2);
    subhash(a1, strlen(s1), pr1);
    subhash(a2, strlen(s2), pr2);
    cout << getmax() << endl;
    return 0;
}