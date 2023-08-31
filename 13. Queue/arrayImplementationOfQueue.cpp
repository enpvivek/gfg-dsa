#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

struct MyQueue {
    int* arr;
    int cap;
    int size;
    MyQueue(int n) {
        cap = n;
        size = 0;
        arr = new int[n];
    }
    void enqueue(int x) {
        arr[size] = x;
        size++;
    }
    void dequeue() {
        for (int i = 0; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
    }
    int getRear() {
        return arr[size - 1];
    }
    int getFront() {
        return arr[0];
    }
    bool isEmpty() {
        return size == 0;
    }
    int getSize() {
        return size;
    }
};

int main() {
    MyQueue q(10);
    q.enqueue(5);
    q.enqueue(10);
    q.enqueue(15);
    cout << q.getRear() << endl;
    cout << q.getFront() << endl;
    cout << q.getSize() << endl;
    q.dequeue();
    cout << q.getFront() << endl;
    q.dequeue();
    cout << q.getFront() << endl;
    cout << q.getSize() << endl;


    return 0;
}