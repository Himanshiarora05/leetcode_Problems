class Solution {
public:
    int numRabbits(vector<int>& nums) {
        unordered_map<int, int> mp;
        int rabbits = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (!mp[nums[i] + 1]) {   
                rabbits += nums[i] + 1;  //starting a new group of diff colour
                if (nums[i] == 0)  continue;  //edge case : no rabbits of that color except him
                mp[nums[i] + 1] = 1;
            } else {
                mp[nums[i]+1]++;       
                int key = nums[i] + 1;
                int val = mp[key];
                if (key == val) {   //we found all the rabbits of same group
                    mp.erase(key);   //erase that group
                }
            }
        }
        return rabbits;
    }
};

//[5,5,5,5,5,5,5,1,1] ans += 6+6+2
//first 6 will be of same group and 7th (5) will be of separate group 