#include<bits/stdc++.h>
using namespace std;
using ll = int64_t;
using ull = uint64_t;

void solve(){
    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        int mx = max(a, b);
        if((a % 2) == 0 && (b % 2) == 0){
            cout << mx * mx <<endl;
        }else{
            mx++;
            cout << mx * mx <<endl;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
