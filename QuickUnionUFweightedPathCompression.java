public class QuickUnionUFweightedPathCompression {
    private int[] id;
    private int[] sz;

    public QuickUnionUFweightedPathCompression(int n) {
        id = new int[n];
        sz = new int[n]; 
        for (int i = 0; i < n; i++) {
            id[i] = i;
            sz[i] = 1; 
        }
    }

    private int root(int i) {
        while (i != id[i]) {
            id[i] = id[id[i]];
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
        if (i == j) {
            return;
        }
        if (sz[i] < sz[j]) {
            id[i] = j;
            sz[j] += sz[i];
        } else {
            id[j] = i;
            sz[i] += sz[j];
        }
    }

    public static void main(String[] args) {
        QuickUnionUFweightedPathCompression uf = new QuickUnionUFweightedPathCompression(10);
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
