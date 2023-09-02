#include <stdio.h>
#include <stdlib.h>

void main(void)
{
	int Number;
	printf("Enter Number to start the countdown : ");
	scanf("%d",&Number);
	if(Number<=0)
	{
		printf("Error !!");
	}
	else
	{
	for(int i=Number;i>0;i--)
	{
		printf("%d\n",i);
		_sleep(1000);
	}
	}
		printf("Blast off to the moon!");
}