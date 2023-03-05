#include <bits/stdc++.h>
#include<graphics.h>
#include<math.h>
using namespace std;
int X,Y;
float C[3][3]={0};
int matrixmultiply(float A[3][3],int B[3][3])
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			for(int k=0;k<3;k++)
			C[i][j]+=A[i][k]*B[k][j];
		}
	}
}

void Translation(int X,int Y)
{
	float A[3][3]={{1,0,20},{0,1,30},{0,0,1}};
	int b[3][3]={{20,80,70},{20,80,150},{1,1,1}};
	matrixmultiply(A,b);
	line(X+C[0][0],Y-C[1][0],X+C[0][1],Y-C[1][1]);
	line(X+C[0][0],Y-C[1][0],X+C[0][2],Y-C[1][2]);
	line(X+C[0][2],Y-C[1][2],X+C[0][1],Y-C[1][1]);
}

void Scaling(int X,int Y)
{
	float A[3][3]={{2,0,0},{0,2,0},{0,0,1}};
	int b[3][3]={{20,80,70},{20,80,150},{1,1,1}};
	matrixmultiply(A,b);
	line(X+C[0][0],Y-C[1][0],X+C[0][1],Y-C[1][1]);
	line(X+C[0][0],Y-C[1][0],X+C[0][2],Y-C[1][2]);
	line(X+C[0][2],Y-C[1][2],X+C[0][1],Y-C[1][1]);
}

void Rotation(int X,int Y,int theta)
{
	float x = theta*3.14159/180.0;
	float A[3][3]={{cos(x),sin(-x),0},{sin(x),cos(x),0},{0,0,1}};
	int b[3][3]={{20,80,70},{20,80,150},{1,1,1}};
	matrixmultiply(A,b);
	line(X+C[0][0],Y-C[1][0],X+C[0][1],Y-C[1][1]);
	line(X+C[0][0],Y-C[1][0],X+C[0][2],Y-C[1][2]);
	line(X+C[0][2],Y-C[1][2],X+C[0][1],Y-C[1][1]);
}

void Shear(int X,int Y)
{
	float A[3][3]={{1,0,0},{2,1,0},{0,0,1}};
	int b[3][3]={{20,80,70},{20,80,150},{1,1,1}};
	matrixmultiply(A,b);
	line(X+C[0][0],Y-C[1][0],X+C[0][1],Y-C[1][1]);
	line(X+C[0][0],Y-C[1][0],X+C[0][2],Y-C[1][2]);
	line(X+C[0][2],Y-C[1][2],X+C[0][1],Y-C[1][1]);
}

void Reflection(int X,int Y)
{
	float A[3][3]={{-1,0,0},{0,1,0},{0,0,1}};
	int b[3][3]={{20,80,70},{20,80,150},{1,1,1}};
	matrixmultiply(A,b);
	line(X+C[0][0],Y-C[1][0],X+C[0][1],Y-C[1][1]);
	line(X+C[0][0],Y-C[1][0],X+C[0][2],Y-C[1][2]);
	line(X+C[0][2],Y-C[1][2],X+C[0][1],Y-C[1][1]);
}

int main() {
	char str[20];
	initwindow(640,680,"Transformation");
	X=getmaxx();
	Y=getmaxy();
	rectangle(0,0,X,Y);
	line(0,Y/2,X,Y/2);
	line(X/2,0,X/2,Y);
	X=X/2;
	Y=Y/2;
	int Theta=90,n;
	cout<<"1.Translation"<<endl<<"2.Scaling"<<endl<<"3.Rotation"<<endl<<"4.Shear"<<endl<<"5.Reflection"<<endl<<"Select Your One choice:";
	cin>>n;
	switch(n)
	{
		case 1:
			Translation(X,Y);
			break;
		case 2:
			Scaling(X,Y);
			break;
		case 3:
			Rotation(X,Y,Theta);
			break;
		case 4:
			Shear(X,Y);
			break;
		case 5:
			Reflection(X,Y);
			break;
	}
	line(X+20,Y-20,X+80,Y-80);
	line(X+20,Y-20,X+70,Y-150);
	line(X+70,Y-150,X+80,Y-80);

	strcpy(str,"Monir Hossain");
	outtextxy(X+80,Y-230,str);
	strcpy(str,"      ID:174053");
	outtextxy(X+80,Y-210,str);

	while(!kbhit())
	{
		delay(100);
	}
    return 0;
}


