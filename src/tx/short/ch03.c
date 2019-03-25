#include <stdio.h>
#include <errno.h>
#include "public.h"
/**进行文件的拷贝功能*/
int main(int args, char **argv){
	int from_fd=0,to_fd=0; /*文件描述符*/
	int bytes_read=0,bytes_write=0; /*读出和写入的字节11数*/
	char * ptr;
	
	char buffer[BUFFER_SIZE];
	
	/*判断一下传入的参数够不够*/
	if(args!=3)
	{
		fprintf(stderr,"Usage:传入的参数不正确,[%s\n\a",strerror(errno));
		return -1;	
	}
	/*开始处理流程，先打开一个文件进行读取*/
	from_fd=open(argv[1],O_RDONLY);
	if(from_fd==-1)
	{
		fprintf(stderr,"打开文件失败【%s】\n\a",strerror(errno));
		return -1;	
	}
	to_fd=open(argv[2],O_CREAT|O_RDWR,0755);
	if(to_fd==-1)
	{
		fprintf(stderr,"打开文件失败【%s】\n\a",strerror(errno));
		return -1;		
	}
	/*开始读取数据*/
	while(bytes_read=read(from_fd,buffer,BUFFER_SIZE))
	{
			if(bytes_read==-1&&(errno!=EINTR))break;
			else if(bytes_read>0)
			{
				ptr=buffer;
				while(bytes_write=write(to_fd,ptr,bytes_read))
				{
					if(bytes_write==-1&&errno!=EINTR) break;
					else if(bytes_write==bytes_read) break;
					else if(bytes_write>0)
					{
						/*如果已经写进去了，则重新赋值*/
						ptr+=bytes_write;
						bytes_read-=bytes_write;
					}	
				}	
				if(bytes_write==-1)
				break;
			}			
	}	
	close(from_fd);
	close(to_fd);
	return 0;
}
