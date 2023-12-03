import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;

public class MyServer extends UnicastRemoteObject implements MyRemoteInterface {
    public MyServer() throws RemoteException {
        // Constructor to declare that it throws RemoteException
    }

    public String hello() throws RemoteException {
        return "Hello From the server!";
    }


    public static void main(String[] args) {
        try {
            MyServer server = new MyServer();
            java.rmi.Naming.rebind("MyServer", server);
            System.out.println("Server is running...");
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
