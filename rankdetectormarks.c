#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct stud
{
	int roll;
	char name[30];
	int sub1,sub2,sub3;
	int total;	
};
void getinput(struct stud *);
void process(struct stud *);
void show(struct stud *);
void main()
{
	struct stud st[3];
	printf("Input of Students\n");
	getinput(st);
	printf("Data is processed\n");
	process(st);
	printf("This is the following details\n");
	show(st);
}
void getinput(struct stud p[])
{
	int i=0;
	printf("Enter details of the Student\n");
	for (int i = 0; i <3; ++i)
	{
		printf("Enter Roll No:\n");
		scanf("%d",&p[i].roll);
		fflush(stdin);
		printf("Enter the name\n");
		gets(p[i].name);
		printf("Enter marks of three subjects\n");
		scanf("%d %d %d",&p[i].sub1,&p[i].sub2,&p[i].sub3);
		p[i].total=p[i].sub1+p[i].sub2+p[i].sub3;
	}
}
void process(struct stud p[])
{
	int i=0,j=0;
	struct stud cp;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3-1-i;j++)
		{
			if(p[j].total<p[j+1].total)
			{
				cp=p[j+1];
				p[j+1]=p[j];
				p[j]=cp;
			}
		}
	}	
}
void show(struct stud p[])
{
	int i=0;
	for(i=0;i<=2;i++)
	{
		printf("Roll No:\tName\tSubject1\tSubject2\tSubject3\tTotal\n");
		printf("%d\t%s\t%d\t%d\t%d\t%d\n",p[i].roll,p[i].name,p[i].sub1,p[i].sub2,p[i].sub3,p[i].total);
	}
}