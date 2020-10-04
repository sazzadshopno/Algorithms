class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0, n = height.size(), l = 0, r = n - 1;
        while(l < r){
            res = max(res, min(height[l], height[r]) * (r - l));
            if(height[l] > height[r]){
                r -= 1;
            }else{
                l += 1;
            }
        }
        return res;
    }
};