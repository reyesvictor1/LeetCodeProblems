import java.util.Scanner;

public class Solution {
    
    public int lengthOfLastWord(String str) {

        // remove whitespace at both the beginning and ending
        String trimmedStr = str.trim();

        // find index of last space character
        int lastSpaceIndex = trimmedStr.lastIndexOf(' ');

        // extract the last word as substring
        String lastWord = trimmedStr.substring(lastSpaceIndex + 1);

        // return length of last word
        return lastWord.length();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the string: ");
        String input = scanner.nextLine();

        Solution solution = new Solution();
        int result = solution.lengthOfLastWord(input);
        System.out.println(result);
    }
}