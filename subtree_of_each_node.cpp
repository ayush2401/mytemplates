//K-OS WITH THE OCDE

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef long double db;

const ll mxn = 1e5 + 5;
vector <ll> v[mxn] , path , subt[mxn];
bool vis[mxn];
ll level[mxn] , start[mxn] , ed[mxn];

// store level of each node
void dfs2(ll x , ll lev) {

    level[x] = lev;
    vis[x] = true;

    for (auto it : v[x])
        if (!vis[it])
            dfs2(it , lev + 1);
}

// store path from root
void dfs1(ll a , ll &b)
{

    vis[a] = 1;
    b++;
    start[a] = b;
    path.pb(a);

    for (auto it : v[a]) {

        if (!vis[it])
            dfs1(it , b);
    }

    ed[a] = b;
}

void solve()
{

    ll n;
    cin >> n;
    ll a[n]; 


    // Initialise
    for (ll i = 0 ; i <= n ; ++i) {
        v[i].clear();
        level[i] = 0;
        vis[i] = false;
    }
     

    // clear for test cases 
    path.clear();



    // create adjacency
    for (ll i = 0 ; i < n - 1 ; ++i) {
        ll x, y;
        cin >> x >> y;
        x-- , y--;
        v[x].pb(y);
        v[y].pb(x);
    }

    ll c = 0;

    // dfs to store subtree
    dfs1(0 , c);


    for (ll i = 0 ; i <= n ; ++i)
        vis[i] = false;

    // dfs to store level
    dfs2(0 , 0);


    ll f = 0 , dis = MAX;
    vell subt[n + 1];


    // store subtree for each node
    for (ll i = 0 ; i < n ; ++i) {
        ll p = level[i];
        if (start[i] != ed[i]) {
            for (ll j = start[i] + 1 ; j <= ed[i] ; ++j) {
                subt[i].pb(path[j - 1]);
            }
        }
    }

}
