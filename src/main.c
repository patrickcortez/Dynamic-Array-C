#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "headers/d_array.h"


char* Lowered(char* string){
    int max=sizeof(string);
    for(int i=0;i<max;i++){
        string[i]=tolower(string[i]);
    }
    return string;
}

int Summation(char* string){
    int max=strlen(string),total=0;

    for(int i=0;i<max;i++){
        total += string[i];
    }
    return total;
}

int main(int argc,char** argv){

    char fallback[] = "None";
    char* command = (argc > 1)? Lowered(argv[1]): fallback;    

    // Dynamic array declaration
    D_array array= InitArray(5);


    if(strcmp(command,"push") == 0){
        Push_Back(&array,'c'); // 0
        Push_Back(&array,Summation(argv[2])); // 1
        Push_Back(&array,'a'); // 2
        Pop_Back(&array);
        Mod_At(&array,1,69); // argv[1] to 69

        printf("Pushed %i\n",Get(&array,1));
        
    }else{
        printf("Command %s, is not a valid command!\n",command);
    }

    return 0;

}