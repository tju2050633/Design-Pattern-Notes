package DAO;

import DAO.Student.*;

public class DAOTest {
    public static void main(String[] args) {
        StudentDAO studentDAO = new StudentDAOImpl();

        for (Student student : studentDAO.getAllStudents()) {
            System.out.println("Student: [RollNo: " + student.getRollNo() + ", Name: " + student.getName() + "]");
        }

        Student student = studentDAO.getAllStudents().get(0);
        student.setName("Michael");
        studentDAO.updateStudent(student);

        studentDAO.getStudent(0);
        System.out.println("Student: [RollNo: " + student.getRollNo() + ", Name: " + student.getName() + "]");
    }
}
