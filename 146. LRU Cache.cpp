class LRUCache {
public:
    struct nodeC{
        int key;
        int val;
        nodeC *next;
        nodeC *last;
        nodeC(int k, int v): key(k), val(v), next(NULL), last(NULL) {}
    };
    vector<nodeC*> pkeys;
    int maxC;
    int index;
    nodeC *head, *tail;
    
    LRUCache(int capacity) {
        pkeys = vector<nodeC*> (5000, NULL);
        nodeC *head=NULL;
        nodeC *tail=NULL;
        maxC = capacity;
        index = 0;
    }
    
    void scan(){
        cout<<"scan: ";
        nodeC *cur = head;
        while(cur!=NULL){
            cout<<cur->key<<" ";
            cur = cur->next;
        }
        cout<<endl;
    }
    
    void dropLRU(){
        // cout<<tail->key<<" tail should be "<<pkeys[key]<<endl;
        if(tail!=NULL&&tail->next==NULL){
            cout<<"drop LRU "<<tail->key<<endl;
            nodeC* temp = tail;
            
            // cout<<"temp key "<<temp->key<<endl;
            tail = temp->last;
            // cout<<"tail key "<<tail->key<<endl;
            if(tail!=NULL)
                tail->next = NULL;
            pkeys[temp->key] = NULL;
            delete temp;
            index--;
        }
    }
    
    int get(int key) {
        
        // cout<<"get "<< key<<endl;
        // scan();
        if(pkeys[key]!=NULL){
            // cout<<key<<" key should be "<<pkeys[key]->key<<endl;
            
            if(pkeys[key]->last!=NULL){
                pkeys[key]->last->next = pkeys[key]->next;
                if(pkeys[key]->next==NULL){
                    // cout<<pkeys[key]<<pkeys[key]->last<<" tail should be "<<tail<<endl;
                    tail = pkeys[key]->last;

                }else
                    pkeys[key]->next->last = pkeys[key]->last;
                pkeys[key]->next = head;
                head->last = pkeys[key];
                pkeys[key]->last = NULL;
                head = pkeys[key];
            }
            // else
                // cout<<pkeys[key]<<" head should be "<<head<<endl;
            return head->val;  
        }else{
            return -1;
        }

    }
    
    void put(int key, int value) {
        
        // cout<<"put "<< key<<" "<<value<<endl;
        // scan();
        if(pkeys[key]!=NULL){
            int tmp = get(key);
            pkeys[key]->val = value;
        }else{
            index++;

            if(index>maxC){
                dropLRU();
            }
            nodeC *MRU = new nodeC(key, value);
            pkeys[key] = MRU;
            if(head==NULL){
                head = MRU;
                tail = MRU;
            }else{
                head->last = MRU;
                MRU->next = head;
                head = MRU;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */