class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        vector<int> h(26,0);
        for(int i = 0;i<s.length();i++){
            h[s[i] - 'a']++;    //freq inc
        }
        for(int i = 0;i<t.length();i++){
            int x = --h[t[i] - 'a'];   //dec freq by using 2nd string
            if(x<0) return false;
        }
        return true;
    }
};