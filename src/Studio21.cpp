#include "mockos/CommandPrompt.h"
#include "mockos/SimpleFileFactory.h"
#include "mockos/SimpleFileSystem.h"
#include "mockos/TouchCommand.h"

int main() {
    SimpleFileSystem *simpleSystem = new SimpleFileSystem();
    SimpleFileFactory *simpleFactory = new SimpleFileFactory();
    TouchCommand *command  = new TouchCommand(simpleSystem, simpleFactory);
    CommandPrompt commandPrompt;
    commandPrompt.setFileSystem(simpleSystem);
    commandPrompt.setFileFactory(simpleFactory);
    commandPrompt.addCommand("touch", command);
    int result =  commandPrompt.run();
    delete command;
    delete simpleFactory;
    delete simpleSystem;
    return result;

}
