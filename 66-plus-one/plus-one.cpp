class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] != 9) {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }
        vector<int> ans(n + 1, 0);
        ans[0] = 1;  //special case when we have array like {9,9,9} it will become {0,0,0} then just add 1 in front of it so that it become {1,0,0,0}
        return ans; 
    }
};