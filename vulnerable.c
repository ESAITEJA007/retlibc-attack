#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//VULNERABLE.C PROGRAM
int func(FILE *badfile)
{
    char buffer[19];

    fread(buffer, sizeof(char), 43, badfile);

    return 1;
}

int main(int argc, char **argv)
{
    FILE *badfile;
    setuid(0);


    badfile = fopen("badfile", "r");
    func(badfile);

    printf("Successs\n");
    fclose(badfile);
    return 1;
}