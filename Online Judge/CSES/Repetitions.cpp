#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s; int res = 0;
	cin >> s;
    for(int i = 0; i < s.size(); i++){
        int cnt = 1;
        for(int j = i + 1; j < s.size(); j++, i++){
            if(s[i] == s[j]){
                cnt++;
            }else{
                break;
            }
        }
        res = max(res, cnt);
    }
    cout << res << endl;
    return 0;
}


