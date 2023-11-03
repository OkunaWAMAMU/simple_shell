#include <stdio.h>
#include <unistd.h>
/**
  *main- functtion that generates pareent process iID in a shell 
  *and it should return the smae output vas long as it is sti,ill
  *in the same shell.
  *@pid_t: called function.
  *Return: the eprocess ID.
  */
int main()
{
	pid_t my_parent_pID = getppid();
	
	printf("My parent process ID is %d\n", my_parent_pID);
	return (0);
}

