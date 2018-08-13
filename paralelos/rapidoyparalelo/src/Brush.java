import java.util.Hashtable;


public class Brush
{
    private static class BrushInternals
    {
        private String theColor;
        public BrushInternals(String color)
        {
            theColor = color;
        }
        public String getColor()
        {
            return theColor;
        }
        public String toString()
        {
            return "internals " + hashCode();
        }
    }
    private static Hashtable brusheInternalsCollection = new Hashtable();
    private final BrushInternals internals;
    public Brush(String color)
    {
        internals = get(color);
    }
    private static BrushInternals get(String color)
    {
        BrushInternals result = null;
        if (brusheInternalsCollection.containsKey(color))
        {
            result = (BrushInternals) brusheInternalsCollection.get(color);
        }
        else
        {
            result = new BrushInternals(color);
            brusheInternalsCollection.put(color, result);
        }
        return result;
    }
    public String getColor()
    {
        return internals.getColor();
    }
    public String printInternals()
    {
        return internals.toString();
    }
}
