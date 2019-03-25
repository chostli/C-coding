/****************************
*程序名称：ch05.c
*功能：配合测试ioctl.c
*作者：lpj
*时间： 2019/3/22 9:50:59
*****************************/
#include <linux/cdrom.h>
#include "public.h"
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>

int ch05()
{
	/*打开设备文件*/
	int fd=0;
	
	fd=open("/dev/cdrom",O_RDONLY);
	if(fd<0)
	{
		fprintf(stderr,"打开 cdrom失败【%s】\n",strerror(errno));
		return -1;	
	}	
	/*开始弹出和关闭CDROM*/
	if(!ioctl(fd,CDROMEJECT,NULL))
	{
		printf("成功弹出CDROM\n");	
	}else{
		printf("弹出CDROM失败\n");	
	}
	return 0;
}