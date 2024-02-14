class Node {
    int data;
    Node next;

    public Node(int data) {
        this.data = data;
        this.next = null;
    }
}

class Queue {
    Node front;
    Node rear;

    public Queue() {
        this.front = null;
        this.rear = null;
    }

    public void enqueue(int data){
        Node newNode = new Node(data);
        if(isEmpty()){
            front = newNode;
            rear = newNode;
        }
        else{
            rear.next = newNode;
            rear = newNode;
        }
        
    }

    public int dequeue(){
        if(isEmpty()){
            System.out.println("The queue is empty");
            return -1;
        }
        else{
            int val = front.data;
            if(front == rear){
                front = null;
                rear = null;
            }
            else{
                front = front.next;
            }
            return val;
        }
        
    }

    public boolean isEmpty() {
        return (front == null);
    }

}

public class Main {
    public static void main(String[] args) {
        Queue queue = new Queue();
        queue.enqueue(5);
        queue.enqueue(10);
        queue.enqueue(15);
        System.out.println("Dequeued: " + queue.dequeue());
        System.out.println("Dequeued: " + queue.dequeue());
        System.out.println("Dequeued: " + queue.dequeue());
        System.out.println("Dequeued: " + queue.dequeue());
    }
}
