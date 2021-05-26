const int mxn = 2e5 + 5;
const int mx = 20; /* log(depth of tree) => worst case log(10^6) */
vector <int> v[mxn];
int depth[mxn] = {}; /* store depth */
int lca[mxn][mx] = {}; /* mark the 2^ith ancestor of node */
int n;

 
void dfs(int x , int par) /* build tree and mark ancestors */
{
    for (auto it : v[x]) {
        if (it != par) {
            lca[it][0] = x;
            depth[it] = 1 + depth[x];
            for (int i = 1 ; i < mx ; ++i) {
                lca[it][i] = lca[lca[it][i - 1]][i - 1];
            }
          
            dfs(it , x);
        }
    }

}


int ancestor(int x , int k) /* get Kth ancestor of x */
{
    for (int i = 0 ; i < mx ; ++i) {
        if (k & (1 << i))
            x = lca[x][i];
    }
    return x;
}

void solve()
{
    cin >> n;
    for (int i = 0 ; i < n - 1 ; ++i) {
        int x, y;
        cin >> x >> y;
        x-- , y--;
        v[x].pb(y);
        v[y].pb(x);
    }

    dfs(0 , -1);
}
