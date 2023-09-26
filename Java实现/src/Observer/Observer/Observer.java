package Observer.Observer;

import Observer.Subject.Subject;

public abstract class Observer {
    protected Subject subject;
    public abstract void update();
}
