package Bridge.Shape;

import Bridge.DrawAPI.DrawAPI;

public class Square extends Shape{
    private int side, x, y;

    public Square(int side, int x, int y, DrawAPI drawAPI){
        super(drawAPI);
        this.side = side;
        this.x = x;
        this.y = y;
    }

    public void draw(){
        drawAPI.drawSquare(side, x, y);
    }
}
