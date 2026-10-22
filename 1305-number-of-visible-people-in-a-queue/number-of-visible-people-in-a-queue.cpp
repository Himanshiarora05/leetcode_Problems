class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> ans;
        for(int i =n-1;i>=0;i--){
            int count = 0;
            while(st.size()>0 && arr[i] >= st.top()){
                st.pop();
                count++;
            }
            if(!st.empty()) count++;
            st.push(arr[i]);
            ans.push_back(count);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};