class Solution {
public:
    typedef pair<int, int> pi;
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pi> pq;
        for (int i = 0; i < arr.size(); i++) {
            int diff = abs(arr[i] - x);
            pq.push({diff, arr[i]});
            if (pq.size() > k) pq.pop();
        }
        vector<int> ans;
        while (pq.size() > 0) {
            int num = pq.top().second;
            ans.push_back(num);
            pq.pop();
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};