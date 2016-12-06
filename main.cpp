#include<iostream>
#include<stdio.h>
#include <GL/glut.h>
#include<math.h>
#include <stdlib.h>
#define PI 3.14159265
using namespace std;
void go();
void score();
int rand1();
void timer(int );
void calculate();
void gover1();
void drawline(int ,int );
int x=240,y=0,xs=240,ys=0,max1=620-(9*34),reset=1,c1=rand()%5,max2,c4=0,ck,sc=0;bool flt,gover=false;
double xl=x,yl=y,x3,y3,len,theta,theta1,lbound=0.13962634,rbound=3.00196631;
struct blast1{
    int a,b;
};
int noc[5];
struct blast1 blast[200];
struct colour{
    double r1,g1,b1;
};
struct colour col1[6];
struct bubble{
    int color,v,vi;
};
struct bubble bubbles[15][12];
//struct bubble *a = new struct bubble[10];
void cols(){
    col1[0].r1=1;
    col1[3].r1=1;
    col1[1].r1=col1[2].r1=col1[4].r1=0;col1[5].r1=0.2;
    col1[1].g1=col1[4].g1=1;
    col1[0].g1=col1[2].g1=col1[3].g1=0;col1[5].g1=0.6;
    col1[2].b1=col1[3].b1=col1[4].b1=1;
    col1[0].b1=col1[1].b1=0;col1[5].b1=0.2;
}
static void resize(int width, int height)
{
    const float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);

    //glMatrixMode(GL_MODELVIEW);
    //glLoadIdentity() ;
}

int rand1(){
    for(int i=0;i<5;i++){
        noc[i]=0;
    }
    for(int j=0;j<15;j++){
        if(j%2==0){
            for(int i=0;i<12;i++){
                if(bubbles[j][i].v==1){
                    noc[bubbles[j][i].color]++;
                }
            }
        }
       else{
            for(int i=0;i<11;i++){
                if(bubbles[j][i].v==1){
                    noc[bubbles[j][i].color]++;
                }
            }
       }
    }
    ck=0;
    for(int i=0;i<5;i++){
        if(noc[i]==0){
            ck++;
        }
    }
    int temp=rand()%5;
    if(ck!=5){
    while(noc[temp]==0){
        temp=rand()%5;
    }}
    return temp;
}

void score1(){
        glColor3f(0.0,0,0);
        glRasterPos2i(170,170);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'G');
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'A');
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'M');
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'E');
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,' ');
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'O');
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'V');
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'E');
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'R');
}

void circle(double xc,double yc,int R,double r,double g,double b){
    for(double t=0;t<=2*PI;t+=.10){

        glBegin(GL_TRIANGLES);
        glColor3d(r,g,b);
        glVertex2d(xc,yc);
        glColor3d(r*0.1,g*0.1,b*0.1);
        glVertex2d(xc+R*cos(t),yc+R*sin(t));
        glColor3d(r*0.1,g*0.1,b*0.1);
        glVertex2d(xc+R*cos(t+0.1),yc+R*sin(t+0.1));
        glEnd();
    }
}
//20root3
void inits(){
    for(int j=0;j<7;j++){
        if(j%2==0){
            for(int i=0;i<12;i++){
                bubbles[j][i].v=1;
                bubbles[j][i].vi=0;
                bubbles[j][i].color=rand()%5;
            }
        }
       else{
            for(int i=0;i<11;i++){
                bubbles[j][i].v=1;
                bubbles[j][i].vi=0;
                bubbles[j][i].color=rand()%5;
            }
       }
    }
}

