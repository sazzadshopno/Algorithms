#include <bits/stdc++.h>
using namespace std;

int main() {
    int matrix[5][5];
    for(int i = 0; i < 5; i++) for(int j = 0; j < 5; j++) cin >> matrix[i][j];
    for(int i = 0; i < 5; i++){
        if(count(matrix[i], matrix[i]+5,1)){
            for(int j = 0; j < 5; j++){
                if (matrix[i][j] == 1) cout << abs(i - 2) + abs(j - 2) << endl;
            }
        }
    }
    return 0;
}
