#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
const int maxn = 1e6 + 10;
typedef long long ll;
using namespace std;

ll a[maxn], b[maxn];
int n;

inline int read() {
    int f = 1, x = 0;
    char ch;
    do {ch = getchar(); if(ch == '-') f = -1;}while(ch < '0' || ch > '9');
    do {x = x * 10 + ch - '0'; ch = getchar();}while(ch >= '0' && ch <= '9');
    return f * x;
}

/*该方程 用于以下形式 
x=b1(mod a1)
x=b2(mod a2)
......
x=bn(mod an)*/

ll exgcd(ll a, ll b, ll &x, ll &y) {
	if(b == 0) {
        x = 1, y = 0;
        return a;
    }
	ll r = exgcd(b, a%b, y, x);
	y -= x*(a/b);
	return r;
}

ll mul(ll x, ll y, ll mod) {
	ll ans = 0, res = x;
	while(y) {
		if(y&1) ans = (ans+res)%mod;
		y >>= 1;
		res = (res+res)%mod;
	} 
	return ans;
}

ll excrt() {
	ll M = a[1], R = b[1], x, y, d; // a是除数，也是答案。b是被除的 
	for(int i = 2; i <= n; i++) {
		d = exgcd(M, a[i], x, y);
		ll c = ((b[i]-R)%a[i]+a[i])%a[i]; // 其实就是扩大b[i], 让b[i]>R.b[i]=b[i]+k*a[i] 
		if(c%d) return -1; // 无解  
		x = mul(x, c/d, a[i]/d);
		R += x*M; // 计算新X1的a，即特解 
		M = M/d*a[i]; // LCM新的最小公倍数 
		R %= M; // 由方程的原始形式可知，可以这么做。而且可以减小数字大小 
	}
	return R > 0? R: R+M;
}

int main() {
	// n = read();
    scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		// a[i] = read(), b[i] = read();
        scanf("%lld%lld", &a[i], &b[i]);
	}
	printf("%lld", excrt()); 
	return 0;
}