class MinStack {
public:
    unordered_map<int,int> mp; 
    vector<int> vv;
    int sz; 
    MinStack() {
        sz = 0;
        mp[0]= INT_MAX; 
    }
    
    void push(int val) {
        vv.push_back(val);
        mp[sz+1] = min(mp[sz], val);
        sz+=1; 
    }
    
    void pop() {
         vv.pop_back(); 
         mp.erase(sz); 
         sz--; 
    }
    
    int top() {
        int top = vv.back(); 
        return top; 
    }
    
    int getMin() {
        return mp[sz]; 
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */