#include<stdio.h>
#include<string.h>
void Reverse_String(char *s, int start, int leng)
{
	char temp;
	while (start<leng)
	{
		temp = s[start];
		s[start] = s[leng];
		s[leng] = temp;
		start++;
		leng--;
	}
}
void Reverse_Word(char *s)
{
	int start, leng,end;
	start = 0;
	end = 0;
	leng = strlen(s)-1;
	if ((s == NULL) || (*s = '\0') || (s[1] == '\0'))
		return 0;                               //如果为空或者一个字符则无需转置
	//   1、将字符串完全转置
	Reverse_String(s, start, leng);
	//   2、查询单词，进行单词转置
	while (s[end] != '\0')                      //若访问到\0处代表字符串已访问完
	{
		while (s[end] != ' ' && s[end] != '\0') //用end去查找单词之间的空格或者\0，一旦找到空格或者\0，end停止++
		{
			end++;
		}
		Reverse_String(s, start, end-1);        //将查询到的该单词进行转置
		start = end + 1;                        //start跳至end+1的位置，开始查询下一个单词
		end++;                                  //end自加
	}
}
void main()
{
	char S[100] = { 0 };
	gets(S);
	Reverse_Word(S);
	printf("%s", S);
}

