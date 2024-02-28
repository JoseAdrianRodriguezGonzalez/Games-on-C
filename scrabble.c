#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char* Text(int a);
int CalculateWord(char *Word);
char* ConvertLowerCase(char *Word);
void Winner(int a,int b);
/*
A=1
B=3
C=3
D=2
E=1
F=4
G=2
H=4
I=1
J=8
K=5
L=1
M=3
N=1
O=1
P=3
Q=10
R=1
S=1
T=1
U=1
V=4
W=4
X=8
Y=4
Z=10
*/
int main(int argc,char** argv){
/*Establish the vector with the values*/
       /**We need to require our data*/
    char *Word1=Text(1);
    char *Word2=Text(2);
    Winner(CalculateWord(Word1),CalculateWord(Word2));
    free(Word1);
    free(Word2); 
    return 0;
}
char* Text(int a){
    int n=100;
    char *Word= (char*)malloc( n*sizeof(char));
    if(Word==NULL){
        fprintf(stderr,"Error: Unable to allocate memory\n");
        exit(EXIT_FAILURE);
    }
    printf("Write your word player %d:",a);
    fgets(Word,n,stdin);
    return Word;
}
int CalculateWord(char *Word){
    int a=0, result=0;
    char letters [26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    int values[26]={1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10};
    char *ptr=ConvertLowerCase(Word);
    while(*ptr!='\0'){
        char *ptr1=strchr(letters,*ptr);
        if(ptr1!=NULL){
            a=values[ptr1-letters];
            result+=a;
        }
        ptr++;
    }
    return result;
}
char * ConvertLowerCase(char *Word){
    char *ptr=Word;
    if(*ptr!='\0'){
        if(*ptr>=65&&*ptr<=90){
            *Word=*ptr+32;
        }
        ConvertLowerCase(ptr+1);
    }
    return Word;
}
void Winner(int a,int b){
    if(a==b){
        printf("Tie");
    }else if(a>b){
        printf("The winner is the player 1");
    }else{
        printf("The winner is the player 2");
    }
}
