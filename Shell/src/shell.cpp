#include "shell.hpp"

int dev::Shell::job(char **)
{
    return 0;
}

dev::Shell::Shell()
{
}

void dev::Shell::start(void)
{
}

char *dev::Shell::read(void)
{
    return nullptr;
}

char **dev::Shell::spilt(char *)
{
    return nullptr;
}

int dev::Shell::execute(char **)
{
    return 0;
}

int dev::Command::help(char **args)
{
    return 0;
}

int dev::Command::cd(char **args)
{
    return 0;
}

int dev::Command::shell_exit(char **args)
{
    return 0;
}

dev::Command::Command()
{
}
