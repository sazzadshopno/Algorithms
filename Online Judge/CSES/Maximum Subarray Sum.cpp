#include<bits/stdc++.h>
using namespace std;
using ll = int64_t;
using ull = uint64_t;

void solve(){
    ll n, r, tr;
    cin >> n;
    vector<ll> v(n);
    for(ll &i: v) cin >> i;
    r = tr = v[0];
    for(int i = 1; i < n; i++){
        tr = max(v[i], tr+v[i]);
        r = max(r, tr);
    }
    cout << r << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
