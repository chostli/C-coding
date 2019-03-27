/**********************************
*���������Լ���ع���
int 	GetFileType(mode_t 	st_mode,char *resp)
���ߣ�lpj
�޸��¼٣�2019/3/27 9:08:13
***********************************/

#include <sys/stat.h>

#include <sys/types.h>

#include "public.h"
#if 0
	int stat(const char*path,struct stat *buf); /*��ȡ�ļ����Ժ���*/
	int fstat(int fildes,struct stat *buf); /*��ȡ�ļ����ԣ�ͨ���򿪵��ļ����*/
	int lstat(const char *path,struct stat *buf); /*ֻ��ȡ���ӷ����ļ������ԣ�*/
	struct stat{
		dev_t st_dev; /*�ļ���פ�豸ID*/
		ino_t st_ino; /*i�ڵ���*/
		mode_t st_mode; /*�ļ�������Ȩ��*/
		nlink_t st_nlink; /*�ļ�������*/
		uid_t st_uid; /*�ļ�����ID*/
		gid_t st_gid; /*�ļ�����ID*/
		dev_t st_rdev; /**�ر��ļ��豸��*/
		off_t st_size; /*�ļ�����*/
		time_t st_atime; /**�ļ��������ʱ��*/
		time_t st_mtime; /*�ļ�����޸�ʱ��*/
		time_t st_ctime; /*�ļ�״̬����ı�ʱ��*/		
	}
#endif
/*�����ļ�������*/
int GetFileType(mode_t st_mode,char*resp)
{

	if(resp==NULL){ return 0;} /*���ļ�ģʽ�ǿ�*/
	else if(S_ISDIR(st_mode))  resp[0]='d'; /*���ļ��Ǹ�Ŀ¼*/
	else if(S_ISCHR(st_mode))  resp[0]='c'; /*���ļ��Ǹ��ַ��ļ�*/
	else if(S_ISBLK(st_mode))  resp[0]='b'; /*���ļ��Ǹ����ļ�*/
	else if(S_ISREG(st_mode))  resp[0]='-'; /*���ļ��Ǹ���ͨ�ļ�*/
	else if(S_ISLNK(st_mode))  resp[0]='l'; /*���ļ��Ǹ����������ļ�*/
	else if(S_ISFIFO(st_mode))   resp[0]='p'; /*���ļ��Ǹ��ܵ��ļ�*/
	else resp[0]=' ';
	return 0;

}
