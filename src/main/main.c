/**********************************
*程序名称：main
*程序功能：通过主函数调用之后的测试程序
*作者：lpj
*时间：2019/3/22 9:57:37
***********************************/

#include <dlfcn.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include "public.h"

int main(int args ,char **argv){
	int ret=0;
	char path[50];
	void(*func)();
	void *handle;
	char repos[50];
	memset(path,0x00,sizeof(path));
	memset(repos,0x00,sizeof(repos));
	/*判断读入的参数是否够
	if(args!=2)
	{
		fprintf(stderr,"参数不够%s\n\a",strerror(errno));
		return -1;
	}
	if(strlen(argv[1])>0)
	*/
	{
		/*组建调用动态库的路径
		sprintf(path,"%slib/%s.so",getenv("HOME"),argv[1]);*/	
		strcpy(path,"/home/lpj/lib/ch06.so");
		handle=(void *)dlopen("./ch06.so",RTLD_LAZY);
		if(handle==NULL)
		{
			printf("调用动态库失败【%s】\n",dlerror());
			return 1;
		}
		func=(void (*)())dlsym(handle,"print1");
		if(func!=NULL)
		{
			printf("开始执行函数吗[]\n");
			func();
		}
		else
		{
			printf("走错误[%s]\n",dlerror());	
		}
		printf("执行函数成功");
		dlclose(handle);
	}
	
	
	return 0;	
}

