class Solution {
public:
    typedef pair<int,int> pi;
    vector<int> frequencySort(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int,int> mp;
        for(auto ele : nums) mp[ele]++; //<ele,freq>

        priority_queue<pi, vector<pi> , greater<pi> > pq;
        for(auto x : mp){
            pq.push({x.second , -x.first}); //<freq,ele>
        }

        while(pq.size()>0){
                int freq = pq.top().first;
                int ele = -pq.top().second;   
                pq.pop();
                while(freq >0) {
                    ans.push_back(ele);
                    freq--;
                }
            }
        return ans;
    }
};