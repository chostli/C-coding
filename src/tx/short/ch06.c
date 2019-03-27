#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "public.h"
int print1()
{
	printf("你好啊\n");
	return 0;	
}
int ch06()
{
	int handle;
	int ret=0;
	char repos[2]; /*文件属性*/
	
	struct stat sStat;
	
	memset(&sStat,0x00,sizeof(sStat));
	memset(repos,0x00,sizeof(repos));
	handle=open("./test",O_RDWR);
	if(handle<0)
	{
		printf("打开文件句柄失败[%s]",strerror(errno));
		return 1;	
	}
	printf("ch6\n");
	/*获取文件属性*/
	fstat(handle,&sStat);
	ret=GetFileType(sStat.st_mode,repos);
	if(ret)
	{
		printf("获取文件属性信息失败【%s】",strerror(errno));
		return 1;	
	}
	else
	{
		printf("获取文件属性类型[%s]",repos);	
	}
	close(handle);
	return 0;	
}
