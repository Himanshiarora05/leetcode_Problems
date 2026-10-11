class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < n; i++) {
            pq.push(nums[i]);
            sum += nums[i];
        }
        while (k--) {
            int x = pq.top();
            if (x == 0)  continue;
            else {
                x = -1 * x;
                pq.pop();
                pq.push(x);
            }
        }
        int newSum = 0;
        while (pq.size() > 0) {
            newSum += pq.top();
            pq.pop();
        }
        return newSum;
    }
};