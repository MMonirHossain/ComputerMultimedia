#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;
int cenx,ceny,r;
int h,k;

void print_symetric(int x,int y){
    putpixel(h-cenx-x,k+ceny+y,15);
    delay(100);
    putpixel(h-cenx-y,k+ceny+x,14);
    putpixel(h-cenx+x,k+ceny+y,13);
    putpixel(h-cenx-y,k+ceny-x,12);
    putpixel(h-cenx-x,k+ceny-y,11);
    putpixel(h-cenx+y,k+ceny+x,10);
    putpixel(h-cenx+x,k+ceny-y,9);
    putpixel(h-cenx+y,k+ceny-x,8);
}

void bresenhamcircle(){

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


void midpointcircle(){
    int p=1-r;

    int x=0,y=r;


    while(x<y){
        print_symetric(x,y);
        if(p>=0){
            p=p+2*(x+1)+1-2*(y-1);
            y--;
        }
        else{
            p=p+2*(x+1)+1;
        }
        x++;
    }

}

int main(){

cout<<"Enter the center of Circle: ";
cin>>cenx>>ceny;
cout<<"Enter the Radius of Circle: ";
cin>>r;

initwindow(400,400,"Hello");

h=getmaxx()/2;
k=getmaxy()/2;

line(0,h,getmaxx(),h);
line(k,0,k,getmaxx());

settextstyle(3,0,2);
char arr[15];
sprintf(arr,"(%d,%d)",cenx,ceny);
putpixel(h-cenx,k+ceny,15);
outtextxy(h-cenx,k+ceny,arr);





//bresenhamcircle();
midpointcircle();



while(!kbhit()){delay(200);}
return 0;



return 0;
}
