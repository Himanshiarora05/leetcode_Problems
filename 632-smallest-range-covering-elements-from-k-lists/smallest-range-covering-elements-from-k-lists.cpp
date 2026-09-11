class Solution {
public:
    typedef pair<int, pair<int,int> > pip;
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<pip , vector<pip> , greater<pip> > pq;  //minheap
        int mx = INT_MIN;
        for(int i = 0;i<nums.size();i++){
            mx = max(mx,nums[i][0]);  //find max of first 3 ele
            pq.push({nums[i][0], {i,0}}); //push first ele of each row
        }
        int mn = pq.top().first;  //min heap top ele
        int st = mn , end = mx;
        while(true){
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            if(col == nums[row].size()-1) break;     //if any pointer is out of bound of its list
            pq.push({nums[row][col+1],{row,col+1}});  //next ele :  taking ele from where minimum ele found
            mx = max(mx,nums[row][col+1]);   //update maximum
            mn = pq.top().first;
            if(mx-mn < end-st){    //check range 
                end = mx;
                st = mn;
            }
        }
        return {st,end};
    }
};