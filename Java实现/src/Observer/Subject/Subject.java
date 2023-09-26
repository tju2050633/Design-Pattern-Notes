package Observer.Subject;

import java.util.ArrayList;
import java.util.List;
import Observer.Observer.Observer;

public  class Subject {
    private List<Observer> observers = new ArrayList<Observer>();
    private int state;

    public void setState(int state) {
        this.state = state;
        notifyObservers();
    }

    public int getState() {
        return state;
    }

    public void attach(Observer observer) {
        observers.add(observer);
    }

    public void detach(Observer observer) {
        observers.remove(observer);
    }

    public void notifyObservers() {
        for(Observer observer : observers) {
            observer.update();
        }
    }

}
