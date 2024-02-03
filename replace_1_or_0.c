#include<stdio.h>
#include<string.h>
char str[100];

void generate_combinations(char *str, int index){
    if(str[index] == '\0'){
        printf("%s\n", str);
        return;
    }
     if(str[index] == '?'){
        str[index] = '0';//replace '?' with '0'
        printf("Index after str[index]='0' = %d\n", index);
        generate_combinations(str, index+1);
        printf("Index after function call after str[index]='0' = %d\n", index);

        str[index] = '1';//replace '?' with '1'
        printf("Index after str[index]='1' = %d\n", index);
        generate_combinations(str, index+1);
        printf("Index after function call after str[index]='1' = %d\n", index);

        str[index] = '?';
        printf("Index after str[index]='?' = %d\n", index);
     }
     else{
        generate_combinations(str, index+1);
     }
}

int main(){
    printf("Enter a string : ");
    scanf("%[^\n]s",str);

    printf("\nCombinations are : \n");
    generate_combinations(str, 0);

    return 0;
}