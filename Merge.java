public class Main {
    public static void main(String[] args) {
        int a[] = {1, 3, 5, 7,8,10,12};
        int b[] = {2, 4, 6, 7, 8, 10, 12, 13};
        int tot = a.length + b.length;
        int c[] = new int[tot];
        int i = 0;
        int j = 0;
        int k = 0;
        
        while (i < a.length && j < b.length) {
            if (a[i] <= b[j]) {
                c[k] = a[i];
                i++;
            } else {
                c[k] = b[j];
                j++;
            }
            k++;
        }
        
        while (j < b.length) {
            c[k++] = b[j++];
        }
        
        while (i < a.length) {
            c[k++] = a[i++];
        }
        
        for (int x = 0; x < tot; x++) {
            System.out.print(c[x] + " ");
        }
    }
}
