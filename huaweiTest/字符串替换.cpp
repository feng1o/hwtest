#if 0
#define  _CRT_SECURE_NO_WARNINGS

#include< stdio.h>
#include< stdlib.h>
#include<string.h>
#define MAXLEN 100
int ReplaceStr(char *sSrc, char *sMatchStr, char *sReplaceStr)
{
	int  StringLen;
	char caNewString[MAXLEN];
	char *FindPos = strstr(sSrc, sMatchStr);//找到第一个匹配字符串，返回其首地址
	if ((!FindPos) || (!sMatchStr))
		return -1;
	while (FindPos)
	{
		memset(caNewString, 0, sizeof(caNewString));
		StringLen = FindPos - sSrc;
		strncpy(caNewString, sSrc, StringLen);
		strcat(caNewString, sReplaceStr);
		strcat(caNewString, FindPos + strlen(sMatchStr));//将第一个匹配字符串的其首地址FindPos+ strlen(sMatchStr)长度的 指针作为剩余字符                                                                                    //  /串的首地址
		strcpy(sSrc, caNewString);
		FindPos = strstr(sSrc, sMatchStr);
	}
	return 0;
}
int main()
{
	char *serverIp = "端到端";
	char endpoint[100] = "http:///vss/service/ /IVSSServices/ ";//（用字符数组，不能用字符指针）
	printf("%s\n", strstr(endpoint, "service"));
	printf("%s\n", strchr(endpoint, 'v'));
	char *space = "";
	printf("源数据 =>:%s\n", endpoint);
	//ReplaceStr(endpoint, space, serverIp);
	printf("结果 =>:%s\n", endpoint);
}
#endif