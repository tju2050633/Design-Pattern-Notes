package MVC;

import MVC.Student.Student;
import MVC.Student.StudentController;
import MVC.Student.StudentView;


public class MVCTest {
    public static void main(String[] args) {
        Student model = new Student("Robert", "10"); // retrieve from database
        StudentView view = new StudentView();
        StudentController controller = new StudentController(model, view);

        controller.updateView();
        controller.setStudentName("John");
        controller.updateView();
    }
}
