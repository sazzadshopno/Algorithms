#include<bits/stdc++.h>
using namespace std;
using ll = int64_t;
const int MOD = 1e9+7;
const int maxN = 1e6+5;
int a[maxN], cnt[maxN];

//  Dirichlet divisor problem
int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, cnter = 0, mx = INT_MIN;
	cin >> n;
	for(int i = 0; i < n; ++i){
        cin >> a[i];
        cnt[a[i]]++;
        mx = max(mx, a[i]);
	}
    for(int i = mx; i > 0; i--){
        int j = i;
        cnter = 0;
        while(j <= mx){
            if(cnt[j] >= 2){
                cout << j << endl;
                return 0;
            }else if(cnt[j] == 1){
                cnter++;
            }
            j += i;
            if(cnter == 2){
                cout << i << endl;
                return 0;
            }
        }
    }
    return 0;
}



