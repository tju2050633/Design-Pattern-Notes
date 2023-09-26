package Bridge.DrawAPI;

public class YellowSquare implements DrawAPI{
    @Override
    public void drawCircle(int radius, int x, int y){
        // Do nothing
    }

    @Override
    public void drawSquare(int side, int x, int y){
        System.out.println("Drawing Square[ color: yellow, side: " + side + ", x: " + x + ", " + y + "]");
    }
}
