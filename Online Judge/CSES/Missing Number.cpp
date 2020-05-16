#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	int64_t n, sum = 0, res, x;
	cin >> n;
    for(int i = 0; i < n - 1; i++) cin >> x, sum += x;
    cout << n * (n + 1) / 2 - sum << endl;
    return 0;
}


