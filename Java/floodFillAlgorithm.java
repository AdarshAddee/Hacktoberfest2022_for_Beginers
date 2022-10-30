import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Queue;
 
class Pair
{
    int x, y;
 
    public Pair(int x, int y)
    {
        this.x = x;
        this.y = y;
    }
}
 
class Main
{
    // Below arrays detail all eight possible movements
    private static final int[] row = { -1, -1, -1, 0, 0, 1, 1, 1 };
    private static final int[] col = { -1, 0, 1, -1, 1, -1, 0, 1 };
 
    // check if it is possible to go to pixel (x, y) from the
    // current pixel. The function returns false if the pixel
    // has a different color, or it's not a valid pixel
    public static boolean isSafe(char[][] mat, int x, int y, char target)
    {
        return x >= 0 && x < mat.length && y >= 0 && y < mat[0].length
                && mat[x][y] == target;
    }
 
    // Flood fill using BFS
    public static void floodfill(char[][] mat, int x, int y, char replacement)
    {
        // base case
        if (mat == null || mat.length == 0) {
            return;
        }
 
        // create a queue and enqueue starting pixel
        Queue<Pair> q = new ArrayDeque<>();
        q.add(new Pair(x, y));
 
        // get the target color
        char target = mat[x][y];
 
        // target color is same as replacement
        if (target == replacement) {
            return;
        }
 
        // break when the queue becomes empty
        while (!q.isEmpty())
        {
            // dequeue front node and process it
            Pair node = q.poll();
 
            // (x, y) represents the current pixel
            x = node.x;
            y = node.y;
 
            // replace the current pixel color with that of replacement
            mat[x][y] = replacement;
 
            // process all eight adjacent pixels of the current pixel and
            // enqueue each valid pixel
            for (int k = 0; k < row.length; k++)
            {
                // if the adjacent pixel at position (x + row[k], y + col[k]) is
                // is valid and has the same color as the current pixel
                if (isSafe(mat,x + row[k], y + col[k], target))
                {
                    // enqueue adjacent pixel
                    q.add(new Pair(x + row[k], y + col[k]));
                }
            }
        }
    }
 
    public static void main(String[] args)
    {
        // matrix showing portion of the screen having different colors
        char[][] mat = {
                "YYYGGGGGGG".toCharArray(),
                "YYYYYYGXXX".toCharArray(),
                "GGGGGGGXXX".toCharArray(),
                "WWWWWGGGGX".toCharArray(),
                "WRRRRRGXXX".toCharArray(),
                "WWWRRGGXXX".toCharArray(),
                "WBWRRRRRRX".toCharArray(),
                "WBBBBRRXXX".toCharArray(),
                "WBBXBBBBXX".toCharArray(),
                "WBBXXXXXXX".toCharArray()
        };
 
        // start node
        int x = 3, y = 9;    // having target color `X`
 
        // replacement color
        char replacement = 'C';
 
        // replace the target color with a replacement color
        floodfill(mat, x, y, replacement);
 
        // print the colors after replacement
        for (char[] row: mat) {
            System.out.println(Arrays.toString(row));
        }
    }
}
