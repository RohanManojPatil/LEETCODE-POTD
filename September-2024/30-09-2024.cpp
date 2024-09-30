class CustomStack {
public:
    int currSize, size;
    vector<int> arr;
    CustomStack(int maxSize) {
        size = maxSize;
        currSize = -1;
        arr.resize(size, 0);
    }
    
    void push(int x) {
        if(currSize  >= size-1)
        {
            return;
        }

        arr[++currSize] = x;
    }
    
    int pop() {
        if(currSize < 0)
        {
            return -1;
        }
        
        int top = arr[currSize];
        currSize--;
        return top;
    }
    
    void increment(int k, int val) {
        for(int i = 0; i<min(currSize+1, k); i++)
        {
            arr[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */