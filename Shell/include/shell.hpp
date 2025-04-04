#ifndef SHELL_H
#define SHELL_H
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <utility>

using namespace std;

class Command;

typedef int(Command::*commandFuncPtr)(void);

// Shell Class
class Shell {

private:
    string userInput;

    int cmdStatus;

    vector<string> commands;

    Command* commandObject;


public:

    Shell();

    ~Shell();

    void start(void);

    void read(void);

    int execute();

    commandFuncPtr get_cmd(void);

};

// Command Class
class Command {

    map<string, commandFuncPtr> availableCommands;

    Command();

    int exit(void);

    int hello(void);

    int invalidCommand(void);

    friend class Shell;

};

#endif