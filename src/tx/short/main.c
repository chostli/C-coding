/**********************************
*�������ƣ�main
*�����ܣ�ͨ������������֮��Ĳ��Գ���
*���ߣ�lpj
*ʱ�䣺2019/3/22 9:57:37
***********************************/
#include "public.h"

int main(int args ,char **argv){
	int ret=0;
	/*�ж϶���Ĳ����Ƿ�*/
	if(args!=2)
	{
		fprintf(stderr,"��������%s\n\a",strerror(errno));
		return -1;
	}
	switch(atoi(argv[1]))
	{
		case 1 :
				ret=ch04();
				if(ret)
				{
					fprintf(stderr,"����fcntl����ʧ��%s\n\a",strerror(errno));
					return -1;	
				}	
				break;
		case 2:
				ret=ch05();
				if(ret)
				{
					fprintf(stderr,"����iocntl����ʧ��%s\n\a",strerror(errno));
					return -1;	
				}	
				break;
		default:
				fprintf(stderr,"����Ҫ���Ե����ݣ���У��[%s],%s\n\a",strerror(errno));
				break;
	}
	return 0;	
}