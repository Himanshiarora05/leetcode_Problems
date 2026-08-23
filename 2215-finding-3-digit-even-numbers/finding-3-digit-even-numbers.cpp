class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        unordered_map<int,int> mp;
        //using mp instead of set as if digits have multiple same elements
        vector<int> ans;
        for(auto ele : digits) mp[ele]++;   //freq of all elements

        for(int i = 100;i<=999;i+=2){
            int x = i;
            int a = x%10;
            x/=10;
            int b = x%10;
            x/=10;
            int c = x ;

            if(mp.find(a) != mp.end()){   //a found
                mp[a]--;    //a ko vapis dalna h
                if(mp[a] == 0) mp.erase(a);   //sare a khtm hogye toh remove it
                if(mp.find(b) != mp.end()){ //b found
                    mp[b]--;
                    if(mp[b] == 0) mp.erase(b);
                    if(mp.find(c) != mp.end()) ans.push_back(i);    //c found
                    mp[b]++;
                }
                mp[a]++;
            }

        }
        return ans;
    }
};