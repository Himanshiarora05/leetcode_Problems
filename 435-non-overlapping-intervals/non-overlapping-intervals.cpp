class Solution {
public:
    //think reverse - ki kitne normally hojayenge without overlap
    static bool cmp(vector<int> v1 ,vector<int> v2){
        return v1[1]<v2[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end(),cmp);
        int cnt = 1;
        int lastTime = arr[0][1];
        for(int i = 1;i<n;i++){
            if(arr[i][0] >= lastTime){  
                cnt++;  
                lastTime = arr[i][1];
            }
        }
        return n - cnt;
    }
};


//[[1,2] , [4,5]]
//last = 2 , arr[i][0] = 4   ->   4>=2     ->   cnt++