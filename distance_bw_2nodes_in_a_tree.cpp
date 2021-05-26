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

int dist(int x , int y)
{
    int L = depth[x] + depth[y];
    if (depth[x] < depth[y])
        swap(x , y);
 
    int up = depth[x] - depth[y];
    for (int i = 0 ; i < mx ; ++i) {
        if (up & (1 << i)) {
            x = lca[x][i];
        }
    }
 
    if (x == y)
        return L - 2 * depth[x];
 
    for (int i = mx - 1 ; i >= 0 ; --i) {
        if (lca[x][i] != lca[y][i]) {
            x = lca[x][i];
            y = lca[y][i];
        }
    }
 
    return L - 2 * depth[lca[x][0]];
  
   /* depth[x] + depth[y] - 2 * (depth[lca(x,y)]) */
}
