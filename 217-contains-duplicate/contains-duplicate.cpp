class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size() <=1) return false;
        unordered_map<int,int> mp;
        for(auto ele : nums) {
            mp[ele]++;
            if(mp[ele] > 1) return true;
        }
        return false;
    }
};