class MinStack {
public:
    vector<int> stack;
    vector<int> stack2;
    MinStack() {
        
    }

    void push(int val) {
        stack.push_back(val);
        if(!stack2.empty() && val > stack2.back()){
            stack2.push_back(stack2.back());   
        } else {
            stack2.push_back(val);
        }
    }

    void pop() {
        stack2.pop_back();
        stack.pop_back();
    }

    int top() {
         return stack.back();
    }

    int getMin() {
        return stack2.back();
    }
};