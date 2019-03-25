/**********************************
*程序名称：main
*程序功能：通过主函数调用之后的测试程序
*作者：lpj
*时间：2019/3/22 9:57:37
***********************************/
#include "public.h"

int main(int args ,char **argv){
	int ret=0;
	/*判断读入的参数是否够*/
	if(args!=2)
	{
		fprintf(stderr,"参数不够%s\n\a",strerror(errno));
		return -1;
	}
	switch(atoi(argv[1]))
	{
		case 1 :
				ret=ch04();
				if(ret)
				{
					fprintf(stderr,"测试fcntl函数失败%s\n\a",strerror(errno));
					return -1;	
				}	
				break;
		case 2:
				ret=ch05();
				if(ret)
				{
					fprintf(stderr,"测试iocntl函数失败%s\n\a",strerror(errno));
					return -1;	
				}	
				break;
		default:
				fprintf(stderr,"不是要测试的数据，清校验[%s],%s\n\a",strerror(errno));
				break;
	}
	return 0;	
}