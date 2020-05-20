#include <bits/stdc++.h>
using namespace std;
//Range Updates and Range Queries
#define mx 200002
using ll = int64_t;
ll B1[mx], B2[mx];
ll N, q;
void add(ll b[], ll idx, ll x){
    while (idx <= N){
        b[idx] += x;
        idx += idx & -idx;
    }
}
void range_add(ll l,ll r,ll x){
    add(B1, l, x);
    add(B1, r+1, -x);
    add(B2, l, x*(l-1));
    add(B2, r+1, -x*r);
}

ll sum(ll b[], ll idx){
    ll total = 0;
    while (idx > 0){
        total += b[idx];
        idx -= idx & -idx;
        }
    return total;
}
ll prefix_sum(ll idx){
    return sum(B1, idx)*idx -  sum(B2, idx);
}
ll range_sum(ll l, ll r){
    return prefix_sum(r) - prefix_sum(l-1);
}
int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    cin >> N >> q;
    for(ll i = 1, x; i <= N; ++i){
        cin >> x;
        range_add(i, i, x);
    }
    while(q--){
        ll k, a, b, c;
        cin >> k;
        if(k == 1){
            cin >> a >> b >> c;
            range_add(a, b, c);
        }else{
            cin >> a;
            cout << range_sum(a, a) << endl;
        }
    }
    return 0;
}
