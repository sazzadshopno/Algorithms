#include<bits/stdc++.h>
using namespace std;
void solve(int64_t n){
    cout << 4 * n * (n + 1) * (2 * n + 1) / 3 << endl;
}
int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int64_t n;
        cin >> n;
        solve(n/2);
    }
    return 0;
}
