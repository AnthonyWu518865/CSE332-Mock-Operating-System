#include "mockos/CommandPrompt.h"
#include "mockos/SimpleFileFactory.h"
#include "mockos/SimpleFileSystem.h"
#include "mockos/LSCommand.h"

int main() {
    SimpleFileSystem *simpleSystem = new SimpleFileSystem();
    SimpleFileFactory *simpleFactory = new SimpleFileFactory();
    LSCommand *command  = new LSCommand(simpleSystem, simpleFactory);
    CommandPrompt commandPrompt;
    commandPrompt.setFileSystem(simpleSystem);
    commandPrompt.setFileFactory(simpleFactory);
    commandPrompt.addCommand("rm", command);
    commandPrompt.run();
    if (simpleSystem ->openFile("file.txt") == nullptr) {
        cout << "correct" << endl;
    }
    return 0;
}
