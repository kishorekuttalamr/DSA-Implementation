class Node {
    int data;
    Node next;

    public Node(int data) {
        this.data = data;
        this.next = null;
    }
}

class Stack {
    Node top;

    public Stack() {
        this.top = null;
    }

    public void push(int data) {
        Node newNode = new Node(data);
        if (top != null) {
            newNode.next = top;
        }
        top = newNode;
    }

    public int pop() {
        int val;
        if (top != null) {
            val = top.data;
            top = top.next;
            return val;
        } else {
            System.out.println("The stack is empty");
            return -1;
        }
    }

    public boolean isEmpty() {
        return (top == null);
    }

    public int peek() {
        return top.data;
    }
}

public class Main {
    public static void main(String[] args) {
        Stack stack = new Stack();
        stack.push(5);
        stack.push(10);
        stack.push(15);
        System.out.println("Peek: " + stack.peek());
        System.out.println("Popped: " + stack.pop());
        System.out.println("Popped: " + stack.pop());
        System.out.println("Popped: " + stack.pop());
        System.out.println("Popped: " + stack.pop());
    }
}
