#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define MAX 1e14


void build(ll a[] , ll lb , ll rb , ll f[] , ll node)
{
    if (lb == rb) {
        f[node] = a[lb];
        return;
    }

    ll mid = (lb + rb) / 2;

    build(a , lb , mid , f , 2 * node);
    build(a , mid + 1 , rb , f , 2 * node + 1);

    f[node] = min(f[2 * node] , f[2 * node + 1]);
    return;

}

ll query(ll lb , ll rb , ll qlb , ll qrb , ll f[] , ll node)
{

    if (lb >= qlb && qrb >= rb) {
        return f[node];
    }

    if (qlb > rb || qrb < lb)
        return MAX;


    ll mid = (lb + rb) / 2;

    ll left = query(lb , mid , qlb , qrb , f , 2 * node);
    ll right = query(mid + 1 , rb , qlb , qrb , f , 2 * node + 1);
    return min(left , right);
}

void update(ll lb , ll rb , ll idx , ll val , ll f[] , ll node)
{
    if (idx > rb || idx < lb)
        return;

    if (lb == rb) {
        f[node] = val;
        return;
    }

    ll mid = (lb + rb) / 2;

    update(lb , mid , idx , val , f,  2 * node);
    update(mid + 1 ,  rb , idx ,  val ,  f ,  2 * node + 1);
    f[node] = min(f[2 * node] , f[2 * node + 1]);
}


int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0);
    //TEST
    ll n, q;
    cin >> n >> q;
    ll a[n];
    for (ll i = 0 ; i < n ; ++i) {
        cin >> a[i];
    }

    ll f[4 * n + 1];
    build(a , 0 , n - 1 , f , 1);
    while (q--) {
        ll t;
        cin >> t;
        ll l , r , idx , val;
        if (t == 1) {
            cin >> l >> r;
            l-- , r--;
            cout << query(0 , n - 1 , l , r ,  f , 1) << endl;
        }
        else {
            cin >> idx >> val;
            idx--;
            update(0 , n - 1 , idx , val , f , 1);
        }
    }

    return 0;
}