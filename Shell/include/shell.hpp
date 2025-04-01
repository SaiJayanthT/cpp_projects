#ifndef SHELL_H
#define SHELL_H

namespace dev{

// Shell Class
class Shell {

private:

    int job(char **);

public:

    Shell();

    void start(void);

    char* read(void);

    char** spilt(char*);

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


}

#endif