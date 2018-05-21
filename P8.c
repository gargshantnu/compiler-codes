#include<stdio.h>
#include<conio.h>
#include<string.h>
void main() {
    char ch;
    int space = 0, newline = 0;
    printf("Enter a string(press @ to quit entering):\n");
    scanf("%c", &ch);
    while(ch!='@') {
        if(ch==' ')
            space++;
        if(ch=='\n') {
            newline++;
        }
        scanf("%c", &ch);
    }
    printf("The number of lines used : %d\n", newline);
    printf("The number of spaces used is : %d\n", space);
}
