#include<bits/stdc++.h>
using namespace std;
using ll = int64_t;
const int MOD = 1e9+7;

ll binpow(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll t;
	cin >> t;
	while(t--){
        ll a, b, c;
        cin >> a >> b >> c;
        cout << binpow(a, binpow(b, c, MOD-1), MOD) << endl;
	}
    return 0;
}


