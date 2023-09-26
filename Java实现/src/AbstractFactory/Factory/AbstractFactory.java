package AbstractFactory.Factory;

import AbstractFactory.Shape.Shape;
import AbstractFactory.Color.Color;

public abstract class AbstractFactory {
    public abstract Color getColor(String color);
    public abstract Shape getShape(String shape);
}
