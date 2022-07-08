#include <bits/stdc++.h>

#define all(x)  (x).begin(), (x).end()

typedef long long i64;

constexpr const int mods[] = {1000000021, 1000000033, 1000000087, 1000000093, 1000000097};
template < typename T > struct strings_hash {
    std::vector<std::vector<i64>> a;
    std::vector<i64> b;
    std::vector<int> c, d;
    int p, x;
    strings_hash(T *s, int n, int m, int p)
        : a(n), b(1, 1), c(m), d(n), p(p), x(1e7) {
        std::mt19937 rng(std::time(nullptr));
        x += rng() % 40;

        for (int i = 0; i != m; ++i)
            c[i] = rng() % (x - m);

        std::sort(all(c));

        for (int i = 1; i <= m; ++i)
            c[i] += i;

        std::shuffle(all(c), rng);

        for (int i = 0; i != n; ++i) {
            d[i] = s[i].size();
            a[i].resize(d[i] + 1);

            for (int j = 0; j != d[i]; ++j)
                a[i][j + 1] = (a[i][j] * x + c[s[i][j]]) % p;
        }

        int l = *std::max_element(all(d));
        b.resize(l + 1);

        for (int i = 0; i != l; ++i)
            b[i + 1] = b[i] * x % p;
    } // s_i[0, d_i) \in [0, m)
    int hash(int i, int l, int r) const {
        int y = a[i][r] - a[i][l] * b[r - l] % p;
        return y < 0 ? y + p : y;
    } // s_i[l, r)
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<std::string> s(n);

    for (int i = 0; i != n; ++i) {
        std::cin >> s[i];
    }

    strings_hash<std::string> hashs(&s[0], n, 128, mods[0]);
    int l = 0, r = *std::max_element(all(hashs.d)) + 1;

    while (l + 1 != r) {
        int m = (l + r) / 2;
        std::set<int> st;

        for (int i = m; i <= hashs.d[0]; ++i) {
            st.insert(hashs.hash(0, i - m, i));
        }

        for (int i = 1; i != n && !st.empty(); ++i) {
            std::set<int> both;

            for (int j = m; j <= hashs.d[0]; ++j) {
                int x = hashs.hash(i, j - m, j);

                if (st.find(x) != st.end()) {
                    both.insert(x);
                }
            }

            std::swap(st, both);
        }

        (st.empty() ? r : l) = m;
    }

    std::cout << l << std::endl;
    return 0;
}