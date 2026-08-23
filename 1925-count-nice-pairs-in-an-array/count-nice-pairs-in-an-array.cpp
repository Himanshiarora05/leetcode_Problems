class Solution {
public:
    int reverse(int n) {
        int rev = 0;
        while (n > 0) {
            int rem = n % 10;
            rev = rev * 10 + rem;
            n = n / 10;
        }
        return rev;
    }
    int countNicePairs(vector<int>& nums) {
        unordered_map<int, int> mp;
        long long count = 0;

        //updating array by ele-rev(ele)
        for(int i = 0;i<nums.size();i++){
            nums[i] = nums[i] - reverse(nums[i]);
        }

        for (int i = 0; i < nums.size(); i++) {
            if (mp.find(nums[i]) != mp.end()) { 
                count += mp[nums[i]];  //increase count by freq
            }
            mp[nums[i]]++;
        }
        
        return count % 1000000007;
    }
};

 //(nums[i] - rev(nums[i])) == (nums[j] - rev(nums[j])).