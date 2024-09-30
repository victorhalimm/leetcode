class CustomStack {
public:

    stack<int> resStack;
    vector<int *> cache;
    int sizeMax;


    CustomStack(int maxSize) {
        sizeMax = maxSize;
    }
    
    void push(int x) {
        if (resStack.size() >= sizeMax) return;

        int num = x;

        resStack.push(num);
        cache.push_back(&resStack.top());
    }
    
    int pop() {

        if (resStack.empty()) return -1;;
        int top = resStack.top();

        resStack.pop();
        cache.pop_back();

        return top;
    }
    
    void increment(int k, int val) {
        int minElement = min(k, (int)resStack.size());

        for (int i = 0; i < minElement; i ++) {
            *cache[i] += val;
        }
    }
};