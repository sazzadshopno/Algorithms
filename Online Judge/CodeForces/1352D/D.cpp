#include<bits/stdc++.h>
using namespace std;
void solve(vector<int > arr, int n){
    int left = 0, right = n - 1, turn = 1;
    int prevl = 0, prevr = 0;
    int l = 0, r = 0;
    while(left <= right){
        if(turn & 1){
            int sum = 0;
            while(left <= right && sum <= prevr){
                sum += arr[left]; left++;
            }
            prevl = sum;
            l += sum;
        }else{
            int sum = 0;
            while(left <= right && sum <= prevl){
                sum += arr[right]; right--;
            }
            prevr = sum;
            r += sum;
        }
        turn++;
    }
    cout << turn - 1 << " " << l << " " << r << endl;
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