/*void shooter(){
    glColor3d(1,1,0);


    glBegin(GL_POLYGON);
    glVertex2d(x-20,y);
    glVertex2d(x-60,y);
    glVertex2d(x-60,y+40);
    glVertex2d(x-20,y+35);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2d(x-30,y);
    glVertex2d(x-30,y+15);
    glVertex2d(x+30,y+15);
    glVertex2d(x+30,y);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2d(x+20,y);
    glVertex2d(x+60,y);
    glVertex2d(x+60,y+40);
    glVertex2d(x+20,y+35);
    glEnd();


}
*/
 void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    //glColor3d(1,0,0);
    //printf("%d",c1);
    glBegin(GL_POLYGON);
        glColor3d(1,1,1);
        glVertex2d(0,0);
        glColor3d(1,0.7,0.8);
        glVertex2d(480,0);
        glColor3d(1,1,1);
        glVertex2d(480,640);
        glColor3d(1,0.7,0.8);
        glVertex2d(0,640);
    glEnd();
    //circle(240,320,500,1,0.75,0.8);
    cols();
    for(int j=0;j<15;j++){
        if(j%2==0){
            for(int i=0;i<12;i++){
                if(bubbles[j][i].v==1){
                    circle((i*40)+20,620-(j*34),20,col1[bubbles[j][i].color].r1,col1[bubbles[j][i].color].g1,col1[bubbles[j][i].color].b1);max2=620-((j+1)*34);
                }
            }
        }
       else{
            for(int i=0;i<11;i++){
                if(bubbles[j][i].v==1){
                    circle((i*40)+40,620-(j*34),20,col1[bubbles[j][i].color].r1,col1[bubbles[j][i].color].g1,col1[bubbles[j][i].color].b1);max2=620-((j+1)*34);
                }
            }
       }
    }
    if(ck==5) gover = true;
    if(gover){
        gover1();
    }
    //circle(20,620,20,col1[bubbles[0][0].color].r1,col1[bubbles[0][0].color].g1,col1[bubbles[0][0].color].b1);
    drawline(xl,yl);
    glColor3d(0,0,0);
    glBegin(GL_LINES);
        glVertex2d(0,260);
        glVertex2d(480,260);
    glEnd();
    if(ck!=5)
        circle(x,y+20,20,col1[c1].r1,col1[c1].g1,col1[c1].b1);

    score();
    glFlush();
}

