class StockSpanner {
public:
    // 100 80 60 70 60 75 (vector)
    // 100 80 60 70 60 75 (stack)
    stack<pair<int, int>> priceStack;

    StockSpanner() {
        
    }
    
    int next(int price) {
        // diri dia sendiri diitung 1
        int span = 1;

        // simpen nilai span dari suatu price krn bisa tinggal dipake ulang sama stock berikutnya ga perlu simulasi itung lagi
        while (!priceStack.empty() && priceStack.top().first <= price) {
            span += priceStack.top().second;
            priceStack.pop();
        }

        priceStack.push({price, span});

        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */