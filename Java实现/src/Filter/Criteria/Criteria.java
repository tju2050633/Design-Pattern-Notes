package Filter.Criteria;

import java.util.List;
import Filter.Person.Person;

public interface Criteria {
    public List<Person> meetCriteria(List<Person> persons);
}
