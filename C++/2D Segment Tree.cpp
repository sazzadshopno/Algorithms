#include <bits/stdc++.h>
using namespace std;
class SegmentTree2D{
     vector< vector<int>> st;       // to store 2D segment tree
     vector< vector<int>> mat;      // to store matrix
    int m, n;

public:
    SegmentTree2D( vector< vector<int>> &matrix){
        mat = matrix;
        m = mat.size();
        n = mat[0].size();
        // initialize st
        st.assign(4 * m,  vector<int> (4 * n, 0));
        build2D(1, 0, m - 1);
    }

    void build( vector<int> &segTree,  vector<int> &ar, int index, int L, int R){
        if(L == R){
            segTree[index] = ar[L];
        }
        else{
        int mid = (L + R) / 2;
        // 2*index will be left child
        build(segTree, ar, 2*index, L, mid);
        // 2*index + 1 will be right child
        build(segTree, ar, 2*index + 1, mid + 1, R);
        // finally, add the values from two children into the parent
        segTree[index] = segTree[2*index] + segTree[2*index + 1];
        }
    }

    int query( vector<int> &segTree, int index, int L, int R, int start, int end){
        if(start > R || end < L){
            // -1 used as null value here
            return -1;
        }

        if (L >= start and R <= end)
            return segTree[index];

        int mid = (L + R) / 2;
        int left = query(segTree, 2*index, L, mid, start, end);
        int right = query(segTree, 2*index + 1, mid + 1, R, start, end);

        if(left == -1)
            return right;
        if(right == -1)
            return left;
        return left + right;
    }

    void build2D(int index, int L, int R){
        // if at leaf node, build a 1D segment tree
        if(L == R)
            build(st[index], mat[L], 1, 0, n - 1);

        else{
            int mid = (L + R) / 2;

            // build left child segment tree
            build2D(2*index, L, mid);
            // build right child segment tree
            build2D(2*index + 1, mid + 1, R);

            // merge left and right children
            for(int i = 0; i < st[index].size(); ++i)
                st[index][i] = st[2*index][i] + st[2*index + 1][i];
        }
    }

    int query2D(int index, int L, int R, int x1, int y1, int x2, int y2){
        if(L > x2 || R < x1)
            return -1;

        if(L >= x1 and R <= x2)
            return query(st[index], 1, 0, n - 1, y1, y2);

        int mid = (L + R) / 2;

        // query left child. Returned value will be integer
        int left = query2D(2*index, L, mid, x1, y1, x2, y2);
        // query right child. Returned value will be integer
        int right = query2D(2*index + 1, mid + 1, R, x1, y1, x2, y2);

        if(left == -1)
            return right;
        if(right == -1)
            return left;

        return left + right;
    }

    // Main query function
    int query(int x1, int y1, int x2, int y2){
        return query2D(1, 0, m - 1, x1, y1, x2, y2);
    }
};

int main(){
    vector< vector<int>> matrix = { vector<int>({1, 1, 2, 2}),
                               vector<int>({3, 3, 4, 4}),
                               vector<int>({5, 5, 6, 6}),
                               vector<int>({7, 7, 8, 8})};

    SegmentTree2D st(matrix);

    cout << "Matrix is\n";
    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < 4; ++j)
             cout << matrix[i][j] << ' ';
         cout << '\n';
    }

    cout << "Sum of sub-matrix ((1, 1), (3, 3)) is " << st.query(1, 1, 3, 3) << '\n';
    cout << "Sum of row 2 is " << st.query(2, 0, 2, 3) << '\n';
    return 0;
}
