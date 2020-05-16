#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	int64_t n, res = 0, x = 5;
	cin >> n;
	while(x <= n){
        res += (n / x);
        x *= 5;
	}
	cout << res << endl;
    return 0;
}





