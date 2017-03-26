#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
using namespace std;
const int size=22;
char map[size+1][size+1];
long long int Time;
void print()
{
	system("printf \033c");
	for(int i=1;i<=size;++i)
	{
		for(int j=1;j<=size;++j)
			printf("%c ",map[i][j]);
		printf("\n");
	}
	printf("Life:%lld\n",Time);
}
void grow()
{
	if(Time%2==0||Time<=50)
	{
		for(int i=1;i<=size;++i)
			for(int j=1;j<=size;++j)
			{
				if(map[i][j]=='N')
				{
					map[i][j]='T';
					if(i+1<=size&&map[i+1][j]==' '&&rand()%2<=0)
						map[i+1][j]='A';
					if(i-1>=1&&map[i-1][j]==' '&&rand()%2<=0)
						map[i-1][j]='A';
					if(j+1<=size&&map[i][j+1]==' '&&rand()%2<=0)
						map[i][j+1]='A';
					if(j-1>=1&&map[i][j-1]==' '&&rand()%2<=0)
						map[i][j-1]='A';
				}
			}
		for(int i=0;i<=size;++i)
			for(int j=1;j<=size;++j)
				if(map[i][j]=='A')
					if(rand()%150==0)
						map[i][j]='O';
					else
						map[i][j]='N';
	}
	for(int i=1;i<=size;++i)
		for(int j=1;j<=size;++j)
			if(map[i][j]=='F')
			{
				map[i][j]=' ';
				if(i+1<=size&&map[i+1][j]=='T')
					map[i+1][j]='S';
				if(i-2>=0&&map[i-2][j]=='T')
					map[i-2][j]='S';
				if(j+1<=size&&map[i][j+1]=='T')
					map[i][j+1]='S';
				if(j-1>=1&&map[i][j-1]=='T')
					map[i][j-1]='S';
				if(i-1>=0&&map[i-1][j]=='T')
					map[i-1][j]='S';
				if(i+1<=size&&map[i+1][j]=='N'&&rand()%2==0)
					map[i+1][j]='W';
				if(i-2>=0&&map[i-2][j]=='N')
					map[i-2][j]='W';
				if(j+1<=size&&map[i][j+1]=='N'&&rand()%2==0)
					map[i][j+1]='W';
				if(j-1>=1&&map[i][j-1]=='N'&&rand()%2==0)
					map[i][j-1]='W';
				if(i-1>=0&&map[i-1][j]=='N'&&rand()%2==0)
					map[i-1][j]='W';
			}
	for(int i=0;i<=size;++i)
		for(int j=1;j<=size;++j)
			if(map[i][j]=='S')
				map[i][j]='F';
	for(int i=1;i<=size;++i)
		for(int j=1;j<=size;++j)
			if(map[i][j]=='O')
				if(map[i-1][j]=='W')
				{
					map[i][j]='N';
					map[i-1][j]=' ';
				}
	for(int i=size;i>=0;--i)
		for(int j=1;j<=size;++j)
			if(map[i][j]=='W')
			{
				if(i==size)
					map[i][j]=' ';
				if(i+1<=size&&map[i+1][j]=='F')
					map[i+1][j]='T';
				if(j+1<=size&&map[i][j+1]=='F')
					map[i][j+1]='T';
				if(j-1>=1&&map[i][j-1]=='F')
					map[i][j-1]='T';
				if(map[i+1][j]==' ')
				{
					map[i+1][j]='W';
					map[i][j]=' ';
				}
				if(map[i+1][j]=='T')
				{
					map[i+1][j]='N';
					map[i][j]=' ';
				}
			}
	for(int i=1;i<=size;++i)
		for(int j=1;j<=size;++j)
			if(map[i][j]=='T'||map[i][j]=='N'||map[i][j]=='O')
				return;
	print();
	printf("Over! Life:%lld",Time);
	exit(0);
}
int main()
{
	srand(time(NULL));
	for(int i=0;i<=size;++i)
		for(int j=1;j<=size;++j)
			map[i][j]=' ';
	map[size][size/2]='N';
	map[size][size/2-1]='N';
	map[size][size/2+1]='N';
	map[size][size/2+2]='N';
	map[size][size/2-2]='N';
	while(true)
	{
		++Time;
		grow();
		if(Time%3==0&&false)
		{
			for(int i=size;i>=1;--i)
				for(int j=1;j<=size;++j)
					map[i][j]=map[i-1][j];
			for(int i=1;i<=size;++i)
				map[0][i]=' ';
		}
		if(Time%20==0)
		{
			int a=rand()%size+1;
			map[size][a]='F';
			map[size-1][a]='F';
			for(int i=1;i<=size;++i)
				if(rand()%5==0)
					map[0][i]='W';
			for(int i=1;i<=size;++i)
				if(rand()%5==0)
					map[1][i]='W';
		}
		if(Time%15==0&&false)
		{
			int a=rand()%size+1;
			int b=rand()%size+1;
			map[a][b]='N';
		}
		if(Time%150==0)
		{
			for(int i=1;i<=20;++i)
			{
				int a=rand()%size+1;
				int b=rand()%size+1;
                                if(map[a][b]!='O')
					map[a][b]='F';
			}
		}
		print();
		for(int i=clock();i>=clock()-50000;);
	}
}
