class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int i = 0;
        int j = tokens.size() - 1;
        int ans = 0;
        int score = 0;
        while(i<=j){
        if(tokens[i] <= power){  //to maximize score we can decrease power when power is more then tokens[i]
                power -= tokens[i];
                score++;
                i++;

                ans = max(ans,score);
            }
            else if(score>0){   //can add number only when score is 1 or more
                power += tokens[j];
                score--;
                j--;
            }
            else break;
        }
        return ans;
    }
};