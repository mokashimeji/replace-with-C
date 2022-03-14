/*
After searching specific string, replacing it with other string .
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char *replace(char *src , char *key ,char *sub);
char *input(char *str);

int main(){
  char src[]="abcdefghijkhijkabcmlnopqabcdemlnhij";
  char *p_key;
  char key[20]; //str to search
  char sub[20]; //substitute
  char new[100]; //str after replasing key with sub

  printf("key : ");
  p_key=input(key);
  printf("%s",p_key);


}

char *input(char *str){
  char *backstr;
  backstr=fgets(str,sizeof(str),stdin);
  return backstr;
}
