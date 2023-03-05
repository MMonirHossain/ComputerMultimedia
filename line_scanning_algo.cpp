#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;
int h,k;
int x1,x2,y11,y2;
void bresenham(){
	int dx,dy,d,inc1,inc2;
	dx=x2-x1;
	dy=y2-y11;
	float m=dy/dx;
	if(m<=1){
		d=2*dy-dx;
		inc1=2*dy;
		inc2=2*(dy-dx);
		while(x1<=x2){
			putpixel(x1+h,k-y11,15);
			delay(100);
			if(d<=0){
				d=d+inc1;
			}
			else{
				d=d+inc2;
				y11++;
			}
			x1++;
		}
	}
	else{
		d=2*dx-dy;
		inc1=2*dx;
		inc2=2*(dx-dy);
		while(y11<=y2){
			putpixel(x1+h,k-y11,15);
			delay(100);
			if(d<0){
				d=d+inc1;
			}
			else{
				d=d+inc2;
				x1++;
			}
			y11++;
		}
	}
}


void dda(){
	int dx,dy;
	dx=x2-x1;
	dy=y2-y11;
	float m=dy/dx;
	float x,y;
	x=x1;
	y=y11;

	if(m<1){
		while(x1<=x2){
			y11=floor(y);
			putpixel(x1+h,k-y11,15);
			delay(100);
			x1++;
			y=y+m;
		}
	}
	else{
		m=dx/dy;
		while(y11<=y2){
			x1=floor(x);
			putpixel(x1+h,k-y11,15);
			delay(100);
			y11++;
			x=x+m;
		}
	}
}

void print_point_as_text(int x,int y){
    char arr[10];
    sprintf(arr,"(%d,%d)",x,y);
    outtextxy(h+x,k-y+10,arr);
}


int main(){
cin>>x1>>y11>>x2>>y2;
initwindow(600,600,"Hello");

h=getmaxx()/2;
k=getmaxy()/2;

line(0,h,getmaxx(),h);
line(k,0,k,getmaxx());


settextstyle(3,0,2);
print_point_as_text(x1,y11);
bresenham();
dda();
print_point_as_text(x2,y2);
while(!kbhit()){delay(200);}
return 0;
}
