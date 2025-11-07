class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st; 
        int total = 0; 
        for(string a : tokens){
             if (a != "+" && a != "-" && a != "*" && a != "/") {
                st.push(stoi(a));
            }else {
                if(st.size() <= 1) return -1; 
                int bb = st.top(); st.pop();
                int aa = st.top(); st.pop();
                if(a == "*") st.push(aa*bb);
                else if(a == "/") st.push(aa/bb);
                else if(a =="+") st.push(aa + bb);
                else if(a == "-") st.push(aa - bb);
            }
        }
        return st.top(); 
    }
};