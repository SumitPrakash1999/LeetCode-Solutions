class Solution {
public:
    string answerString(string word, int numFriends) {
        int n=word.length();
        if(numFriends==1) return word;

        string temp(word.begin(),word.end());
        sort(temp.begin(),temp.end());
        char big=temp[n-1];

        vector<int> ind;
        for(int i=0;i<n;i++){
            if(word[i]==big){
                ind.push_back(i);
            }
        }
        vector<string> ans;
        int rem=n-(numFriends-1);
        for(int i=0;i<ind.size();i++){
            if(n-ind[i]>=rem) ans.push_back(word.substr(ind[i],rem));
            else ans.push_back(word.substr(ind[i],n-ind[i]));
        }

        sort(ans.begin(),ans.end());
        return ans[ans.size()-1];        
    }
};