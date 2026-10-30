class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& arr, vector<int>& newInterval) {
        //divide array into 3 parts -> before , overlapping part and after
        int n = arr.size();
        vector<vector<int>> ans;
        int i = 0;
        while(i<n && arr[i][1] < newInterval[0]){
            ans.push_back(arr[i]);
            i++;
        }
        while(i<n && arr[i][0] <= newInterval[1]){
            newInterval[0] = min(newInterval[0],arr[i][0]);
            newInterval[1] = max(newInterval[1],arr[i][1]);
            i++;
        }
        ans.push_back(newInterval);
        while(i<n){
            ans.push_back(arr[i]);
            i++;            
        }
        return ans;
    }
};