void dfs(int i,int j,int c){
    cout << i << j << c <<endl;
    if(i%2==0){
            if(i==0){
                if(j>0 && j<11){
            if(bubbles[i+1][j-1].v==1&&bubbles[i+1][j-1].color==c&&bubbles[i+1][j-1].vi==0){
                blast[c4].a=i+1;
                blast[c4].b=j-1;
                bubbles[i+1][j-1].vi=1;
                c4++;
                dfs(i+1,j-1,c);
            }
            if(bubbles[i+1][j].v==1&&bubbles[i+1][j].color==c&&bubbles[i+1][j].vi==0){
                blast[c4].a=i+1;
                blast[c4].b=j;
                bubbles[i+1][j].vi=1;
                c4++;
                dfs(i+1,j,c);
            }
            if(bubbles[i][j-1].v==1&&bubbles[i][j-1].color==c&&bubbles[i][j-1].vi==0){
                blast[c4].a=i;
                blast[c4].b=j-1;
                bubbles[i][j-1].vi=1;
                c4++;
                dfs(i,j-1,c);
            }
            if(bubbles[i][j+1].v==1&&bubbles[i][j+1].color==c&&bubbles[i][j+1].vi==0){
                blast[c4].a=i;
                blast[c4].b=j+1;
                bubbles[i][j+1].vi=1;
                c4++;
                dfs(i,j+1,c);
            }
        }
        if(j=0){
            if(bubbles[i+1][j].v==1&&bubbles[i+1][j].color==c&&bubbles[i+1][j].vi==0){
                blast[c4].a=i+1;
                blast[c4].b=j;
                bubbles[i+1][j].vi=1;
                c4++;
                dfs(i+1,j,c);
            }
            if(bubbles[i][j+1].v==1&&bubbles[i][j+1].color==c&&bubbles[i][j+1].vi==0){
                blast[c4].a=i;
                blast[c4].b=j+1;
                bubbles[i][j+1].vi=1;
                c4++;
                dfs(i,j+1,c);
            }
        }
        if(j=11){
            if(bubbles[i+1][j-1].v==1&&bubbles[i+1][j-1].color==c&&bubbles[i+1][j-1].vi==0){
                blast[c4].a=i+1;
                blast[c4].b=j-1;
                bubbles[i+1][j-1].vi=1;
                c4++;
                dfs(i+1,j-1,c);
            }
            if(bubbles[i][j-1].v==1&&bubbles[i][j-1].color==c&&bubbles[i][j-1].vi==0){
                blast[c4].a=i;
                blast[c4].b=j-1;
                bubbles[i][j-1].vi=1;
                c4++;
                dfs(i,j-1,c);
            }
        }
            }
        else if(j>0 && j<11){
            if(bubbles[i-1][j-1].v==1&&bubbles[i-1][j-1].color==c&&bubbles[i-1][j-1].vi==0){
                blast[c4].a=i-1;
                blast[c4].b=j-1;
                bubbles[i-1][j-1].vi=1;
                c4++;
                dfs(i-1,j-1,c);
            }
            if(bubbles[i-1][j].v==1&&bubbles[i-1][j].color==c&&bubbles[i-1][j].vi==0){
                blast[c4].a=i-1;
                blast[c4].b=j;
                bubbles[i-1][j].vi=1;
                c4++;
                dfs(i-1,j,c);
            }
            if(bubbles[i+1][j-1].v==1&&bubbles[i+1][j-1].color==c&&bubbles[i+1][j-1].vi==0){
                blast[c4].a=i+1;
                blast[c4].b=j-1;
                bubbles[i+1][j-1].vi=1;
                c4++;
                dfs(i+1,j-1,c);
            }
            if(bubbles[i+1][j].v==1&&bubbles[i+1][j].color==c&&bubbles[i+1][j].vi==0){
                blast[c4].a=i+1;
                blast[c4].b=j;
                bubbles[i+1][j].vi=1;
                c4++;
                dfs(i+1,j,c);
            }
            if(bubbles[i][j-1].v==1&&bubbles[i][j-1].color==c&&bubbles[i][j-1].vi==0){
                blast[c4].a=i;
                blast[c4].b=j-1;
                bubbles[i][j-1].vi=1;
                c4++;
                dfs(i,j-1,c);
            }
            if(bubbles[i][j+1].v==1&&bubbles[i][j+1].color==c&&bubbles[i][j+1].vi==0){
                blast[c4].a=i;
                blast[c4].b=j+1;
                bubbles[i][j+1].vi=1;
                c4++;
                dfs(i,j+1,c);
            }
        }
        if(j=0){
            if(bubbles[i-1][j].v==1&&bubbles[i-1][j].color==c&&bubbles[i-1][j].vi==0){
                blast[c4].a=i-1;
                blast[c4].b=j;
                bubbles[i-1][j].vi=1;
                c4++;
                dfs(i-1,j,c);
            }
            if(bubbles[i+1][j].v==1&&bubbles[i+1][j].color==c&&bubbles[i+1][j].vi==0){
                blast[c4].a=i+1;
                blast[c4].b=j;
                bubbles[i+1][j].vi=1;
                c4++;
                dfs(i+1,j,c);
            }
            if(bubbles[i][j+1].v==1&&bubbles[i][j+1].color==c&&bubbles[i][j+1].vi==0){
                blast[c4].a=i;
                blast[c4].b=j+1;
                bubbles[i][j+1].vi=1;
                c4++;
                dfs(i,j+1,c);
            }
        }
        if(j=11){
            if(bubbles[i-1][j-1].v==1&&bubbles[i-1][j-1].color==c&&bubbles[i-1][j-1].vi==0){
                blast[c4].a=i-1;
                blast[c4].b=j-1;
                bubbles[i-1][j-1].vi=1;
                c4++;
                dfs(i-1,j-1,c);
            }
            if(bubbles[i+1][j-1].v==1&&bubbles[i+1][j-1].color==c&&bubbles[i+1][j-1].vi==0){
                blast[c4].a=i+1;
                blast[c4].b=j-1;
                bubbles[i+1][j-1].vi=1;
                c4++;
                dfs(i+1,j-1,c);
            }
            if(bubbles[i][j-1].v==1&&bubbles[i][j-1].color==c&&bubbles[i][j-1].vi==0){
                blast[c4].a=i;
                blast[c4].b=j-1;
                bubbles[i][j-1].vi=1;
                c4++;
                dfs(i,j-1,c);
            }
        }
    }
    else{
        if(j>0 && j<10){
            if(bubbles[i-1][j+1].v==1&&bubbles[i-1][j+1].color==c&&bubbles[i-1][j+1].vi==0){
                blast[c4].a=i-1;
                blast[c4].b=j+1;
                bubbles[i-1][j+1].vi=1;
                c4++;
                dfs(i-1,j+1,c);
            }
            if(bubbles[i-1][j].v==1&&bubbles[i-1][j].color==c&&bubbles[i-1][j].vi==0){
                blast[c4].a=i-1;
                blast[c4].b=j;
                bubbles[i-1][j].vi=1;
                c4++;
                dfs(i-1,j,c);
            }
            if(bubbles[i+1][j+1].v==1&&bubbles[i+1][j+1].color==c&&bubbles[i+1][j+1].vi==0){
                blast[c4].a=i+1;
                blast[c4].b=j+1;
                bubbles[i+1][j+1].vi=1;
                c4++;
                dfs(i+1,j+1,c);
            }
            if(bubbles[i+1][j].v==1&&bubbles[i+1][j].color==c&&bubbles[i+1][j].vi==0){
                 blast[c4].a=i+1;
                blast[c4].b=j;
                bubbles[i+1][j].vi=1;
                c4++;
                dfs(i+1,j,c);
            }
            if(bubbles[i][j-1].v==1&&bubbles[i][j-1].color==c&&bubbles[i][j-1].vi==0){
                blast[c4].a=i;
                blast[c4].b=j-1;
                bubbles[i][j-1].vi=1;
                c4++;
                dfs(i,j-1,c);
            }
            if(bubbles[i][j+1].v==1&&bubbles[i][j+1].color==c&&bubbles[i][j+1].vi==0){
                blast[c4].a=i;
                blast[c4].b=j+1;
                bubbles[i][j+1].vi=1;
                c4++;
                dfs(i,j+1,c);
            }
        }
        if(j=0){
            if(bubbles[i-1][j+1].v==1&&bubbles[i-1][j+1].color==c&&bubbles[i-1][j+1].vi==0){
                blast[c4].a=i-1;
                blast[c4].b=j+1;
                bubbles[i-1][j+1].vi=1;
                c4++;
                dfs(i-1,j+1,c);
            }
            if(bubbles[i-1][j].v==1&&bubbles[i-1][j].color==c&&bubbles[i-1][j].vi==0){
                blast[c4].a=i-1;
                blast[c4].b=j;
                bubbles[i-1][j].vi=1;
                c4++;
                dfs(i-1,j,c);
            }
            if(bubbles[i+1][j+1].v==1&&bubbles[i+1][j+1].color==c&&bubbles[i+1][j+1].vi==0){
                 blast[c4].a=i+1;
                blast[c4].b=j+1;
                bubbles[i+1][j+1].vi=1;
                c4++;
                dfs(i+1,j+1,c);
            }
            if(bubbles[i+1][j].v==1&&bubbles[i+1][j].color==c&&bubbles[i+1][j].vi==0){
                blast[c4].a=i+1;
                blast[c4].b=j;
                bubbles[i+1][j].vi=1;
                c4++;
                dfs(i+1,j,c);
            }
            if(bubbles[i][j+1].v==1&&bubbles[i][j+1].color==c&&bubbles[i][j+1].vi==0){
                blast[c4].a=i;
                blast[c4].b=j+1;
                bubbles[i][j+1].vi=1;
                c4++;
                dfs(i,j+1,c);
            }
        }
        if(j=10){
            if(bubbles[i-1][j+1].v==1&&bubbles[i-1][j+1].color==c&&bubbles[i-1][j+1].vi==0){
                blast[c4].a=i-1;
                blast[c4].b=j+1;
                bubbles[i-1][j+1].vi=1;
                c4++;
                dfs(i-1,j+1,c);
            }
            if(bubbles[i-1][j].v==1&&bubbles[i-1][j].color==c&&bubbles[i-1][j].vi==0){
                blast[c4].a=i-1;
                blast[c4].b=j;
                bubbles[i-1][j].vi=1;
                c4++;
                dfs(i-1,j,c);
            }
            if(bubbles[i+1][j+1].v==1&&bubbles[i+1][j+1].color==c&&bubbles[i+1][j+1].vi==0){
                 blast[c4].a=i+1;
                blast[c4].b=j+1;
                bubbles[i+1][j+1].vi=1;
                c4++;
                dfs(i+1,j+1,c);
            }
            if(bubbles[i+1][j].v==1&&bubbles[i+1][j].color==c&&bubbles[i+1][j].vi==0){
                blast[c4].a=i+1;
                blast[c4].b=j;
                bubbles[i+1][j].vi=1;
                c4++;
                dfs(i+1,j,c);
            }
            if(bubbles[i][j-1].v==1&&bubbles[i][j-1].color==c&&bubbles[i][j-1].vi==0){
                blast[c4].a=i;
                blast[c4].b=j-1;
                bubbles[i][j-1].vi=1;
                c4++;
                dfs(i,j-1,c);
            }
        }
    }
}

