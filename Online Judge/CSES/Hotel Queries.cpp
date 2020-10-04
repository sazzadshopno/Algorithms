#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
const int maxN = 2e5+5;
const ll maxV = 1e9;
const ll INF = 1e15;
struct cmp{
    bool operator()(const pair<ll, ll> &a, const pair<ll, ll> &b)const {
        if(a.first == b.first){
            return b.second > a.second;
        }
        return a.first < b.first;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    int n, m;
    cin >> n >> m;
    ll arr[n+1];
    multiset<pair<ll, ll>, cmp> t;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        t.insert({arr[i], i});
    }
    while(m--){
        ll i;
        cin >> i;
        multiset<pair<ll, ll> >::iterator pos = t.lower_bound({i, -1});
        if(pos != t.end()){
            pair<ll, ll> r = *pos;
            if(r.first > maxV){
                cout << 0 << " ";
                continue;
            }
            cout << r.second << " ";
            t.erase(pos);
            arr[r.second] = arr[r.second] - i;
            if(arr[r.second] == 0){
                t.insert({INF, r.second});
            }else{
                t.insert({arr[r.second], r.second});
            }
        }else{
            cout << "0 ";
        }
        cout << endl;
        for(pair<ll, ll> i: t){
            cout << "Value: " <<  i.first << " Index: " << i.second << endl;
        }
    }
    return 0;
}

