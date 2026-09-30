class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int n = accounts.size();
        int m = accounts[0].size();
        int maxAns = INT_MIN;
        for(int i = 0;i<n;i++){
            int ans = 0;
            for(int j = 0;j<m;j++){
                ans += accounts[i][j]; 
            }
            maxAns = max(maxAns,ans);
        }
        return maxAns;
    }
};