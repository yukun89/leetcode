#include <string.h>
#include <stdio.h>
 
int main(){
    char s[] = "a,b*c,d";
    const char *sep = ",*"; //可按多个字符来分割
    char *p;
    p = strtok(s, sep);
    while(p){
        printf("%s ", p);
        p = strtok(NULL, sep);
    }
    printf("\n");
    return 0;
}
