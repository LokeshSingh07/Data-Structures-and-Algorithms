// 155. Min Stack

class MinStack {
public:
    vector<pair<int,int>> arr;  // val, mini
    int topI;

    MinStack() {
        this->topI = -1;    
    }
    
    void push(int val) {
        if(topI != -1){
            pair<int, int> P = arr[topI];
            int minEl = min(val, P.second);
            arr.push_back({val, minEl});
        }
        else{
            arr.push_back({val, val});
        }
        topI++;
    }
    
    void pop() {
        if(topI != -1){
            arr.pop_back();
            topI--;
        }
    }
    
    int top() {
        if(topI != -1){
            pair<int, int> P = arr[topI];
            return P.first;
        }
        return -1;
    }
    
    int getMin() {
        if(topI != -1){
            pair<int, int> P = arr[topI];
            return P.second;
        }
        return -1;
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