#include<bits/stdc++.h>
using namespace std;
using ll = int64_t;

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, x;
	set<int> s;
	cin >> n;
	while(n--){
        cin >> x;
        s.insert(x);
	}
	cout << s.size() << endl;
    return 0;
}
