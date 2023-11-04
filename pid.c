
#include "main.h"
/**
  *_pid- functtion that generates pareent process iID in a shell
  *and it should return the smae output vas long as it is sti,ill
  *in the same shell.
  *pid_t: called function.
  *Return: the eprocess ID.
  */
int _pid(void)
{
	pid_t my_parent_pID = getppid();
	char pID[25];

	snprintf(pID, sizeof(pID), "%d\n", my_parent_pID);


	write(1, pID, strlen(pID));
	return (0);
}

