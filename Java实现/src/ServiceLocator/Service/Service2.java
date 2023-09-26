package ServiceLocator.Service;

public class Service2 implements Service {
    public void execute() {
        System.out.println("Executing Service1");
    }

    public String getName() {
        return "Service1";
    }
}
