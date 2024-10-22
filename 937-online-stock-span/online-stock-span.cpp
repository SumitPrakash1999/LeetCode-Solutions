class StockSpanner {
public:
    vector<int> arr;
    int ind;
    StockSpanner() {
        arr.clear();
        ind=-1;               
    }
    
    int next(int price) {
        ind++;
        arr.push_back(price);
        int cnt=1;
        for(int i=ind-1;i>=0;i--){
            if(arr[i]<=price) cnt++;
            else break;
        }
        return cnt;
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */