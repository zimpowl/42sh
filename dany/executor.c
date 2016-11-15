#include "executor.h"

struct values
{
  int value;
  char *buff;
};

int exec(char *args[])
{
  int status;
  pid_t pid = fork();
  if (pid == -1)
    exit(EXIT_FAILURE);
  else if (pid > 0)
  {
    waitpid(-1, &status, 0);
    return WEXITSTATUS(status) & 0x7F;
  }
  else
  {  
    status = execvp(args[0], args);
    exit(status);
  }
  if (WIFEXITED(status))
    exit(WEXITSTATUS(status));
  exit(EXIT_FAILURE);
}

int exec_pipe(char **args[])
{
  int i = 0;
  int j = 0;
  while (args[i])
  {
    while (args[i][j])
    {
      printf("%s ", args[i][j]);
      j++;
    }
    printf("\n");
    j = 0;
    i++;
  }
  printf("\n");
  /////


  i = 0;
  int ins[2];
  //int outs[2];
  pipe(ins);
  //pipe(outs);
  //char buff[200];

  while (args[i])
  {
    int status;
    pid_t pid = fork();
    if (pid == -1)
      exit(EXIT_FAILURE);
    else if (pid == 0)
    {
      dup2(0, ins[0]);
      //dup2(1, outs[1]);
      status = execvp(args[i][0], args[i]);
      exit(status);
    }

    write(ins[1], "hey\n", 4);
    close(ins[0]);
    close(ins[1]);

    //read(outs[0], &buff, 200);
    //printf("%s\n", buff);
    //close(outs[0]);
    //close(outs[1]);
    waitpid(-1, &status, 0);
    
    //return WEXITSTATUS(status) & 0x7F;
    //if (WIFEXITED(status))
     // exit(WEXITSTATUS(status));
   // exit(EXIT_FAILURE);*/
    i++;
  }
  return 0;//res;
}

  

int main(void)
{
  /*if (argc > 0)
  {
    char *arg1[argc];
    arg1[argc - 1] = NULL;
    for (int i = 1; i < argc; ++i)
      arg1[i - 1] = argv[i];
    char ***args = malloc(sizeof (char **) * 4);
    char *arg2[] = { "more", NULL };
    //char *arg3[] = { "echo", "ok", NULL };

    args[0] = arg1;
    args[1] = arg2;
    //args[2] = arg3;
    args[2] = NULL;
    int res = exec_pipe(args);
    return res;
  }*/

  char ***args = malloc(sizeof (char **) * 3);
  char *arg1[] = { "more", NULL };
  //char *arg2[] = { "more", NULL };
  args[0] = arg1;
  args[1] = NULL;//arg2;
  //args[2] = NULL;
  
  int res = exec_pipe(args);
  return res;
}
       
