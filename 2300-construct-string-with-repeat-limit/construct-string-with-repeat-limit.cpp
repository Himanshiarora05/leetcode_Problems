class Solution {
public:
    string repeatLimitedString(string s, int k) {
        unordered_map<char, int> mp;
        for (char c : s) {
            mp[c]++;
        }
        priority_queue<pair<char, int>> pq;
        for (auto x : mp) {
            pq.push({x.first, x.second});
        }

        string ans = "";
        while (pq.size() > 0) {
            char a = pq.top().first;
            int freq = pq.top().second;
            pq.pop();

            int use = min(freq, k);
            for (int i = 0; i < use; i++)  ans += a;
            freq -= use;

            if (freq > 0) {
                if (pq.empty())  break;

                char a2 = pq.top().first;
                int freq2 = pq.top().second;
                pq.pop();

                ans += a2;
                freq2--;
                if (freq2 > 0) {
                    pq.push({a2, freq2});
                }
                pq.push({a, freq});
            }
        }
        return ans;
    }
};


//goal is to make lexi largest string ....so used maxheap for that 
//a char can occur atmost k times together so for partition used second largest char
//used min(freq,k) -> so atmost k times...
