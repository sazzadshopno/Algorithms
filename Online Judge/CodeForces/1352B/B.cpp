#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int num, k;
        cin >> num >> k;
        int m = k - 1;
        if(num > m && (num - m) % 2){
            cout << "YES" << endl;
            for(int i = 0; i < m; i++){
                cout << "1 ";
            }
            cout << num - m << endl;
        }else{
            if(num > m * 2 && (num - (m * 2)) % 2 == 0){
                cout << "YES" << endl;
                for(int i = 0; i < m; i++){
                    cout << "2 ";
                }
                cout << num - (m * 2) << endl;
            }else{
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}
