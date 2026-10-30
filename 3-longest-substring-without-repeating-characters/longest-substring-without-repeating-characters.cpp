class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int n = s.length();
        int j = 0;
        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            while (st.find(s[i]) != st.end()) { // mil gya
                st.erase(s[j]);
                j++;
            }
            st.insert(s[i]);
            ans = max(ans, i - j + 1);
        }
        return ans;
    }
};