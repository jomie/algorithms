/* Relevant:
http://www.cs.fsu.edu/~baker/devices/lxr/http/source/linux/drivers/s390/block/dasd_ioctl.c
parted sources: labels/dasd.c..
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <linux/fs.h>
#include <stdio.h>
#include <asm/dasd.h>

#ifndef BLKGETSIZE
#define BLKGETSIZE _IO(0x12,96)                   /* return device size */
#endif

#ifndef BLKPBSZGET
#define BLKSSZGET  _IO(0x12,104)/* get block device sector size */
#endif


int main(int argc, char **argv)
{
  int size;
  int logicalsectsize = 0, physicalsectsize=0;
  dasd_information_t dasd_info;

  int fd = open("/dev/dasda", O_RDONLY | O_NONBLOCK);

  if (ioctl(fd,  BLKPBSZGET, &physicalsectsize) < 0)
    {
      printf("Can't get physical sector size.\n");
    }


  if (ioctl(fd, BLKSSZGET, &logicalsectsize) < 0)
    {
      printf("Can't get logical sector size.\n");
    }

  printf("%d %d\n",physicalsectsize, logicalsectsize);


  /* s390 stuff */
  if(ioctl(fd,BIODASDINFO,&dasd_info) < 0){
    printf("BIODASDINFO call failed \n");
  }


  printf("Device number %u\n",dasd_info.dev_model);
  return 0;
}