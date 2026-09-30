class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> pre(n);
        pre[0] = arr[0];
        for (int i = 1; i < n; i++) {
            pre[i] = pre[i - 1] + arr[i];
        }
        unordered_map<int, int> mp;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (pre[i] == k) {
                cnt++;
            }
            int rem = pre[i] - k;
            cnt += mp[rem];  //increement by freq   //check prev prefix sums
            mp[pre[i]]++;    //inserting value and their freq to map  //check current prefix sums
        }
        return cnt;
    }
};