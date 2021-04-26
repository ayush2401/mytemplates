const ll mxn = 1e6 + 2;
ll n, m;
map <pair<ll, ll> , ll> vis;
ll dx[] = {1 , -1 , 0 , 0};
ll dy[] = {0 , 0 , 1 , -1};
string s[mxn];
bool valid(ll x , ll y)
{
    return (x < n && x >= 0 && y < m && y >= 0 && s[x][y] == '1' && !vis[ {x, y}]);
}

ll bfs(ll x , ll y)
{
    queue <pair<ll, ll>> q;
    q.push({x , y});
    vis[ {x , y}] = 1;
    ll c = 0;
    while (!q.empty()) {

        pair<ll, ll> pp = q.front();
        q.pop();
        c++;

        for (ll i = 0 ; i < 4 ; ++i) {
            ll X = pp.ff + dx[i] , Y = pp.ss + dy[i];
            if (valid(X, Y)) {
                vis[ {X, Y}] = 1;
                q.push({X, Y});
            }
        }
    }

    return c;

}
