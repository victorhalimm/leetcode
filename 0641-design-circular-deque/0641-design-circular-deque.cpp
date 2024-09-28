class MyCircularDeque {
public:

    int maxSize = -1;
    int size = 0;
    int front, back;
    vector<int> arr;

    MyCircularDeque(int k) {
        arr = vector<int>(k, -1);
        maxSize = k;
        front = 0;
        back = k - 1;
    }
    
    bool insertFront(int value) {
        
        if (isFull()) return false;

        front = (front - 1 + maxSize) % maxSize;
        arr[front] = value;
        size ++;

        return true;
    }
    
    bool insertLast(int value) {
        
        if (isFull()) return false;

        back = (back + 1) % maxSize;
        arr[back] = value;
        size ++;

        return true;
    }
    
    bool deleteFront() {
        if (isEmpty()) return false;

        arr[front] = -1;
        front = (front + 1) % maxSize;
        size --;

        return true;
    }
    
    bool deleteLast() {
        if (isEmpty()) return false;

        arr[back] = -1;
        back = (back - 1 + maxSize) % maxSize;
        size --;

        return true;
    }
    
    int getFront() {
        return arr[front];
    }
    
    int getRear() {
        return arr[back];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == maxSize;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */