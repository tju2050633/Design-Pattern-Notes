package Singleton;

public class SingletonTest {
    public static void main(String[] args) {
        // Illegal construct
        // Compile Time Error: The constructor SingleObject() is not visible
        // SingleObject object = new SingleObject();

        // Get the only object available
        SingleObject object = SingleObject.getInstance();

        // Show the message
        object.showMessage();
    }
}
