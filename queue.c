#include<stdio.h>
#define size 5
struct queue
{
	int data[5];
	int front;
	int rear;
};
typedef struct queue queue;
queue s;

void enqueue(int d)
{
	if(s.rear==size-1)
	{
		printf("queue overflow");
		return;
	}
	if(s.front==-1)
	{
		s.front=0;
	}
	s.rear++;
	s.data[s.rear]=d;
	return;
}
int dequeue()
{
	int m;
	if(s.front==-1)
	{
		printf("\n queue underflow");
		return 0;
	}
	m=s.data[s.front];
	if(s.rear==s.front)
	{
                s.front=-1;
		s.rear=-1;
	}
	else
	{
		s.front++;
	}
	return m;
}

void display()
{
	int i;
	if(s.front!=-1)
	{
		printf("\n s.front=%d s.rear=%d\n",s.front,s.rear);
		for(i=s.front;i<=s.rear;i++)
		{
			printf("%d\n",s.data[i]);
		}
	}
	return;
	}
	main()
	{
		int a,n,p;
		s.front=-1;
		s.rear=-1;
		do
		{
			printf("\n 1.enqueue");
			printf("\n 2.dequeue");
			printf("\n 3.display");
			printf("\n 4.exit");
			printf("\n enter your choice");
			scanf("%d",&n);
			switch(n)
			{
				case 1:
					printf("enter any no");
					scanf("%d",&a);
					enqueue(a);
					display();
					break;
				case 2:
					p=dequeue();
					printf("\n the deleted element is:%d",p);
					display();
					break;
				case 4:
					display();
					break;
			}
		}while(n!=4);
	}
