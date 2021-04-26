/* build tree */

void build(ll a[] , ll lb , ll rb , ll f[] , ll node)
{
    if (lb == rb) {
        f[node] = a[lb];
        return;
    }

    ll mid = (lb + rb) / 2;

    build(a , lb , mid , f , 2 * node);
    build(a , mid + 1 , rb , f , 2 * node + 1);

    f[node] = f[2 * node] + f[2 * node + 1];
    return;

}

/* query on range */

ll query(ll lb , ll rb , ll qlb , ll qrb , ll f[] , ll node)
{

    if (lb >= qlb && qrb >= rb) {
        return f[node];
    }

    if (qlb > rb || qrb < lb)
        return 0;


    ll mid = (lb + rb) / 2;

    ll left = query(lb , mid , qlb , qrb , f , 2 * node);
    ll right = query(mid + 1 , rb , qlb , qrb , f , 2 * node + 1);
    return left + right;
}

/* update index */

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
    f[node] = f[2 * node] + f[2 * node + 1];
}
