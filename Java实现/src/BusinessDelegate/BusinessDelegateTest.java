package BusinessDelegate;

import BusinessDelegate.Client.Client;
import BusinessDelegate.Delegate.BusinessDelegate;

public class BusinessDelegateTest {
    public static void main(String[] args) {
        BusinessDelegate businessDelegate = new BusinessDelegate();
        Client client = new Client(businessDelegate);
        businessDelegate.setServiceType("EJB");
        client.doTask();
        businessDelegate.setServiceType("JMS");
        client.doTask();
    }
}
