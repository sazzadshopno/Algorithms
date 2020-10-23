class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int n = digits.size();
        digits[n - 1] += 1;
        int carry = digits[n - 1] / 10;
        digits[n - 1] %= 10;
        for (int i = n - 2; i > -1; i--)
        {
            if (carry)
            {
                digits[i] += carry;
                carry = digits[i] / 10;
                digits[i] %= 10;
            }
        }
        if (carry)
        {
            digits.insert(digits.begin(), carry);
        }
        return digits;
    }
};