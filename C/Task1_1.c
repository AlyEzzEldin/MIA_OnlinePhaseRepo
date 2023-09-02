#include <stdio.h>

void main(void)
{
	//printf("GRU");
	for(int i=0;i<5;i++)
	{
		for(int space=0;space<1;space++)
		{
			printf(" ");
		}
		for(int j=0;j<22;j++)
		{
			if(i==0)
			{
				if((j>=0&&j<=4)||(j>=8&&j<=11)||j==16||j==21)
				{
					printf("*");
				}
				else
				{
					printf(" ");
				}
			}
			else if (i==1)
			{
				if(j==0||j==8||j==12||j==16||j==21)
				{
					printf("*");
				}
				else
				{
					printf(" ");
				}
			}
			else if (i==2)
			{
				if(j==1||j==2||(j>=5&&j<=7)||(j>=12&&j<=15)||(j>=17&&j<=20))
				{
					printf(" ");
				}
				else
				{
					printf("*");
				}
			}
			else if(i==3)
			{
				if(j==0||j==4||j==8||j==12||j==16||j==21)
				{
					printf("*");
				}
				else
				{
					printf(" ");
				}
			}
			else
			{
				if((j>=5&&j<=7)||(j>=9&&j<=12)||(j>=14&&j<=15))
				{
					printf(" ");
				}
				else
				{
					printf("*");
				}
			}
			
		}
		printf("\n");
	}
}