import java.util.*;
class Main{
    public static Stack<Integer> sortStack(Stack<Integer> input){
        Stack<Integer> temp = new Stack<Integer>();
        while(!input.isEmpty()){
            int tmp = input.pop();
            while(!temp.isEmpty() && temp.peek()<tmp){
                input.push(temp.pop());
            }
            temp.push(tmp);
        }
        return temp;
    }
     public static void main(String args[])
    {
        Stack<Integer> input = new Stack<Integer>();
        input.add(34);
        input.add(3);
        input.add(31);
        input.add(98);
        input.add(92);
        input.add(23);
     
        Stack<Integer> tmpStack=sortStack(input);
        System.out.println("Sorted numbers are:");
     
        while (!tmpStack.empty())
        {
            System.out.print(tmpStack.pop()+" ");
        } 
    }
}
