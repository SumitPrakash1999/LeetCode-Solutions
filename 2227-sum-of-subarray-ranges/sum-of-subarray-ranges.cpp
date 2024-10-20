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
    long long sosMin(vector<int>& arr,int n) {
        vector<int> nsr=getNSR(arr);
        vector<int> nsl=getNSL(arr);
        long long sum=0;
        int mod=1e9+7;
        for(int i=0;i<n;i++){
            long long ways=(i-nsl[i])*(nsr[i]-i);
            long long temp=(ways*arr[i]);
            sum=(sum+temp);
        }
        return sum;        
    }

    vector<int> getNGR(vector<int> & arr){
        vector<int> ans(arr.size());
        stack<int> st;
        for(int i=arr.size()-1;i>=0;i--){
            if(st.empty()){
                ans[i]=arr.size();
            }
            else{
                while(!st.empty()&&arr[i]>arr[st.top()]){
                    st.pop();
                }
                ans[i]=st.empty()?arr.size():st.top();
            }
            st.push(i);
        }
        return ans;
    }
     vector<int> getNGL(vector<int> & arr){
        vector<int> ans(arr.size());
        stack<int> st;
        for(int i=0;i<arr.size();i++){
            if(st.empty()){
                ans[i]=-1;
            }
            else{
                while(!st.empty()&&arr[i]>=arr[st.top()]){
                    st.pop();
                }
                ans[i]=st.empty()?-1:st.top();
            }
            st.push(i);
        }
        return ans;
    }
    long long sosMax(vector<int>& arr,int n) {
        vector<int> ngr=getNGR(arr);
        vector<int> ngl=getNGL(arr);
        long long sum=0;
        int mod=1e9+7;
        for(int i=0;i<n;i++){
            long long ways=(i-ngl[i])*(ngr[i]-i);
            long long temp=(ways*arr[i]);
            sum=(sum+temp);
        }
        return sum;        
    }

    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        long long s=sosMin(nums,n);
        long long t=sosMax(nums,n);
        return abs(s-t);        
    }
};