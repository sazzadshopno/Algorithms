#include<bits/stdc++.h>
using namespace std;
using ll = int64_t;

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll t;
	cin >> t;
	while(t--){
        ll a, b;
        cin >> a >> b;
        if((a + b) % 3 == 0 && min(a, b) * 2 >= max(a, b)){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
	}
    return 0;
}
