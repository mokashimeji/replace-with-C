/*
After searching specific string, replacing it with other string .
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char *input(char *str,int sizeof_str);
char *replace(char *src , char *key ,char *sub, char *new, int sizeof_new);


int main(){
  char src[]="abcdefghijkhijkabcmlnopqabcdemlnhij";
  char key[20]; //str to search
  char sub[20]; //substitute
  char new[100]; //str after replasing key with sub
  char *p_key;
  char *p_sub;
  char *p_new;

  printf("key (serch for ...) : ");
  p_key=input(key,sizeof(key));

  printf("sub (replace with ... ) : ");
  p_sub=input(sub,sizeof(sub));

  p_new=replace(src,p_key,p_sub,new ,sizeof(new));
  printf("\n\nresult : %s",p_new);

}

char *input(char *str , int sizeof_str){
  char *buff;
  buff=fgets(str,sizeof_str,stdin);
  buff[strcspn(buff,"\n")]=0;
  return buff;
/*
Giving sizeof(str) as the 2st argument of fgets() , does not make sense.
Becsuse str is just a pointer.
So istead of giving sizeof(str), give integer itself ,which includeing the sizeof(argument).

*/
}

char *replace(char *src , char *key ,char *sub, char *new ,int sizeof_new){

  char *p_src;
  int counter;
  int len_src=strlen(src);
  int len_key=strlen(key);
  int len_sub=strlen(sub);
  char *p_new;
  p_new=new;

  printf("\nsrc=%s\nkey=%s\nsub=%s\n",src,key,sub);

  printf("\nlen_src=%d  len_key=%d\n",len_src,len_key);
  printf("the last letter of src = %c[%p]\nthe last letter of key = %c[%p]\n\n",*(src+len_src-1),(src+len_src-1),*(src+len_key-1),(src+len_key-1)); //they are the characters located at the end of each strins.


  while(*src!='\0'&&p_new+sizeof_new-1>new){
    printf("*src = %c\n",*src);
    printf("p_new+sizeof_new-1 = %p    new = %p \n",p_new+sizeof_new-1,new);

    if(strncmp(src,key,len_key)==0){ //the case where key is included in src
      printf("gaccha!!\n");

        if(p_new+sizeof_new-1>=new+len_sub){  //the case where key is included in src, AND there is enough spaace to store sub instead of key in str
          strcpy(new,sub);
          new+=len_sub;
          printf("remaining : %d",p_new+sizeof_new-new);
        }

        else{                                 //the case where key is included in src, BUT there is NOT enough space to store any letters in str.
          strncpy(new,sub,sizeof_new-(new-p_new)-1);
          new+=sizeof_new-(new-p_new)-1;
        }

        src+=len_key;    //No matter whether if get excuted or else get excuted

    }

    else{
      *new=*src;
      src++;
      new++;
    }

  }
  *new='\0';

  return p_new;


/*for loop : dosent work well
    for(p_src=src,counter=0 ; src+len_src>=p_src+len_key ; p_src++,counter++){
    printf("counter : %3d\n",counter);
    printf("src=%30s  :  p_src(+ %d )=%30s  :  strncmp(p_src,key,strlen(key) = %5d\n\n",src,counter,p_src,strncmp(p_src,key,strlen(key)));
    if(strncmp(p_src,key,strlen(key))==0){
      printf("Detected!! \n\n");
    }
  }
*/

}
