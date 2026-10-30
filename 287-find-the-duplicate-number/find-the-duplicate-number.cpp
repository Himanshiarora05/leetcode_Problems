class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto x : nums){
            mp[x]++;
        }
        int ans;
        for(auto y : mp){
            int freq = y.second;
            if(freq > 1){
                ans = y.first;
                break;
            }
        }
        return ans;
    }
};