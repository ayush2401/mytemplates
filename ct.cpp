//K-OS WITH THE OCDE

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")

#include <iostream>
#include <numeric>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <stack>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <deque>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <climits>

using namespace std;

typedef long long int ll;
typedef long double db;


#define TEST ll t; cin>>t; while(t--)
#define vell vector<ll>
#define pl pair<ll,ll>
#define all(v) v.begin(),v.end()
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define dbg(x)  cerr << #x << ": "<< x <<endl
#define dbg2(x,y) cerr<< #x <<": "<< x <<" || "<< #y << ": " << y << endl

#define endl "\n"
#define MAX 1e18
#define MIN INT_MIN
#define mod 1000000007



void solve()
{
    ll n, m;
    cin >> n >> m;

    vector <ll> f(n + 2 , 0);
    vector <pair<ll, ll>> B;

    for (ll i = 0 ; i < m ; ++i) {

        ll t , x , y;
        cin >> t >> x >> y;

        if (t) {
            f[x]++;
            f[y + 1]--;
        }
        else
            B.pb({x, y});
    }

    for (ll i = 1 ; i <= n ; ++i)
        f[i] += f[i - 1];

    ll mx = 10000;

    for (ll i = 1 ; i <= n ; ) {

        ll j = 0;
        while (j + i <= n && f[j + i])
            ++j;

        mx--;
        for (ll k = i ; k <= i + j ; ++k)
            f[k] = mx;

        i = j + 1;

    }


    for (auto it : B) {

        ll l = it.ff;
        ll r = it.ss;

        bool ok = false;

        for (ll i = l ; i < r ; ++i) {

            if (f[i] > f[i + 1]) {
                ok = true;
                break;
            }
        }

        if (!ok) {
            cout << "NO";
            return;
        }
    }

    for (ll i = 1 ; i <= n ; ++i)
        cout << f[i] << " ";





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

