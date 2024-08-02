class LRUCache {
    int cap;
public:
class node{
    public:
    int key,val;
    node* next;
    node* prev;
    node(int key,int val){
       this->key = key;
       this->val =val;
    }
};
        node* head = new node(-1,-1);
        node* tail = new node(-1,-1);
    unordered_map<int,node*>m;

    void deletenode(node* temp){
        node* right = temp->next;
        node* left = temp->prev;
        left->next = right;
        right->prev = left;
    }
    void addnode(node* temp){
        node* right = head ->next;
        head->next = temp;
        temp->prev = head;
        temp->next=right;
        right->prev =temp;
    }
    LRUCache(int capacity){
        cap = capacity;
        head->next= tail;
        tail->prev= head;
    }
    
    int get(int key) {
        if(m.find(key)!=m.end()){
        node* temp = m[key];
        deletenode(temp);
        addnode(temp);
        return temp->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            deletenode(m[key]);
            m.erase(key);
        }
        else if(m.size()==cap){
            m.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new node(key,value));
        m[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