void dfs1(int i,int j){
    if(i==0){
                flt=false;
            }
    if(i%2==0){
            if(i==0){
                if(j>0 && j<11){
            if(bubbles[i+1][j-1].v==1&&bubbles[i+1][j-1].vi==0){

                blast[c4].a=i+1;
                blast[c4].b=j-1;
                bubbles[i+1][j-1].vi=1;
                c4++;
                dfs1(i+1,j-1);
            }
            if(bubbles[i+1][j].v==1&&bubbles[i+1][j].vi==0){

                blast[c4].a=i+1;
                blast[c4].b=j;
                bubbles[i+1][j].vi=1;
                c4++;
                dfs1(i+1,j);
            }
            if(bubbles[i][j-1].v==1&&bubbles[i][j-1].vi==0){

                blast[c4].a=i;
                blast[c4].b=j-1;
                bubbles[i][j-1].vi=1;
                c4++;
                dfs1(i,j-1);
            }
            if(bubbles[i][j+1].v==1&&bubbles[i][j+1].vi==0){

                blast[c4].a=i;
                blast[c4].b=j+1;
                bubbles[i][j+1].vi=1;
                c4++;
                dfs1(i,j+1);
            }
        }
        if(j=0){
            if(bubbles[i+1][j].v==1&&bubbles[i+1][j].vi==0){

                blast[c4].a=i+1;
                blast[c4].b=j;
                bubbles[i+1][j].vi=1;
                c4++;
                dfs1(i+1,j);
            }
            if(bubbles[i][j+1].v==1&&bubbles[i][j+1].vi==0){

                blast[c4].a=i;
                blast[c4].b=j+1;
                bubbles[i][j+1].vi=1;
                c4++;
                dfs1(i,j+1);
            }
        }
        if(j=11){
            if(bubbles[i+1][j-1].v==1&&bubbles[i+1][j-1].vi==0){
                blast[c4].a=i+1;
                blast[c4].b=j-1;
                bubbles[i+1][j-1].vi=1;
                c4++;
                dfs1(i+1,j-1);
            }
            if(bubbles[i][j-1].v==1&&bubbles[i][j-1].vi==0){
                blast[c4].a=i;
                blast[c4].b=j-1;
                bubbles[i][j-1].vi=1;
                c4++;
                dfs1(i,j-1);
            }
        }
            }
        else if(j>0 && j<11){
            if(bubbles[i-1][j-1].v==1&&bubbles[i-1][j-1].vi==0){

                blast[c4].a=i-1;
                blast[c4].b=j-1;
                bubbles[i-1][j-1].vi=1;
                c4++;
                dfs1(i-1,j-1);
            }
            if(bubbles[i-1][j].v==1&&bubbles[i-1][j].vi==0){

                blast[c4].a=i-1;
                blast[c4].b=j;
                bubbles[i-1][j].vi=1;
                c4++;
                dfs1(i-1,j);
            }
            if(bubbles[i+1][j-1].v==1&&bubbles[i+1][j-1].vi==0){

                blast[c4].a=i+1;
                blast[c4].b=j-1;
                bubbles[i+1][j-1].vi=1;
                c4++;
                dfs1(i+1,j-1);
            }
            if(bubbles[i+1][j].v==1&&bubbles[i+1][j].vi==0){

                blast[c4].a=i+1;
                blast[c4].b=j;
                bubbles[i+1][j].vi=1;
                c4++;
                dfs1(i+1,j);
            }
            if(bubbles[i][j-1].v==1&&bubbles[i][j-1].vi==0){

                blast[c4].a=i;
                blast[c4].b=j-1;
                bubbles[i][j-1].vi=1;
                c4++;
                dfs1(i,j-1);
            }
            if(bubbles[i][j+1].v==1&&bubbles[i][j+1].vi==0){

                blast[c4].a=i;
                blast[c4].b=j+1;
                bubbles[i][j+1].vi=1;
                c4++;
                dfs1(i,j+1);
            }
        }
        if(j=0){
            if(bubbles[i-1][j].v==1&&bubbles[i-1][j].vi==0){

                blast[c4].a=i-1;
                blast[c4].b=j;
                bubbles[i-1][j].vi=1;
                c4++;
                dfs1(i-1,j);
            }
            if(bubbles[i+1][j].v==1&&bubbles[i+1][j].vi==0){

                blast[c4].a=i+1;
                blast[c4].b=j;
                bubbles[i+1][j].vi=1;
                c4++;
                dfs1(i+1,j);
            }
            if(bubbles[i][j+1].v==1&&bubbles[i][j+1].vi==0){

                blast[c4].a=i;
                blast[c4].b=j+1;
                bubbles[i][j+1].vi=1;
                c4++;
                dfs1(i,j+1);
            }
        }
        if(j=11){
            if(bubbles[i-1][j-1].v==1&&bubbles[i-1][j-1].vi==0){

                blast[c4].a=i-1;
                blast[c4].b=j-1;
                bubbles[i-1][j-1].vi=1;
                c4++;
                dfs1(i-1,j-1);
            }
            if(bubbles[i+1][j-1].v==1&&bubbles[i+1][j-1].vi==0){
                blast[c4].a=i+1;
                blast[c4].b=j-1;
                bubbles[i+1][j-1].vi=1;
                c4++;
                dfs1(i+1,j-1);
            }
            if(bubbles[i][j-1].v==1&&bubbles[i][j-1].vi==0){
                blast[c4].a=i;
                blast[c4].b=j-1;
                bubbles[i][j-1].vi=1;
                c4++;
                dfs1(i,j-1);
            }
        }
    }
    else{
        if(j>0 && j<10){
            if(bubbles[i-1][j+1].v==1&&bubbles[i-1][j+1].vi==0){
                blast[c4].a=i-1;
                blast[c4].b=j+1;
                bubbles[i-1][j+1].vi=1;
                c4++;
                dfs1(i-1,j+1);
            }
            if(bubbles[i-1][j].v==1&&bubbles[i-1][j].vi==0){
                blast[c4].a=i-1;
                blast[c4].b=j;
                bubbles[i-1][j].vi=1;
                c4++;
                dfs1(i-1,j);
            }
            if(bubbles[i+1][j+1].v==1&&bubbles[i+1][j+1].vi==0){
                blast[c4].a=i+1;
                blast[c4].b=j+1;
                bubbles[i+1][j+1].vi=1;
                c4++;
                dfs1(i+1,j+1);
            }
            if(bubbles[i+1][j].v==1&&bubbles[i+1][j].vi==0){
                 blast[c4].a=i+1;
                blast[c4].b=j;
                bubbles[i+1][j].vi=1;
                c4++;
                dfs1(i+1,j);
            }
            if(bubbles[i][j-1].v==1&&bubbles[i][j-1].vi==0){
                blast[c4].a=i;
                blast[c4].b=j-1;
                bubbles[i][j-1].vi=1;
                c4++;
                dfs1(i,j-1);
            }
            if(bubbles[i][j+1].v==1&&bubbles[i][j+1].vi==0){
                blast[c4].a=i;
                blast[c4].b=j+1;
                bubbles[i][j+1].vi=1;
                c4++;
                dfs1(i,j+1);
            }
        }
        if(j=0){
            if(bubbles[i-1][j+1].v==1&&bubbles[i-1][j+1].vi==0){
                blast[c4].a=i-1;
                blast[c4].b=j+1;
                bubbles[i-1][j+1].vi=1;
                c4++;
                dfs1(i-1,j+1);
            }
            if(bubbles[i-1][j].v==1&&bubbles[i-1][j].vi==0){
                blast[c4].a=i-1;
                blast[c4].b=j;
                bubbles[i-1][j].vi=1;
                c4++;
                dfs1(i-1,j);
            }
            if(bubbles[i+1][j+1].v==1&&bubbles[i+1][j+1].vi==0){
                 blast[c4].a=i+1;
                blast[c4].b=j+1;
                bubbles[i+1][j+1].vi=1;
                c4++;
                dfs1(i+1,j+1);
            }
            if(bubbles[i+1][j].v==1&&bubbles[i+1][j].vi==0){
                blast[c4].a=i+1;
                blast[c4].b=j;
                bubbles[i+1][j].vi=1;
                c4++;
                dfs1(i+1,j);
            }
            if(bubbles[i][j+1].v==1&&bubbles[i][j+1].vi==0){
                blast[c4].a=i;
                blast[c4].b=j+1;
                bubbles[i][j+1].vi=1;
                c4++;
                dfs1(i,j+1);
            }
        }
        if(j=10){
            if(bubbles[i-1][j+1].v==1&&bubbles[i-1][j+1].vi==0){
                blast[c4].a=i-1;
                blast[c4].b=j+1;
                bubbles[i-1][j+1].vi=1;
                c4++;
                dfs1(i-1,j+1);
            }
            if(bubbles[i-1][j].v==1&&bubbles[i-1][j].vi==0){
                blast[c4].a=i-1;
                blast[c4].b=j;
                bubbles[i-1][j].vi=1;
                c4++;
                dfs1(i-1,j);
            }
            if(bubbles[i+1][j+1].v==1&&bubbles[i+1][j+1].vi==0){
                 blast[c4].a=i+1;
                blast[c4].b=j+1;
                bubbles[i+1][j+1].vi=1;
                c4++;
                dfs1(i+1,j+1);
            }
            if(bubbles[i+1][j].v==1&&bubbles[i+1][j].vi==0){
                blast[c4].a=i+1;
                blast[c4].b=j;
                bubbles[i+1][j].vi=1;
                c4++;
                dfs1(i+1,j);
            }
            if(bubbles[i][j-1].v==1&&bubbles[i][j-1].vi==0){
                blast[c4].a=i;
                blast[c4].b=j-1;
                bubbles[i][j-1].vi=1;
                c4++;
                dfs1(i,j-1);
            }
        }
    }
}

