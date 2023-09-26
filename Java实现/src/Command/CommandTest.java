package Command;

import Command.Order.*;
import Command.Receiver.*;
import Command.Requester.Broker;

public class CommandTest {
    public static void main(String[] args) {
        Stock abcStock = new Stock();
        
        BuyStock buyStockOrder = new BuyStock(abcStock);
        SellStock sellStockOrder = new SellStock(abcStock);
        
        Broker broker = new Broker();
        broker.takeOrder(buyStockOrder);
        broker.takeOrder(sellStockOrder);
        
        broker.placeOrders();
    }
}
