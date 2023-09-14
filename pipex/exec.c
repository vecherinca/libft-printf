#include "pipex.h"

void init_child(int count, t_pipex pipex, char **env, t_a_list *cmd)
{
	int fd[2];
	pipe(fd);
	pid_t pid; 
	pid = fork();
	if (pid == 0)
	{
		if (count == 0)
		{
			dup2(pipex.file1, STDIN_FILENO);
			dup2(fd[1], STDOUT_FILENO);
		}
		if (count == pipex.cmd_count - 1)
			dup2(pipex.file2, STDOUT_FILENO);
		else
			dup2(fd[1], STDOUT_FILENO);
		execve(cmd -> path, cmd ->cmd, env);
		close(fd[0]);
	}
	else
	{
		wait(NULL);
		dup2(fd[0], STDIN_FILENO);
		close(fd[1]);
		close(fd[0]);
	}	
}

void execute(t_pipex pipex, char **env)
{
	int i = 0;
	t_a_list *cmd;
	cmd = pipex.cmd -> first;
	while (cmd != NULL)
	{
		init_child(i, pipex, env, cmd);
		cmd = cmd -> next;
		i++;
	}
	
}