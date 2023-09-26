package AbstractFactory.Factory;

import AbstractFactory.Color.*;
import AbstractFactory.Shape.Shape;

public class ColorFactory extends AbstractFactory{
    public Color getColor(String color) {
        if (color == null) {
            return null;
        }
        if (color.equalsIgnoreCase("BLUE")) {
            return new Blue();
        } else if (color.equalsIgnoreCase("GREEN")) {
            return new Green();
        } else if (color.equalsIgnoreCase("RED")) {
            return new Red();
        }
        return null;
    }
    public Shape getShape(String shape) {
        return null;
    }
}
