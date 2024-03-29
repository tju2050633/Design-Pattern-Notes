package CompositeEntity.Client;

import CompositeEntity.CompositeEntity.CompositeEntity;

public class Client {
    private CompositeEntity compositeEntity = new CompositeEntity();

    public void printData() {
        for (String data : compositeEntity.getData()) {
            System.out.println("Data: " + data);
        }
    }

    public void setData(String data1, String data2) {
        compositeEntity.setData(data1, data2);
    }
}
