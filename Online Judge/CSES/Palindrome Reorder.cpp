#include<bits/stdc++.h>
using namespace std;
using ll = int64_t;

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s, res = "";
	int n, num_of_odd = 0;
	cin >> s;
	n = s.size();
    unordered_map<char, int> mp;
	for(char c: s) mp[c]++;

	for(pair<char, int> p: mp){
        if(p.second & 1) num_of_odd++;
        if(num_of_odd > 1){
            cout << "NO SOLUTION" << endl;
            return 0;
        }
        if(p.second & 1) res = string(p.second, p.first);
	}

	for(pair<char, int> p: mp){
        if(!(p.second & 1)){
            string dups = string(p.second / 2, p.first);
            res = dups + res;
            res = res + dups;
            mp[p.first] = 0;
        }
    }
    cout << res << endl;
    return 0;
}



