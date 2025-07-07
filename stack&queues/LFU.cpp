/*
##LFUCache(int capacity) Initializes the object with the capacity of the data structure.
##int get(int key) Gets the value of the key if the key exists in the cache. Otherwise, returns -1.
##void put(int key, int value) Update the value of the key if present, or inserts the key if not already present. 
  When the cache reaches its capacity, it should invalidate and remove the least frequently used key before inserting a new item
. For this problem, when there is a tie (i.e., two or more keys with the same frequency), the least recently used key would be invalidated.
*/
/*
IDEA:
## to get least frequent use map<frequency,dll>
## in dll it is stored in LRU manner
## map<key,Node> to retreive fast key , value
*/

struct Node{
    int key;
    int value;
    int cnt;
    Node* prev;
    Node* next;
    Node(int _key,int _value){
        cnt=1;
        this->key=_key;
        this->value=_value;
    }
};
struct DLL{
    Node* tail;
    Node* head;
    int size;
    DLL(){
        head=new Node(0,0);
        tail=new Node(0,0);
        head->next=tail;
        tail->prev=head;
        size=0;
    }
    void addFront(Node * node){
        Node* headnxt=head->next;
        head->next=node;
        node->prev=head;
        node->next=headnxt;
        headnxt->prev=node;
        size++;
    }
    void removeNode(Node* node){
        node->prev->next=node->next;
        node->next->prev=node->prev;
        size--;
    }
};
class LFUCache {
    map<int,Node*>keymp;
    map<int,DLL*>freqmp;
    int minfreq;
    int currsize;
    int maxsize;
public:
    LFUCache(int capacity) {
        maxsize=capacity;
        minfreq=0;
        currsize=0;
    }
    void update(Node* node){
        freqmp[node->cnt]->removeNode(node);
        if(minfreq==node->cnt && freqmp[node->cnt]->size==0){
            minfreq++;
        }
        DLL * nxtHigherfreqlist=new DLL();
        if(freqmp.find(node->cnt+1)!=freqmp.end()){
            nxtHigherfreqlist=freqmp[node->cnt+1];
        }
        node->cnt=node->cnt+1;
        nxtHigherfreqlist->addFront(node);
        freqmp[node->cnt]=nxtHigherfreqlist;
    }
    int get(int key) {
        if(keymp.find(key)!=keymp.end()){
            update(keymp[key]);
            return keymp[key]->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        //key already exists>> update
        if(keymp.find(key)!=keymp.end()){
            Node * node=keymp[key];
            node->value=value;
            update(node);
        }
        else{
            if(keymp.size()==maxsize){
                //delete least frequent
                DLL* list=freqmp[minfreq];
                keymp.erase(list->tail->prev->key);
                list->removeNode(list->tail->prev);
            }
            //add new key value;
            minfreq=1;
            DLL* newList=new DLL();
            if(freqmp.find(minfreq)!=freqmp.end()){
                newList=freqmp[minfreq];
            }
            Node * node=new Node(key,value);
            newList->addFront(node);
            keymp[key]=node;
            freqmp[minfreq]=newList;
        }
    }
};
