#include "shell.hpp"

void logger(std::string data){
    std::cout << "<log> " << data << " </log>" << std::endl;
}


Shell::Shell()
{
    logger("Shell Created");
}

int Shell::job(std::string)
{
    return 0;
}

void Shell::start(void)
{
    do{
        std::cout << "C++@SHELL MINGW64 (CUSTOM MADE)" << std::endl;
        std::cout << "$ ";
        read();
        split();
    }while(1);
}

void Shell::read(void)
{
    // Read commands in cin
    getline(std::cin, line);
    std::cout << line << std::endl;

}

void Shell::split()
{
    std::stringstream buffer;
    buffer << line;
    std::string cmd;

    while (getline(buffer, cmd, ' ')){
        commands.push_back(cmd);
    }

    for (std::string& c: commands){
        std::cout << c << std::endl;
    } 
    std::cout << std::endl;
}

int Shell::execute(char **)
{
    return 0;
}

int Command::help(char **args)
{
    return 0;
}

int Command::cd(char **args)
{
    return 0;
}

int Command::shell_exit(char **args)
{
    return 0;
}

Command::Command()
{
}
