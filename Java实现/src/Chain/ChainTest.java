package Chain;

import Chain.Logger.*;

public class ChainTest {
    public static void main(String[] args) {
        AbstractLogger loggerChain = getChainOfLoggers();
        
        loggerChain.logMessage(AbstractLogger.INFO, "This is an information.");

        System.out.println("");
        
        loggerChain.logMessage(AbstractLogger.DEBUG, "This is a debug level information.");
        
        System.out.println("");

        loggerChain.logMessage(AbstractLogger.ERROR, "This is an error information.");
    }
    
    private static AbstractLogger getChainOfLoggers() {
        AbstractLogger errorLogger = new ErrorLogger(AbstractLogger.ERROR);
        
        AbstractLogger fileLogger = new FileLogger(AbstractLogger.DEBUG);
        fileLogger.setNextLogger(errorLogger);
        
        AbstractLogger consoleLogger = new ConsoleLogger(AbstractLogger.INFO);
        consoleLogger.setNextLogger(fileLogger);
        
        return consoleLogger;
    }
}
