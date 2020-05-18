#include <bits/stdc++.h>
using namespace std;
#define mx 200002
int arr[mx];
int tree[4 * mx];
void init(int node, int b, int e){
    if(b == e){
        tree[node] = arr[b];
        return;
    }
    int left = node << 1;
    int right = (node << 1) + 1;
    int mid = (b + e) >> 1;
    init(left, b, mid);
    init(right, mid + 1, e);
    tree[node] = min(tree[left], tree[right]);
}
int query(int node, int b, int e, int i, int j){
    if(i > e || b > j){
        return INT_MAX;
    }
    if(b >= i && e <= j){
        return tree[node];
    }
    int left = (node << 1);
    int right = (node << 1) + 1;
    int mid = (b + e) >> 1;
    int p1 = query(left, b, mid, i, j);
    int p2 = query(right, mid + 1, e, i, j);
    return min(p1, p2);
}
void update(int node, int b, int e, int idx, int value){
    if(idx > e || b > idx) return;
    if(b >= idx && e <= idx){
        tree[node] = value;
        return;
    }
    int left = (node << 1);
    int right = (node << 1) + 1;
    int mid = (b + e) >> 1;
    update(left, b, mid, idx, value);
    update(right, mid + 1, e, idx, value);
    tree[node] = min(tree[left], tree[right]);
}
int main(){
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    init(1, 0, n - 1);
    while(q--){
        int k, l, r;
        cin >> k >> l >> r;
        if(k == 2){
            cout << query(1, 0, n - 1, l-1, r-1) << endl;
        }else{
            update(1, 0, n - 1, l - 1, r);
        }
    }
    return 0;
}

