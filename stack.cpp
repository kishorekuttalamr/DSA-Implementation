#include <iostream>
#include <string>
using namespace std;

class Stack {
private:
    int top;
    int arr[5];

public:
    Stack() {
        top = -1;
        for (int i = 0; i < 5; i++) {
            arr[i] = 0;
        }
    }

    // Check if the stack is empty
    bool isEmpty() {
        return (top == -1);
    }

    // Check if the stack is full
    bool isFull() {
        int n = sizeof(arr) / sizeof(arr[0]);
        return (top == n - 1); // Check against n - 1 to account for 0-based indexing
    }

    // Push an element onto the stack
    void push(int val) {
        if (isFull()) {
            cout << "STACK OVERFLOW" << endl;
        } else {
            arr[++top] = val;
        }
    }

    // Pop an element from the stack
    int pop() {
        if (isEmpty()) {
            cout << "STACK UNDERFLOW" << endl;
            return 0;
        } else {
            int popVal = arr[top];
            arr[top] = 0;
            top--;
            return popVal;
        }
    }

    // Count the number of elements in the stack
    int count() {
        return top + 1;
    }

    // Peek at an element at a specific position
    int peek(int pos) {
        if (isEmpty() || pos < 0 || pos > top) {
            cout << "INVALID POSITION OR STACK UNDERFLOW" << endl;
            return 0;
        } else {
            return arr[pos];
        }
    }

    // Change the value at a specific position
    void change(int pos, int val) {
        if (pos < 0 || pos > top) {
            cout << "INVALID POSITION" << endl;
        } else {
            arr[pos] = val;
            cout << "Value changed at position " << pos << endl;
        }
    }

    // Display all values in the stack
    void display() {
        cout << "Values present in the stack are:" << '\n';
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << '\n';
        }
    }
};

int main() {
    Stack s;
    int option, pos, val;

    do {
        cout << "OPERATIONS TO PERFORM, TO EXIT PRESS 0" << endl;
        cout << "1. PUSH()" << endl;
        cout << "2. POP()" << endl;
        cout << "3. ISFULL()" << endl;
        cout << "4. ISEMPTY()" << endl;
        cout << "5. PEEK()" << endl;
        cout << "6. COUNT()" << endl;
        cout << "7. CHANGE()" << endl;
        cout << "8. DISPLAY()" << endl;
        cout << "9. CLEAR SCREEN" << endl;
        cin >> option;

        switch (option) {
            case 0:
                break;
            case 1:
                cout << "Enter a value to push onto the stack: ";
                cin >> val;
                s.push(val);
                break;
            case 2:
                cout << "POPPED VALUE: " << s.pop() << endl;
                break;
            case 3:
                if (s.isFull()) {
                    cout << "Stack is full" << endl;
                } else {
                    cout << "Stack is not full" << endl;
                }
                break;
            case 4:
                if (s.isEmpty()) {
                    cout << "Stack is empty" << endl;
                } else {
                    cout << "Stack is not empty" << endl;
                }
                break;
            case 5:
                cout << "Enter the position: ";
                cin >> pos;
                cout << "Value at position " << pos << " is " << s.peek(pos) << endl;
                break;
            case 6:
                cout << "Number of elements in the stack: " << s.count() << endl;
                break;
            case 7:
                cout << "Enter the position and value: ";
                cin >> pos >> val;
                s.change(pos, val);
                break;
            case 8:
                s.display();
                break;
            case 9:
                system("cls");
                break;
            default:
                cout << "Invalid option" << endl;
        }
    } while (option != 0);

    return 0;
}
