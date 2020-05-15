#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, mul = 10, m;
        cin >> m;
        n = m;
        vector<int> v;
        while(mul <= m){
            if(n % mul == 0){
                mul *= 10;
            }else{
                v.push_back(n % mul);
                n -= (n % mul);
                mul *= 10;
            }
        }

        v.push_back(n);
        cout << v.size() << endl;
        for(int i: v){
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
