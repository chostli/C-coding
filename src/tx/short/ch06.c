#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "public.h"
int print1()
{
	printf("��ð�\n");
	return 0;	
}
int ch06()
{
	int handle;
	int ret=0;
	char repos[2]; /*�ļ�����*/
	
	struct stat sStat;
	
	memset(&sStat,0x00,sizeof(sStat));
	memset(repos,0x00,sizeof(repos));
	handle=open("./test",O_RDWR);
	if(handle<0)
	{
		printf("���ļ����ʧ��[%s]",strerror(errno));
		return 1;	
	}
	printf("ch6\n");
	/*��ȡ�ļ�����*/
	fstat(handle,&sStat);
	ret=GetFileType(sStat.st_mode,repos);
	if(ret)
	{
		printf("��ȡ�ļ�������Ϣʧ�ܡ�%s��",strerror(errno));
		return 1;	
	}
	else
	{
		printf("��ȡ�ļ���������[%s]",repos);	
	}
	close(handle);
	return 0;	
}
