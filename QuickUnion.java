public class QuickUnionUF {
    private int[] id;

    public QuickUnionUF(int n) {
        id = new int[n];
        for (int i = 0; i < n; i++) {
            id[i] = i;
        }
    }

    private int root(int i) {
        while (i != id[i]) {
            i = id[i];
        }
        return i;
    }

    public boolean connected(int p, int q) {
        return root(p) == root(q);
    }

    public void union(int p, int q) {
        int i = root(p);
        int j = root(q);
        id[i] = j;
    }

    public static void main(String[] args) {
        QuickUnionUF uf = new QuickUnionUF(10);
        uf.union(4, 3);
        uf.union(3, 8);
        uf.union(6, 5);
        uf.union(9, 4);
        uf.union(2, 1);

        System.out.println("Connected(8, 9): " + uf.connected(8, 9));
        System.out.println("Connected(5, 0): " + uf.connected(5, 0));

        uf.union(5, 0);
        uf.union(7, 2);
        uf.union(6, 1);

        System.out.println("Connected(5, 0): " + uf.connected(5, 0));
        System.out.println("Connected(7, 8): " + uf.connected(7, 8));
    }
}
