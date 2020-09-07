//K-OS WITH THE OCDE

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")

#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef long double db;


const ll mxn = 3e5 + 5;
vell v[mxn];
bool vis[mxn] = {false};
ll deg[mxn] = {0};
ll r;

void dfs(ll x , ll &mx , ll count)
{
    vis[x] = true;
    count++;

    for (auto it : v[x]) {
        if (!vis[it]) {
            if (count >= mx) {
                mx = count;
                r = it;
            }

            dfs(it , mx , count);
        }
    }
}

void solve()
{
    ll n;
    cin >> n;

    if (n == 1) {
        cout << 0;
        return;
    }

    for (ll i = 0 ; i < n - 1 ; ++i) {
        ll x, y;
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }

    ll mx = MIN;
    dfs(1 , mx , 1);
    memset(vis , false , sizeof(vis));
    dfs(r , mx , 1);

   

}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    //TEST
    solve();
}

