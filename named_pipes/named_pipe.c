#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
 
int main()
{
    int fd;
 
    // FIFO file path
    char * myfifo = "/tmp/myfifo";
 
    // Creating the named file(FIFO)
    // mkfifo(<pathname>, <permission>)
    mkfifo(myfifo, 0666);

	perror("");
 
    char arr1[80], arr2[80];
        // Open FIFO for write only
        fd = open(myfifo, O_WRONLY);
	perror("");
 
        // Take an input arr2ing from user.
        // 80 is maximum length
        fgets(arr2, 80, stdin);
	perror("");
 
        // Write the input arr2ing on FIFO
        // and close it
        write(fd, arr2, strlen(arr2)+1);
	perror("");
        close(fd);
 
        // Open FIFO for Read only
        fd = open(myfifo, O_RDONLY);
	perror("");
 
        // Read from FIFO
        read(fd, arr1, sizeof(arr1));
	perror("");
 
        // Print the read message
        printf("User2: %s\n", arr1);
        close(fd);
    return 0;
}
