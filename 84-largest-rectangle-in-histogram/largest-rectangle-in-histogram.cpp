class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();
        stack<int> st1;
        vector<int> nse(n);
        for(int i = n-1;i>=0;i--){
            while(!st1.empty() && arr[st1.top()] >= arr[i]) st1.pop();
            if(st1.empty()) nse[i] = n;
            else nse[i] = st1.top();
            st1.push(i);
        }
        stack<int> st2;
        vector<int> pse(n);
        for(int i = 0;i<n;i++){
            while(!st2.empty() && arr[st2.top()] >= arr[i]) st2.pop();
            if(st2.empty()) pse[i] = -1;
            else pse[i] = st2.top();
            st2.push(i);
        }
        int area = 0;
        for(int i = 0;i<n;i++){
            int h = arr[i];
            int b = nse[i] - pse[i] -1;
            area = max(area,h*b);
        }
        return area;
    }
};