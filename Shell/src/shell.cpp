#include "shell.hpp"

// Shell Class
Shell::Shell()
{
    command = new Command();
    cout << "#################################################" << endl;
    cout << "############## WELCOME TO SHELL #################" << endl;
    cout << "#################################################" << endl;

    cout << "+++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "+++++++++++++++ AVAILABLE COMMANDS ++++++++++++++" << endl;
    for (pair<string, commandFuncPtr> p : command->bucket){
        cout << ">> " << p.first << endl;
    }
    cout << "+++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
}

Shell::~Shell()
{
    delete command;
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
        command->status = execute();

        // Clear
        command->name = " ";
        command->args.clear();

    }while(command->status);
}

void Shell::read(void)
{
    stringstream buffer;
    string userInput, args;

    // Read commands in cin
    getline(cin, userInput);

    buffer << userInput;

    getline(buffer, command->name, ' ');

    while (getline(buffer, args, ' ')){
        command->args.push_back(args);
    }

}

int Shell::execute()
{

    int(Command::*func)(void) = (*command)();

    return (command->*func)();
}



// Command Class
Command::Command()
{
    bucket["exit"] = Command::exit;
    bucket["hello"] = Command::hello;
    bucket["add"] = Command::add;
    
}


int Command::exit()
{
    return 0;
}

int Command::hello(void)
{
    cout << "Hello World!." << endl;
    return 1;
}

int Command::add(void)
{
    int num1 = stoi(args[0]);
    int num2 = stoi(args[1]);
    cout << num1 << " + " << num2 << " = " << (num1 + num2) << endl;
    return 1;
}

commandFuncPtr Command::operator()(void)
{
    for (pair<string, commandFuncPtr> p : bucket){
        if (p.first == name)
        {
            return p.second;
        }

    }
    return Command::invalidCommand;
}

int Command::invalidCommand(void)
{
    cout << "!!! Received Invalid Command. Please Try Again !!! \n" << endl;
    return 1;
}

