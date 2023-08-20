#include <iostream>
using namespace std;

class circularQueue
{
private:
    int front;
    int rear;
    int arr[5];

public:
    circularQueue()
    {
        front = -1;
        rear = -1;
        for (int i = 0; i < 5; i++)
        {
            arr[i] = 0; // Initialize the array with 0s
        }
    }

    // Check if the queue is empty
    bool isEmpty()
    {
        return (front == -1 && rear == -1);
    }

    // Check if the queue is full
    bool isFull()
    {
        if ((rear + 1) % 5 == front) // Array indices are 0 to 4 (total of 5 elements)
        {
            return true; // If rear is at the last index, the queue is full
        }
        else
        {
            return false; // Otherwise, the queue is not full
        }
    }

    // Enqueue an element into the circular queue
    void enqueue(int val)
    {
        if (isFull())
        {
            cout << "CircularQueue overflow" << endl;
            return; // If the queue is full, don't add new elements
        }
        else if (front == -1 && rear == -1)
        {
            front = rear = 0; // First element in the queue
            arr[rear] = val;  // Add the value at the rear
        }
        else
        {
            rear = (rear + 1) % 5; // Move the rear pointer
            arr[rear] = val;       // Add the value at the new rear
        }
    }

    // Dequeue an element from the circular queue
    int dequeue()
    {
        int x = 0;
        if (isEmpty())
        {
            cout << "Queue underflow" << endl;
            return -1; // Return -1 to indicate no valid dequeued value
        }
        else if (front == rear)
        {
            x = arr[front]; // Get the value at front (only element left)
            front = -1;     // Reset front and rear as the queue is now empty
            rear = -1;
            arr[x] = 0; // Set the dequeued element to 0
            return x;
        }
        else
        {
            x = arr[front];          // Get the value at front
            arr[front] = 0;          // Set the dequeued element to 0
            front = (front + 1) % 5; // Move the front pointer
            return x;
        }
    }

    // Calculate the count of elements in the circular queue
    int count()
    {
        if (isEmpty())
            return 0;
        else if (rear >= front)
            return rear - front + 1;
        else
            return (5 - front + rear + 1) % 5;
    }

    // Display the elements in the circular queue
    void display()
    {
        if (isEmpty())
        {
            cout << "No elements in the circular queue." << endl;
        }
        else
        {
            cout << "The values in the circular queue are:" << endl;
            for (int i = front; i <= rear || (rear < front && i < 5); i = (i + 1) % 5)
            {
                cout << arr[i] << endl; // Display elements from front to rear
            }
        }
    }
};

int main()
{
    circularQueue q;
    int option, val;
    do
    {
        cout << "OPERATION, TO EXIT PRESS 0." << endl;
        cout << "1. Enqueue()" << endl;
        cout << "2. Dequeue()" << endl;
        cout << "3. isEmpty()" << endl;
        cout << "4. isFull()" << endl;
        cout << "5. count()" << endl;
        cout << "6. display()" << endl;
        cout << "7. Clear screen" << endl;
        cin >> option;

        switch (option)
        {
        case 0:
            break;
        case 1:
            cout << "Enter a value to enqueue: ";
            cin >> val;
            q.enqueue(val); // Add the value to the queue
            break;
        case 2:
        {
            int dequeuedValue = q.dequeue(); // Remove and get the value from the front
            if (dequeuedValue != -1)
            {
                cout << "Dequeued value is: " << dequeuedValue << endl;
            }
        }
        break;
        case 3:
            if (q.isEmpty())
            {
                cout << "Circular Queue is empty" << endl;
            }
            else
            {
                cout << "Circular Queue is not empty" << endl;
            }
            break;
        case 4:
            if (q.isFull())
            {
                cout << "Circular Queue is full" << endl;
            }
            else
            {
                cout << "Circular Queue is not full" << endl;
            }
            break;
        case 5:
            cout << "Number of elements are: " << q.count() << endl;
            break;
        case 6:
            q.display(); // Display the elements in the queue
            break;
        case 7:
            system("cls"); // Use "clear" for Linux/Mac or "cls" for Windows
            break;
        default:
            cout << "Invalid choice" << endl;
        }
    } while (option != 0);

    return 0;
}
