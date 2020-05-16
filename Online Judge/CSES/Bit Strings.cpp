#include<bits/stdc++.h>
using namespace std;
int big_mod(int64_t a, int64_t b, int64_t m){
    int64_t r = 1, e = a;
        while (b) {
        if (b & 1) r = (r * e) % m;
        e = (e * e) % m;
        b >>= 1;
    }
    return r;
}
int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	int64_t n;
	cin >> n;
	cout << big_mod(2, n, 1000000007) << endl;
    return 0;
}






