#include <stdio.h>

int main(int argc, char *argv[])
{

	if (argc == 2) 
	{
		printf("hello, %s\n", argv[1]);
	} else if (argc == 3)
	{
		printf("hello, %s and %s\n", argv[1], argv[2]);
	}

	return(0);
}


