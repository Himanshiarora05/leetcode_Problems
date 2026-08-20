class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        unordered_set<string> s;
        int count = 0;
        for(int i = 0;i<words.size();i++){
            string rev = words[i];
            reverse(rev.begin(),rev.end());
            if(s.find(rev) != s.end()){ //found in set
                count++;
            }
            else s.insert(words[i]);
        } 
        return count;
    }
};

//insert only when you didnot find it in set 
//if reverse exists in set just count++ no need to insert it