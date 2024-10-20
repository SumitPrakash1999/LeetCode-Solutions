class Solution {
public:
    vector<int> getNSR(vector<int> & arr){
        vector<int> ans(arr.size());
        stack<int> st;
        for(int i=arr.size()-1;i>=0;i--){
            if(st.empty()){
                ans[i]=arr.size();
            }
            else{
                while(!st.empty()&&arr[i]<arr[st.top()]){
                    st.pop();
                }
                ans[i]=st.empty()?arr.size():st.top();
            }
            st.push(i);
        }
        return ans;
    }
     vector<int> getNSL(vector<int> & arr){
        vector<int> ans(arr.size());
        stack<int> st;
        for(int i=0;i<arr.size();i++){
            if(st.empty()){
                ans[i]=-1;
            }
            else{
                while(!st.empty()&&arr[i]<=arr[st.top()]){
                    st.pop();
                }
                ans[i]=st.empty()?-1:st.top();
            }
            st.push(i);
        }
        return ans;
    }
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nsr=getNSR(arr);
        int n=arr.size();
        vector<int> nsl=getNSL(arr);
        long long sum=0;
        int mod=1e9+7;
        for(int i=0;i<n;i++){
            long long ways=(i-nsl[i])*(nsr[i]-i);
            long long temp=(ways*arr[i])%mod;
            sum=(sum+temp)%mod;
        }
        return sum;        
    }
};