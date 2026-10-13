class Solution {
public:
    vector<vector<int>> generate(int k) {
        vector<vector<int>> ans(k);
        for (int i = 0; i < k; i++) {
            ans[i].resize(i + 1, 1);
            for (int j = 1; j < i; j++) {
                ans[i][j] = ans[i - 1][j] + ans[i - 1][j - 1];
            }
        }
        return ans;
    }
};