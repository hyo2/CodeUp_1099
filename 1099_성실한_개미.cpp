#include <stdio.h>

void print_map(int a[][11])
{
	for(int i=1;i<=10;i++) 
	{
		for(int j=1;j<=10;j++)
		{
			printf("%d ",a[i][j]);
		}
			printf("\n");
	}
}

int main()
{
	int x,y;
		
	int a[11][11]={};
	
	for(int i=1;i<=10;i++) // 입력 받기 
	{
		for(int j=1;j<=10;j++)
		{
			scanf("%d",&a[i][j]); 
		}
	} 
	
	// 개미집 
	x=2;
	y=2;
	 	
	printf("\n");
	
	if(a[x][y]==2)
	{
		a[x][y]=9;
		print_map(a);
	}
	
	else
	{
		a[x][y]=9;
		
		while(a[x][y]!=2)
		{ 
			if(a[x][y+1]==0)
			{
				a[x][y+1]=9;
				y++;
			}
			
			else if(a[x][y+1]==1&&a[x+1][y]==0)
			{
				a[x+1][y]=9;
				x++;
			}
			
			if(a[x+1][y]==2||a[x][y+1]==2) // 먹이를 찾은 경우 
			{
				if(a[x][y+1]==2) // 옆에 먹이가 있는 경우  
				{
					a[x][y+1]=9;
					break;
				}
				
				else if(a[x+1][y]==2&&a[x][y+1]==1) // 아래에 먹이가 있는 경우
				{
					a[x+1][y]=9;
					break;
				}
			}
			
			if(a[x+1][y]==1&&a[x][y+1]==1) // 더이상 움직일 수 없는 경우 
			{
				a[x][y]=9;
				break;
			}
			
			if(x==10&&y==10) // 맨 아래 오른쪽에 도착한 경우 
				break;
		}
		
		print_map(a);	
	}
	
	return 0;
}
