#include "shell.hpp"


Shell::Shell()
{
    cmd = new Command();
}

Shell::~Shell()
{
    delete cmd;
    cout << "Deleted Command Object" << endl;
}


void Shell::start(void)
{
    do{
        cout << "C++@SHELL MINGW64 (CUSTOM MADE)" << endl;
        cout << "$ ";
        read();
        split();
        cmdStatus = execute();
        // Clear
        commands.clear();

    }while(cmdStatus);
}

void Shell::read(void)
{
    // Read commands in cin
    getline(cin, userInput);

}

void Shell::split()
{
    stringstream buffer;
    buffer << userInput;
    string args;

    while (getline(buffer, args, ' ')){
        commands.push_back(args);
    }

}

int Shell::execute()
{

    int(Command::*func)(void) = get_cmd();
    return (cmd->*func)();
}

Command::Command()
{
    avbcmd["exit"] = Command::exit;
    
}


int Command::exit()
{
    cout << "exit Called" << endl;
    return 0;
}

func_ptr Shell::get_cmd(void)
{
    for (pair<string, func_ptr> p : cmd->avbcmd){
        if (p.first == commands[0])
        {
            return p.second;
        }

    }
    return &Command::dummy;
}

int Command::dummy(void)
{
    cout << "Dummy Called" << endl;
    return 0;
}


