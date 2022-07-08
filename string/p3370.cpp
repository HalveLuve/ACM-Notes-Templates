#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;
const int maxn = 1e5 + 5, maxm = 1e4 + 4;
ull base = 131, mod1 = 19260817, mod2 = 19660813;
char s[maxm];
int n, ans = 1;

struct Node {
    ull x, y;
}a[maxn];

inline int read() {
	int s = 0, w = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-') w = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		s = s*10 + ch - '0';
		ch = getchar();
	}
	return s * w;
}

ull hash1(char s[]) {
    int l = strlen(s);
    ull res = 0;
    for(int i = 0; i < l; i++) {
        res = (res * base + (ull)s[i]) % mod1; 
    }
    return res;
}

ull hash2(char s[]) {
    int l = strlen(s);
    ull res = 0;
    for(int i = 0; i < l; i++) {
        res = (res * base + (ull)s[i]) % mod2;
    }
    return res;
}

bool cmp(Node a, Node b) {
    return a.x < b.x;
}

int main() {
    n = read();
    for(int i = 1; i <= n; i++) {
        cin >> s;
        a[i].x = hash1(s);
        a[i].y = hash2(s);
    }
    sort(a + 1, a+ n + 1, cmp);
    for(int i = 2; i <= n; i++) {
        if(a[i-1].x != a[i].x || a[i-1].y != a[i].y) ans++;
    }
    cout << ans << endl;
    return 0;
}