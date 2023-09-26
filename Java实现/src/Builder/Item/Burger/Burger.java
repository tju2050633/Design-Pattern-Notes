package Builder.Item.Burger;

import Builder.Item.Item;
import Builder.Packing.Packing;
import Builder.Packing.Wrapper;

public abstract class Burger implements Item{
    @Override
    public Packing packing() {
        return new Wrapper();
    }
}
