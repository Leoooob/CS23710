/* 
 * File:   main.cpp
 * Author: kis12
 *
 * Created on 04 December 2014, 14:08
 */

#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
/*
 * 
 */
int main(int argc, char** argv) {
    char ch, file_name[25];
    FILE *fp;
    
    printf("Please enter the name of the file \n");
    gets(file_name);
    fp=fopen(file_name,"r");
    
    if(fp==NULL)
    {
        perror("Could  not open the file \n");
        exit(EXIT_FAILURE);
    }
    printf("This file %s contains: \n",file_name);
    
    while((ch=fgetc(fp))!=EOF)
        printf(%c,ch);
    
    fclose(fp);
    return 0;
}

