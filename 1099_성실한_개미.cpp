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
	
	for(int i=1;i<=10;i++) // �Է� �ޱ� 
	{
		for(int j=1;j<=10;j++)
		{
			scanf("%d",&a[i][j]); 
		}
	} 
	
	// ������ 
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
			
			if(a[x+1][y]==2||a[x][y+1]==2) // ���̸� ã�� ��� 
			{
				if(a[x][y+1]==2) // ���� ���̰� �ִ� ���  
				{
					a[x][y+1]=9;
					break;
				}
				
				else if(a[x+1][y]==2&&a[x][y+1]==1) // �Ʒ��� ���̰� �ִ� ���
				{
					a[x+1][y]=9;
					break;
				}
			}
			
			if(a[x+1][y]==1&&a[x][y+1]==1) // ���̻� ������ �� ���� ��� 
			{
				a[x][y]=9;
				break;
			}
			
			if(x==10&&y==10) // �� �Ʒ� �����ʿ� ������ ��� 
				break;
		}
		
		print_map(a);	
	}
	
	return 0;
}
