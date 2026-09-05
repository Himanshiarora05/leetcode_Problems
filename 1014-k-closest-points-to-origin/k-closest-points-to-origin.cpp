class Solution {
public:
    typedef pair<int, vector<int>> pi;
    vector<vector<int>> kClosest(vector<vector<int>>& arr, int k) {
        priority_queue<pi> pq;
        for (int i = 0; i < arr.size(); i++) {
            int x = arr[i][0];
            int y = arr[i][1];
            int dis = x * x + y * y;
            pq.push({dis, arr[i]});
            if (pq.size() > k)  pq.pop();
        }
        vector<vector<int>> ans;
        while (pq.size() > 0) {
            vector<int> num = pq.top().second;
            ans.push_back(num);
            pq.pop();
        }
        return ans;
    }
};