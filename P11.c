#include<stdio.h>
#include<conio.h>
char input[100];
char prod[100][100];
int pos=-1, l, st = -1;
char id, num;
void advance() {
    pos++;
    if(pos<l) {
        if(input[pos]>='0' && input[pos]<='9') {
            num = input[pos];
            id = '\0';
        }
        if((input[pos]>='a' || input[pos]>='A')&&
           (input[pos]<='z' || input[pos]<='Z')) {
            id = input[pos];
            num = '\0';
        }
    }
}
void E() {
    strcpy(prod[++st], "E->TE'");
    T();
    Ed();
}
void Ed() {
    int p = 1;
    if(input[pos]=='+') {
        p = 0;
        strcpy(prod[++st], "E'->+TE'");
        advance();
        T();
        Ed();
    }
    if(input[pos]=='-') {
        p = 0;
        strcpy(prod[++st], "E'->-TE'");
        advance();
        T();
        Ed();
    }
    if(p==1)
        strcpy(prod[++st], "E'->null");
}

void T() {
    strcpy(prod[++st], "T->FT'");
    F();
    Td();
}
void Td() {
    int p = 1;
    if(input[pos]=='*') {
        p = 0;
        strcpy(prod[++st],"T'->*FT'");
        advance();
        F();
        Td();
    }
    if(input[pos]=='/') {
        p = 0;
        strcpy(prod[++st], "T'->/FT'");
        advance();
        F();
        Td();
    }
    if(p==1)
        strcpy(prod[++st], "T'->null");
}
void F() {
    if(input[pos]==id) {
        strcpy(prod[++st], "F->id");
        advance();
    }
    if(input[pos]=='(') {
        strcpy(prod[++st], "F->(E)");
        advance();
        E();
        if(input[pos]==')')
            advance();
    }
    if(input[pos]==num) {
        strcpy(prod[++st], "F->num");
        advance();
    }
}
int main() {
    int i;
    printf("The grammar is\n");
    printf("E-> TE'\n");
    printf("E'-> +TE' | -TE' | null\n");
    printf("T-> FT'\n");
    printf("T'-> *FT'| /FT' | null\n");
    printf("F-> id/ (E)/ num\n");
    printf("Enter Input String ");
    scanf("%s", input);
    l = strlen(input);
    input[l] = '$';
    advance();
    E();
    if(pos==l) {
        printf("String Accepted\n");
        for(i = 0; i<=st; i++)
            printf("%s\n", prod[i]);
        }
    else
        printf("String rejected\n");
return 0;
}
























//#include<stdio.h>
//#include<conio.h>
//char *p;
//E();
//EP();
//T();
//F();
//TP();
//int main() {
//    printf("The grammar is\n");
//    printf("E->E+T/T\n");
//    printf("T->T*F/F\n");
//    printf("F->(E)/id\n");
//    printf("\n Enter the string to be parsed:");
//    scanf("%s", p);
//    if(E())
//        printf("\nString parsed");
//    else
//        printf("\nString not parsed");
//    return 0;
//}
//E() {
//    T();
//    if(EP())
//        return 1;
//    else
//        return 0;
//}
//EP() {
//    if(*p=='+') {
//        p++;
//        T();
//        EP();
//    }
//    else if(*p=='\0')
//        return 1;
//    else
//        return 0;
//}
//T() {
//    F();
//    if(TP())
//        return 1;
//    else
//        return 0;
//}
//TP() {
//    if(*p=='*') {
//        p++;
//        F();
//        TP();
//    }
//    else if(*p=='\0')
//        return 0;
//}
//F() {
//    if(*p=='i')
//        p++;
//    if(*p=='d')
//        p++;
//    else if(*p=='(') {
//        p++;
//        F();
//        F();
//    }
//    else if(*p==')')
//        p++;
//    else
//        return 0;
//}
