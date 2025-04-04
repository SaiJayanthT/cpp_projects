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

typedef int(Command::*func_ptr)(void);

// Shell Class
class Shell {

private:
    string userInput;

    int cmdStatus;

    vector<string> commands;

    Command* cmd;


public:

    Shell();

    ~Shell();

    void start(void);

    void read(void);

    void split();

    int execute();

    func_ptr get_cmd(void);

};

// Command Class
class Command {

public:
    

    map<string, func_ptr> avbcmd;

    Command();

    friend class Shell;

    int exit(void);

    int dummy(void);


};

#endif