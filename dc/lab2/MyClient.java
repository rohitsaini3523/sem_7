import java.rmi.Naming;

public class MyClient {
    public static void main(String[] args) {
        try {
            MyRemoteInterface remoteObject = (MyRemoteInterface) Naming.lookup("rmi://localhost/MyServer");
            /* reading file for reading value of a and b */
            java.io.File file = new java.io.File("input.txt");
            java.util.Scanner input = new java.util.Scanner(file);
            int a = input.nextInt();
            int b = input.nextInt();
            input.close();
            System.out.println("Server says: " + a + " + " + b + " = " + remoteObject.add(a, b));
            System.out.println("Server says: " + a + " - " + b + " = " + remoteObject.subtract(a, b));
            System.out.println("Server says: " + a + " * " + b + " = " + remoteObject.multiply(a, b));
            System.out.println("Server says: " + a + " / " + b + " = " + remoteObject.divide(a, b));
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
