#include <stdio.h>
#include <stdlib.h> //for malloc
#include <string.h>


char **r;
int *vis;
int n, count=0;


int main()
{
	char **char_array_create(int n);
	int *visited(int n);
	void show(char **p, int n); //函数声明
	void DFS(int row, int num_left);

	printf("请输入棋盘一个整数表示的维度n*n:");
	scanf("%d",&n);
	r = char_array_create(n); //建立了一个初始棋盘
	show(r, n);

	vis = visited(n); //设置标志数组
	printf("[\n");
	DFS(0, n);
//	show(r, n);
	printf("]\n");
	printf("%d\n", count);
	return 0;
}



/***************************************************************
 **定义一个函数，申请一定长度的二维动态数组，其长度用参数传入***
 ***************************************************************/
char **char_array_create(int n)
{
	int i, j;
	char **p = (char **)malloc(n*sizeof(char *));//先按行数申请n个指针型字节的空间
	for(i = 0; i < n; i++)
	{
		p[i] = (char *)malloc(sizeof(char)*n); 
		//然后依次按一维数组申请，每个一维数组按列数申请n个字符型字节的空间
		for(j = 0; j < n; j++)
		{
			p[i][j] = '.';
		}
	}

	return p;  //返回得到字符型数组的指针
}


/********************************
 ****显示二维数组的信息**********
 ********************************/
void show(char **p, int n)
{
	int i, j;
	printf("[");
	for(i = 0; i < n; i++)
	{
		if(i == 0)
		{
			printf("\"%s",p[i]);
			printf("\",");
			printf("\n");
		}
		else if(i == n-1)
		{
			printf(" \"");
			printf("%s",p[i]);
			putchar('"');
		}
		else
		{	
			printf(" \"");
			printf("%s",p[i]);
			printf("\",");
			printf("\n");
		}
	}
	printf("],");
	printf("\n");
}


/***************************
 ***申请一个一维动态数组****
 ***************************/
int *visited(int n)
{
	int *p = (int *)malloc(sizeof(int)*n);
	memset(p, 0, sizeof(int)*n);
	return p;
}


/***********************************************************
 ***输入：row->可以填入的最优先位置的行
          num_left->还有多少棋子需要填入
 ***功能：搜索将num_left个棋子填入(a,0)以后位置的所有可行解
 ***********************************************************/
void DFS(int row, int num_left)
{
	if(num_left == 0)
	{
		count++;
		show(r, n);
		return;
	}
	int i, j;
	for(i = row; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			if(!vis[j])
			{
				r[i][j] = 'Q';
				vis[j] = 1;
				DFS(i + 1, num_left - 1);
				r[i][j] = '.';
				vis[j] = 0;
			}
	
		}
	}

}
