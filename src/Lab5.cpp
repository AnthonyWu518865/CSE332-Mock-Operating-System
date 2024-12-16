#include "mockos/CommandPrompt.h"
#include "mockos/SimpleFileFactory.h"
#include "mockos/SimpleFileSystem.h"
#include "mockos/LSCommand.h"
#include "mockos/RemoveCommand.h"
#include "mockos/TouchCommand.h"
#include "mockos/CatCommand.h"
#include "mockos/DisplayCommand.h"
#include "mockos/CopyCommand.h"
#include "mockos/MacroCommand.h"
#include "mockos/MacroParsingStrategy.h"
#include "mockos/RenameParsingStrategy.h"

int main() {
    SimpleFileSystem *simpleSystem = new SimpleFileSystem();
    SimpleFileFactory *simpleFactory = new SimpleFileFactory();

    LSCommand *command  = new LSCommand(simpleSystem);
    TouchCommand *touchCommand = new TouchCommand(simpleSystem, simpleFactory);
    RemoveCommand *removeCommand = new RemoveCommand(simpleSystem);
    CatCommand *catCommand = new CatCommand(simpleSystem);
    DisplayCommand *displayCommand = new DisplayCommand(simpleSystem);
    CopyCommand *copyCommand = new CopyCommand(simpleSystem);

    MacroParsingStrategy* strategy = new MacroParsingStrategy();


    CommandPrompt commandPrompt;

    RenameParsingStrategy* rpStrategy = new RenameParsingStrategy();

    MacroCommand* touchlsMacro = new MacroCommand(simpleSystem);
    touchlsMacro -> setParseStrategy(strategy);
    touchlsMacro -> addCommand(touchCommand);
    touchlsMacro -> addCommand(command);

    MacroCommand* renameCommand = new MacroCommand(simpleSystem);
    renameCommand -> setParseStrategy(rpStrategy);
    renameCommand -> addCommand(copyCommand);
    renameCommand -> addCommand(removeCommand); //deletion of file.txt

    commandPrompt.setFileSystem(simpleSystem);
    commandPrompt.setFileFactory(simpleFactory);

    commandPrompt.addCommand("touch", touchCommand);
    commandPrompt.addCommand("touchls", touchlsMacro);
    commandPrompt.addCommand("rn", renameCommand);
    commandPrompt.addCommand("ls", command);
    commandPrompt.addCommand("rm", removeCommand);
    commandPrompt.addCommand("cat", catCommand);
    commandPrompt.addCommand("ds", displayCommand);
    commandPrompt.addCommand("cp", copyCommand);

    commandPrompt.run();
    
    delete simpleSystem;
    delete simpleFactory;
    delete command;
    delete touchCommand;
    delete removeCommand;
    delete catCommand;
    delete displayCommand;
    delete copyCommand;
    delete rpStrategy;
    delete touchlsMacro;
    delete renameCommand;
    delete strategy;

    return 0;
}