/**
 *    author: Ayush
 *    From: Earth
**/
#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define dbg(x)  cerr << #x << ": "<< x <<endl
#define dbg2(x,y) cerr<< #x <<": "<< x <<" || "<< #y << ": " << y << endl


/* MINIMUM HAMILTONIAN PATH for K vertices */


const int mxn = 2e5 + 5;
const int mx = 20; /* log(depth of tree) => worst case log(10^6) */
vector <int> v[mxn];
const int K = 18;
int dist[K][K];

int get(int x , int y)
{
    int D[mxn] = {} , vis[mxn] = {};
    queue <int> q;
    q.push(x);
    D[x] = 0 , vis[x] = 1;
    while (!q.empty()) {
        int p = q.front();
        q.pop();
        if (p == y) return D[p];

        for (auto it : v[p]) {
            if (!vis[it]) {
                vis[it] = 1 , D[it] = D[p] + 1;
                q.push(it);
            }
        }
    }

    return -1;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0 ; i < m ; ++i) {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    int k;
    cin >> k;
    int p[k];

    for (int i = 0 ; i < k ; ++i) {
        cin >> p[i];
    }

    for (int i = 0 ; i < k ; ++i) {
        for (int j = 0 ; j < k ; ++j) {
            dist[i][j] = get(p[i] , p[j]);
            if (dist[i][j] == -1) {
                cout << -1 << "\n";
                return 0;
            }
        }
    }

    vector <vector<int>> dp((1 << k) ,  vector<int> (k , mxn));
    for (int i = 0 ; i < k ; ++i) {
        dp[(1 << i)][i] = 0;
    }

    for (int mask = 1 ; mask < (1 << k) ; ++mask) {
        for (int i = 0 ; i < k ; ++i) {
            if (mask & (1 << i)) {
                for (int j = 0 ; j < k ; ++j) {
                    if (mask & (1 << j) && j != i) {
                        dp[mask][i] = min(dp[mask][i] , dp[mask ^ (1 << i)][j] + dist[i][j]);
                    }
                }
            }
        }
    }

    int ans = mxn;
    for (int i = 0 ; i < k ; ++i) {
        ans = min(ans , dp[(1 << k) - 1][i] + 1);
    }

    cout << ans << "\n";

    return 0;
}
