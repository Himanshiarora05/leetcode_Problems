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

        for(int x : nums) {
            int val = x - reverse(x);

            count += mp[val];
            mp[val]++;
        }

        return count % 1000000007;
    }
};

 //(nums[i] - rev(nums[i])) == (nums[j] - rev(nums[j])).