class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long long ans = 0;
        stack<int> st;

        for(int i = 0; i <= n; i++) {
            while(!st.empty() && (i == n || arr[st.top()] >= arr[i])) {
                int idx = st.top();
                st.pop();

                int left = st.empty() ? idx + 1 : idx - st.top();
                int right = i - idx;

                ans = (ans + (long long)arr[idx] * left * right) % 1000000007;
            }
            st.push(i);
        }

        return ans;
    }
};