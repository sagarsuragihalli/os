#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main () {
  int fd1;
  char buf [100];

  fd1 = open ( "/tmp/myfifo", O_RDONLY ); 
while(1){
  read ( fd1, buf, 100 ); 
  printf ( "%s\n", buf ); 
	sleep(1);
}
	getchar();
  close (fd1);

} 