void remove1(){
    sc+=c4;
        for(int i=0;i<c4;i++){
        bubbles[blast[i].a][blast[i].b].v=0;

    }
}

void float1(){
    c4=0;
    for(int j=0;j<15;j++){
        if(j%2==0){
            for(int i=0;i<12;i++){
                    if(bubbles[j][i].vi==0){
                c4=0;
                flt=true;
                dfs1(j,i);

                if(flt){
                    remove1();
                }
            }}
        }
       else{
            for(int i=0;i<11;i++){
                if(bubbles[j][i].vi==0){
                c4=0;
                flt=true;
                dfs1(j,i);
                if(flt){
                    remove1();
                }
            }
            }
       }
    }
}

void burst(int i,int j,int c){
    c4=0;
    blast[c4].a=i;
    blast[c4].b=j;
    bubbles[i][j].vi=1;
    c4++;
    dfs(i,j,c);

    if(c4>=3){
    remove1();
    for(int j=0;j<15;j++){
        if(j%2==0){
            for(int i=0;i<12;i++){
                bubbles[j][i].vi=0;
            }
        }
       else{
            for(int i=0;i<11;i++){
                bubbles[j][i].vi=0;
            }
       }
    }
    float1();}
    for(int j=0;j<15;j++){
        if(j%2==0){
            for(int i=0;i<12;i++){
                bubbles[j][i].vi=0;
            }
        }
       else{
            for(int i=0;i<11;i++){
                bubbles[j][i].vi=0;
            }
       }
    }
    glutPostRedisplay();
}

