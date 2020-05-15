#include<bits/stdc++.h>
using namespace std;
void solve(int64_t n, int64_t m){
    if(n == 1){
        cout << 0 << endl;
    }else if(n == 2){
        cout << m << endl;
    }else{
        cout << m * 2 << endl;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int64_t n, m;
        cin >> n >> m;
        solve(n, m);
    }
    return 0;
}




