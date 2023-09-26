package Singleton;

// 饿汉式实现
// 没有Lazy初始化、利用classloader机制保证线程安全

public class SingleObject {
    // singleton
    private static SingleObject instance = new SingleObject();
    private SingleObject() {}
    public static SingleObject getInstance() {
        return instance;
    }

    // method
    public void showMessage() {
        System.out.println("Hello World!");
    }
}
