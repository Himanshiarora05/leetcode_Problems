class Solution {
public:
    int minimumDeviation(vector<int>& nums) { 
        // Max heap
        priority_queue<int> pq;
        int mn = INT_MAX;
        for (int num : nums) {
            if (num % 2 == 1) {   //Make every number even
                num *= 2;
            }
            pq.push(num);
            mn = min(mn, num);
        }
        int ans = pq.top() - mn;
        while (pq.top() % 2 == 0) { //reduce the maximum
            int mx = pq.top();
            pq.pop();
            mx /= 2;
            pq.push(mx);
            mn = min(mn, mx);
            ans = min(ans, pq.top() - mn);
        }
        return ans;
    }
};