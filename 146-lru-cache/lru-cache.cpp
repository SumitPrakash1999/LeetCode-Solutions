class LRUCache {
public:
    class Node{
    public:
        int key;
        int val;
        Node* prev;
        Node* next;
        Node(int k,int v){
            key=k;
            val=v;
        }
    };
    int cap;
    Node* head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);
    unordered_map<int, Node*> mpp;
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;        
    }
    void insertAfterHead(Node* node){
        Node* temp=head->next;
        head->next=node;
        node->next=temp;
        node->prev=head;
        temp->prev=node;

    }
    void deleteNode(Node* node){
        Node* left=node->prev;
        Node* right=node->next;
        left->next=right;
        right->prev=left;
        node->prev=nullptr;
        node->next=nullptr;
    }
    
    int get(int key_) {
        if(mpp.find(key_)!=mpp.end()){
            Node* n=mpp[key_];
            int res=n->val;
            deleteNode(n);
            insertAfterHead(n);
            return res;
        }
        return -1;      
        
    }
    
    void put(int key_, int value) {
       if(mpp.find(key_)!=mpp.end()){
        Node* n=mpp[key_];
        n->val=value;
        deleteNode(n);
        insertAfterHead(n);
       }
       else{
        if(mpp.size()==cap){
            Node* temp=tail->prev;
            deleteNode(temp);
            mpp.erase(temp->key);
        }
        Node* newnode=new Node(key_, value);
        mpp[key_]=newnode;
        insertAfterHead(newnode);
       }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */