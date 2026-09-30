class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        int j = 0;
        int n = nums.size();
        while (n--) {
            if(nums[i] != 0){
                swap(nums[i], nums[j]);
                j++;
            }
            i++;
        }
    }
};