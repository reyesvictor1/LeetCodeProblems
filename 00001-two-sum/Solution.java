import java.util.ArrayList;

public class Solution {

    public ArrayList<Integer> twoSum(ArrayList<Integer> nums, int target) {
        ArrayList<Integer> result = new ArrayList<Integer>();
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (i != j) {
                    if (nums.get(i) + nums.get(j) == target) {
                        result.add(i);
                        result.add(j);
                        return result;
                    }
                } 
            }
        }
        return result;
    }

    public int[] twoSum(int[] nums, int target) {
        int[] result = new int[2];
        for (int i = 0; i < nums.length; i++) {
            for (int j = 0; j < nums.length; j++) {
                if (i != j) {
                    if (nums[i] + nums[j] == target) {
                        result[0] = i;
                        result[1] = j;
                        return result;
                    }
                }
            }
        }
        return result;
    }

    public void arrayPrinter(ArrayList<Integer> arrayList) {
        System.out.print("[");
        for (int i = 0; i < arrayList.size(); i++) {
            System.out.print(arrayList.get(i));
            if (i != arrayList.size() - 1)
            System.out.print(" ");
        }
        System.out.println("]");
    }

    public void arrayPrinter(int[] array) {
        System.out.print("[");
        for (int i = 0; i < array.length; i++) {
            System.out.print(array[i]);
            if (i != array.length - 1) System.out.print(" ");
        }
        System.out.println("]");
    }
    
    public static void main(String[] args) {

        boolean useArrayList = false;
        int target = 9;
        
        Solution solution = new Solution();
        System.out.println("target = " + target);

        if (useArrayList) {
            ArrayList<Integer> input = new ArrayList<>();
            input.add(2);
            input.add(5);
            input.add(7);
            input.add(10);
            solution.arrayPrinter(input);
            ArrayList<Integer> result = solution.twoSum(input, target);
            solution.arrayPrinter(result);
        } else {
            int[] input = {2, 5, 7, 10};
            solution.arrayPrinter(input);
            int[] result = solution.twoSum(input, target);
            solution.arrayPrinter(result);
        }
    }
}