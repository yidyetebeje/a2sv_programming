class MyCircularDeque {
public:
    int* circularDeque;
    int size = 0;
    int capacity;
    MyCircularDeque(int k) {
        capacity = k;
        circularDeque = new int[k];
    }

    bool insertFront(int value) {
        if(isFull()){
            return false;
        }
        for (int i = size - 1; i >= 0; i--)
        {
            circularDeque[i + 1] = circularDeque[i];
        }
        circularDeque[0] = value;
        size++;
        return true;
    }

    bool insertLast(int value) {
        if(isFull()){
            return false;
        }
        circularDeque[size] = value;
        size++;
        return true;
    }

    bool deleteFront() {
        if(isEmpty()){
            return false;
        }
        for(int i = 0; i < size - 1; i++){
            circularDeque[i] = circularDeque[i + 1];
        }
        size--;
        return true;
    }

    bool deleteLast() {
        if(isEmpty()){
            return false;
        }
        size--;
        return true;
    }

    int getFront() {
        if(isEmpty()){
            return -1;
        }
        return circularDeque[0];
    }

    int getRear() {
        if(isEmpty()){
            return -1;
        }
        return circularDeque[size - 1];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
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