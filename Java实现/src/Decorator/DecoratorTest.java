package Decorator;

import Decorator.Decorator.*;
import Decorator.Shape.*;

public class DecoratorTest {
    public static void main(String[] args) {
        Shape circle = new Circle();
        Shape rectangle = new Rectangle();
        Shape redCircle = new RedShapeDecorator(new Circle());
        Shape redRectangle = new RedShapeDecorator(new Rectangle());
        Shape blueCircle = new BlueShapeDecorator(new Circle());
        Shape blueRectangle = new BlueShapeDecorator(new Rectangle());

        
        System.out.println("Circle with normal border");
        circle.draw();

        System.out.println("\nRectangle with normal border");
        rectangle.draw();
        
        System.out.println("\nCircle of red border");
        redCircle.draw();
        
        System.out.println("\nRectangle of red border");
        redRectangle.draw();

        System.out.println("\nCircle of blue border");
        blueCircle.draw();

        System.out.println("\nRectangle of blue border");
        blueRectangle.draw();
    }
}
