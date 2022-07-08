#include <iostream>
typedef long long ll;
using namespace std;
ll mod = 1, a, b, n, flag;

ll read() {
	ll f = 1, re = 0;
	char ch;
	for(ch = getchar(); !isdigit(ch)&&ch!='-'; ch = getchar());
	    if(ch == '-') f=-1, ch=getchar();
	for(; isdigit(ch); ch = getchar()){
		re = (re<<3) + (re<<1) + ch - '0';
		if(re >= mod) flag = 1; 
		re %= mod;
	}
    return re * f;
} 

ll ksm(ll a, ll b) {
	ll ans = 1;
	while(b) {
		if(b&1) ans = ans*a%n;
		a = a*a%n;
		b >>= 1;
	}
    return ans;
}

void getphi1() {//求单个欧拉函数的方法1
	ll m = n;
	for(ll i = 2; i*i <= m ;i++){ 
		if(m%i) continue; 
		mod *= (i-1);
        m /= i;
		while(m%i == 0) {
            mod *= i;
            m /= i;
        }//保证枚举的i一定为质数 
	}
    if(m > 1) mod *= m-1;
}

void getphi2() {//求单个欧拉函数的方法2
	ll m = n;
    mod = n;
	for(ll i = 2; i*i <= m; i++){
		if(m%i) continue;
		mod = mod/i*(i-1);
		while(m%i == 0) m/=i;
	}
    if(m > 1) mod = mod/m*(m-1);
}

int main() {
	scanf("%lld%lld", &a, &n); 
	a %= n;
	getphi2();
    b = read();
	if(flag) b += mod;
	printf("%lld\n", ksm(a, b));
	return 0;
}
