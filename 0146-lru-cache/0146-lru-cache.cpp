class LRUCache {
public:
    class ListNode{
        public:
        int key,val;
        ListNode* prev=NULL;
        ListNode* next=NULL;
        ListNode(int _key,int _val)
        {
            key=_key;
            val=_val;
        }
    };
    int cap;
    ListNode* back=new ListNode(-1,-1);
    ListNode* front=new ListNode(-1,-1);
    map<int,ListNode*> mp;
    LRUCache(int capacity) {
        cap=capacity;
        front->next=back;
        back->prev=front;
    }
    void deleteNode(int key) {
        ListNode* temp=mp[key];
        ListNode* prev=temp->prev;
        ListNode* next=temp->next;
        next->prev=prev;
        prev->next=next;
        mp.erase(key);
    }
    void insertAfterHead(ListNode *node) {
        front->next->prev=node;
        node->next=front->next;
        front->next=node;
        node->prev=front;
        mp[node->key]=node;

        // ListNode *temp=front;
        // while(temp->next!=back)
        // {
        //     cout<<temp->next->key<<","<<temp->next->val<<" ";
        //     temp=temp->next;
        // }
        // cout<<endl;
    }
    int get(int key) {
        if(mp.find(key)==mp.end())
            return -1;
        ListNode* temp=mp[key];
        deleteNode(key);
        insertAfterHead(temp);
        return temp->val;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end())
        {
            deleteNode(key);
        }
        else if(cap==0)
        {
            deleteNode(back->prev->key);
        }
        else
        {
            cap--;
        }
        insertAfterHead(new ListNode(key,value));
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */