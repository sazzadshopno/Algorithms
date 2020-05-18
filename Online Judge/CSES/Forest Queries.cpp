#include <bits/stdc++.h>
using namespace std;
#define N 1010
#define M 1010
int t[4*N][4*M] = {0}, a[N][M] = {0};
int n, m, q;
void build_y(int vx, int lx, int rx, int vy, int ly, int ry) {
    if (ly == ry) {
        if (lx == rx)
            t[vx][vy] = a[lx][ly];
        else
            t[vx][vy] = t[vx*2][vy] + t[vx*2+1][vy];
    } else {
        int my = (ly + ry) / 2;
        build_y(vx, lx, rx, vy*2, ly, my);
        build_y(vx, lx, rx, vy*2+1, my+1, ry);
        t[vx][vy] = t[vx][vy*2] + t[vx][vy*2+1];
    }
}

void build_x(int vx=1, int lx=0, int rx=n-1) {
    if (lx != rx) {
        int mx = (lx + rx) / 2;
        build_x(vx*2, lx, mx);
        build_x(vx*2+1, mx+1, rx);
    }
    build_y(vx, lx, rx, 1, 0, m-1);
}

int query_y(int vx, int vy, int tly, int try_, int ly, int ry) {
    if (ly > ry)
        return 0;
    if (ly == tly && try_ == ry)
        return t[vx][vy];
    int tmy = (tly + try_) / 2;
    return query_y(vx, vy*2, tly, tmy, ly, min(ry, tmy))
         + query_y(vx, vy*2+1, tmy+1, try_, max(ly, tmy+1), ry);
}

int query_x(int lx, int rx, int ly, int ry, int vx=1, int tlx=0, int trx=n-1) {
    if (lx > rx)
        return 0;
    if (lx == tlx && trx == rx)
        return query_y(vx, 1, 0, m-1, ly, ry);
    int tmx = (tlx + trx) / 2;
    return query_x(lx, min(rx, tmx), ly, ry, vx*2, tlx, tmx)
         + query_x(max(lx, tmx+1), rx, ly, ry, vx*2+1, tmx+1, trx);
}

void update_y(int vx, int lx, int rx, int vy, int ly, int ry, int x, int y, int new_val) {
    if (ly == ry) {
        if (lx == rx)
            t[vx][vy] = new_val;
        else
            t[vx][vy] = t[vx*2][vy] + t[vx*2+1][vy];
    } else {
        int my = (ly + ry) / 2;
        if (y <= my)
            update_y(vx, lx, rx, vy*2, ly, my, x, y, new_val);
        else
            update_y(vx, lx, rx, vy*2+1, my+1, ry, x, y, new_val);
        t[vx][vy] = t[vx][vy*2] + t[vx][vy*2+1];
    }
}

void update_x(int x, int y, int new_val, int vx=1, int lx=0, int rx=n-1) {
    if (lx != rx) {
        int mx = (lx + rx) / 2;
        if (x <= mx)
            update_x(x, y, new_val, vx*2, lx, mx);
        else
            update_x(x, y, new_val, vx*2+1, mx+1, rx);
    }
    update_y(vx, lx, rx, 1, 0, m-1, x, y, new_val);
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    cin >> n >> q;
    m = n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            char c;
            cin >> c;
            a[i][j] = c == '*'? 1 : 0;
        }
    }
    build_x();
    while(q--){
        int y1, x1, y2, x2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << query_x(x1-1,x2-1,y1-1,y2-1) << endl;
    }
    return 0;
}
