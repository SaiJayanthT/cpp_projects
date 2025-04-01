#ifndef SHELL_H
#define SHELL_H
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

void logger(std::string);

// Shell Class
class Shell {

private:
    std::string line;
    int status;
    std::vector<std::string> commands;

    int job(std::string);   


public:

    Shell();

    void start(void);

    void read(void);

    void split();

    int execute(char**);

};

// Command Class
class Command {

    Command();

    int help(char** args);

    int cd(char** args);

    int shell_exit(char** args);

    friend class Shell;
    

};

#endif