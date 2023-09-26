package Builder.Item;

import Builder.Packing.Packing;

public interface Item {
    public String name();
    public Packing packing();
    public float price();
}
