class Node {
public: 
    Node* next;
    Node* prev; 
    int val; 
    int key; 
    Node(int value, int key) : val(value), key(key), next(nullptr), prev(nullptr) {}
};

class LRUCache {
private:  // Should be private!
    Node* start; 
    Node* end; 
    unordered_map<int, Node*> cacheMap; 
    int totalSz; 
    int sz; 

    void assign(Node* a, Node* b) {
        a->next = b; 
        b->prev = a;
    }

    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void addToFront(Node* node) {
        node->next = start->next;
        node->prev = start;
        start->next->prev = node;
        start->next = node;
    }

    void moveToFront(Node* node) {
        removeNode(node);
        addToFront(node);
    }

    void popFromLast() {
        if(start->next == end) return;  // Empty cache
        
        Node* toDelete = end->prev;
        cacheMap.erase(toDelete->key);
        removeNode(toDelete);
        delete toDelete;  // FIX: Free memory
        sz--;             // FIX: Decrement size
    }

public:
    LRUCache(int capacity) {
        start = new Node(0, -1);
        end = new Node(0, -2);
        assign(start, end); 
        totalSz = capacity; 
        sz = 0; 
    }
    
    ~LRUCache() {  // FIX: Add destructor
        Node* curr = start;
        while(curr) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
    }
    
    int get(int key) {
        if(cacheMap.find(key) == cacheMap.end()) return -1; 
        moveToFront(cacheMap[key]);
        return cacheMap[key]->val;  
    }

    void put(int key, int value) {
        // Key already exists - update value and move to front
        if(cacheMap.find(key) != cacheMap.end()) {
            cacheMap[key]->val = value;  // FIX: Update value!
            moveToFront(cacheMap[key]);
            return;
        }
        
        // Key doesn't exist - need to add new node
        if(sz >= totalSz) {
            popFromLast();
        }
        
        Node* newNode = new Node(value, key);
        cacheMap[key] = newNode;
        addToFront(newNode);
        sz++;
    }
};