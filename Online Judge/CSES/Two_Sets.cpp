#include<bits/stdc++.h>
using namespace std;
using ll = int64_t;

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n;
	cin >> n;
    ll sn = n * (n + 1) / 2;
    if(sn & 1){
        cout << "NO" << endl;
    }else{
        vector<ll> res;
        ll s = 0, e = 0, i = n;
        sn /= 2;
        while(true){
            res.push_back(i);
            s += i--;
            e = sn - s;
            if(!e) break;
            if(e <= i){
                res.push_back(e);
                break;
            }
        }
        cout << "YES" << endl;
        cout << res.size() << endl;
        for(int j = 0; j < res.size(); j++){
            cout << res[j] << " ";
        }
        cout << "\n" << n - res.size() << endl;
        for(int j = i; j >= 1; j--){
            if(j == e) continue;
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}

