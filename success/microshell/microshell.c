#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

void ft_str(char *str)
{
    int i = 0;

    while(str[i])
    {
        write(2, &str[i], 1);
        i++;
    }
}

void cd(char **argv, int i)
{
    if(i != 2)
        return(ft_str("error: cd: bad arguments\n"));
    if(chdir(argv[1]) == -1)
    {
        ft_str("error: cd: cannot change directory to ");
        ft_str(argv[1]);
        ft_str("\n");
        return;
    }
}

void exec(char **argv, int i, char **env)
{
    int is_pipe = 0;
    int fd[2];
    int pid;

    if(argv[i] && !strcmp(argv[i], "|"))
        is_pipe = 1;
    if(is_pipe && pipe(fd) == -1)
        return(ft_str("error: fatal\n"));
    pid = fork();
    if(pid == -1)
        return(ft_str("error: fatal\n"));
    if(pid == 0)
    {
        argv[i] = 0;
        if(is_pipe)
        {
            if(dup2(fd[1], 1) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1)
            return(ft_str("error: fatal\n"));
        }
        execve(argv[0], argv, env);
        ft_str("error: cannot execute ");
        ft_str(argv[0]);
        ft_str("\n");
        return;
    }
    waitpid(pid, 0, 0);
    if(is_pipe)
    {
        if(dup2(fd[0], 0) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1)
        return(ft_str("error: fatal\n"));
    }
}

int main(int ac, char **argv, char **env)
{
    int i = 0;

    if (ac > 1)
    {
        while(argv[i] && argv[++i])
        {
            argv += i;
            i = 0;
            while(argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
                i++;
            if(!strcmp(argv[0], "cd"))
                cd(argv, i);
            else if(i)
                exec(argv, i, env);
        }
    }
    return(0);
}