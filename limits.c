#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <limits.h>
static void pr_sysconf(char *mesg,int name)
{
    long val;

    fputs(mesg,stdout);
    errno=0;
    if((val=sysconf(name))<0)
    {
    if(errno!=0)
    {
        if(errno==EINVAL)
            fputs(" (not supported)/n",stdout);
        else
        {
        perror("sysconf");
        exit(1);
        }
    }
    }
    else
    printf(" %ld/n",val);
}
static void pr_pathconf(char *mesg,char *path,int name)
{
    long val;

    fputs(mesg,stdout);
    errno=0;
    if((val=pathconf(path,name))<0)
    {
    if(errno!=0)
    {
        if(errno==EINVAL)
            fputs(" (not supported)/n",stdout);
        else
        {
            perror("pathconf");
            exit(1);
        }
    }
    //does not setting the errno ,so the system does not
        //give this var a limit
    else
        fputs(" (no limit)/n",stdout);
    }
    else
    printf(" %ld/n",val);
}
void fatal(char *mes)
{
    perror(mes);
    exit(1);
}
int main(int argc,char **argv)
{
    if(argc!=2)
    {
    fprintf(stderr,"usage :%s dirname/n",argv[0]);
    exit(1);
    }
#ifdef ARG_MAX
    printf("ARG_MAX defined  be %d/n",ARG_MAX+0);
#else
    printf("no symbol for ARG_MAX/n");
#endif
#ifdef _SC_ARG_MAX
    pr_sysconf("ARG_MAX = ",_SC_ARG_MAX);
#else
    printf("no symbol for _SC_ARG_MAX/N");
#endif

#ifdef MAX_CANON
    printf("MAX_CANON defined o be %d/n",MAX_CANON+0);
#else
    printf("no symbol for MAX_CANON/n");
#endif
#ifdef _PC_MAX_CANON
    pr_pathconf("MAX_CANON = ",argv[1],_PC_MAX_CANON);
#else
    printf("no symbol for _PC_MAX_CANON/n");
#endif

    exit(0);
}
