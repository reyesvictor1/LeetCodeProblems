import java.util.*;

public class Solution {

    public int searchInsert(ArrayList<Integer> nums, int target) {
        for (int i = 0; i < nums.size(); i++)
            if (target <= nums.get(i)) return i;
        return nums.size();
    }

    public int searchInsert(int[] nums, int target) {
        for (int i = 0; i < nums.length; i++)
            if (target <= nums[i]) return i;
        return nums.length;
    }

    public static void main(String[] args) {
        
        boolean useArrayList = false;
        int target = 4;
        int result = 0;
        Solution solution = new Solution();
        System.out.print("input: ");

        if (useArrayList) {
            ArrayList<Integer> nums = new ArrayList<>();
            nums.add(1);
            nums.add(3);
            nums.add(5);
            nums.add(6);
            result = solution.searchInsert(nums, target);
            for (int num : nums) System.out.print(num + " ");
        } else {
            int[] nums = {1, 3, 5, 6};
            result = solution.searchInsert(nums, target);
            for (int num : nums) System.out.print(num + " ");
        }

        System.out.println("");
        System.out.println("target: " + target);
        System.out.println("result: " + result);
    }
}