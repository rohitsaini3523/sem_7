import java.rmi.Naming;

public class MyClient {
    public static void main(String[] args) {
        try {
            MyRemoteInterface remoteObject = (MyRemoteInterface) Naming.lookup("rmi://localhost/MyServer");
            System.out.println("Server says: " + remoteObject.hello());
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
