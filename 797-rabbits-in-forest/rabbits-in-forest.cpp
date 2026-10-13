class Solution {
public:
    int numRabbits(vector<int>& nums) {
        unordered_map<int,int> mp;
        int ans = 0;
        for(int i = 0;i<nums.size();i++){
            int key = nums[i] + 1;
            if(mp[key] == 0){
                ans += key;
                mp[key] = 1;
            }
            else{
                mp[key]++;
            }
            if(mp[key] == key) 
                mp.erase(key);
        }
        return ans;
    }
};