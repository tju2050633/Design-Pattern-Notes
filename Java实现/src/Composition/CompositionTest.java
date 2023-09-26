package Composition;

import Composition.Employee.Employee;

public class CompositionTest {
    public static void main(String[] args) {

        // Create the CEO
        Employee CEO = new Employee("John","CEO", 30000);

        // Create the head of sales
        Employee headSales = new Employee("Robert","Head Sales", 20000);

        // Create the head of marketing
        Employee headMarketing = new Employee("Michel","Head Marketing", 20000);

        // Create the clerk of sales
        Employee clerk1 = new Employee("Laura","Marketing", 10000);
        Employee clerk2 = new Employee("Bob","Marketing", 10000);

        // Create the clerk of sales
        Employee salesExecutive1 = new Employee("Richard","Sales", 10000);
        Employee salesExecutive2 = new Employee("Rob","Sales", 10000);

        // Add the head of sales to the CEO
        CEO.add(headSales);

        // Add the head of marketing to the CEO
        CEO.add(headMarketing);

        // Add the clerks to the head of marketing
        headMarketing.add(clerk1);
        headMarketing.add(clerk2);

        // Add the sales executives to the head of sales
        headSales.add(salesExecutive1);
        headSales.add(salesExecutive2);

        // Print all employees of the organization
        System.out.println(CEO);

        for (Composition.Employee.Employee headEmployee : CEO.getSubordinates()) {
            System.out.println(headEmployee);

            for (Composition.Employee.Employee employee : headEmployee.getSubordinates()) {
                System.out.println(employee);
            }
        }
    }
}
