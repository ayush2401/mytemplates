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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;


typedef long long int ll;
typedef long double db;

#define pair_set tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>
#define ordered_set tree <int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define TEST int t; cin>>t; while(t--)
#define vell vector<int>
#define pl pair<int,int>
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

const int mxn = 2e5 + 5;
const int mx = 20;
vector <int> v[mxn] , path;
int depth[mxn] = {};
int in[mxn] , ou[mxn];
int tim = 0;
vector <int> s[mxn];

void dfs(int x , int par)
{
    in[x] = tim++;
    for (auto it : v[x]) {
        if (it != par) {
            depth[it] = 1 + depth[x];
            dfs(it , x);
        }
    }

    ou[x] = tim;
}

/* NO of nodes in the subtree of x and is at level k using euler tour */

int get(int x , int k)
{

    if (k == depth[x]) return 1;
    int F = upper_bound(all(s[k]) , in[x]) - s[k].begin();
    int B = upper_bound(all(s[k]) , ou[x]) - s[k].begin();
    return B - F;
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 1 ; i < n ; ++i) {
        int x;
        cin >> x;
        x--;
        v[x].pb(i);
        v[i].pb(x);
    }


    dfs(0 , -1);
    for (int i = 1 ; i <= n ; ++i)
        s[depth[i]].pb(in[i]);

    for (int i = 1 ; i <= n ; ++i) {
        sort(all(s[i]));
    }

    
    /* queries to get no of nodes in the subtree of x with depth k */
    int q;
    cin >> q;
    while (q--) {
        int x , k;
        cin >> x >> k;
        cout << get(x - 1, k) << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //TEST
    solve();
}
