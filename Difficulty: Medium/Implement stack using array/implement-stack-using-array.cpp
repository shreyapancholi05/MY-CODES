class myStack {
  public:
        int *arr;
        int size;
        int top;
    myStack(int n) {
        // Define Data Structures
        arr = new int[n];
        size = n;
        top = -1;
    }

    bool isEmpty() {
        // check if the stack is empty
        return (top == -1);
    }

    bool isFull() {
        return (top == size - 1);
        
    }

    void push(int x) {
        if(!isFull()){
            top++;
            arr[top] = x;
        }
    }

    void pop() {
        if(!isEmpty()){
            top--;
        }
    }

    int peek() {
        if(!isEmpty()){
            return arr[top];
        }
        return -1;
    }
};