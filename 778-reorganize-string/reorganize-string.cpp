class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> mp;
        for(char ele : s) mp[ele]++;

        priority_queue< pair<int,char> > pq;
        for(auto x : mp){
            if(x.second >(s.length() +1 )/2)     //any ele freq is more then (n+1)/2 : means not possible 
                return "";
            pq.push({x.second , x.first});
        }
        
        string ans = "";
        while(pq.size()>1){
            auto top1 = pq.top(); pq.pop();
            auto top2 = pq.top(); pq.pop();

            ans += top1.second;
            ans += top2.second;

            if(--top1.first > 0) pq.push(top1);    //push ele back to the queue with freq--
            if(--top2.first > 0) pq.push(top2);
        }
        if(!pq.empty()){
            if(pq.top().first > 1) return "";   //still any ele has freq more then 1 
            ans += pq.top().second;
        }
        return ans;
    }
};