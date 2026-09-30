class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extra) {
        int n = candies.size();
        int maxi = INT_MIN;
        for(int i = 0;i<n;i++)  maxi = max(maxi,candies[i]);

        vector<bool> ans;
        for(int i = 0;i<n;i++){
            bool x = false;
            if((candies[i]+ extra) >= maxi) x = true;
            ans.push_back(x);
        }
        return ans;
    }
};