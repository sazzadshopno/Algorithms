#include<bits/stdc++.h>
using namespace std;
void solve(int n){
    if(n <= 3){
        cout << -1 << endl;
    }else{
        for(int i = n - (1 - n % 2); i >= 1; i -= 2) cout << i << " ";
        cout << 4 << " " << 2 << " ";
        for(int i = 6; i <= n; i += 2)  cout << i << " ";
        cout << endl;
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        solve(n);
    }
    return 0;
}


