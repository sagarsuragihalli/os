#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char phrase[50];// = "Stuff this in your pipe";

int main () {
  int fd1; 
  while(1){
  scanf("%s",phrase);
  fd1 = open ("mypipe", O_WRONLY|O_CREAT,0777 ); 
  write (fd1, phrase,50); //strlen ( phrase)+1 ); 
  close (fd1);
 }
}
