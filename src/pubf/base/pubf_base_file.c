/**********************************
*程序名称以及相关功能
int 	GetFileType(mode_t 	st_mode,char *resp)
作者：lpj
修改事假：2019/3/27 9:08:13
***********************************/

#include <sys/stat.h>

#include <sys/types.h>

#include "public.h"
#if 0
	int stat(const char*path,struct stat *buf); /*获取文件属性函数*/
	int fstat(int fildes,struct stat *buf); /*获取文件属性，通过打开的文件句柄*/
	int lstat(const char *path,struct stat *buf); /*只获取链接符号文件的属性，*/
	struct stat{
		dev_t st_dev; /*文件常驻设备ID*/
		ino_t st_ino; /*i节点编号*/
		mode_t st_mode; /*文件类型与权限*/
		nlink_t st_nlink; /*文件链接数*/
		uid_t st_uid; /*文件属性ID*/
		gid_t st_gid; /*文件数组ID*/
		dev_t st_rdev; /**特别文件设备号*/
		off_t st_size; /*文件长度*/
		time_t st_atime; /**文件最近访问时间*/
		time_t st_mtime; /*文件最近修改时间*/
		time_t st_ctime; /*文件状态最近改变时间*/		
	}
#endif
/*返回文件的类型*/
int GetFileType(mode_t st_mode,char*resp)
{

	if(resp==NULL){ return 0;} /*该文件模式是空*/
	else if(S_ISDIR(st_mode))  resp[0]='d'; /*该文件是个目录*/
	else if(S_ISCHR(st_mode))  resp[0]='c'; /*该文件是个字符文件*/
	else if(S_ISBLK(st_mode))  resp[0]='b'; /*该文件是个块文件*/
	else if(S_ISREG(st_mode))  resp[0]='-'; /*该文件是个普通文件*/
	else if(S_ISLNK(st_mode))  resp[0]='l'; /*该文件是个符号链接文件*/
	else if(S_ISFIFO(st_mode))   resp[0]='p'; /*该文件是个管道文件*/
	else resp[0]=' ';
	return 0;

}
