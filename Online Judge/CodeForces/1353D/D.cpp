#include<bits/stdc++.h>
using namespace std;
void solve(int64_t n){
    int arr[n+1];
    memset(arr, 0, sizeof(arr));
    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push({n, {-1, -n}});
    int cnt = 1;
    while(!pq.empty()){
        int l = -pq.top().second.first;
        int r = -pq.top().second.second;
        pq.pop();
        int mid = (l + r) / 2;
        arr[mid] = cnt++;
        if(l == r) continue;
        if(l < mid){
            pq.push({mid - l, {-l, -(mid-1)}});
        }
        if(mid < r){
            pq.push({r - mid, {-(mid+1), -r}});
        }
    }

    for(int i = 1; i <= n; i++) cout << arr[i] << " ";
    cout << endl;
}
int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int64_t n;
        cin >> n;
        solve(n);
    }
    return 0;
}

