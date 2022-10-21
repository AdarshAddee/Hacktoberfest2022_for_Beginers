public class TrappingRainwater {

    // TRAPPING RAINWATER and T.C of this code = O(n)

    public static int trappedRainwater(int height[]) {
        int n = height.length;

        // calculate left max boundary
        int leftMax[] = new int[n];
        leftMax[0] = height[0];
        for (int i = 1; i < n; i++) {
            leftMax[i] = Math.max(height[i], leftMax[i - 1]);
        }

        // calculate right max boundary
        int rightMax[] = new int[n];
        rightMax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rightMax[i] = Math.max(height[i], rightMax[i + 1]);
        }

        int trappedWater = 0;
        // loop
        for (int i = 0; i < n; i++) {
            // calculate water level= min(leftmax bound. leftmax bound)
            int waterLevel = Math.min(leftMax[i], rightMax[i]);
            // calclate water trapped= waterlevel - height[i]
            trappedWater += waterLevel - height[i];

        }
        return trappedWater;
    }

    public static void main(String args[]) {
        int height[] = {0,1,0,2,1,0,1,3,2,1,2,1};
        System.out.println("Water trapped between the bars = " + trappedRainwater(height));
    }

}
