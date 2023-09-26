package AbstractFactory.Factory;

import AbstractFactory.Shape.*;
import AbstractFactory.Color.Color;


public class ShapeFactory extends AbstractFactory{
    public Shape getShape(String shape) {
        if (shape == null) {
            return null;
        }
        if (shape.equalsIgnoreCase("CIRCLE")) {
            return new Circle();
        } else if (shape.equalsIgnoreCase("RECTANGLE")) {
            return new Rectangle();
        } else if (shape.equalsIgnoreCase("SQUARE")) {
            return new Square();
        }
        return null;
    }
    public Color getColor(String color) {
        return null;
    }
}
