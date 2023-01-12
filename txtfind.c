#include <stdio.h>
#include <string.h>
#define LINE 256
#define WORD 30

void print_lines();
void print_similar_words();
int getword();
int get_line();
int similar();
int substring();


int get_line(char s[]) {
    int i;
    for (i = 0; i<LINE; ++i)
    {
        if (scanf("%c",&s[i])==EOF)
        {
            s[i]='\0';
            break;
        }
        if (s[i]=='\n')
        {
            s[i]='\0';
            break;
        }
    }
    if (i == LINE){
       s[i-1]='\0';
    }
    return i;
}

int getword(char w[]) {
    int i;
    for (i = 0; i<WORD; ++i)
    {
        if (scanf("%c",&w[i])==EOF)
        {
            w[i]='\0';
            break;
        }
        if (w[i]=='\n') 
        {
            w[i]='\0';
            break;
        }
        if(w[i]=='\t')
        {
            w[i]='\0';
            break;
        }
        if(w[i]==' ')
        {
            w[i]='\0';
            break;
        }
    }
    if (i==WORD){
        w[i-1]='\0';
    }
    return i;
}

int substring(char * str1, char * str2) {
    int i,j;
    if(strlen(str2)>strlen(str1)){
        return 0;
    }
    for (i=0; i<=strlen(str1); ++i)
    {
        int count=0;
        for (j=0; j<=strlen(str2); ++j)
        {
            if (str2[j]==str1[i+j])
                count=count+1;
        }
        if (strlen(str2)<=count){
            return 1;
        }
    }
    return 0;
}

int similar(char *s, char *t, int n) {
    if (strlen(s)-strlen(t)!=n)
        return 0;
    int i,j;
    j=0;
    for (i=0; i<strlen(s); ++i)
    {
        if (j<strlen(t))
        {
           if (s[i]==t[j]){
            j=j+1;
           }
        }
    }
    if(strlen(t)==j){
    return 1;
    }
    return 0;
}

void print_lines(char * str) {
    char linearr[LINE];

    while(get_line(linearr))
    {
        if (substring(linearr, str))
            printf("%s\n", linearr);
    }
}

void print_similar_words(char * str) {
    char wordarr[WORD];

    while(getword(wordarr))
    {
        if (similar(wordarr, str, 0) || similar(wordarr, str, 1))
            printf("%s\n", wordarr);
    }
}

void main(){
char text[WORD];
char options = '\0';

    getword(text);
    printf("chose option between a or b");
    scanf(" %c\n", &options);

    if (options == 'a'){
        print_lines(text);
    }
    else{
     if (options == 'b'){
        print_similar_words(text);}
        else{
            printf("the option that you put not avalible");
        }
    }
}

