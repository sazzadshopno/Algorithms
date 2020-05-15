#include<bits/stdc++.h>
using namespace std;
void solve(vector<int > arr, int n){
    int res = 0;
    int cnt[8005];
    memset(cnt, 0, sizeof(cnt));
    for(int i = 0; i < n; i++){
        int sum = arr[i];
        for(int j = i + 1; j < n; j++){
            sum += arr[j];
            if(sum > 8000) break;
            cnt[sum] = 1;
        }
    }
    for(int i = 0; i < n; i++){
        res += cnt[arr[i]];
    }
    cout << res << endl;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int > a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        solve(a, n);
    }
    return 0;
}

