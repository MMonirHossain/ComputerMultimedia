#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;
int h,k;


bool TBRL[3][4];
pair<float,float> A,B;

float x_min,y_min,x_max,y_max;

void tbrl(int point,float x,float y){
    TBRL[point][0]=( (y-y_max)>0);
    TBRL[point][1]=( (y_min-y)>0);
    TBRL[point][2]=( (x-x_max)>0);
    TBRL[point][3]=( (x_min-x)>0);
}

bool OR(){
    for(int i=0;i<=1;i++){
        for(int j=0;j<=3;j++){
            if( TBRL[i][j] ) return true;
        }
    }
    return false;
}

bool AND(){
    for(int i=0;i<=3;i++){
            TBRL[2][i]=(TBRL[0][i] & TBRL[1][i]);
    }

    for(int j=0;j<=3;j++){
            if(TBRL[2][j]) return true;
    }
    //cout<<"\nAND: "<<TBRL[2][0]<<TBRL[2][1]<<TBRL[2][2]<<TBRL[2][3]<<"\n";
    return false;
}



void clip(pair<float,float> A, pair<float,float> B){

    tbrl(0,A.first,A.second);
    tbrl(1,B.first,B.second);

    cout<<TBRL[0][0]<<TBRL[0][1]<<TBRL[0][2]<<TBRL[0][3]<<"\n";
    cout<<TBRL[1][0]<<TBRL[1][1]<<TBRL[1][2]<<TBRL[1][3]<<"\n";


    if(OR()==0){
        cout<<"Visible\n";
            delay(5000);
            cleardevice();
            rectangle(x_min,y_min,x_max,y_max);
            setcolor(10);
            line(A.first,A.second,B.first,B.second);
            setcolor(15);
            delay(5000);
            cleardevice();
            return;
    }
    else{
        if(AND()){
            cout<<"Not Visible\n";return;
        }
        else{

            float x,y;
            float m=(A.second-B.second)/(A.first-B.first);

            if(TBRL[0][0]){ y=y_max; x=A.first+( (y - A.second)/m ); A.first=x;A.second=y; }
            if(TBRL[0][1]){ y=y_min; x=A.first+(y - A.second)/m; A.first=x;A.second=y; }
            if(TBRL[0][2]){ x=x_max; y=A.second+(x - A.first)*m; A.first=x;A.second=y; }
            if(TBRL[0][3]){ x=x_min; y=A.second+(x - A.first)*m; A.first=x;A.second=y; }

            if(TBRL[1][0]){ y=y_max; x=B.first+(y - B.second)/m; B.first=x;B.second=y; }
            if(TBRL[1][1]){ y=y_min; x=B.first+(y - B.second)/m; B.first=x;B.second=y; }
            if(TBRL[1][2]){ x=x_max; y=B.second+(x - B.first)*m; B.first=x;B.second=y; }
            if(TBRL[1][3]){ x=x_min; y=B.second+(x - B.first)*m; B.first=x;B.second=y; }

            tbrl(0,A.first,A.second);
            tbrl(1,B.first,B.second);
            if(AND()){
            cout<<"Not Visible\n";return;
            }



            delay(5000);
            cleardevice();
            rectangle(x_min,y_min,x_max,y_max);
            setcolor(10);
            line(A.first,A.second,B.first,B.second);
            setcolor(15);
            delay(5000);
            cleardevice();

        }

    }

}



void print_point_as_text(int x,int y){
    char arr[10];
    sprintf(arr,"(%d,%d)",x,y);
    outtextxy(x,y,arr);
}


int main(){

initwindow(600,600,"Hello");

cout<<"Enter the max and min points: ";
cin>>x_max>>y_max>>x_min>>y_min;

//rectangle(x_min,y_max,x_max,y_min);



while(1){
rectangle(x_min,y_min,x_max,y_max);
cout<<"Enter points A: ";
cin>>A.first>>A.second;
cout<<"Enter points B: ";
cin>>B.first>>B.second;

line(A.first,A.second,B.first,B.second);

clip(A,B);

}


while(!kbhit()){delay(200);}
return 0;
}


