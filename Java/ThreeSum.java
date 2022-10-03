import java.util.*;



public class ThreeSum {
    public static void main(String[] args) {
        int[] arr = {-1,0,1,2,-1,-4};

        List<List<Integer>> res = threeSum(arr);
        System.out.println(res);



    }
    public static List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> r = new LinkedList<>();
        for(int i = 0; i < nums.length -2; i++){
            if(i == 0 || (i > 0 && nums[i] != nums[i - 1])){
                int lo = i + 1 , hi = nums.length - 1, sum = 0 - nums[i];
                while(lo < hi){
                    if(nums[lo] + nums[hi] == sum){
                        r.add(Arrays.asList(nums[i], nums[lo], nums[hi]));
                        while(lo < hi && nums[lo] == nums[lo + 1])lo++;
                        while(lo < hi && nums[hi] == nums[hi - 1])hi--;
                        lo++;hi--;
                    }
                    else if(nums[lo] + nums[hi] < sum)lo++;
                    else hi--;
                }
            }
        }
        return r;
    }
}



