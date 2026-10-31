class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int sum = nums[0];
        for (int i = 0; i < n; i++) {
            if (i> sum)  return false;
            int x = nums[i] + i;
            sum = max(sum,x);
            
        }
        return true;
    }
};