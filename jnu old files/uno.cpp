#include<stdio.h>
#include<string.h>

void findUnion(char str1[], char str2[]) {

    int f, p = 0;
    int i, j;

    char str3[100];
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    while (str1[p] != '\0') {
        str3[p] = str1[p];
        p++;
    }

    for (i = 0; i < len2; i++) {
        f = 0;
        for (j = 0; j < len1; j++) {
            if (str2[i] == str1[j]) {
                f = 1;
            }
        }
        if (f == 0) {
            str3[p] = str2[i];
            p++;
        }
    }
    str3[p] = '\0';
    printf("\nUnion of Two String :%s", str3);
}

void findIntersection(char str1[], char str2[]) {

    int i, j, k = 0;
    char str3[100];

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    for (i = 0; i < len1; i++) {
        for (j = 0; j < len2; j++) {
            if (str1[i] == str2[j]) {
                str3[k] = str1[i];
                k++;
            }
        }
    }
    str3[k] = '\0';
    printf("\nIntersection of Two String :%s", str3);
}

int main() {

    char str1[100];
    char str2[100];
    char str3[100];

    printf("Enter First String :");
    gets(str1);

    printf("\nEnter Second String :");
    gets(str2);

    findUnion(str1, str2);
    findIntersection(str1, str2);

    return 0;
}

            
            
