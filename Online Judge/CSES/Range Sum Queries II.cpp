#include <bits/stdc++.h>
using namespace std;
#define mx 200002
int64_t arr[mx];
int64_t tree[4 * mx];
void init(int64_t node, int64_t b, int64_t e){
    if(b == e){
        tree[node] = arr[b];
        return;
    }
    int64_t left = node << 1;
    int64_t right = (node << 1) + 1;
    int64_t mid = (b + e) >> 1;
    init(left, b, mid);
    init(right, mid + 1, e);
    tree[node] = tree[left] + tree[right];
}
int64_t query(int64_t node, int64_t b, int64_t e, int64_t i, int64_t j){
    if(i > e || b > j){
        return 0;
    }
    if(b >= i && e <= j){
        return tree[node];
    }
    int64_t left = (node << 1);
    int64_t right = (node << 1) + 1;
    int64_t mid = (b + e) >> 1;
    int64_t p1 = query(left, b, mid, i, j);
    int64_t p2 = query(right, mid + 1, e, i, j);
    return p1 + p2;
}
void update(int64_t node, int64_t b, int64_t e, int64_t idx, int64_t value){
    if(idx > e || b > idx) return;
    if(b >= idx && e <= idx){
        tree[node] = value;
        return;
    }
    int64_t left = (node << 1);
    int64_t right = (node << 1) + 1;
    int64_t mid = (b + e) >> 1;
    update(left, b, mid, idx, value);
    update(right, mid + 1, e, idx, value);
    tree[node] = tree[left] + tree[right];
}
int main(){
    int64_t n, q;
    cin >> n >> q;
    for(int64_t i = 0; i < n; i++){
        cin >> arr[i];
    }
    init(1, 0, n - 1);
    while(q--){
        int64_t k, l, r;
        cin >> k >> l >> r;
        if(k == 2){
            cout << query(1, 0, n - 1, l-1, r-1) << endl;
        }else{
            update(1, 0, n - 1, l - 1, r);
        }
    }
    return 0;
}

