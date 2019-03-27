/****************************
*程序名称：ch04.c
*功能：配合测试fctl.c
*作者：lpj
*时间： 2019/3/22 9:50:59
*****************************/
#include "public.h"
int ch04(void)
{
		int MYMODE ,val;
		int fd =open("test.txt",O_RDWR); /*打开一个文件*/
		printf("打开的文件id【%d】\n\a",fd);
		
		/*获得文件状态*/
		val=fcntl(fd,F_GETFL,0);
		MYMODE=val & O_ACCMODE;
		if(MYMODE==O_RDONLY){
			printf("这个文件有读权限\n");
			
		}
		else if(MYMODE==O_WRONLY)
		{
			printf("这个文件有写权限\n");
			
		}
		else if(MYMODE==O_RDWR)
		{
			printf("这个文件可读可写权限\n");
		
		}
		else
		{
			printf("莫名的文件状态，请检查[%d]\n",MYMODE);	
			
		}
		close(fd);
		return 0;
}
