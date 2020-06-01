// BuildNumber.cpp : Defines the entry point for the console application.
//
#include "stdio.h"
#include "string.h"
#include "ctype.h"
#include "stdlib.h"
#include <wchar.h>
#include <locale.h>
#include <fstream>

using namespace std;
//#define MAXPATH 1024
//#define MAXLINE 1024

char* itoaj(int num, char* str, int base);

int main(int argc, char* argv[])
{
    char filename[1024];
    char buffer[1024];
    char * pstr;
    char * posc;
    unsigned int number;
    int n;
    int i;
    ifstream fp;
    ofstream fo;
    int cp=0;

    setlocale (LC_CTYPE, "Spanish");

    strcpy(filename,"buildnumber.h");
    char linebuf[1024];
    int nBuild=1;
    if (argc>1)
    {
        char *cmd=argv[1];
        strncpy(filename,cmd,1023);
    }else return 0;
    printf("BuildNumber 2.0\n");

    printf(" J. Gambandé 2020\n");
    printf("Inspirado en trabajos de S. Gregory 2016\n");

    fp.open(filename);
    strcat(filename,".temp");
    fo.open(filename);

    if (fp.is_open())
    {
    	printf("\ns ");
       while(!fp.eof())
        {
        	printf("\n%i ",cp++);
            fp.getline(buffer,1000);
            printf("%s",buffer);
        	pstr= strstr(buffer,"#define BUILDNUMBER");
            if(pstr){
            	posc= (char*)(pstr + strlen("#define BUILDNUMBER") + 1);
            	number=atoi(posc);
            	number++;
            	itoaj(number,posc,10);
        	}
            fo.write(buffer,strlen(buffer));
            fo.put('\n');
			printf("\n5 ");
        }

        fo.close();
        fp.close();

        for(i=strlen(filename); i>0; i--){
        	if(filename[i]=='.')break;
        }
        filename[i]=0;
        strcpy(buffer,"DEL ");
        strcat(buffer,filename);
        printf("\n%s\n",buffer);
        system(buffer);                   // borrar el original
        filename[i]='.';

        strcpy(buffer,filename);
        printf("\n%s\n",buffer);
        filename[i]=0;
        rename(buffer,filename);				// cambia nombre

    }
    else
    {
        return 0;
    }
    return -3;
}
