//K-OS WITH THE OCDE

#include<bits/stdc++.h>

// MOORE VOTING ALGO TO CHECK MAX ACCOURENCE OF A NUMBER IN AN ARRAY
int find(ll a[] , ll n)
{
    ll idx = 0 , count = 1;
    

    // most recourring value
    for (ll i = 1 ; i < n ; ++i) {
        if (a[idx] == a[i])
            count++;
        else
            count--;

        if (!count) {
            idx = i;
            count = 1;
        }
    }

    return a[idx];


}

bool ch(ll a[] , ll n , ll x)
{
    ll c = 0;

    // check for the most significancy

    for (ll i = 0 ; i < n ; ++i)
        if (a[i] == x)
            c++;
    
    // if frequency greater than half of the size return true
    if (c > n / 2)
        return true;

    return false;

}

// MOORE VOTING ALGO
void solve()
{
    ll n;
    cin >> n;
    ll a[n];
    for (ll i = 0 ; i < n ; ++i)
        cin >> a[i];
    
    // obtain value
    ll mx_e = find(a , n);
    

    // check
    if (ch(a , n , mx_e))
        cout << "YES " << mx_e << endl;
    else
        cout << "NO" << endl;
}




