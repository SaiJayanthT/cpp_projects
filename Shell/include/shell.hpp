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

    Command* command;


public:

    Shell();

    ~Shell();

    void start(void);

    void read(void);

    int execute();

};

// Command Class
class Command {

    string name;
    map<string, commandFuncPtr> bucket;
    vector<string> args;
    int status;

    Command();

    int exit(void);

    int hello(void);

    int add(void);

    int invalidCommand(void);

    commandFuncPtr operator()(void);

    friend class Shell;

};

#endif