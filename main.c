#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct word{
    char letters[20];
    struct word*next;
}word;

word*push(word*begin,char*str){
    word*p=(word*)malloc(sizeof(word));
    p->letters[0]='\0';
    strcat(p->letters,str);
    p->next=begin;
    begin=p;
    return begin;
}


void wordsPrint(word*begin){
    while(begin->next!=NULL){
        printf("%s\n",begin->letters);
        begin=begin->next;
    }
}

word*findFirst(word*begin){
    if(begin==NULL){
        return NULL;
    }
    word*p=NULL;
    while(begin->next!=NULL){
        p=begin;
        begin=begin->next;
    }
    return p;
}

int main()
{
    printf("Hello world!\n");

    //1
    char str[80]={0};
    int flag=1,size=0;

    word*begin=(word*)malloc(sizeof(word));
    begin->next=NULL;
    strcat(begin->letters,"end");

    printf("Enter string\n");
    while(flag==1){
        scanf("%s",str);
        //printf("While: %s\n",str);
        size=strlen(str);
        if(str[size-1]=='.'){
            flag=0;
            str[size-1]='\0';
        }
        begin=push(begin,str);
    }
    wordsPrint(begin);
    word*p=findFirst(begin);

    printf("First word is: %s\n",p->letters);
    printf("Last word is: %s\n",begin->letters);


    return 0;
}
