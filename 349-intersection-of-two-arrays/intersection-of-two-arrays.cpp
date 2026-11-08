class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st;
        unordered_set<int> ans;
        for(int i = 0;i<nums1.size();i++){
            st.insert(nums1[i]);
        }
        for(int i = 0;i<nums2.size();i++){
            if(st.find(nums2[i]) != st.end()){
                ans.insert(nums2[i]);
                st.erase(nums2[i]);
            }
        }
        vector<int> result;
        for(auto x : ans){
            result.push_back(x);
        }
        return result;
    }
};