#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int64_t n, k;
        cin >> n >> k;
        printf("%lld\n", --k/--n+1+k);
    }
    return 0;
}
