package Builder.Item.ColdDrink;

import Builder.Item.Item;
import Builder.Packing.Packing;
import Builder.Packing.Bottle;

public abstract class ColdDrink implements Item{
    @Override
    public Packing packing() {
        return new Bottle();
    }
}
