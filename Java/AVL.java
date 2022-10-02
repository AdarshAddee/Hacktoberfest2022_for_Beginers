package AVL;

public class AVL {

    private AVLnode root;

    private static class AVLnode {
        private AVLnode left;
        private AVLnode right;
        private int data;
        private int height;

        AVLnode(int data) {
            this.data = data;
        }

    }

    // Recursive Insert Method
    public void insert(int data) {
        root = insert(root, data);
    }

    private AVLnode insert(AVLnode root, int data) {
        if (root == null) {
            return new AVLnode(data);
        }
        if (data < root.data) {
            root.left = insert(root.left, data);
        } else {
            root.right = insert(root.right, data);
        }

        return root;
    }

    public void inOrder(AVLnode root) {
        if (root == null) {
            return;
        }
        inOrder(root.left);
        System.out.print(root.data + " ");
        inOrder(root.right);
    }

    public static void main(String[] args) {
        AVL tree = new AVL();
        tree.insert(10);
        tree.insert(20);
        tree.insert(30);

        tree.inOrder(tree.root);
    }
}
