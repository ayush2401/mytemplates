/* pair comperator */
bool cmp(const pair<ll,ll> &a , const pair<ll,ll> &b)
{
    if(a.ff < b.ff)
        return true;
 
    if(a.ff == b.ff) {
        return a.ss < b.ss;
    }
    
    return false;
}
