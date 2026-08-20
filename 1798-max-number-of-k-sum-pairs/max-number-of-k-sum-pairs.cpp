class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int ans = 0;  //no. of pairs
        for(int x : nums){
            int y = k - x;
            if(mp[y]>0){  //pair found
                ans++;  
                mp[y]--;  //freq--
            }
            else mp[x]++;  //store in mp
        }
        return ans;
    }
};