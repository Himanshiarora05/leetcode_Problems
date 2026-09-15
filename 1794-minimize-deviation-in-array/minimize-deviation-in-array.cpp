class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> maxpq; //max heap
        int mini = INT_MAX , diff = INT_MAX;
        for(auto ele : nums){
            if(ele%2 != 0) ele*=2;  //make every odd ele -> even
            maxpq.push(ele);
            mini = min(mini,ele);
        }

        while(maxpq.top()%2 == 0){ //jab tak pq ka top ele odd na hojaye
            int x = maxpq.top(); 
            maxpq.pop();
            diff = min(diff,x - mini);
            mini = min(mini,x/2);
            maxpq.push(x/2);
        }
        return min(diff,maxpq.top()- mini);
    }
};