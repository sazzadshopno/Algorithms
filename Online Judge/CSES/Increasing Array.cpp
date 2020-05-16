#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	int64_t n, res = 0;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; i++) cin >> v[i];
    for(int i = 1; i < n; i++){
        if(v[i] < v[i - 1]){
            res += (v[i - 1] - v[i]);
            v[i] += (v[i - 1] - v[i]);
        }
    }
    cout << res << endl;
    return 0;
}



