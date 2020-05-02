#include<set>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0, l = 0, r = 0;
        set<char> sett;
        while(r < s.length()){
            if(sett.find(s[r]) == sett.end()){
                sett.insert(s[r]);
                res = max(res, (int) sett.size());
                r++;
            }else{
                sett.erase(s[l]);
                l++;
            }
        }
        return res;
    }
};
