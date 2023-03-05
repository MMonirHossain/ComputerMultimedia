#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;
int h,k;
//int x1,x2,y11,y2;

void bresenham(int x1,int y11,int x2,int y2){
	int dx,dy,d,inc1,inc2;
	dx=x2-x1;
	dy=y2-y11;
	//float m=dy/dx;
	if( abs(dy)<=abs(dx) ){
        cout<<"Up\n";
		d=2*dy-dx;
		inc1=2*dy;
		inc2=2*(dy-dx);
		while(x1<=x2){
			putpixel(x1,y11,14);
			delay(30);
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

	    cout<<"Down\n";
		d=2*dx-dy;
		inc1=2*dx;
		inc2=2*(dx-dy);
		//if(y11>y2){swap(y11,y2);swap(x1,x2);}
		while(y11<=y2){
            //cout<<x1<<" "<<y11<<"\n";
			putpixel(x1,y11,14);
			delay(30);
			if(d<=0){
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


int cenx, ceny;
void print_symetric(int x,int y){
    putpixel(cenx-x,ceny+y,15); delay(5);
    putpixel(cenx-y,ceny+x,14);
    putpixel(cenx+x,ceny+y,13);
    putpixel(cenx-y,ceny-x,12);
    putpixel(cenx-x,ceny-y,11);
    putpixel(cenx+y,ceny+x,10);
    putpixel(cenx+x,ceny-y,9);
    putpixel(cenx+y,ceny-x,8);
}

void bresenhamcircle(int nx,int ny,int r){
    cenx=nx;ceny=ny;
    int d=3-2*r;
    int x=0,y=r;
    while(x<y){
        print_symetric(x,y);
        if(d>=0){
            y--;
            d=d+10+4*(x-y);
        }
        else{
            d=d+6+4*x;
        }
        x++;
    }
}


void print_point_as_text(int x,int y){
    char arr[10];
    sprintf(arr,"(%d,%d)",x,y);
    outtextxy(x,y,arr);
}


int main(){

initwindow(600,600,"Hello");

bresenham(10,10,400,11);
bresenham(11,250,401,249);
bresenham(10,10,11,250);
bresenham(400,11,401,249);
bresenham(195,10,195,60);
bresenham(195,180,195,250);
bresenhamcircle(195,120,60);

while(!kbhit()){delay(200);}
return 0;
}

