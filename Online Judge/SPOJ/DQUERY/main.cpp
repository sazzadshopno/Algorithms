#include<bits/stdc++.h>
using namespace std;

const int maxn = 1000006;
int K, ans[maxn], a[maxn], cnt[maxn], dis;

struct Query{
    int index, L, R;
    bool operator < (const Query &other) const {
		int block_own = L/K;
		int block_other = other.L/K;
		if(block_own == block_other)
            return R < other.R;
		return block_own < block_other;
	}
}query[maxn];

void add(int index){
    if(cnt[a[index]] == 0) dis++;
    cnt[a[index]] += 1;
}

void remove(int index){
    if(cnt[a[index]] == 1)  dis--;
    cnt[a[index]] = max(0, cnt[a[index]] - 1);
}

int main(){
    int n;
    cin>>n;
    K = sqrt(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int q;
    cin >> q;
    for(int i=0;i<q;i++){
        cin >> query[i].L >> query[i].R;
        query[i].L--;
        query[i].R--;
        query[i].index = i;
    }
    sort(query, query+q);
    int L=0, R=-1;
    for(int i=0;i<q;i++){
        while(R<query[i].R) add(++R);
        while(L<query[i].L) remove(L++);
        while(R>query[i].R) remove(R--);
        while(L>query[i].L) add(--L);
        ans[query[i].index] = dis;
    }
    for(int i=0;i<q;i++){
        cout << ans[i] << "\n";
    }
    return 0;
}
