package FrontController;

import FrontController.FrontController.FrontController;

public class FrontControllerTest {
    public static void main(String[] args) {
        FrontController frontController = new FrontController();
        frontController.dispatchRequest("HOME");
        frontController.dispatchRequest("STUDENT");
    }
}
