class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(),deck.end());
        int n = deck.size();
        queue<int> q;
        vector<int> ans(n);
        for(int i = 0;i<n;i++){
            q.push(i);
        }
        int i = 0;
        while(!q.empty()){
            int idx = q.front();   
            ans[idx] = deck[i];
            q.pop();
            q.push(q.front());
            q.pop();
            i++;
        }
        return ans;
    }
};


//ek element ko ans me dalo and ek element ko push back to queue
//sort the given array [coz ans array vohi natural order chahta h] so playing reverse game