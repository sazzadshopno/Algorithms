class Solution
{
public:
    int numberOfSubarrays(vector<int> &arr, int k)
    {
        for (int &x : arr)
            x = x & 1 ? 1 : 0;
        unordered_map<int, int> prevSum;
         int currsum = 0, res = 0, n = arr.size(), sum = k;
        for (int i = 0; i < n; i++)
        {
                    currsum += arr[i];
                    if (currsum == sum)
            res++;
                    if (prevSum.find(currsum - sum) != prevSum.end())
            res += (prevSum[currsum - sum]);
                    prevSum[currsum]++;

                
        }
            return res;
    }
};