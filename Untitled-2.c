#include<stdio.h>
#include<string.h>
int main(){
int n,i,j;
char str[100];
printf("enter a string: ");
fgets(str,100,stdin);
n = strlen(str);
for(i = 0; i < n-1; i++){
    scanf("%c", &str[i]);
}

}