#include <string>
using namespace std;

class Solution {
public:
    bool isPossibleToRearrange(string s, string t, int k) {
        int n=s.size();
        int len=n/k;
        unordered_map<string,int> mpp;
        for(int i=0;i<n;i+=len) mpp[s.substr(i,len)]++;
        for(int i=0;i<n;i+=len) mpp[t.substr(i,len)]--;

        for(auto it:mpp){
            if(it.second!=0) return false;
        }
        return true;
        
    }
};