ll power(ll a, ll b, ll m, ll ans = 1) {
    for(; b; b >>= 1, a = 1LL * a * a % m) if(b & 1) ans = 1LL * ans * a % m;
    return ans;
}

namespace fft {
const ll root = 31;
const ll root_1 = power(root, mod - 2,mod);

    void fft(vector <ll> & a, bool invert) {
        ll n = a.size();
        ll pw = power(invert ? root_1 : root, (mod - 1) / n,mod);
        for (ll m = n, h; h = m / 2, m >= 2; pw = 1LL * pw * pw % mod, m = h) {
            for (ll i = 0, w = 1; i < h; ++i, w = 1LL * w * pw % mod)
                for (ll j = i; j < n; j += m) {
                    ll k = j + h, x = (a[j] - a[k] + mod) % mod;
                    a[j] += a[k]; a[j] %= mod;
                    a[k] = 1LL * w * x % mod;
                }
        }

        for (ll i = 0, j = 1; j < n - 1; j++) {
            for (ll k = n / 2; k > (i ^= k); k /= 2);
            if (j < i) swap(a[i], a[j]);
        }

        if (invert) {
            ll rev = power(n, mod - 2,mod);
            for (ll i = 0; i < n; i++) a[i] = 1LL * a[i] * rev % mod;
        }
    }

    vector <ll> multiply(const vector<ll> & a, const vector <ll> & b, ll ok = 0) {
        ll n = 1, mx = a.size() + b.size() - 1;
        while (n < mx) n <<= 1;

        if (mx < 256) {
            vector <ll> c(mx , 0);
            for (ll i = 0; i < a.size(); i++)
                for (ll j = 0; j < b.size(); j++)
                    c[i + j] = add(c[i + j] , mult(a[i] , b[j]));

            return c;
        }

        vector <ll> na = a, nb = b;
        na.resize(n); nb.resize(n);
        fft(na, false);
        if (ok) nb = na;
        else fft(nb, false);
        for (ll i = 0; i < n; i ++) na[i] = 1LL * na[i] * nb[i] % mod;
        fft(na, true); na.resize(mx);
        return na;
    }
};
