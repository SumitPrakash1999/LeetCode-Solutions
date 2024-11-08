class Solution {
public:
    unordered_map<string,int> mpp;
    vector<vector<string>> ans;
    string beg;
    void dfs(string endword,vector<string> &seq){
        if(endword==beg){
            reverse(seq.begin(),seq.end());
            ans.push_back(seq);
            reverse(seq.begin(),seq.end());
            return;
        }
        int steps=mpp[endword];
        for(int i=0;i<endword.size();i++){
                char temp=endword[i];
                for(char x='a';x<='z';x++){
                    endword[i]=x;
                    if(mpp.find(endword)!=mpp.end()&&mpp[endword]+1==steps){
                        seq.push_back(endword);
                        dfs(endword,seq);
                        seq.pop_back();
                    }
                }
                endword[i]=temp;
        }

    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> mapp(wordList.begin(),wordList.end());
        queue<string> q;
        beg=beginWord;
        q.push(beginWord);
        mpp[beginWord]=1;
        mapp.erase(beginWord);
        while(!q.empty()){
            string word=q.front();
            int steps=mpp[word];
            q.pop();
            if(word==endWord) break;
            for(int i=0;i<word.size();i++){
                char temp=word[i];
                for(char x='a';x<='z';x++){
                    word[i]=x;
                    if(mapp.find(word)!=mapp.end()){
                        q.push(word);
                        mpp[word]=steps+1;
                        mapp.erase(word);
                    }
                }
                word[i]=temp;
            }
        }
        if(mpp.find(endWord)!=mpp.end()){
                vector<string> seq;
                seq.push_back(endWord);
                dfs(endWord,seq);
            
        }
        return ans;        
    }
};