#include <iostream>

class Stack {
private:
    int* data;
    int capacity;
    int topIndex;

public:
    Stack (int maxSize) {
        capacity = maxSize;
        data = new int[maxSize];
        topIndex = -1;
    }

    ~Stack() {
        delete[] data;
    }

    void push(int value) {
        if (isFull()) {
            std::cout << "[ERROR] Stack overflow!" << std::endl;
            return;
        }
        data[++topIndex] = value;
    }

    int pop() {
        if (isEmpty()) {
            std::cout << "[ERROR] Stack is empty!" << std::endl;
            return -1;
        }
        return data[topIndex--];
    }

    int top() const {
        if (isEmpty()) {
            std::cout << "[ERROR] Stack is empty!" << std::endl;
            return -1;
        }
        return data[topIndex];
    }

    bool isEmpty() const {
        return topIndex < 0;
    }

    bool isFull() const {
        return topIndex == capacity - 1;
    }

    int size() const {
        return topIndex + 1;
    }
};

int main() {
    Stack s(5);

    for (int i = 0; i < 5; i++) {
        s.push(i);
    }

    s.push(5);

    std::cout << "Top: " << s.top() << ", Size: " << s.size() << std::endl;

    for (int i = 0; i < 5; i++) {
        s.pop();
    }

    s.pop();
}
