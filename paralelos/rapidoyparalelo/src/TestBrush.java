
public class TestBrush
{
    public static void main(String[] args)
    {
        Brush b1 = new Brush("blue");
        Brush b2 = new Brush("blue");
        Brush b3 = new Brush("red");
        System.out.println("b1's color is " + b1.getColor());
        System.out.println("b2's color is " + b2.getColor());
        System.out.println("b3's color is " + b3.getColor());
        System.out.println("is b1 == b2? " + (b1 == b2));
        System.out.println("is b1 == b3? " + (b1 == b3));
        System.out.println("b1's color is " + b1.printInternals());
        System.out.println("b2's color is " + b2.printInternals());
        System.out.println("b3's color is " + b3.printInternals());
    }
}