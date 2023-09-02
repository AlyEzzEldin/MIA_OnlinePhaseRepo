#include <stdio.h>
typedef unsigned char u8;
typedef signed char s8;

typedef unsigned short int u16;
typedef signed short int s16;

typedef unsigned long int u32;
typedef signed long int s32;

typedef float f32;
typedef double f64;

typedef struct
{
	u16 ID;
	u8 str[100];
}Task;

u8 Num_Tasks=0;
Task Task_List[100];

void Add_Task(void)
{
	Task New_Task;
	u8 test;
	do
	{
	printf("Enter Task ID \"Starting from 1\": ");
	scanf("%d",&New_Task.ID);
	
			for (u8 i=0;i<Num_Tasks;i++) 
		{
			if (Task_List[i].ID == New_Task.ID) 
			{
				printf("Wrong ID\n");
				test = Task_List[i].ID;
			}
		}
	}while(New_Task.ID==test);
	
	
	printf("Enter task description : ");
	getchar();
	fgets(New_Task.str,100,stdin);
	
	Task_List[Num_Tasks]=New_Task;
	Num_Tasks++;
}
void View_Tasks(void)
{
	if(Num_Tasks==0)
	{
		printf("No tasks to view");
	}
	else
	{
		printf("Current Tasks : \n");
		for(u8 i=0;i<Num_Tasks;i++)
		{
			printf("Task ID : %d \n",Task_List[i].ID);
			printf("Task Description : %s \n",Task_List[i].str);
			printf("***********************\n");
		}
	}
}
void Remove_Task(void)
{
	u16 ID_Remove;
	printf("Enter Task ID to remove : ");
	scanf("%d",&ID_Remove);
	
	s16 Task_Index=-1;
	for(u8 i=0;i<Num_Tasks;i++)
	{
		if(ID_Remove==Task_List[i].ID)
		{
			Task_Index = i;
			break;
		}
	}
	
	if(Task_Index==-1)
	{
		printf("Wrong Task ID!\n");
	}
	else
	{
		for(u8 i=Task_Index;i<Num_Tasks-1;i++)
		{
			Task_List[i]=Task_List[i+1];
			Num_Tasks--;
			printf("Task removed succesfully!\n");
		}
	}
	
}
void main(void)
{
	u8 option;
	do
	{
		printf("\nMinions Task Manager\n\n");
		printf("1.Add Task\n");
		printf("2.View Tasks\n");
		printf("3.Remove Task\n");
		printf("4.Exit\n\n");
		printf("Select an option: ");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
			{
				Add_Task();
				break;
			}
			case 2:
			{
				View_Tasks();
				break;
			}
			case 3:
			{
				Remove_Task();
				break;
			}
			case 4:
			{
				printf("Exiting Minions Task Manager. Have a great day!\n");\
				break;
			}
			default:
			{
				printf("Wrong option\n");
			}
		}
	}while(option!=4);
}
