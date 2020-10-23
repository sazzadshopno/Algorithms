class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> p(amount+1, 0);
        p[0] = 1;
        for(int i = 0; i < coins.size(); i++) for(int j = coins[i]; j <= amount; j++) p[j] += p[j- coins[i]];
        return p[amount];
    }
};
