package Visitor;

import Visitor.ComputerPart.Computer;
import Visitor.ComputerPart.ComputerPart;
import Visitor.Visitor.ComputerPartDisplayVisitor;

public class VisitorTest {
    public static void main(String[] args) {
        ComputerPart computer = new Computer();
        computer.accept(new ComputerPartDisplayVisitor());
    }
}
