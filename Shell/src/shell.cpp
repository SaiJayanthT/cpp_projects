#include "shell.hpp"

// Shell Class
Shell::Shell()
{
    commandObject = new Command();
    cout << "#################################################" << endl;
    cout << "############## WELCOME TO SHELL #################" << endl;
    cout << "#################################################" << endl;

    cout << "+++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "+++++++++++++++ AVAILABLE COMMANDS ++++++++++++++" << endl;
    for (pair<string, commandFuncPtr> p : commandObject->availableCommands){
        cout << ">> " << p.first << endl;
    }
    cout << "+++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
}

Shell::~Shell()
{
    delete commandObject;
    cout << "#################################################" << endl;
    cout << "############## SHELL EXIT #######################" << endl;
    cout << "#################################################" << endl;
}


void Shell::start(void)
{
    do{
        cout << "C++@SHELL MINGW64 (CUSTOM MADE)" << endl;
        cout << "$ ";
        read();
        cmdStatus = execute();
        // Clear
        commands.clear();

    }while(cmdStatus);
}

void Shell::read(void)
{
    // Read commands in cin
    getline(cin, userInput);

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

    return (commandObject->*func)();
}


// Command Class
Command::Command()
{
    availableCommands["exit"] = Command::exit;
    availableCommands["hello"] = Command::hello;
    
}


int Command::exit()
{
    return 0;
}

int Command::hello(void)
{
    cout << "Hello Sir/Madam." << endl;
    return 1;
}

commandFuncPtr Shell::get_cmd(void)
{
    for (pair<string, commandFuncPtr> p : commandObject->availableCommands){
        if (p.first == commands[0])
        {
            return p.second;
        }

    }
    return &Command::invalidCommand;
}

int Command::invalidCommand(void)
{
    cout << "!!! Received Invalid Command. Please Try Again !!! \n" << endl;
    return 1;
}


