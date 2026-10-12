class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int n = people.size();
        int i =0 ,j = n-1;
        int boat = 0;
        while(i <=j){
            if(people[i] + people[j] <= limit){
                boat++;
                i++;j--;
            }
            else{  
                //people[i] + people[j] > limit that means last weight bohot jada h and it will need individual boat toh will not pair
                boat++;
                j--;
            }
        }
        return boat;
    }
};