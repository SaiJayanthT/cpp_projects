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
        commandStatus = execute();

        // Clear
        commandName = " ";
        commandObject->commandArgs.clear();

    }while(commandStatus);
}

void Shell::read(void)
{
    stringstream buffer;
    string args;

    // Read commands in cin
    getline(cin, userInput);

    buffer << userInput;

    getline(buffer, commandName, ' ');

    while (getline(buffer, args, ' ')){
        commandObject->commandArgs.push_back(args);
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
    availableCommands["add"] = Command::add;
    
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

int Command::add(void)
{
    int num1 = stoi(commandArgs[0]);
    int num2 = stoi(commandArgs[1]);
    cout << num1 << " + " << num2 << " = " << (num1 + num2) << endl;
    return 1;
}

commandFuncPtr Shell::get_cmd(void)
{
    for (pair<string, commandFuncPtr> p : commandObject->availableCommands){
        if (p.first == commandName)
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


