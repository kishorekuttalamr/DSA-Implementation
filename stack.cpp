#include <iostream>
#include <string>
using namespace std;
class Stack
{
private:
    int top;
    int arr[5];

public:
    Stack()
    {
        top = -1;
        for (int i = 0; i < 5; i++)
        {
            arr[i] = 0;
        }
    }
    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isFull()
    {
        int n = sizeof(arr) / sizeof(arr[0]);
        if (top == n)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void push(int val)
    {
        if (isFull())
        {
            cout << "STACK OVERFLOW" << endl;
        }
        else
        {
            arr[++top] = val;
        }
    }
    int pop()
    {
        if (isEmpty())
        {
            cout << "STACK UNDERFLOW" << endl;
            return 0;
        }
        else
        {
            int popVal = arr[top];
            arr[top] = 0;
            top--;
            return popVal;
        }
    }
    int count()
    {
        return top + 1;
    }
    int peek(int pos)
    {
        if (isEmpty())
        {
            cout << "STACK UNDERFLOW" << endl;
            return 0;
        }
        else
        {
            return arr[pos];
        }
    }
    void change(int pos, int val)
    {
        arr[pos] = val;
        cout << "value changed at" << pos << endl;
    }
    void display()
    {
        cout << "values present in the stack are" << '\n';
        int n = sizeof(arr) / sizeof(arr[0]);
        for (int i = n - 1; i >= 0; i--)
        {
            cout << arr[i] << '\n';
        }
    }
};
int main()
{
    Stack s;
    int option, pos, val;

    do
    {

        cout << "OPERATIONS TO PERFORM, IN ORDER TO EXIT, PRESS 0" << endl;
        cout << "1.PUSH()" << endl;
        cout << "2.POP()" << endl;
        cout << "3.ISFULL()" << endl;
        cout << "4.ISEMPTY()" << endl;
        cout << "5.PEEK()" << endl;
        cout << "6.COUNT()" << endl;
        cout << "7.CHANGE()" << endl;
        cout << "8.DISPLAY()" << endl;
        cout << "9.CLEAR SCREEN" << endl;
        cin >> option;
        switch (option)
        {
        case 0:
            break;
        case 1:
            cout << "enter a value to input in the stack" << endl;
            cin >> val;
            s.push(val);
            break;
        case 2:
            cout << "POPPED VALUE:" << s.pop() << endl;
            break;
        case 3:
            if (s.isEmpty())
            {
                cout << "stack is empty" << endl;
            }
            else
            {
                cout << "stack is not empty" << endl;
            }
            break;
        case 4:
            if (s.isFull())
            {
                cout << "stack is full" << endl;
            }
            else
            {
                cout << "stack is not full" << endl;
            }
        case 5:
            cout << "enter the position" << endl;
            cin >> pos;
            cout << "value at position " << pos << "is " << s.peek(pos) << endl;
        case 6:
            cout << "number of elements in the stack : " << s.count() << endl;
            break;
        case 7:
            cout << "enter the position and value" << endl;
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
            cout << "invalid option" << endl;
        }
    } while (option != 0);
}