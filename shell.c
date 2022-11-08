#include <stdlib.h>
#include <stdio.h>
#include <string.h>



int main(int argc, char **argv)
{

    char *shell  = getenv("SHELL");
    if(shell){
	printf("%x\n", (unsigned int)shell);
	}

    return 1;
}