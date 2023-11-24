import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;

public class MyServer extends UnicastRemoteObject implements MyRemoteInterface {
    public MyServer() throws RemoteException {
        // Constructor to declare that it throws RemoteException
    }

    public int add(int a, int b) throws RemoteException {
        return a + b;
    }

    public int subtract(int a, int b) throws RemoteException {
        return a - b;
    }

    public int multiply(int a, int b) throws RemoteException {
        return a * b;
    }

    public double divide(int a, int b) throws RemoteException {
        if (b == 0) {
            throw new RemoteException("Division by zero is not allowed.");
        }
        return (double) a / b;
    }

    public static void main(String[] args) {
        try {
            MyServer server = new MyServer();
            java.rmi.Naming.rebind("MyServer", server);
            System.out.println("Calculator Server is running...");
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
