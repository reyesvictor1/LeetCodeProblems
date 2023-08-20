public class Solution {

    public boolean isPalindrome(int x) {

        // convert integer to string
        String A = Integer.toString(x);

        // create a StringBuilder to reverse the string
        StringBuilder B = new StringBuilder(A);
        B.reverse();

        // compare both strings
        for (int i = 0; i < A.length(); i++) {
            if (A.charAt(i) != B.charAt(i)) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        int x = 121;  // outputs true
        int y = -121; // outputs false
        int z = 1;    // outputs true

        Solution solution = new Solution();
        System.out.println(x + " : " + solution.isPalindrome(x));
        System.out.println(y + " : " + solution.isPalindrome(y));
        System.out.println(z + " : " + solution.isPalindrome(z));
    }
}