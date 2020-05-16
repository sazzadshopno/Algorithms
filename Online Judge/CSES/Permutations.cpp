#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	int64_t n, res = 0;
	cin >> n;
	if(n == 1){
        cout << 1 << endl;
	}else if(n <= 3){
        cout << "NO SOLUTION" << endl;
	}else if(n == 4){
        cout << "2 4 1 3" << endl;
	}else{
	    for(int i = n - (n % 2); i >= 2; i -= 2){
            cout << i << " ";
        }
        for(int i = n - (!(n & 1)); i >= 1; i -= 2){
            cout << i << " ";
        }
	}
    return 0;
}