void score()
{
    int a[10];
    a[0]=0;
    int c=0;
    int ss=sc;
    if(sc==0) c=1;
    for(int i=0;ss!=0;i++)
    {
        a[i]=ss%10;
        ss=ss/10;
        c++;
    }
    glColor3f(0,0,0);
    glRasterPos2d(330,170);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'S');
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'C');
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'O');
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'R');
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'E');
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,':');
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'-');
    for(int i=c-1;i>=0;i--)
    {
         glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,48+a[i]);
    }
    glFlush();
}

static void key(int key, int x1, int y1)
{
    switch(key){
        case GLUT_KEY_LEFT : if(x>20&&reset==1) {xs-=220;x=xs;glutPostRedisplay();}break;
        case GLUT_KEY_RIGHT : if(x<460&&reset==1) {xs+=220;x=xs;glutPostRedisplay();}break;
        //case GLUT_KEY_UP : calculate();break;
    }
    glutPostRedisplay();
}

void mouse(int x1,int y1){
    if(max2>212){
    xl=x1;yl=y1;glutPostRedisplay();}
}

void drawline(int x1,int y1){
     theta=atan2((640-(double)y1-20),((double)x1-xs));
     //if(theta>1.570796325 && theta<4.712388975 ){
     if(theta>rbound){
        theta=rbound;
     }
     //else{
     if(theta<lbound){
        theta=lbound;
     }
    double x2=xs+(100*cos(theta)),y2=20+(100*sin(theta));
    glLineWidth(3);
    glBegin(GL_LINES);
        glVertex2d(xs,20);
        glVertex2d(x2,y2);
    glEnd();
    glFlush();
}

