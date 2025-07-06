/*
Implement the LRUCache class:

1)LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
2)int get(int key) Return the value of the key if the key exists, otherwise return -1.
3)void put(int key, int value) Update the value of the key if the key exists. 
  Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, 
  delete the least recently used key.
The functions get and put must each run in O(1) average time complexity.
*/
/*
Idea: LRU(least recent used)
after get or put operation curr element will be latest used so update this.
## use doubly LL(storing LRU efficiently) and unorderedMap(retreiving key)
## head node1 node2 tail
*/
class Node{
    public:
        int key;
        int val;
        Node* prev;
        Node* next;
        Node(int key,int val){
            this->key=key;
            this->val=val;
        }
};
class LRUCache {
public:
    unordered_map<int,Node*>mp;
    int cap;
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    void deleteNode(Node* curr){
        curr->prev->next=curr->next;
        curr->next->prev=curr->prev;
    }
    // to insert just after head node ( for most recent)
    void insertFirst(Node* curr){
        Node* temp=head->next;
        head->next=curr;
        curr->prev=head;
        curr->next=temp;
        temp->prev=curr;
    }
    int get(int key) {
        //when key exists in map
        if(mp.find(key)!=mp.end()){
            Node* curr=mp[key];
            deleteNode(curr);
            insertFirst(curr); 
            return curr->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            //if key is already in map then update
            mp[key]->val=value;
            deleteNode(mp[key]);
            insertFirst(mp[key]);
        }
        else{
            //key not found
            Node * temp=new Node(key,value);
            if(mp.size()==cap){
                //remove least recently used
                mp.erase(tail->prev->key);
                deleteNode(tail->prev);
                insertFirst(temp);
                mp[key]=temp;
            }
            else{
                insertFirst(temp);
                mp[key]=temp;
            }
        }
    }
};
