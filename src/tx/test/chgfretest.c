#include <stdio.h>
#include <unistd.h>
int main()
{
	FILE *fp;
	char szbuf[100];
	char pathname[100];
	
	sprintf(pathname,"%s/txt/1",getenv("HOME"));
	/*将屏幕标准输出的内容重定向到新的地方*/
	if((fp=freopen(pathname,"w",stderr))==NULL)
	{
		printf("stderr -- /txt/1 failed\n");
		return 1;
	}
	fputs("I like unix\n",stderr);
	fclose(fp);
	
	/*将标准输入从、txt/1输入*/
	if((fp=freopen(pathname,"r",stdin))==NULL)
	{
		printf("stdin-- /txt/1 failed\n");
		return 1;
	}
	memset(szbuf,0,sizeof(szbuf));
	fgets(szbuf,sizeof(szbuf),stdin);
	printf("szbuf[%s]\n)",szbuf);
	return 0;
}