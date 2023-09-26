package Visitor.ComputerPart;

import Visitor.Visitor.ComputerPartVisitor;

public interface ComputerPart {
    public void accept(ComputerPartVisitor computerPartVisitor);
}
