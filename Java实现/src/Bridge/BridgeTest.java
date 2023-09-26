package Bridge;

import Bridge.DrawAPI.*;
import Bridge.Shape.*;

public class BridgeTest {
    public static void main(String[] args){
        Shape redCircle = new Circle(100, 100, 10, new RedCircle());
        Shape greenCircle = new Circle(100, 100, 10, new GreenCircle());
        Shape blueSquare = new Square(10, 100, 100, new BlueSquare());
        Shape yellowSquare = new Square(10, 100, 100, new YellowSquare());

        redCircle.draw();
        greenCircle.draw();
        blueSquare.draw();
        yellowSquare.draw();
    }
}
