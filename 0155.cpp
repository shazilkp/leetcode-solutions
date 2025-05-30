class MinStack {
private:
    vector<pair<int,int>> minData;
    int t;
    stack<int> s;
public:
    MinStack() {
    }
    
    void push(int val) {
        s.push(val);
        if(minData.size() == 0){
            minData.push_back({val,1});
            t = 0;
        }
        else if(val < minData[t].first){
            minData.push_back({val,1});
            t++;
        }
        else if(val == minData[t].first){
            minData[t].second++;
        }
    }
    
    void pop() {
        int ele = s.top();
        cout << ele << "is out " <<"\n";
        if(ele == minData[t].first){
            if(minData[t].second > 0){
                minData[t].second--;
            }

            if(minData[t].second == 0){
                t--;
                minData.pop_back();
              
            }
        }
        s.pop();
       // printS(s);
       // printMin(minData);
    }
    
    int top() {
        int ele = s.top();
        return ele;
    }
    
    int getMin() {
        return minData[t].first;
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
