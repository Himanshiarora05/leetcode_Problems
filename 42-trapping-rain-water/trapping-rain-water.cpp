class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l = 0;
        int r = n-1;
        int lmax = 0 , rmax = 0;
        int ans = 0;
        while(l<r){
            lmax = max(lmax , height[l]);
            rmax = max(rmax, height[r]);
            if(lmax < rmax){       //the smaller boundary is the deciding factor
                ans += lmax-height[l];   //calculate the water traped at each pillar
                l++;
            }
            else{
                ans += rmax - height[r];
                r--;
            }
        }
        return ans;
    }
};