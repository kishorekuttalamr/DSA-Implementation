import java.util.*;

public class Multistack {
    int m, n;
    int arr[];
    int bottom[], top[];

    public Multistack(int size, int no) {
        m = size;
        n = no;
        arr = new int[size];
        bottom = new int[no];
        top = new int[no];
        for (int i = 0; i < no; i++) {
            bottom[i] = i * (m / n);
            top[i] = i * (m / n) - 1;
        }
    }

    public void push(int sno, int val) {
        if (top[sno] < (sno + 1) * (m / n) - 1) {
            top[sno]++;
            arr[top[sno]] = val;
        } else {
            System.out.println("Stack number " + sno + " overflow");
        }
    }

    public void pop(int sno) {
        if (top[sno] > bottom[sno]) {
            System.out.println(arr[top[sno]]);
            top[sno]--;
        } else {
            System.out.println("Stack number " + sno + " underflow");
        }
    }

    public void printstack() {
        for (int i = 0; i < n; i++) {
            for (int j = bottom[i]; j <= top[i]; j++) {
                System.out.println(arr[j]);
            }
        }
    }

    public static void main(String[] args) {
        Multistack m = new Multistack(8, 2);
        m.push(0, 1);
        m.push(0, 2);
        m.push(1, 9);
        m.push(1, 10);
        m.push(1, 9);
        m.push(1, 10);
        m.push(1, 9);
        m.push(1, 10);
        m.printstack();
    }
}
