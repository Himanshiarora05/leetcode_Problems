class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        unordered_set<int> s; 
        for(int i = 0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        for(auto x : mp){
            int freq = x.second;
            if(s.find(freq) != s.end()) return false;
            else s.insert(freq);
        }
        return true;
    }
};