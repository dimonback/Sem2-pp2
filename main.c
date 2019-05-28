#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    FILE *fp;
    char* temp;
    char *getWordfrom(FILE *fp);
    
    if (argc != 2)
    {
        printf("Usage: %s filename",argv[0]);
        exit(-2);
    }
    
    if ((fp = fopen(argv[1], "r"))==NULL)
    {
        printf("Error while opening file.\n");
        exit(-3);
    }

    temp = getWordfrom(fp);
    
    while(temp!= NULL){
         binary(temp);
         res(temp);
    }
    
     printf(" ", res(temp));
}


int issep(char c)
{
    if (c == ' ' || c == '\n'|| c == '\t')
        return(1);
    return(0);
}


int binary(char* s)
{
    int bin = 0;
    while (*s)
    {
        bin |= (1 << (tolower(*s)-'a'));
        s++;
    }
    return(bin);
}


int res(int bin)
{
    static char s[26];
    int w = bin;
    int j=0;
    
    while (w>0)
    {
        if (w&1)
            s[j++] = s[j++] + 1;
        w = w >> 1;
    }
    return(s);
}


char *getWordfrom(FILE *fp)
{
    static char buffer[64];
    int i = 1;
    while(issep(buffer[0] = fgetc(fp)));
    
    if(buffer[0] == EOF)
        return NULL;
    
    while(!issep(buffer[i] = fgetc(fp)))
        i++;
    
    buffer[i] = '\0';
    return buffer;
}
