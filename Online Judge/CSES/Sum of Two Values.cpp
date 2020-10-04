#include<bits/stdc++.h>
using namespace std;
using ll = int64_t;
using ull = uint64_t;

void solve(){
    ll n, x;
    cin >> n >> x;
    vector<ll> v(n);
    for(ll &i: v) cin >> i;
    unordered_map<ll, ll> mp;
    for(int i = 1; i <= n; i++){
        ll r = mp[x-v[i-1]];
        if(!mp[x-v[i-1]]){
            mp[v[i-1]] = i;
        }else{
            cout << r << " " << i << endl;
            return;
        }
    }
    cout << "IMPOSSIBLE" << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
