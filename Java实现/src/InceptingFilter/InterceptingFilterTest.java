package InceptingFilter;

import InceptingFilter.Client.Client;
import InceptingFilter.Filter.*;
import InceptingFilter.FilterManager.FilterManager;
import InceptingFilter.FilterManager.Target;

public class InterceptingFilterTest {
    public static void main(String[] args) {
        FilterManager filterManager = new FilterManager(new Target());
        filterManager.setFilter(new AuthenticationFilter());
        filterManager.setFilter(new DebugFilter());

        Client client = new Client();
        client.setFilterManager(filterManager);
        client.sendRequest("HOME");
    }
}