void timer(int val){
    if(y<max1){
        x+=10*cos(theta1);
        y+=10*sin(theta1);
    }
    else{
        y=max1;
        if((((620-max1)/34)-1)%2==0){
                int c2=0;
        for(int i=0;i<12;i++){

                c2++;
                //if(bubbles[(620-max1)/34][i].v==1){
            x3=(i*40)+20-x;
            y3=34;
            len = sqrt(x3*x3+y3*y3);
            if(bubbles[((620-max1)/34)-1][i].v==1){
            if(len<=40){
                if(i==11){
                    bubbles[(620-max1)/34][10].v=1;
                    bubbles[(620-max1)/34][10].vi=0;
                    bubbles[(620-max1)/34][10].color=c1;
                    burst((620-max1)/34,10,c1);
                }
                else{
                    if(bubbles[(620-max1)/34][i].v==0){
                    bubbles[(620-max1)/34][i].v=1;
                    bubbles[(620-max1)/34][i].vi=0;
                    bubbles[(620-max1)/34][i].color=c1;
                    burst((620-max1)/34,i,c1);}
                    else{
                        bubbles[(620-max1)/34][i-1].v=1;
                        bubbles[(620-max1)/34][i-1].vi=0;
                    bubbles[(620-max1)/34][i-1].color=c1;
                    burst((620-max1)/34,i-1,c1);
                    }
                }
                reset=1;x=xs;y=0;c1=rand1()%5;c2=0;break;
            }}
        if(c2==12){
            max1+=34;c2=0;
        }
        }}
        else{
            int c3=0;
        for(int i=0;i<11;i++){
            c3++;
            x3=(i*40)+40-x;
            y3=34;
            len = sqrt(x3*x3+y3*y3);
            if(bubbles[((620-max1)/34)-1][i].v==1){
            if(len<=40){
                    if(bubbles[(620-max1)/34][i+1].v==0){
                bubbles[(620-max1)/34][i+1].v=1;
                bubbles[(620-max1)/34][i+1].vi=0;
                bubbles[(620-max1)/34][i+1].color=c1;
                burst((620-max1)/34,i+1,c1);}
                else{
                bubbles[(620-max1)/34][i].v=1;
                bubbles[(620-max1)/34][i].vi=0;
                bubbles[(620-max1)/34][i].color=c1;
                burst((620-max1)/34,i,c1);
                }
                reset=1;x=xs;y=0;c1=rand1()%5;c3=0;break;
            }}
            if(c3==11){
            max1+=34;c3=0;

        }
        }
        }
    }
    glutPostRedisplay();
    go();
}

