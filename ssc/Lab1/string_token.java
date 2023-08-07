import java.util.Scanner;
import java.util.StringTokenizer;

public class string_token {
    public static void main(String[] args) {
        try {
            Scanner scan = new Scanner(System.in);
            System.out.print("Enter the String:");
            String S = scan.nextLine();
            StringTokenizer st = new StringTokenizer(S, " ");
            while (st.hasMoreTokens()) {
                System.out.println("Remaining are: " + st.countTokens());
                System.out.println(st.nextToken());
            }
            scan.close();
        } catch (Exception e) {
            System.out.println("An error occurred: " + e.getMessage());
        }
    }

    public static String[] token(String S, String delimiter) {
        String[] ansArray;
        int numOfTokens = 0;
        StringTokenizer st = new StringTokenizer(S, delimiter);

        // Count the number of tokens first
        while (st.hasMoreTokens()) {
            st.nextToken();
            numOfTokens++;
        }

        // Initialize the array with the correct size
        ansArray = new String[numOfTokens];

        // Reset the tokenizer
        st = new StringTokenizer(S, delimiter);

        // Store tokens in the array
        int index = 0;
        while (st.hasMoreTokens()) {
            ansArray[index] = st.nextToken();
            index++;
        }
        return ansArray;
    }
}
