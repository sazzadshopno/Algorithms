#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
    while(t--){
        uint64_t a, b, mx, mn, s;
        cin >> a >> b;
        mx = max(a, b);
        mn = min(a, b);
        s = (mx - 1) * (mx - 1);
        if(a == b) s += a;
        else if(mx & 1){
            if(mx == b) s += mx * 2 - a;
            else s += b;
        }else{
            if(mx == a) s += mx * 2 - b;
            else s += a;
        }

        cout << s << endl;
    }
    return 0;
}
