class Solution {
public:
    int calPoints(vector<string>& arr) {
        stack<int> st;
        for(int i = 0;i<arr.size();i++){
            if(arr[i] == "C")  st.pop();
            else if(arr[i] == "D"){
                int x = st.top();
                st.push(x*2);
            }
            else if(arr[i] == "+"){
                int x = st.top();
                st.pop();
                int y = st.top();
                st.push(x);
                st.push(x+y);
            }
            else {
                int a = stoi(arr[i]);
                st.push(a);
                }
        }
        int sum = 0;
        while(st.size()>0){
            int a = st.top();
            sum += a;
            st.pop();
        }
        return sum;
    }
};