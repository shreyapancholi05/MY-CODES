class myQueue {

  public:
    int *arr;
    int size;
    int top;
    myQueue(int n) {
        arr = new int[n];
        size = n;
        top = 0;
    }

    bool isEmpty() {
        if(top == 0){
            return true;
        }
        else{
            return false;
        }
    }

    bool isFull() {
        return (top == size);
    }

    void enqueue(int x) {
        if(!isFull()){
            arr[top] = x;
            top++;
        }
    }

    void dequeue() {
        if(!isEmpty()){
            for(int i=1; i<top; i++){
                arr[i-1] = arr[i];
            }
            top--;
        }
    }

    int getFront() {
        if(!isEmpty()){
            return arr[0];
        }
        return -1;
    }

    int getRear() {
        if(!isEmpty()){
            return arr[top - 1];
        }
        return -1;
    }
};