#include<bits/stdc++.h>
using namespace std;
void solve(int64_t n, int64_t k, vector<int> a, vector<int> b){
    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());
    for(int i = 0; i < k; i++){
        if(a[i] < b[i]){
            a[i] = b[i];
        }else{
            break;
        }
    }
    int res = 0;
    for(int i: a) res += i;
    cout << res << endl;
}
int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int64_t n, k;
        cin >> n >> k;
        vector<int> a(n), b(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        for(int i = 0; i < n; i++){
            cin >> b[i];
        }
        solve(n, k, a, b);
    }
    return 0;
}





