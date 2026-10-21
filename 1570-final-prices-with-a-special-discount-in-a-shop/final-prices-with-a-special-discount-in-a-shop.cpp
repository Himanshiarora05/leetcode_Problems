class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> ans(n);
        for(int i = 0;i<n;i++){
            int j = i+1;
            while(j<n){
                if(prices[i] >= prices[j]){
                    ans[i] = prices[i] - prices[j];
                    break;
                } 
                j++;
            }
            if(j == n) ans[i] = prices[i];
        }
       return ans; 
    }
};