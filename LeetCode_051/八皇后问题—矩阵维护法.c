#include <stdio.h>
#include <stdlib.h>

/**************************************************
 ##################################################
 ##################矩阵维护法######################
 ##################################################
 **************************************************/


int cheeseboard[8][8];
int queen[8];  //用来记录每一行中放置皇后的列数 
int lastqueen = -1;
int res = 0;

int main()
{
	//函数声明
	int search_line(int i, int j);
	void set_queen(int i, int j);
	void backtrack_queen(int i);
	void print_cheeseboard();

	//初始化棋盘
	for(int i = 0; i < 8; i++)
	{
		for(int j = 0; j <8; j++)
		{
			cheeseboard[i][j] = 0;
		}
	}
	print_cheeseboard();

	for(int i=0;; i++)  //一行一行地操作
	{
		int j = search_line(i, lastqueen+1);
		if(j == -1)      //没有放皇后的位置了，回溯
		{
			if(i == 0)
				break;   //真正结束的位置
			backtrack_queen(i - 1);    //撤销刚才对上一行的操作
			lastqueen = queen[i - 1];  
			//记录上一行放置queen的位置，便于回溯的时候从这个位置之后寻找可放置皇后的位置
			i -= 2;
			//减2是因为循环中后边还有个i++，这样总的效果实现i-1,即回到上一行，重新寻找皇后的可放位置
		}
		else
		{
			lastqueen = -1;
			set_queen(i, j);
			if(i == 7)
			{
				res++;
				print_cheeseboard();
				for(int k=0; k<8; k++)
				{
					printf("%3d", queen[k]);
				}
				printf("\n");

				backtrack_queen(7);
				lastqueen = j;
				i--;
			}
		}
	}

	printf("\n%d\n", res);
	return 0;
}



/*******************************************************************
 *****搜寻棋盘中的某一行有没有可放的位置，返回可放置位置的列数******
 *******************************************************************/
int search_line(int i, int j)
{
	for(; j < 8; j++)
	{
		if(cheeseboard[i][j] == 0)
			return j;
	}
	return -1;
}



/****************************************************************
 ****在可放位置上放上皇后，并对这个皇后会影响的棋格进行操作******
 ****************************************************************/
void set_queen(int i, int j)
{
	cheeseboard[i][j] = -1;
	queen[i] = j;

	for(int temp=0; temp<8; temp++) // 对列操作
	{
		if(cheeseboard[temp][j] != -1)
			cheeseboard[temp][j]++;
	}
	for(int temp=0; temp<8; temp++) // 对行操作
	{
		if(cheeseboard[i][temp] != -1)
			cheeseboard[i][temp]++;	
	}
	
	int temp_j = j + 1;
	for(int temp_i = i+1; temp_i<8 && temp_j<8; temp_i++) //对东南对角线操作
	{
		cheeseboard[temp_i][temp_j++]++;
	}
	
	temp_j = j + 1;
	for(int temp_i = i-1; temp_i>=0 && temp_j<8; temp_i--) //对东北对角线操作
	{
		cheeseboard[temp_i][temp_j++]++;
	}

	temp_j = j - 1;
	for(int temp_i = i+1; temp_i<8 && temp_j>=0; temp_i++) //对西南对角线操作
	{
		cheeseboard[temp_i][temp_j--]++;
	}

	temp_j = j - 1;
	for(int temp_i = i-1; temp_i>=0 && temp_j>=0; temp_i--) //对西北对角线操作
	{
		cheeseboard[temp_i][temp_j--]++;
	}

	return;
}



/****************************************************************************
 ******回溯上一行放置皇后的位置，撤销刚才对行、列、对角线上各元素的操作******
 ****************************************************************************/
void backtrack_queen(int i)
{
	int j = queen[i];
	for(int temp=0; temp<8; temp++) // 对列操作
	{
		if(cheeseboard[temp][j] != -1)
			cheeseboard[temp][j]--;
	}
	for(int temp=0; temp<8; temp++) // 对行操作
	{
		if(cheeseboard[i][temp] != -1)
			cheeseboard[i][temp]--;	
	}
	
	int temp_j = j + 1;
	for(int temp_i = i+1; temp_i<8 && temp_j<8; temp_i++) //对东南对角线操作
	{
		cheeseboard[temp_i][temp_j++]--;
	}
	
	temp_j = j + 1;
	for(int temp_i = i-1; temp_i>=0 && temp_j<8; temp_i--) //对东北对角线操作
	{
		cheeseboard[temp_i][temp_j++]--;
	}

	temp_j = j - 1;
	for(int temp_i = i+1; temp_i<8 && temp_j>=0; temp_i++) //对西南对角线操作
	{
		cheeseboard[temp_i][temp_j--]--;
	}

	temp_j = j - 1;
	for(int temp_i = i-1; temp_i>=0 && temp_j>=0; temp_i--) //对西北对角线操作
	{
		cheeseboard[temp_i][temp_j--]--;
	}

	cheeseboard[i][j] = 0;
	return;
}


/**********************************
 ***********打印棋盘***************
 **********************************/
void print_cheeseboard()
{
	printf("[\n");
	for(int i=0; i<8; i++)
	{
		for(int j=0; j<8; j++)
		{
			printf("%3d",cheeseboard[i][j]);
		}
		printf("\n");
	}
	printf("]\n");
	
	return;
}




