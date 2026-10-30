class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;
        for (auto x : strs) {
            string temp = x;
            sort(temp.begin(), temp.end());
            if (mp.find(temp) == mp.end()) {
                vector<string> v;
                v.push_back(x);
                mp[temp] = v;
            } else {
                mp[temp].push_back(x);
            }
        }
        for (auto x : mp) {
            vector<string> v = x.second;
            ans.push_back(v);
        }
        return ans;
    }
};