#include<stdio.h>
#include<conio.h>
char ch, first[10], stack[10];
int i, j, k;
void main() {
    FILE *fp;
    fp = fopen("in txt","w");
    printf("Enter the productions..\n");
    while(((ch=getchar())!='@'))
        putc(ch, fp);
    fclose(fp);
    fp = fopen("in txt","r");
    i = 0;
    while(!(feof(fp))) {
        ch = fgetc(fp);
        if(feof(fp))
            break;
        first[i++] = ch;
        while(ch!='\n')
            ch = fgetc(fp);
    }
    rewind(fp);
    i = 0;
    j = 0;
    while(first[i]!='\0') {
        ch = getc(fp);
        if(ch==first[i])
            stack[j] = '$';
        else
            while(!(feof(fp))) {
                while(ch!='>')
                    ch = getc(fp);
                while(ch!=first[i]) {
                    if(feof(fp))
                        goto down;
                    ch = fgetc(fp);
                }
                ch = fgetc(fp);
                stack[j] = ch;
                down :
                    j++;
            }
        print();
        i++;
    }
}
print() {
    printf("FOLLOW[%c]={", first[i]);
    for(k=0; stack[k]!='\0'; k++)
        printf("%c",stack[k]);
    printf("}\n");
    return 0;
}