void gover1(){
        //glPointSize(10);
        glColor3f(1.0,0,0);
        glRasterPos2i(170,170);
        if(ck!=5){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'G');
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'A');
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'M');
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'E');
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,' ');
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'O');
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'V');
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'E');
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'R');}
        else{
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'C');
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'O');
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'N');
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'G');
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'R');
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'A');
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'T');
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'S');
        }
        glFlush();
}


void mymouse(int button,int state,int x1,int y1){
    if(button==GLUT_LEFT_BUTTON&&state==GLUT_DOWN){
           // cout << max2 << endl;
        if(max2<=212){
            gover=true;

        }
        if(!gover){
        theta1=theta;
        reset=0;
        max1=max2;
        go();}
    }
    if(button==GLUT_RIGHT_BUTTON&&state==GLUT_DOWN){

    }
}

void go(){
    if(x<20){x=20;theta1=PI-theta1;}
    if(x>460){x=460;theta1=PI-theta1;}
    if(y>620){
        y=620;
        double temp=(x-20)/40;
        x=(int)temp;
        if(temp-x>=0.5){
            x++;
        }
        bubbles[0][x].v=1;
        bubbles[0][x].color=c1;
        reset=1;x=xs;y=0;c1=rand1()%5;
    }
    if(reset==0)
        glutTimerFunc(1,timer,0);
}

static void idle(void)
{
    glutPostRedisplay();
}



int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(480,640);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);

    glutCreateWindow("Bubble Shooter");
    inits();
    glutDisplayFunc(display);
    glutSpecialFunc(key);
    glutMouseFunc(mymouse);
    glutPassiveMotionFunc(mouse);
    glClearColor(0,0,0,1);
    gluOrtho2D(0,480,0,640);
    glutMainLoop();
    return EXIT_SUCCESS;
}
