#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
const int maxn = 9;
vector<int> prime = {2, 3, 5, 7};
// int prime2[11] = {23, 29, 31, 37, 51, 53, 57, 59, 71, 73, 79};
int candidate[4] = {1, 3, 7, 9};

bool is_prime(int x) {
    for(int i = 2; i * i <= x; i++) {
        if(x % i == 0) return false;
    }
    return true;
}

int main() {
    int n, ans;
    vector<int> p;
    cin >> n;
    for(int k = 1; k < n; k++) {
        for(auto i:prime) {
            for(int j = 0; j < 4; j++) {
                int tmp = i * 10 + candidate[j];
                if(is_prime(tmp)) p.push_back(tmp); 
            }
        }
        prime = p;
        p.clear();
    }
    for (auto i:prime) cout << i << endl;
    return 0;
}