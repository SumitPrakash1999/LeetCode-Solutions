class Solution {
public:
    // vector<int> getNSL(vector<int>& heights,int n){
    //     vector<int> nsl(n);
    //     stack<int> st;
    //     for(int i=0;i<n;i++){
    //         if(st.empty()){
    //             nsl[i]=-1;
    //         }
    //         else{
    //             while(!st.empty()&&heights[i]<=heights[st.top()]){
    //                 st.pop();
    //             }
    //             nsl[i]=st.empty()?-1:st.top();
    //         }
    //         st.push(i);
    //     }
    //     return nsl;

    // }
    // vector<int> getNSR(vector<int>& heights,int n){
    //     vector<int> nsr(n);
    //     stack<int> st;
    //     for(int i=n-1;i>=0;i--){
    //         if(st.empty()){
    //             nsr[i]=n;
    //         }
    //         else{
    //             while(!st.empty()&&heights[i]<heights[st.top()]){
    //                 st.pop();
    //             }
    //             nsr[i]=st.empty()?n:st.top();
    //         }
    //         st.push(i);
    //     }
    //     return nsr;

    // }
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        // vector<int> nsr=getNSR(heights,n);
        // vector<int> nsl=getNSL(heights,n);
        int ans=0;
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty()&&heights[st.top()]>heights[i]){
                int ele=st.top();
                st.pop();
                int nsr=i;
                int nsl=st.empty()?-1:st.top();
                ans=max(ans,(nsr-nsl-1)*heights[ele]);
            }
            st.push(i);         
           
        }
        while(!st.empty()){
            int nsr=n;
            int ele=st.top();
            st.pop();
            int nsl=st.empty()?-1:st.top();
            ans=max(ans,(nsr-nsl-1)*heights[ele]);
        }
        return ans;
        
    }
};