#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    int fd;
    char buf[50];
    char * myfifo = "/tmp/myfifo";

    /* create the FIFO (named pipe) */
    mkfifo(myfifo, 0666);

    /* write "Hi" to the FIFO */
    fd = open(myfifo, O_WRONLY);
	while (1)
	//scanf("%s",buf);
    write(fd, "hello", sizeof("hello"));
    close(fd);

    /* remove the FIFO */
    unlink(myfifo);

    return 0;
}
