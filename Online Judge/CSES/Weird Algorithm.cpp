#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	int64_t n;
	cin >> n;
    while(n != 1){
        cout << n << " ";
        if(n & 1){
            n = n * 3 + 1;
        }else{
            n /= 2;
        }
    }
    cout << 1 << endl;
    return 0;
}

