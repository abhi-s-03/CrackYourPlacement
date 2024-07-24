class LRUCache {
public:
    class node{
        public:
        int key;
        int val;
        node* llink;
        node* rlink;
        node(int k,int v){
            key=k;
            val=v;
        }
    };

    int cap;
    unordered_map<int,node*> m;
    node* head=new node(-1,-1);
    node* tail=new node(-1,-1);
    LRUCache(int capacity) {
        cap=capacity;
        head->rlink=tail;
        tail->llink=head;
    }

    void addnode(node *t){
        node *temp=head->rlink;
        t->rlink=temp;
        t->llink=head;
        head->rlink=t;
        temp->llink=t;
    }

    void deletenode(node *t){
        t->llink->rlink=t->rlink;
        t->rlink->llink=t->llink;
    }
    
    int get(int key) {
        if(m.find(key)!=m.end()){
            node *temp=m[key];
            int tval=temp->val;
            m.erase(key);
            deletenode(temp);
            addnode(temp);
            m[key]=head->rlink;
            return tval;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            node * link=m[key];
            m.erase(key);
            deletenode(link);
        }
        if(m.size()==cap){
            m.erase(tail->llink->key);
            deletenode(tail->llink);
        }
        addnode(new node(key,value));
        m[key]=head->rlink;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */