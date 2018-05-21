#include<stdio.h>
#include<string.h>
char *p;
e();
t();
main() {
    int i, j=0, n, b[10], k=0;
    char a[10], c[10];
    printf("Enter the string\n");
    scanf("%s", a);
    for(i = 0, j = 0; i<strlen(a); i++) {
        switch(a[i]) {
            case '+' :
            case '-' :
                c[j] = a[i];
                b[j] = 1;
                j++;
                break;
            case '*' :
            case '/' :
                c[j] = a[i];
                b[j] = 2;
                j++;
                break;
            case '^' :
                c[j]=a[i];
                b[j]=3;
                j++;
                break;
            default :
                if(k==0) {
                    k = 1;
                    c[j] = a[i];
                    b[j] = 4;
                    j++;
                }
        }
    }
    c[j] = '$';
    b[j] = 0;
    j++;
    printf("\n\n");
    printf("\n\t----------------------------------");
    printf("\n\n");
    for(i=0; i<j; i++)
        printf("\t%c", c[i]);
    printf("\t");
    for(i=0; i<j; i++) {
        printf("\n\t---------------------------------");
        printf("\n\n%c",c[i]);
        for(n=0;n<j;n++) {
            if(b[i]<b[n])
                printf("\t<");
            if(b[i]>b[n])
                printf("\t>");
            if(b[i]==b[n])
                printf("\t=");
        }
        printf("\t");
    }
    printf("\n\t--------------------------------------");
    p = a;
    if(e())
        printf("\n\nString parsed");
    else
        printf("\nString not parsed");
    return 0;
}
int e() {
    if(*p=='i') {
        p++;
        t();
        t();
    }
    else
        return 0;
}
int t() {
    if(*p==NULL)
        return 1;
    else if(*p=='+' || *p=='*') {
        p++;
        if(*p=='i')
            p++;
        else
            return 0;
    }
    else
        return 0;
}
