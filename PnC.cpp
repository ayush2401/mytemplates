ll add(ll a,ll b)  { return ((a%mod+b%mod)%mod); }
ll sub(ll a,ll b)  { return ((a%mod-b%mod)%mod); }
ll mult(ll a,ll b) { return (((a%mod)*(b%mod))%mod); }


const ll mxn = 3e5 + 5;
ll fact[mxn] , rev[mxn];

ll power(ll a, ll b, ll m, ll ans = 1) {
    for(; b; b >>= 1, a = 1LL * a * a % m) if(b & 1) ans = 1LL * ans * a % m;
    return ans;
}

void factorial()
{
    fact[0] = rev[0] = 1;
    for(ll i = 1; i < mxn; i++) fact[i] = fact[i-1] * i % mod;
    rev[mxn-1] = power(fact[mxn-1], mod - 2, mod);
    for(ll i = mxn - 2; i >= 1; i--) rev[i] = rev[i+1] * (i + 1) % mod;
}

ll nCr(ll n , ll r)
{
    if (r > n) return 0;
    return 1LL * fact[n] * rev[r] % mod * rev[n-r] % mod;
}
