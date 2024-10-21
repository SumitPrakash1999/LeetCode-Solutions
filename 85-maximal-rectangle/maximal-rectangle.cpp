class Solution {
public:
    int largestrec(vector<int> & arr){
        int n=arr.size();
        stack<int> st;
        int val=0;
        for(int i=0;i<n;i++){
            while(!st.empty()&&arr[i]<arr[st.top()]){
                int ele=st.top(); st.pop();
                int nsr=i;
                int nsl=st.empty()?-1:st.top();
                val=max(val,((nsr-nsl-1)*arr[ele]));
            }
            st.push(i);
        }
        while(!st.empty()){
            int nsr=n;
            int ele=st.top(); st.pop();
            int nsl=st.empty()?-1:st.top();
            val=max(val,((nsr-nsl-1)*arr[ele]));
        }
        return val;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int res=0;
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> histogram(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1')histogram[j]+=1;
                else histogram[j]=0;
            }
            res=max(res,largestrec(histogram));
        }
        return res;
    }
};