import java.io.File;
import java.util.Scanner;

class reader {
    public static void main(String[] args)
    {
        String S = read();
        // System.out.println(S);
    }

    public static String read()
    {
        String S = "";
        try {
            File file = new File("C:\\Users\\rohit\\Documents\\GitHub\\sem_7\\ssc\\Lab1\\input.txt");
            Scanner sc = new Scanner(file);
            // System.out.println("Reading File Using Scanner");
            while (sc.hasNextLine()) {
                S += sc.nextLine() + "\n";
                // System.out.println(S);
            }
            sc.close();
        } catch (Exception e) {
            e.getStackTrace();
        }
        return S;
    }
}