/**********************************
*�������ƣ�main
*�����ܣ�ͨ������������֮��Ĳ��Գ���
*���ߣ�lpj
*ʱ�䣺2019/3/22 9:57:37
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
	/*�ж϶���Ĳ����Ƿ�
	if(args!=2)
	{
		fprintf(stderr,"��������%s\n\a",strerror(errno));
		return -1;
	}
	if(strlen(argv[1])>0)
	*/
	{
		/*�齨���ö�̬���·��
		sprintf(path,"%slib/%s.so",getenv("HOME"),argv[1]);*/	
		strcpy(path,"/home/lpj/lib/ch06.so");
		handle=(void *)dlopen("./ch06.so",RTLD_LAZY);
		if(handle==NULL)
		{
			printf("���ö�̬��ʧ�ܡ�%s��\n",dlerror());
			return 1;
		}
		func=(void (*)())dlsym(handle,"print1");
		if(func!=NULL)
		{
			printf("��ʼִ�к�����[]\n");
			func();
		}
		else
		{
			printf("�ߴ���[%s]\n",dlerror());	
		}
		printf("ִ�к����ɹ�");
		dlclose(handle);
	}
	
	
	return 0;	
}

