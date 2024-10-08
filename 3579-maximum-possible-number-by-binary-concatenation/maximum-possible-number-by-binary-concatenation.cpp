class Solution {
public:
    string dtob(int num){
        string temp="";
        while(num!=0){
            int rem=num%2;
            temp+=(char)(rem+'0');
            num=num/2;
        }
        reverse(temp.begin(),temp.end());
        int i=0;
        // cout<<temp<<endl;
        while(temp[i]=='0'){
            temp.erase(temp.begin());
        }
        return temp;
    }
    // int cnt(string s){
    //     int tot=0;
    //     for(int i=0;i<s.length();i++){
    //         if(s[i]=='1') tot++;
    //     }
    //     return tot;
    // }
    int btod(string num){
        int ind=0;
        int val=0;
        for(int i=num.length()-1;i>=0;i--){
            val+=(num[i]-'0')*pow(2,ind);
            ind++;
        }
        return val;
    }
    int maxGoodNumber(vector<int>& nums) {
        int n=nums.size();
        string a=dtob(nums[0]);
        string b=dtob(nums[1]);
        string c=dtob(nums[2]);

        //     cout<<dtob(13)<<endl;
        // cout<<btod("1101")<<endl;


        return max({
            btod(a+b+c),
            btod(a+c+b),
            btod(b+a+c),
            btod(b+c+a),
            btod(c+a+b),
            btod(c+b+a)
        });  

    

        
    }
};