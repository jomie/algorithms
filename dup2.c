#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFMAXSIZE 4096

int main(int argc, char *argv[])
{
    int fd;
    int n;
    char buf[BUFMAXSIZE];
        
    if((fd = open("./fd_test.txt", O_RDWR )) == -1)
    {
        perror("open error!");
        return(1);
    }
    
    //dup2(fd,0);       
     dup2(0,fd);
    
    while((n = read(fd, buf, BUFMAXSIZE)) > 0)
    {
        printf("begin to read...\n");
        if(write(STDOUT_FILENO, buf, n) != n)
        {
            perror("write error!");
            return(1);
        }
        printf("end to write...\n");    
    }
    if(n < 0)
    {
        perror("read error");
        return(1);
    }

    return 0;
}