#include "mockos/CommandPrompt.h"
#include "mockos/SimpleFileFactory.h"
#include "mockos/SimpleFileSystem.h"
#include "mockos/LSCommand.h"
#include "mockos/RemoveCommand.h"
#include "mockos/TouchCommand.h"
#include "mockos/CatCommand.h"
#include "mockos/DisplayCommand.h"

int main() {
    SimpleFileSystem *simpleSystem = new SimpleFileSystem();
    SimpleFileFactory *simpleFactory = new SimpleFileFactory();
    LSCommand *command  = new LSCommand(simpleSystem);
    TouchCommand *touchCommand = new TouchCommand(simpleSystem, simpleFactory);
    RemoveCommand *removeCommand = new RemoveCommand(simpleSystem);
    CatCommand *catCommand = new CatCommand(simpleSystem);
    DisplayCommand *displayCommand = new DisplayCommand(simpleSystem);
    CommandPrompt commandPrompt;
    commandPrompt.setFileSystem(simpleSystem);
    commandPrompt.setFileFactory(simpleFactory);
    commandPrompt.addCommand("touch", touchCommand);
    commandPrompt.addCommand("ls", command);
    commandPrompt.addCommand("rm", removeCommand);
    commandPrompt.addCommand("cat", catCommand);
    commandPrompt.addCommand("ds", displayCommand);
    commandPrompt.run();
    delete simpleSystem;
    delete simpleFactory;
    delete command;
    delete touchCommand;
    delete removeCommand;
    delete catCommand;
    delete displayCommand;
    return 0;
}
