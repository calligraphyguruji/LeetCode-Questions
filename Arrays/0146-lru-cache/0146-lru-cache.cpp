class LRUCache {
public:
    //OverWhelming Question : can be categorised into hard Level Problem in my opinion 
    //Space Complexity : O(capacity) => using unordered map to store elements till capacity O(capacity) + linked list to store capacity+2 elements dummy head, dummy tail : O(capacity+2) .
    class Node{
        public :
           int key, val ;
           Node *next ;
           Node *prev ;
           
           //constructor
           Node(int k, int v){
            key = k ; 
            val = v ;
            prev = next = NULL ;
 
           }
    } ;

    Node *head = new Node(-1, -1) ;
    Node *tail = new Node(-1, -1) ;
    
    //unordered map to optimise to get function
    unordered_map<int, Node*> m ;
    
    
    //addNode function : to insert at head->next
    void addNode(Node *newNode){ //Time Complexity = O(1)
        Node *oldNext = head->next ;//save head->next in oldNext
        
        //make connection to insert
        head->next = newNode ; 
        oldNext->prev = newNode ;

        newNode->next = oldNext ;
        newNode->prev = head ; 
    }
    
    //delete function : to delete Nodes
    void delNode(Node *oldNode){ //Time Complexity = O(1)
        Node *oldPrev = oldNode->prev ; //points towards oldPrev
        Node *oldNext = oldNode->next ; //points towards oldNext

        //change connections : to cut the wire
        oldPrev->next = oldNext ;
        oldNext->prev = oldPrev ;

    }
    int limit ; //to store capacity or limit

    LRUCache(int capacity) {
        limit = capacity ;
        head->next = tail ;
        tail->prev = head ;
    }
    
    int get(int key) {
        //base-case
        if(m.find(key) == m.end()){
            return -1 ;
        }

        Node *ansNode = m[key] ;
        int ans = ansNode->val ;
        //make LRU to MR(most recent)
        //1. erase & delete that used Node
        m.erase(key) ;
        delNode(ansNode) ;
        //2. insert in map & LL that same used Node
        addNode(ansNode) ; //at the start of the LL (MR)
        m[key] = ansNode ; //store in map
    
        return ans ;
    }
    
    void put(int key, int val) { //Time Complexity = O(1)
        //firstly check already exists 
        if(m.find(key) != m.end()){
            Node *oldNode = m[key] ;
            delNode(oldNode) ; //if exists then delete Node
            m.erase(key) ; //also erase value from map
        }

        //if capacity reached
        if(m.size() == limit){
            //delete LRU data erase from the map & LL 
            m.erase(tail->prev->key) ;
            delNode(tail->prev) ;
        }

        Node *newNode = new Node(key, val) ;
        addNode(newNode) ; //add this newNode in the LL
        m[key] = newNode ; //also the key , Node* in map
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */