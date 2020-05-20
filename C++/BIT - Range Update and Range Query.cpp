#include <bits/stdc++.h>
using namespace std;
//Range Updates and Range Queries
#define mx 200002
int B1[mx], B2[mx];
int N, q;
void add(int b[], int idx, int x){
    while (idx <= N){
        b[idx] += x;
        idx += idx & -idx;
    }
}
void range_add(int l,int r,int x){
    add(B1, l, x);
    add(B1, r+1, -x);
    add(B2, l, x*(l-1));
    add(B2, r+1, -x*r);
}

int sum(int b[], int idx){
    int total = 0;
    while (idx > 0){
        total += b[idx];
        idx -= idx & -idx;
        }
    return total;
}
int prefix_sum(int idx){
    return sum(B1, idx)*idx -  sum(B2, idx);
}
int range_sum(int l, int r){
    return prefix_sum(r) - prefix_sum(l-1);
}
int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    cin >> N >> q;
    for(int i = 1, x; i <= N; ++i){
        cin >> x;
        range_add(i, i, x);
    }
    while(q--){
        int k, a, b, c;
        cin >> k;
        if(k == 1){
            cin >> a >> b >> c;
            range_add(a, b, c);
        }else{
            cin >> a;
            cout << range_sum(a, a) << endl;
        }
    }
    return 0;
}
