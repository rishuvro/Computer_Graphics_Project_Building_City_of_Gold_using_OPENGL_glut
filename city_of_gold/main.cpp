#include <iostream>
#include <GL/gl.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <bits/stdc++.h>
#include <GL/gl.h>
#include <windows.h>
#include<mmsystem.h>
#include <math.h>

GLfloat eyeX = 10;
GLfloat eyeY = 40;
GLfloat eyeZ = 180;

GLfloat lookX = 0;
GLfloat lookY = 0;
GLfloat lookZ = 0;

GLfloat zoom = 1.0;
GLfloat zoomFactor = 0.1;

static GLfloat v_cube[8][3] =
{
    {0, 0, 0},
    {0, 0, 1},
    {0, 1, 0},
    {0, 1, 1},
    {1, 0, 0},
    {1, 0, 1},
    {1, 1, 0},
    {1, 1, 1}
};

static GLubyte c_ind[6][4] =
{
    {0, 2, 6, 4},
    {1, 5, 7, 3},
    {0, 4, 5, 1},
    {2, 3, 7, 6},
    {0, 1, 3, 2},
    {4, 6, 7, 5}
};

static void getNormal3p(GLfloat x1, GLfloat y1, GLfloat z1, GLfloat x2, GLfloat y2, GLfloat z2, GLfloat x3, GLfloat y3, GLfloat z3)
{
    GLfloat Ux, Uy, Uz, Vx, Vy, Vz, Nx, Ny, Nz;

    Ux = x2 - x1;
    Uy = y2 - y1;
    Uz = z2 - z1;

    Vx = x3 - x1;
    Vy = y3 - y1;
    Vz = z3 - z1;

    Nx = Uy * Vz - Uz * Vy;
    Ny = Uz * Vx - Ux * Vz;
    Nz = Ux * Vy - Uy * Vx;

    glNormal3f(Nx, Ny, Nz);
}

void cube(float r, float g, float b)
{
    glBegin(GL_QUADS);
    glColor3f(r, g, b);
    for (GLint i = 0; i < 6; i++)
    {
        getNormal3p(v_cube[c_ind[i][0]][0], v_cube[c_ind[i][0]][1], v_cube[c_ind[i][0]][2],
                    v_cube[c_ind[i][1]][0], v_cube[c_ind[i][1]][1], v_cube[c_ind[i][1]][2],
                    v_cube[c_ind[i][2]][0], v_cube[c_ind[i][2]][1], v_cube[c_ind[i][2]][2]);

        for (GLint j = 0; j < 4; j++)
        {
            glVertex3fv(&v_cube[c_ind[i][j]][0]);
        }
    }
    glEnd();
}

static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-3, 3, -3, 3, 2.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(eyeX, eyeY, eyeZ, lookX, lookY, lookZ, 0, 1, 0);

    int windowWidth = glutGet(GLUT_WINDOW_WIDTH);
    int windowHeight = glutGet(GLUT_WINDOW_HEIGHT);
    glViewport(0, 0, windowWidth, windowHeight);

    glPushMatrix();

    // Land
    glPushMatrix();
    glTranslated(-200, -0.1, -200);
    glScaled(500, 1, 400);
    cube(0.0, 0.7, 0.0);
    glPopMatrix();

    // Road
    glPushMatrix();
    glTranslated(0, 0.1, -200);
    glScaled(30, 1, 400);
    cube(0.38, 0.28, 0.2);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-1, 0.1, -200);
    glScaled(1, 1, 400);
    cube(1, 1, 1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(30, 0.1, -200);
    glScaled(1, 1, 400);
    cube(1, 1, 1);
    glPopMatrix();

    // Middle divider
    glPushMatrix();
    glTranslated(15, 0.2, -200);
    glScaled(2, 1, 400);
    cube(1, 1, 1);
    glPopMatrix();














   //human
glPushMatrix();
glTranslated(10,2.2,20);
glScaled(0.3,0.2,0.3);
  //body
    glPushMatrix();
    glTranslated(0,0,0);
    glScaled(8,5,.2);
    cube(0.196078,0.6,0.8);
    glPopMatrix();

    //eye
    glPushMatrix();
    glTranslated(2.7,6.5,0);
    glScaled(.5,.5,.2);
    cube(0,0,0);
    glPopMatrix();

    glPushMatrix();
    glTranslated(4.8,6.5,0);
    glScaled(.5,.5,.2);
    cube(0,0,0);
    glPopMatrix();

    //hand
    glPushMatrix();
    glTranslated(-2.4,.4,0);
    glRotated(-30,0,0,1);

    glPushMatrix();
    glTranslated(-3,3,0);
    glScaled(3,2,.2);
    cube(0.196078,0.6,0.8);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-3,-1,0);
    glScaled(3,4,.2);
    cube(0.96,0.80,0.69);
    glPopMatrix();

    glPopMatrix();

    glPushMatrix();

    glTranslated(13,2,0);
    glRotated(30,0,0,1);

    glPushMatrix();
    glTranslated(-3,3,0);
    glScaled(3,2,.2);
    cube(0.196078,0.6,0.8);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-3,-1,0);
    glScaled(3,4,.2);
    cube(0.96,0.80,0.69);
    glPopMatrix();


    glPopMatrix();
    //head
    glPushMatrix();
    glTranslated(2,5,0);
    glScaled(4,3,.2);
    cube(0.96,0.80,0.69);
    glPopMatrix();


    //leg
    glPushMatrix();
    glRotated(30,1,0,0);
    glPushMatrix();
    glTranslated(0,-5,0);
    glScaled(4,5,.2);
    cube(0,0,1);
    glPopMatrix();


    glPushMatrix();
    glTranslated(0,-6,0);
    glScaled(4,1,.2);
    cube(0.137255,0.556863,0.137255);
    glPopMatrix();

    glPopMatrix();

    glPushMatrix();
    glTranslated(4,-5,0);
    glScaled(4,5,.2);
    cube(0,0,1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(4,-6,0);
    glScaled(4,1,.2);
    cube(0.137255,0.556863,0.137255);
    glPopMatrix();
glPopMatrix();


//second human
glPushMatrix();
glTranslated(-5,0,0);
 //human
glPushMatrix();
glTranslated(10,2.2,20);
glScaled(0.3,0.2,0.3);
  //body
    glPushMatrix();
    glTranslated(0,0,0);
    glScaled(8,5,.2);
    cube(0.196078,0.6,0.8);
    glPopMatrix();

    //eye
    glPushMatrix();
    glTranslated(2.7,6.5,0);
    glScaled(.5,.5,.2);
    cube(0,0,0);
    glPopMatrix();

    glPushMatrix();
    glTranslated(4.8,6.5,0);
    glScaled(.5,.5,.2);
    cube(0,0,0);
    glPopMatrix();

    //hand
    glPushMatrix();
    glTranslated(-2.4,.4,0);
    glRotated(-30,0,0,1);

    glPushMatrix();
    glTranslated(-3,3,0);
    glScaled(3,2,.2);
    cube(0.196078,0.6,0.8);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-3,-1,0);
    glScaled(3,4,.2);
    cube(0.96,0.80,0.69);
    glPopMatrix();

    glPopMatrix();

    glPushMatrix();

    glTranslated(13,2,0);
    glRotated(30,0,0,1);

    glPushMatrix();
    glTranslated(-3,3,0);
    glScaled(3,2,.2);
    cube(0.196078,0.6,0.8);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-3,-1,0);
    glScaled(3,4,.2);
    cube(0.96,0.80,0.69);
    glPopMatrix();


    glPopMatrix();
    //head
    glPushMatrix();
    glTranslated(2,5,0);
    glScaled(4,3,.2);
    cube(0.96,0.80,0.69);
    glPopMatrix();


    //leg
    glPushMatrix();
    glRotated(30,1,0,0);
    glPushMatrix();
    glTranslated(0,-5,0);
    glScaled(4,5,.2);
    cube(0,0,1);
    glPopMatrix();


    glPushMatrix();
    glTranslated(0,-6,0);
    glScaled(4,1,.2);
    cube(0.137255,0.556863,0.137255);
    glPopMatrix();

    glPopMatrix();

    glPushMatrix();
    glTranslated(4,-5,0);
    glScaled(4,5,.2);
    cube(0,0,1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(4,-6,0);
    glScaled(4,1,.2);
    cube(0.137255,0.556863,0.137255);
    glPopMatrix();
glPopMatrix();

glPopMatrix();


//human 3
glPushMatrix();
glTranslated(10,0,0);
 //human
glPushMatrix();
glTranslated(10,2.2,20);
glScaled(0.3,0.2,0.3);
  //body
    glPushMatrix();
    glTranslated(0,0,0);
    glScaled(8,5,.2);
    cube(0.196078,0.6,0.8);
    glPopMatrix();

    //eye
    glPushMatrix();
    glTranslated(2.7,6.5,0);
    glScaled(.5,.5,.2);
    cube(0,0,0);
    glPopMatrix();

    glPushMatrix();
    glTranslated(4.8,6.5,0);
    glScaled(.5,.5,.2);
    cube(0,0,0);
    glPopMatrix();

    //hand
    glPushMatrix();
    glTranslated(-2.4,.4,0);
    glRotated(-30,0,0,1);

    glPushMatrix();
    glTranslated(-3,3,0);
    glScaled(3,2,.2);
    cube(0.196078,0.6,0.8);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-3,-1,0);
    glScaled(3,4,.2);
    cube(0.96,0.80,0.69);
    glPopMatrix();

    glPopMatrix();

    glPushMatrix();

    glTranslated(13,2,0);
    glRotated(30,0,0,1);

    glPushMatrix();
    glTranslated(-3,3,0);
    glScaled(3,2,.2);
    cube(0.196078,0.6,0.8);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-3,-1,0);
    glScaled(3,4,.2);
    cube(0.96,0.80,0.69);
    glPopMatrix();


    glPopMatrix();
    //head
    glPushMatrix();
    glTranslated(2,5,0);
    glScaled(4,3,.2);
    cube(0.96,0.80,0.69);
    glPopMatrix();


    //leg
    glPushMatrix();
    glRotated(30,1,0,0);
    glPushMatrix();
    glTranslated(0,-5,0);
    glScaled(4,5,.2);
    cube(0,0,1);
    glPopMatrix();


    glPushMatrix();
    glTranslated(0,-6,0);
    glScaled(4,1,.2);
    cube(0.137255,0.556863,0.137255);
    glPopMatrix();

    glPopMatrix();

    glPushMatrix();
    glTranslated(4,-5,0);
    glScaled(4,5,.2);
    cube(0,0,1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(4,-6,0);
    glScaled(4,1,.2);
    cube(0.137255,0.556863,0.137255);
    glPopMatrix();
glPopMatrix();

glPopMatrix();


//human 4

glPushMatrix();
glTranslated(-17,0,7);
 //human
glPushMatrix();
glTranslated(10,2.2,20);
glScaled(0.3,0.2,0.3);
  //body
    glPushMatrix();
    glTranslated(0,0,0);
    glScaled(8,5,.2);
    cube(0.196078,0.6,0.8);
    glPopMatrix();

    //eye
    glPushMatrix();
    glTranslated(2.7,6.5,0);
    glScaled(.5,.5,.2);
    cube(0,0,0);
    glPopMatrix();

    glPushMatrix();
    glTranslated(4.8,6.5,0);
    glScaled(.5,.5,.2);
    cube(0,0,0);
    glPopMatrix();

    //hand
    glPushMatrix();
    glTranslated(-2.4,.4,0);
    glRotated(-30,0,0,1);

    glPushMatrix();
    glTranslated(-3,3,0);
    glScaled(3,2,.2);
    cube(0.196078,0.6,0.8);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-3,-1,0);
    glScaled(3,4,.2);
    cube(0.96,0.80,0.69);
    glPopMatrix();

    glPopMatrix();

    glPushMatrix();

    glTranslated(13,2,0);
    glRotated(30,0,0,1);

    glPushMatrix();
    glTranslated(-3,3,0);
    glScaled(3,2,.2);
    cube(0.196078,0.6,0.8);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-3,-1,0);
    glScaled(3,4,.2);
    cube(0.96,0.80,0.69);
    glPopMatrix();


    glPopMatrix();
    //head
    glPushMatrix();
    glTranslated(2,5,0);
    glScaled(4,3,.2);
    cube(0.96,0.80,0.69);
    glPopMatrix();


    //leg
    glPushMatrix();
    glRotated(30,1,0,0);
    glPushMatrix();
    glTranslated(0,-5,0);
    glScaled(4,5,.2);
    cube(0,0,1);
    glPopMatrix();


    glPushMatrix();
    glTranslated(0,-6,0);
    glScaled(4,1,.2);
    cube(0.137255,0.556863,0.137255);
    glPopMatrix();

    glPopMatrix();

    glPushMatrix();
    glTranslated(4,-5,0);
    glScaled(4,5,.2);
    cube(0,0,1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(4,-6,0);
    glScaled(4,1,.2);
    cube(0.137255,0.556863,0.137255);
    glPopMatrix();
glPopMatrix();

glPopMatrix();



//human 5
glPushMatrix();
glTranslated(-35,0,0);
 //human
glPushMatrix();
glTranslated(10,2.2,20);
glScaled(0.3,0.2,0.3);
  //body
    glPushMatrix();
    glTranslated(0,0,0);
    glScaled(8,5,.2);
    cube(0.196078,0.6,0.8);
    glPopMatrix();

    //eye
    glPushMatrix();
    glTranslated(2.7,6.5,0);
    glScaled(.5,.5,.2);
    cube(0,0,0);
    glPopMatrix();

    glPushMatrix();
    glTranslated(4.8,6.5,0);
    glScaled(.5,.5,.2);
    cube(0,0,0);
    glPopMatrix();

    //hand
    glPushMatrix();
    glTranslated(-2.4,.4,0);
    glRotated(-30,0,0,1);

    glPushMatrix();
    glTranslated(-3,3,0);
    glScaled(3,2,.2);
    cube(0.196078,0.6,0.8);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-3,-1,0);
    glScaled(3,4,.2);
    cube(0.96,0.80,0.69);
    glPopMatrix();

    glPopMatrix();

    glPushMatrix();

    glTranslated(13,2,0);
    glRotated(30,0,0,1);

    glPushMatrix();
    glTranslated(-3,3,0);
    glScaled(3,2,.2);
    cube(0.196078,0.6,0.8);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-3,-1,0);
    glScaled(3,4,.2);
    cube(0.96,0.80,0.69);
    glPopMatrix();


    glPopMatrix();
    //head
    glPushMatrix();
    glTranslated(2,5,0);
    glScaled(4,3,.2);
    cube(0.96,0.80,0.69);
    glPopMatrix();


    //leg
    glPushMatrix();
    glRotated(30,1,0,0);
    glPushMatrix();
    glTranslated(0,-5,0);
    glScaled(4,5,.2);
    cube(0,0,1);
    glPopMatrix();


    glPushMatrix();
    glTranslated(0,-6,0);
    glScaled(4,1,.2);
    cube(0.137255,0.556863,0.137255);
    glPopMatrix();

    glPopMatrix();

    glPushMatrix();
    glTranslated(4,-5,0);
    glScaled(4,5,.2);
    cube(0,0,1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(4,-6,0);
    glScaled(4,1,.2);
    cube(0.137255,0.556863,0.137255);
    glPopMatrix();
glPopMatrix();

glPopMatrix();


//human 6
glPushMatrix();
glTranslated(50,0,30);
 //human
glPushMatrix();
glTranslated(10,2.2,20);
glScaled(0.3,0.2,0.3);
  //body
    glPushMatrix();
    glTranslated(0,0,0);
    glScaled(8,5,.2);
    cube(0.196078,0.6,0.8);
    glPopMatrix();

    //eye
    glPushMatrix();
    glTranslated(2.7,6.5,0);
    glScaled(.5,.5,.2);
    cube(0,0,0);
    glPopMatrix();

    glPushMatrix();
    glTranslated(4.8,6.5,0);
    glScaled(.5,.5,.2);
    cube(0,0,0);
    glPopMatrix();

    //hand
    glPushMatrix();
    glTranslated(-2.4,.4,0);
    glRotated(-30,0,0,1);

    glPushMatrix();
    glTranslated(-3,3,0);
    glScaled(3,2,.2);
    cube(0.196078,0.6,0.8);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-3,-1,0);
    glScaled(3,4,.2);
    cube(0.96,0.80,0.69);
    glPopMatrix();

    glPopMatrix();

    glPushMatrix();

    glTranslated(13,2,0);
    glRotated(30,0,0,1);

    glPushMatrix();
    glTranslated(-3,3,0);
    glScaled(3,2,.2);
    cube(0.196078,0.6,0.8);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-3,-1,0);
    glScaled(3,4,.2);
    cube(0.96,0.80,0.69);
    glPopMatrix();


    glPopMatrix();
    //head
    glPushMatrix();
    glTranslated(2,5,0);
    glScaled(4,3,.2);
    cube(0.96,0.80,0.69);
    glPopMatrix();


    //leg
    glPushMatrix();
    glRotated(30,1,0,0);
    glPushMatrix();
    glTranslated(0,-5,0);
    glScaled(4,5,.2);
    cube(0,0,1);
    glPopMatrix();


    glPushMatrix();
    glTranslated(0,-6,0);
    glScaled(4,1,.2);
    cube(0.137255,0.556863,0.137255);
    glPopMatrix();

    glPopMatrix();

    glPushMatrix();
    glTranslated(4,-5,0);
    glScaled(4,5,.2);
    cube(0,0,1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(4,-6,0);
    glScaled(4,1,.2);
    cube(0.137255,0.556863,0.137255);
    glPopMatrix();
glPopMatrix();

glPopMatrix();


//human 7
glPushMatrix();
glTranslated(60,0,35);
 //human
glPushMatrix();
glTranslated(10,2.2,20);
glScaled(0.3,0.2,0.3);
  //body
    glPushMatrix();
    glTranslated(0,0,0);
    glScaled(8,5,.2);
    cube(0.196078,0.6,0.8);
    glPopMatrix();

    //eye
    glPushMatrix();
    glTranslated(2.7,6.5,0);
    glScaled(.5,.5,.2);
    cube(0,0,0);
    glPopMatrix();

    glPushMatrix();
    glTranslated(4.8,6.5,0);
    glScaled(.5,.5,.2);
    cube(0,0,0);
    glPopMatrix();

    //hand
    glPushMatrix();
    glTranslated(-2.4,.4,0);
    glRotated(-30,0,0,1);

    glPushMatrix();
    glTranslated(-3,3,0);
    glScaled(3,2,.2);
    cube(0.196078,0.6,0.8);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-3,-1,0);
    glScaled(3,4,.2);
    cube(0.96,0.80,0.69);
    glPopMatrix();

    glPopMatrix();

    glPushMatrix();

    glTranslated(13,2,0);
    glRotated(30,0,0,1);

    glPushMatrix();
    glTranslated(-3,3,0);
    glScaled(3,2,.2);
    cube(0.196078,0.6,0.8);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-3,-1,0);
    glScaled(3,4,.2);
    cube(0.96,0.80,0.69);
    glPopMatrix();


    glPopMatrix();
    //head
    glPushMatrix();
    glTranslated(2,5,0);
    glScaled(4,3,.2);
    cube(0.96,0.80,0.69);
    glPopMatrix();


    //leg
    glPushMatrix();
    glRotated(30,1,0,0);
    glPushMatrix();
    glTranslated(0,-5,0);
    glScaled(4,5,.2);
    cube(0,0,1);
    glPopMatrix();


    glPushMatrix();
    glTranslated(0,-6,0);
    glScaled(4,1,.2);
    cube(0.137255,0.556863,0.137255);
    glPopMatrix();

    glPopMatrix();

    glPushMatrix();
    glTranslated(4,-5,0);
    glScaled(4,5,.2);
    cube(0,0,1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(4,-6,0);
    glScaled(4,1,.2);
    cube(0.137255,0.556863,0.137255);
    glPopMatrix();
glPopMatrix();

glPopMatrix();


//human 8
glPushMatrix();
glTranslated(65,0,30);
 //human
glPushMatrix();
glTranslated(10,2.2,20);
glScaled(0.3,0.2,0.3);
  //body
    glPushMatrix();
    glTranslated(0,0,0);
    glScaled(8,5,.2);
    cube(0.196078,0.6,0.8);
    glPopMatrix();

    //eye
    glPushMatrix();
    glTranslated(2.7,6.5,0);
    glScaled(.5,.5,.2);
    cube(0,0,0);
    glPopMatrix();

    glPushMatrix();
    glTranslated(4.8,6.5,0);
    glScaled(.5,.5,.2);
    cube(0,0,0);
    glPopMatrix();

    //hand
    glPushMatrix();
    glTranslated(-2.4,.4,0);
    glRotated(-30,0,0,1);

    glPushMatrix();
    glTranslated(-3,3,0);
    glScaled(3,2,.2);
    cube(0.196078,0.6,0.8);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-3,-1,0);
    glScaled(3,4,.2);
    cube(0.96,0.80,0.69);
    glPopMatrix();

    glPopMatrix();

    glPushMatrix();

    glTranslated(13,2,0);
    glRotated(30,0,0,1);

    glPushMatrix();
    glTranslated(-3,3,0);
    glScaled(3,2,.2);
    cube(0.196078,0.6,0.8);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-3,-1,0);
    glScaled(3,4,.2);
    cube(0.96,0.80,0.69);
    glPopMatrix();


    glPopMatrix();
    //head
    glPushMatrix();
    glTranslated(2,5,0);
    glScaled(4,3,.2);
    cube(0.96,0.80,0.69);
    glPopMatrix();


    //leg
    glPushMatrix();
    glRotated(30,1,0,0);
    glPushMatrix();
    glTranslated(0,-5,0);
    glScaled(4,5,.2);
    cube(0,0,1);
    glPopMatrix();


    glPushMatrix();
    glTranslated(0,-6,0);
    glScaled(4,1,.2);
    cube(0.137255,0.556863,0.137255);
    glPopMatrix();

    glPopMatrix();

    glPushMatrix();
    glTranslated(4,-5,0);
    glScaled(4,5,.2);
    cube(0,0,1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(4,-6,0);
    glScaled(4,1,.2);
    cube(0.137255,0.556863,0.137255);
    glPopMatrix();
glPopMatrix();

glPopMatrix();



















// First temple
    glPushMatrix();
    glTranslated(-20, 0.2, 10);
    glScaled(15, 5, 15);
    cube(1.0, 0.87, 0.0);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-18, 5.2, 12);
    glScaled(10, 5, 10);
    cube(1.0, 0.80, 0.0);
//door
    glPopMatrix();
    glPushMatrix();
    glTranslated(-8, 5.2, 16);
    glScaled(0.1, 4, 1);
    cube(0.2, 0.1, 0.2);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-17, 10.2, 13);
    glScaled(7, 4, 7);
    cube(1.0, 0.70, 0.0);
    glPopMatrix();
    //door
    glPopMatrix();
    glPushMatrix();
    glTranslated(-10, 10.2, 13);
    glScaled(0.3, 4, 1);
    cube(0.2, 0.2, 0.4);
    glPopMatrix();


    glPushMatrix();
    glTranslated(-10, 10.2, 19);
    glScaled(0.3, 4, 1);
    cube(0.2, 0.2, 0.4);
    glPopMatrix();

        glPushMatrix();
    glTranslated(-15, 14.2, 15);
    glScaled(4, 4, 4);
    cube(1.0, 0.60, 0.0);
        glPopMatrix();



        glPushMatrix();
        glTranslated(0,0,50);
        // First temple
    glPushMatrix();
    glTranslated(-20, 0.2, 10);
    glScaled(15, 5, 15);
    cube(1.0, 0.87, 0.0);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-18, 5.2, 12);
    glScaled(10, 5, 10);
    cube(1.0, 0.80, 0.0);
//door
    glPopMatrix();
    glPushMatrix();
    glTranslated(-8, 5.2, 16);
    glScaled(0.1, 4, 1);
    cube(0.2, 0.1, 0.2);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-17, 10.2, 13);
    glScaled(7, 4, 7);
    cube(1.0, 0.70, 0.0);
    glPopMatrix();
    //door
    glPopMatrix();
    glPushMatrix();
    glTranslated(-10, 10.2, 13);
    glScaled(0.3, 4, 1);
    cube(0.2, 0.2, 0.4);
    glPopMatrix();


    glPushMatrix();
    glTranslated(-10, 10.2, 19);
    glScaled(0.3, 4, 1);
    cube(0.2, 0.2, 0.4);
    glPopMatrix();

        glPushMatrix();
    glTranslated(-15, 14.2, 15);
    glScaled(4, 4, 4);
    cube(1.0, 0.60, 0.0);
        glPopMatrix();
        glPopMatrix();


         glPushMatrix();
        glTranslated(0,0,70);
        // First temple
    glPushMatrix();
    glTranslated(-20, 0.2, 10);
    glScaled(15, 5, 15);
    cube(1.0, 0.87, 0.0);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-18, 5.2, 12);
    glScaled(10, 5, 10);
    cube(1.0, 0.80, 0.0);
//door
    glPopMatrix();
    glPushMatrix();
    glTranslated(-8, 5.2, 16);
    glScaled(0.1, 4, 1);
    cube(0.2, 0.1, 0.2);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-17, 10.2, 13);
    glScaled(7, 4, 7);
    cube(1.0, 0.70, 0.0);
    glPopMatrix();
    //door
    glPopMatrix();
    glPushMatrix();
    glTranslated(-10, 10.2, 13);
    glScaled(0.3, 4, 1);
    cube(0.2, 0.2, 0.4);
    glPopMatrix();


    glPushMatrix();
    glTranslated(-10, 10.2, 19);
    glScaled(0.3, 4, 1);
    cube(0.2, 0.2, 0.4);
    glPopMatrix();

        glPushMatrix();
    glTranslated(-15, 14.2, 15);
    glScaled(4, 4, 4);
    cube(1.0, 0.60, 0.0);
        glPopMatrix();
        glPopMatrix();


         glPushMatrix();
        glTranslated(0,0,90);
        // First temple
    glPushMatrix();
    glTranslated(-20, 0.2, 10);
    glScaled(15, 5, 15);
    cube(1.0, 0.87, 0.0);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-18, 5.2, 12);
    glScaled(10, 5, 10);
    cube(1.0, 0.80, 0.0);
//door
    glPopMatrix();
    glPushMatrix();
    glTranslated(-8, 5.2, 16);
    glScaled(0.1, 4, 1);
    cube(0.2, 0.1, 0.2);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-17, 10.2, 13);
    glScaled(7, 4, 7);
    cube(1.0, 0.70, 0.0);
    glPopMatrix();
    //door
    glPopMatrix();
    glPushMatrix();
    glTranslated(-10, 10.2, 13);
    glScaled(0.3, 4, 1);
    cube(0.2, 0.2, 0.4);
    glPopMatrix();


    glPushMatrix();
    glTranslated(-10, 10.2, 19);
    glScaled(0.3, 4, 1);
    cube(0.2, 0.2, 0.4);
    glPopMatrix();

        glPushMatrix();
    glTranslated(-15, 14.2, 15);
    glScaled(4, 4, 4);
    cube(1.0, 0.60, 0.0);
        glPopMatrix();
        glPopMatrix();

        //second temple
    glPushMatrix();
    glTranslated(35, 0.2, 10);
    glScaled(15, 5, 15);
    cube(1.0, 0.87, 0.0);
    glPopMatrix();

    glPushMatrix();
    glTranslated(37, 5.2, 12);
    glScaled(10, 5, 10);
    cube(1.0, 0.80, 0.0);
//door
    glPopMatrix();
    glPushMatrix();
    glTranslated(37, 5.2, 16);
    glScaled(-0.5, 4, 1);
    cube(0.2, 0.1, 0.2);
    glPopMatrix();

    glPushMatrix();
    glTranslated(39, 10.2, 13);
    glScaled(7, 4, 7);
    cube(1.0, 0.70, 0.0);
    glPopMatrix();
    //door
    glPopMatrix();
    glPushMatrix();
    glTranslated(39, 10.2, 13);
    glScaled(-0.3, 4, 1);
    cube(0.2, 0.2, 0.4);
    glPopMatrix();

    glPushMatrix();
    glTranslated(39, 10.2, 19);
    glScaled(-0.3, 4, 1);
    cube(0.2, 0.2, 0.4);
    glPopMatrix();

        glPushMatrix();
    glTranslated(41, 14.2, 15);
    glScaled(4, 4, 4);
    cube(1.0, 0.60, 0.0);
        glPopMatrix();

// first tree

glPushMatrix();
        glTranslated(-10,0.3,32);
        glScaled(1.5,10,1.5);
       cube(0.44, 0.33, 0.23);
       glPopMatrix();

        glPushMatrix();
        glTranslated(-13,10,29);
        glScaled(8,3,8);
       cube(0, 0.4, 0);
       glPopMatrix();

        glPushMatrix();
        glTranslated(-11,13,31);
        glScaled(5,3,5);
       cube(0, 0.4, 0);
       glPopMatrix();

        glPushMatrix();
        glTranslated(-9,16,32);
        glScaled(3,2,3);
       cube(0, 0.4, 0);
       glPopMatrix();

       //second tree

glPushMatrix();
        glTranslated(35,0.3,32);
        glScaled(1.5,10,1.5);
       cube(0.44, 0.33, 0.23);
       glPopMatrix();

        glPushMatrix();
        glTranslated(32,10,29);
        glScaled(8,3,8);
       cube(0, 0.4, 0);
       glPopMatrix();

        glPushMatrix();
        glTranslated(33,13,31);
        glScaled(5,3,5);
       cube(0, 0.4, 0);
       glPopMatrix();

        glPushMatrix();
        glTranslated(34,16,32);
        glScaled(3,2,3);
       cube(0, 0.4, 0);
       glPopMatrix();
// gate


glPushMatrix();
    glTranslated(-11, 0.2, -5);
    glScaled(10, 5, 10);
cube(0.8, 0.7, 0.5);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-8, 5.2, -3);
    glScaled(5, 40, 5);
cube(0.5, 0.2, 0.1);
    glPopMatrix();

glPushMatrix();
    glTranslated(31, 0.2, -5);
    glScaled(10, 5, 10);
cube(0.8, 0.7, 0.5);
    glPopMatrix();

        glPushMatrix();
    glTranslated(33, 5.2, -3);
    glScaled(5, 40, 5);
cube(0.5, 0.2, 0.1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-8, 40.2, -3);
    glScaled(42, 5, 5);
cube(0.5, 0.2, 0.1);
    glPopMatrix();

//gate door
    glPushMatrix();
    glTranslated(-3, 5.2, -3);
    glRotated(45,0,2,0);
    glScaled(20, 35, 5);
cube(0.35, 0.21, 0.12);
    glPopMatrix();




    glPushMatrix();
    glTranslated(33, 5.2, -3);
    glRotated(-45,0,2,0);
    glScaled(-15, 35, 5);
cube(0.35, 0.21, 0.12);
    glPopMatrix();



    //Name of the city
    //c
    glPushMatrix();
    glTranslated(-40, 60, -3);
    glScaled(5, 1, 1);
    cube(0.75, 0.75, 0.75);
    glPopMatrix();


    glPushMatrix();
    glTranslated(-40, 60, -3);
    glScaled(1, 10, 1);
    cube(0.75, 0.75, 0.75);
    glPopMatrix();

glPushMatrix();
    glTranslated(-40, 70, -3);
    glScaled(5, 1, 1);
    cube(0.75, 0.75, 0.75);
    glPopMatrix();

//I



    glPushMatrix();
    glTranslated(-30.4, 60, -3);
    glScaled(1, 11, 1);
    cube(0.75, 0.75, 0.75);
    glPopMatrix();




//T



glPushMatrix();
    glTranslated(-23.6, 60, -3);
    glScaled(1, 10, 1);
    cube(0.75, 0.75, 0.75);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-27, 70, -3);
    glScaled(7, 1, 1);
    cube(0.75, 0.75, 0.75);
    glPopMatrix();

//y

glPushMatrix();
glTranslated(-16, 60, -3);
glScaled(1, 5, 1);
cube(0.75, 0.75, 0.75);
glPopMatrix();

glPushMatrix();
glTranslated(-15, 65, -3);
glRotated(53,0,0,1);
glScaled(6.5, 1, 1);
cube(0.75, 0.75, 0.75);
glPopMatrix();

glPushMatrix();
glTranslated(-15, 65, -3);
glRotated(113,0,0,1);
glScaled(6.5, 1, 1);
cube(0.75, 0.75, 0.75);
glPopMatrix();


//O

glPushMatrix();
glTranslated(0, 60, -3);
glScaled(5, 1, 1);
cube(0.75, 0.75, 0.75);
glPopMatrix();

glPushMatrix();
glTranslated(0, 60, -3);
glScaled(1, 10, 1);
cube(0.75, 0.75, 0.75);
glPopMatrix();

glPushMatrix();
glTranslated(0, 70, -3);
glScaled(5, 1, 1);
cube(0.75, 0.75, 0.75);
glPopMatrix();

glPushMatrix();
glTranslated(5, 71, -3);
glScaled(1, -11, 1);
cube(0.75, 0.75, 0.75);
glPopMatrix();

glPushMatrix();
glTranslated(5, 60, -3);
glScaled(-5, 1, 1);
cube(0.75, 0.75, 0.75);
glPopMatrix();

//F

glPushMatrix();
glTranslated(8, 60, -3);
glScaled(1, 10, 1);
cube(0.75, 0.75, 0.75);
glPopMatrix();

glPushMatrix();
glTranslated(8, 65, -3);
glScaled(3, 1, 1);
cube(0.75, 0.75, 0.75);
glPopMatrix();

glPushMatrix();
glTranslated(8, 70, -3);
glScaled(6, 1, 1);
cube(0.75, 0.75, 0.75);
glPopMatrix();


//G
glPushMatrix();
glTranslated(20, 60, -3);
glScaled(5, 1, 1);
cube(0.75, 0.75, 0.75);
glPopMatrix();

glPushMatrix();
glTranslated(25, 60, -3);
glScaled(1, 3, 1);
cube(0.75, 0.75, 0.75);
glPopMatrix();

glPushMatrix();
glTranslated(26, 63, -3);
glScaled(-2, 1, 1);
cube(0.75, 0.75, 0.75);
glPopMatrix();

glPushMatrix();
glTranslated(23, 64, -3);
glScaled(1, -2, 1);
cube(0.75, 0.75, 0.75);
glPopMatrix();

glPushMatrix();
glTranslated(20, 60, -3);
glScaled(1, 10, 1);
cube(0.75, 0.75, 0.75);
glPopMatrix();

glPushMatrix();
glTranslated(20, 70, -3);
glScaled(6, 1, 1);
cube(0.75, 0.75, 0.75);
glPopMatrix();

glPushMatrix();
glTranslated(25, 70, -3);
glScaled(1, -2, 1);
cube(0.75, 0.75, 0.75);
glPopMatrix();


//O

glPushMatrix();
glTranslated(28, 60, -3);
glScaled(5, 1, 1);
cube(0.75, 0.75, 0.75);
glPopMatrix();

glPushMatrix();
glTranslated(28, 60, -3);
glScaled(1, 10, 1);
cube(0.75, 0.75, 0.75);
glPopMatrix();

glPushMatrix();
glTranslated(28, 70, -3);
glScaled(5, 1, 1);
cube(0.75, 0.75, 0.75);
glPopMatrix();

glPushMatrix();
glTranslated(32, 71, -3);
glScaled(1, -11, 1);
cube(0.75, 0.75, 0.75);
glPopMatrix();

glPushMatrix();
glTranslated(32, 60, -3);
glScaled(-4, 1, 1);
cube(0.75, 0.75, 0.75);
glPopMatrix();


//L

glPushMatrix();
glTranslated(35, 60, -3);
glScaled(6, 1, 1);
cube(0.75, 0.75, 0.75);
glPopMatrix();


glPushMatrix();
glTranslated(35, 60, -3);
glScaled(1, 11, 1);
cube(0.75, 0.75, 0.75);
glPopMatrix();


//D


glPushMatrix();
glTranslated(43, 60, -3);
glScaled(1, 11, 1);
cube(0.75, 0.75, 0.75);
glPopMatrix();


glPushMatrix();
glTranslated(43.5, 70, -3);
glRotated(-25,0,0,1);
glScaled(5, 1, 1);
cube(0.75, 0.75, 0.75);
glPopMatrix();

glPushMatrix();
glTranslated(47.5, 69, -3);
glScaled(1, -6.5, 1);
cube(0.75, 0.75, 0.75);
glPopMatrix();

glPushMatrix();
glTranslated(43.5, 60, -3);
glRotated(25,0,0,1);
glScaled(5.4, 1, 1);
cube(0.75, 0.75, 0.75);
glPopMatrix();







       //first water-pool

    glPushMatrix();
    glTranslated(-30, 0.2, -30);
    glScaled(15, 1, 15);
cube(8 / 255.0, 66 / 255.0, 134 / 255.0);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-33, 0.2, -30);
    glScaled(3, 1, 15);
cube(0.35, 0.21, 0.12);
    glPopMatrix();


    //second water-pool
glPushMatrix();
glTranslated(70,0.2,0);
    glPushMatrix();
    glTranslated(-30, 0.2, -30);
    glScaled(15, 1, 15);
cube(8 / 255.0, 66 / 255.0, 134 / 255.0);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-33, 0.2, -30);
    glScaled(3, 1, 15);
cube(0.35, 0.21, 0.12);
    glPopMatrix();
glPopMatrix();


//big water pond






//king temple
    glPushMatrix();
    glTranslated(-60, 0.1, -50);
    glScaled(120, 5, -120);
    cube(0.957, 0.816, 0.247);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-50, 0.1, -57);
    glScaled(5, 20, 5);
cube(1, 1, 1);
    glPopMatrix();

        glPushMatrix();
    glTranslated(50, 0.1, -57);
    glScaled(5, 20, 5);
cube(1, 1, 1);
    glPopMatrix();

        glPushMatrix();
    glTranslated(-50, 0.1, -110);
    glScaled(5, 20, 5);
cube(1, 1, 1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(50, 0.1, -110);
    glScaled(5, 20, 5);
    cube(1, 1, 1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-60, 20.1, -50);
    glScaled(120, 10, -120);
cube(1, 0.765, 0);
    glPopMatrix();

        glPushMatrix();
    glTranslated(-60, 30.1, -50);
    glScaled(125, 10, -122);
cube(0.752, 0.224, 0.169) ;
    glPopMatrix();


        glPushMatrix();
   glTranslated(-40, 5.1, -50);
      glRotated(45,0,2,0);
   glScaled(20, 20, 1);
cube(0.980, 0.859, 0.847);
glPopMatrix();

    glPushMatrix();
   glTranslated(-20, 5.1, -50);
      glRotated(45,0,2,0);
   glScaled(20, 20, 1);
cube(0.980, 0.859, 0.847);
glPopMatrix();

    glPushMatrix();
   glTranslated(0, 5.1, -50);
      glRotated(45,0,2,0);
   glScaled(20, 20, 1);
cube(0.980, 0.859, 0.847);
glPopMatrix();

    glPushMatrix();
   glTranslated(20, 5.1, -50);
      glRotated(45,0,2,0);
   glScaled(20, 20, 1);
cube(0.980, 0.859, 0.847);
glPopMatrix();

    glPushMatrix();
   glTranslated(40, 5.1, -50);
      glRotated(45,0,2,0);
   glScaled(20, 20, 1);
cube(0.980, 0.859, 0.847);
glPopMatrix();


 glPushMatrix();
    glTranslated(-40, 30.1, -90);
    glScaled(10, 40, 10);
cube(0.752, 0.1, 0.169) ;
    glPopMatrix();

 glPushMatrix();
    glTranslated(45, 30.1, -90);
    glScaled(10, 40, 10);
cube(0.752, 0.1, 0.169) ;
    glPopMatrix();


  glPushMatrix();
    glTranslated(-60, 70.1, -50);
    glScaled(125, 10, -122);
cube(1.0, 0.8431, 0.0) ;
    glPopMatrix();

glPushMatrix();
    glTranslated(30, 40.1, -90);
    glScaled(3, 3, 3);
    cube(1.0, 0.60, 0.0);
    glPopMatrix();


    glPushMatrix();
    glTranslated(25, 40.1, -70);
    glScaled(5, 5, 5);
    cube(1.0, 0.60, 0.0);
    glPopMatrix();

    glPushMatrix();
    glTranslated(20, 40.1, -100);
    glScaled(5, 5, 5);
    cube(1.0, 0.60, 0.0);
    glPopMatrix();

    glPushMatrix();
    glTranslated(20, 40.1, -120);
    glScaled(5, 10, 5);
    cube(1.0, 0.60, 0.0);
    glPopMatrix();

 glPushMatrix();
    glTranslated(10, 40.1, -120);
    glScaled(5, 10, 5);
    cube(1.0, 0.60, 0.0);
    glPopMatrix();


    glPushMatrix();
    glTranslated(5, 40.1, -120);
    glScaled(5, 7, 5);
    cube(1.0, 0.60, 0.0);
    glPopMatrix();


    glPushMatrix();
    glTranslated(-15, 40.1, -120);
    glScaled(5, 5, 5);
    cube(1.0, 0.60, 0.0);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-15, 40.1, -130);
    glScaled(5, 5, 5);
    cube(1.0, 0.60, 0.0);
    glPopMatrix();

    glPushMatrix();
    glTranslated(15, 40.1, -130);
    glScaled(5, 5, 5);
    cube(1.0, 0.60, 0.0);
    glPopMatrix();

glPushMatrix();
    glTranslated(25, 40.1, -130);
    glScaled(3, 3, 3);
    cube(1.0, 0.60, 0.0);
    glPopMatrix();


    glPushMatrix();
    glTranslated(25, 40.1, -140);
    glScaled(3, 3, 3);
    cube(1.0, 0.60, 0.0);
    glPopMatrix();

glPushMatrix();
    glTranslated(-15, 40.1, -140);
    glScaled(5, 5, 5);
    cube(1.0, 0.60, 0.0);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-15, 40.1, -150);
    glScaled(5, 5, 5);
    cube(1.0, 0.60, 0.0);
    glPopMatrix();

    glPushMatrix();
    glTranslated(15, 40.1, -150);
    glScaled(5, 5, 5);
    cube(1.0, 0.60, 0.0);
    glPopMatrix();

glPushMatrix();
    glTranslated(25, 40.1, -140);
    glScaled(3, 3, 3);
    cube(1.0, 0.60, 0.0);
    glPopMatrix();



    glPushMatrix();
    glTranslated(25, 40.1, -150);
    glScaled(3, 3, 3);
    cube(1.0, 0.60, 0.0);
    glPopMatrix();


    glPushMatrix();
    glTranslated(25, 40.1, -150);
    glScaled(3, 3, 3);
    cube(1.0, 0.60, 0.0);
    glPopMatrix();

glPushMatrix();
    glTranslated(-15, 40.1, -150);
    glScaled(5, 5, 5);
    cube(1.0, 0.60, 0.0);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-15, 40.1, -160);
    glScaled(5, 5, 5);
    cube(1.0, 0.60, 0.0);
    glPopMatrix();

    glPushMatrix();
    glTranslated(15, 40.1, -160);
    glScaled(5, 5, 5);
    cube(1.0, 0.60, 0.0);
    glPopMatrix();

glPushMatrix();
    glTranslated(25, 40.1, -160);
    glScaled(3, 3, 3);
    cube(1.0, 0.60, 0.0);
    glPopMatrix();

//house 3
glPushMatrix();
glTranslated(-20,0,20);


        glPushMatrix();
       glTranslated(-40,0,30);
       glScaled(12,3,12);
       cube(0.52,0.39,0.39);
       glPopMatrix();

        glPushMatrix();
       glTranslated(-40,3,31);
       glScaled(10,15,10);
cube(0.96,0.87,0.71);
       glPopMatrix();

        glPushMatrix();
       glTranslated(-30,3,35);
       glScaled(0.1,10,2);
       cube(0,0,0);
       glPopMatrix();

glPushMatrix();
glTranslated(-40, 15, 30);
glScaled(13, 2, 13);
cube(0.96,0.75,0.0);
glPopMatrix();

glPopMatrix();



    //house 1

        glPushMatrix();
       glTranslated(-40,0,30);
       glScaled(12,3,12);
       cube(0.52,0.39,0.39);
       glPopMatrix();

        glPushMatrix();
       glTranslated(-40,3,31);
       glScaled(10,15,10);
cube(0.96,0.87,0.71);
       glPopMatrix();

        glPushMatrix();
       glTranslated(-30,3,35);
       glScaled(0.1,10,2);
       cube(0,0,0);
       glPopMatrix();

glPushMatrix();
glTranslated(-40, 15, 30);
glScaled(13, 2, 13);
cube(0.96,0.75,0.0);
glPopMatrix();


glPushMatrix();
glTranslated(-15,0.1,40);
    //house 4

        glPushMatrix();
       glTranslated(-40,0,30);
       glScaled(12,3,12);
       cube(0.6980,0.1333,0.1333);
       glPopMatrix();

        glPushMatrix();
       glTranslated(-40,3,31);
       glScaled(10,15,10);
cube(1.0,0.8431,0.0);
       glPopMatrix();

        glPushMatrix();
       glTranslated(-30,3,35);
       glScaled(0.1,10,2);
       cube(0,0,0);
       glPopMatrix();

glPushMatrix();
glTranslated(-40, 15, 30);
glScaled(13, 2, 13);
cube(0.96,0.75,0.0);
glPopMatrix();


glPopMatrix();

    //house 2

        glPushMatrix();
       glTranslated(50,0,30);
       glScaled(12,3,12);
       cube(0.52,0.39,0.39);
       glPopMatrix();

        glPushMatrix();
       glTranslated(50,3,31);
       glScaled(10,15,10);
       cube(1,1,1);
       glPopMatrix();

        glPushMatrix();
       glTranslated(49,3,35);
       glScaled(0.1,10,2);
       cube(0,0,0);
       glPopMatrix();

glPushMatrix();
glTranslated(49, 15, 30);
glScaled(13, 2, 13);
cube(0.22, 0.11, 0.05);
glPopMatrix();

//house 3

    glPushMatrix();
       glTranslated(-40,0,20);
       glScaled(12,3,12);
       cube(0.52,0.39,0.39);
       glPopMatrix();

        glPushMatrix();
       glTranslated(-40,3,21);
       glScaled(10,15,10);
cube(0.96,0.87,0.71);
       glPopMatrix();

        glPushMatrix();
       glTranslated(-30,3,25);
       glScaled(0.1,10,2);
       cube(0,0,0);
       glPopMatrix();

glPushMatrix();
glTranslated(-40, 15, 20);
glScaled(13, 2, 13);
cube(0.96,0.75,0.0);
glPopMatrix();



glPushMatrix();
glTranslated(5,0.1,30);
 //house 6

        glPushMatrix();
       glTranslated(-40,0,30);
       glScaled(12,3,12);
       cube(0.52,0.39,0.39);
       glPopMatrix();

        glPushMatrix();
       glTranslated(-40,3,31);
       glScaled(10,15,10);
cube(0.7608,0.6980,0.5020);
       glPopMatrix();

        glPushMatrix();
       glTranslated(-30,3,35);
       glScaled(0.1,10,2);
       cube(0,0,0);
       glPopMatrix();

glPushMatrix();
glTranslated(-40, 15, 30);
glScaled(13, 2, 13);
cube(0.96,0.75,0.0);
glPopMatrix();

glPopMatrix();


glPushMatrix();
glTranslated(25,0.1,10);
 //house 1

        glPushMatrix();
       glTranslated(-40,0,30);
       glScaled(12,3,12);
       cube(0.52,0.39,0.39);
       glPopMatrix();

        glPushMatrix();
       glTranslated(-40,3,31);
       glScaled(10,15,10);
cube(0.96,0.7,0.71);
       glPopMatrix();

        glPushMatrix();
       glTranslated(-30,3,35);
       glScaled(0.1,10,2);
       cube(0,0,0);
       glPopMatrix();

glPushMatrix();
glTranslated(-40, 15, 30);
glScaled(13, 2, 13);
cube(0.96,0.75,0.0);
glPopMatrix();

glPopMatrix();



glPushMatrix();
glTranslated(-50,0.1,30);
 //house 7

        glPushMatrix();
       glTranslated(-40,0,30);
       glScaled(12,3,12);
       cube(0.52,0.39,0.39);
       glPopMatrix();

        glPushMatrix();
       glTranslated(-40,3,31);
       glScaled(10,15,10);
cube(0.7608, 0.6980, 0.5020);
       glPopMatrix();

        glPushMatrix();
       glTranslated(-30,3,35);
       glScaled(0.1,10,2);
       cube(0,0,0);
       glPopMatrix();

glPushMatrix();
glTranslated(-40, 15, 30);
glScaled(13, 2, 13);
cube(0.96,0.75,0.0);
glPopMatrix();

glPopMatrix();



glPushMatrix();
glTranslated(-25,0.1,60);
 //house 8

        glPushMatrix();
       glTranslated(-40,0,30);
       glScaled(12,3,12);
       cube(0.52,0.39,0.39);
       glPopMatrix();

        glPushMatrix();
       glTranslated(-40,3,31);
       glScaled(10,15,10);
 cube(0.9804, 0.9412, 0.9020);
       glPopMatrix();

        glPushMatrix();
       glTranslated(-30,3,35);
       glScaled(0.1,10,2);
       cube(0,0,0);
       glPopMatrix();

glPushMatrix();
glTranslated(-40, 15, 30);
glScaled(13, 2, 13);
cube(0.96,0.75,0.0);
glPopMatrix();

glPopMatrix();





glPushMatrix();
glTranslated(100,0.1,10);
//big tree


glPushMatrix();
glTranslated(-50, 0.1, 0);
glScaled(5,40,5);
cube(0.35, 0.21, 0.12);
glPopMatrix();

//tree house
glPushMatrix();
       glTranslated(-53,40,-3);
       glScaled(12,3,12);
cube(0.44, 0.33, 0.23);
       glPopMatrix();

glPushMatrix();
       glTranslated(-53,43,-3);
       glScaled(10,15,10);
cube(0.35, 0.21, 0.12);
       glPopMatrix();

       glPushMatrix();
       glTranslated(-43,43,0);
       glScaled(0.1,10,2);
       cube(0,0,0);
       glPopMatrix();

       glPushMatrix();
       glTranslated(-43,43,3);
       glScaled(0.1,10,2);
       cube(0,0,0);
       glPopMatrix();


glPushMatrix();
glTranslated(-58, 56, -8);
glScaled(18, 3, 18);
cube(0.0,0.4,0.0);
glPopMatrix();

glPushMatrix();
glTranslated(-56, 59, -6);
glScaled(16, 3, 16);
cube(0.0,0.4,0.0);
glPopMatrix();

glPushMatrix();
glTranslated(-53, 62, -3);
glScaled(13, 3, 13);
cube(0.0,0.4,0.0);
glPopMatrix();


glPopMatrix();

//big tree


glPushMatrix();
glTranslated(-50, 0.1, 0);
glScaled(5,40,5);
cube(0.35, 0.21, 0.12);
glPopMatrix();

//tree house
glPushMatrix();
       glTranslated(-53,40,-3);
       glScaled(12,3,12);
cube(0.44, 0.33, 0.23);
       glPopMatrix();

glPushMatrix();
       glTranslated(-53,43,-3);
       glScaled(10,15,10);
cube(0.35, 0.21, 0.12);
       glPopMatrix();

       glPushMatrix();
       glTranslated(-43,43,0);
       glScaled(0.1,10,2);
       cube(0,0,0);
       glPopMatrix();

       glPushMatrix();
       glTranslated(-43,43,3);
       glScaled(0.1,10,2);
       cube(0,0,0);
       glPopMatrix();


glPushMatrix();
glTranslated(-58, 56, -8);
glScaled(18, 3, 18);
cube(0.0,0.4,0.0);
glPopMatrix();

glPushMatrix();
glTranslated(-56, 59, -6);
glScaled(16, 3, 16);
cube(0.0,0.4,0.0);
glPopMatrix();

glPushMatrix();
glTranslated(-53, 62, -3);
glScaled(13, 3, 13);
cube(0.0,0.4,0.0);
glPopMatrix();


//temple three
glPushMatrix();
glTranslated(0,0.1,40);
glPushMatrix();
    glTranslated(35, 0.2, 10);
    glScaled(15, 5, 15);
    cube(1.0, 0.87, 0.0);
    glPopMatrix();

    glPushMatrix();
    glTranslated(37, 5.2, 12);
    glScaled(10, 5, 10);
    cube(1.0, 0.80, 0.0);
//door
    glPopMatrix();
    glPushMatrix();
    glTranslated(37, 5.2, 16);
    glScaled(-0.5, 4, 1);
    cube(0.2, 0.1, 0.2);
    glPopMatrix();

    glPushMatrix();
    glTranslated(39, 10.2, 13);
    glScaled(7, 4, 7);
    cube(1.0, 0.70, 0.0);
    glPopMatrix();
    //door
    glPopMatrix();
    glPushMatrix();
    glTranslated(39, 10.2, 13);
    glScaled(-0.3, 4, 1);
    cube(0.2, 0.2, 0.4);
    glPopMatrix();

    glPushMatrix();
    glTranslated(39, 10.2, 19);
    glScaled(-0.3, 4, 1);
    cube(0.2, 0.2, 0.4);
    glPopMatrix();

        glPushMatrix();
    glTranslated(41, 14.2, 15);
    glScaled(4, 4, 4);
    cube(1.0, 0.60, 0.0);
        glPopMatrix();

glPopMatrix();

//temple four
glPushMatrix();
glTranslated(0,0.1,60);
glPushMatrix();
    glTranslated(35, 0.2, 10);
    glScaled(15, 5, 15);
    cube(1.0, 0.87, 0.0);
    glPopMatrix();

    glPushMatrix();
    glTranslated(37, 5.2, 12);
    glScaled(10, 5, 10);
    cube(1.0, 0.80, 0.0);
//door
    glPopMatrix();
    glPushMatrix();
    glTranslated(37, 5.2, 16);
    glScaled(-0.5, 4, 1);
    cube(0.2, 0.1, 0.2);
    glPopMatrix();

    glPushMatrix();
    glTranslated(39, 10.2, 13);
    glScaled(7, 4, 7);
    cube(1.0, 0.70, 0.0);
    glPopMatrix();
    //door
    glPopMatrix();
    glPushMatrix();
    glTranslated(39, 10.2, 13);
    glScaled(-0.3, 4, 1);
    cube(0.2, 0.2, 0.4);
    glPopMatrix();

    glPushMatrix();
    glTranslated(39, 10.2, 19);
    glScaled(-0.3, 4, 1);
    cube(0.2, 0.2, 0.4);
    glPopMatrix();

        glPushMatrix();
    glTranslated(41, 14.2, 15);
    glScaled(4, 4, 4);
    cube(1.0, 0.60, 0.0);
        glPopMatrix();
glPopMatrix();



//temple five
glPushMatrix();
glTranslated(30,0.1,20);
glPushMatrix();
    glTranslated(35, 0.2, 10);
    glScaled(15, 5, 15);
    cube(1.0, 0.87, 0.0);
    glPopMatrix();

    glPushMatrix();
    glTranslated(37, 5.2, 12);
    glScaled(10, 5, 10);
    cube(1.0, 0.80, 0.0);
//door
    glPopMatrix();
    glPushMatrix();
    glTranslated(37, 5.2, 16);
    glScaled(-0.5, 4, 1);
    cube(0.2, 0.1, 0.2);
    glPopMatrix();

    glPushMatrix();
    glTranslated(39, 10.2, 13);
    glScaled(7, 4, 7);
    cube(1.0, 0.70, 0.0);
    glPopMatrix();
    //door
    glPopMatrix();
    glPushMatrix();
    glTranslated(39, 10.2, 13);
    glScaled(-0.3, 4, 1);
    cube(0.2, 0.2, 0.4);
    glPopMatrix();

    glPushMatrix();
    glTranslated(39, 10.2, 19);
    glScaled(-0.3, 4, 1);
    cube(0.2, 0.2, 0.4);
    glPopMatrix();

        glPushMatrix();
    glTranslated(41, 14.2, 15);
    glScaled(4, 4, 4);
    cube(1.0, 0.60, 0.0);
        glPopMatrix();
glPopMatrix();


// my code

    //tree r1

    glPushMatrix();

    glTranslated(20,0,30);
    //second tree

        glPushMatrix();
        glTranslated(35,0.3,32);
        glScaled(1.5,10,1.5);
       cube(0.44, 0.33, 0.23);
       glPopMatrix();

        glPushMatrix();
        glTranslated(32,10,29);
        glScaled(8,3,8);
       cube(0, 0.4, 0);
       glPopMatrix();

        glPushMatrix();
        glTranslated(33,13,31);
        glScaled(5,3,5);
       cube(0, 0.4, 0);
       glPopMatrix();

        glPushMatrix();
        glTranslated(34,16,32);
        glScaled(3,2,3);
       cube(0, 0.4, 0);
       glPopMatrix();

    glPopMatrix();


    //tree r2
    glPushMatrix();

    glTranslated(20,0,45);
    //second tree

        glPushMatrix();
        glTranslated(35,0.3,32);
        glScaled(1.5,10,1.5);
       cube(0.44, 0.33, 0.23);
       glPopMatrix();

        glPushMatrix();
        glTranslated(32,10,29);
        glScaled(8,3,8);
       cube(0, 0.4, 0);
       glPopMatrix();

        glPushMatrix();
        glTranslated(33,13,31);
        glScaled(5,3,5);
       cube(0, 0.4, 0);
       glPopMatrix();

        glPushMatrix();
        glTranslated(34,16,32);
        glScaled(3,2,3);
       cube(0, 0.4, 0);
       glPopMatrix();

    glPopMatrix();


    //tree r3
    glPushMatrix();

    glTranslated(20,0,60);
    //second tree

        glPushMatrix();
        glTranslated(35,0.3,32);
        glScaled(1.5,10,1.5);
       cube(0.44, 0.33, 0.23);
       glPopMatrix();

        glPushMatrix();
        glTranslated(32,10,29);
        glScaled(8,3,8);
       cube(0, 0.4, 0);
       glPopMatrix();

        glPushMatrix();
        glTranslated(33,13,31);
        glScaled(5,3,5);
       cube(0, 0.4, 0);
       glPopMatrix();

        glPushMatrix();
        glTranslated(34,16,32);
        glScaled(3,2,3);
       cube(0, 0.4, 0);
       glPopMatrix();

    glPopMatrix();


    //tree r4
    glPushMatrix();

    glTranslated(20,0,75);
    //second tree

        glPushMatrix();
        glTranslated(35,0.3,32);
        glScaled(1.5,10,1.5);
       cube(0.44, 0.33, 0.23);
       glPopMatrix();

        glPushMatrix();
        glTranslated(32,10,29);
        glScaled(8,3,8);
       cube(0, 0.4, 0);
       glPopMatrix();

        glPushMatrix();
        glTranslated(33,13,31);
        glScaled(5,3,5);
       cube(0, 0.4, 0);
       glPopMatrix();

        glPushMatrix();
        glTranslated(34,16,32);
        glScaled(3,2,3);
       cube(0, 0.4, 0);
       glPopMatrix();

    glPopMatrix();

    //tree r5
    glPushMatrix();

    glTranslated(20,0,90);
    //second tree

        glPushMatrix();
        glTranslated(35,0.3,32);
        glScaled(1.5,10,1.5);
       cube(0.44, 0.33, 0.23);
       glPopMatrix();

        glPushMatrix();
        glTranslated(32,10,29);
        glScaled(8,3,8);
       cube(0, 0.4, 0);
       glPopMatrix();

        glPushMatrix();
        glTranslated(33,13,31);
        glScaled(5,3,5);
       cube(0, 0.4, 0);
       glPopMatrix();

        glPushMatrix();
        glTranslated(34,16,32);
        glScaled(3,2,3);
       cube(0, 0.4, 0);
       glPopMatrix();

    glPopMatrix();

    //tree r6
    glPushMatrix();

    glTranslated(20,0,105);
    //second tree

        glPushMatrix();
        glTranslated(35,0.3,32);
        glScaled(1.5,10,1.5);
       cube(0.44, 0.33, 0.23);
       glPopMatrix();

        glPushMatrix();
        glTranslated(32,10,29);
        glScaled(8,3,8);
       cube(0, 0.4, 0);
       glPopMatrix();

        glPushMatrix();
        glTranslated(33,13,31);
        glScaled(5,3,5);
       cube(0, 0.4, 0);
       glPopMatrix();

        glPushMatrix();
        glTranslated(34,16,32);
        glScaled(3,2,3);
       cube(0, 0.4, 0);
       glPopMatrix();

    glPopMatrix();

    glPopMatrix();





    //second line tree r

    glPushMatrix();


    glTranslated(20,0,0);
    // my code

    //tree r1

    glPushMatrix();

    glTranslated(20,0,30);
    //second tree

        glPushMatrix();
        glTranslated(35,0.3,32);
        glScaled(1.5,10,1.5);
       cube(0.44, 0.33, 0.23);
       glPopMatrix();

        glPushMatrix();
        glTranslated(32,10,29);
        glScaled(8,3,8);
       cube(0, 0.4, 0);
       glPopMatrix();

        glPushMatrix();
        glTranslated(33,13,31);
        glScaled(5,3,5);
       cube(0, 0.4, 0);
       glPopMatrix();

        glPushMatrix();
        glTranslated(34,16,32);
        glScaled(3,2,3);
       cube(0, 0.4, 0);
       glPopMatrix();

    glPopMatrix();


    //tree r2
    glPushMatrix();

    glTranslated(20,0,45);
    //second tree

        glPushMatrix();
        glTranslated(35,0.3,32);
        glScaled(1.5,10,1.5);
       cube(0.44, 0.33, 0.23);
       glPopMatrix();

        glPushMatrix();
        glTranslated(32,10,29);
        glScaled(8,3,8);
       cube(0, 0.4, 0);
       glPopMatrix();

        glPushMatrix();
        glTranslated(33,13,31);
        glScaled(5,3,5);
       cube(0, 0.4, 0);
       glPopMatrix();

        glPushMatrix();
        glTranslated(34,16,32);
        glScaled(3,2,3);
       cube(0, 0.4, 0);
       glPopMatrix();

    glPopMatrix();


    //tree r3
    glPushMatrix();

    glTranslated(20,0,60);
    //second tree

        glPushMatrix();
        glTranslated(35,0.3,32);
        glScaled(1.5,10,1.5);
       cube(0.44, 0.33, 0.23);
       glPopMatrix();

        glPushMatrix();
        glTranslated(32,10,29);
        glScaled(8,3,8);
       cube(0, 0.4, 0);
       glPopMatrix();

        glPushMatrix();
        glTranslated(33,13,31);
        glScaled(5,3,5);
       cube(0, 0.4, 0);
       glPopMatrix();

        glPushMatrix();
        glTranslated(34,16,32);
        glScaled(3,2,3);
       cube(0, 0.4, 0);
       glPopMatrix();

    glPopMatrix();


    //tree r4
    glPushMatrix();

    glTranslated(20,0,75);
    //second tree

        glPushMatrix();
        glTranslated(35,0.3,32);
        glScaled(1.5,10,1.5);
       cube(0.44, 0.33, 0.23);
       glPopMatrix();

        glPushMatrix();
        glTranslated(32,10,29);
        glScaled(8,3,8);
       cube(0, 0.4, 0);
       glPopMatrix();

        glPushMatrix();
        glTranslated(33,13,31);
        glScaled(5,3,5);
       cube(0, 0.4, 0);
       glPopMatrix();

        glPushMatrix();
        glTranslated(34,16,32);
        glScaled(3,2,3);
       cube(0, 0.4, 0);
       glPopMatrix();

    glPopMatrix();

    //tree r5
    glPushMatrix();

    glTranslated(20,0,90);
    //second tree

        glPushMatrix();
        glTranslated(35,0.3,32);
        glScaled(1.5,10,1.5);
       cube(0.44, 0.33, 0.23);
       glPopMatrix();

        glPushMatrix();
        glTranslated(32,10,29);
        glScaled(8,3,8);
       cube(0, 0.4, 0);
       glPopMatrix();

        glPushMatrix();
        glTranslated(33,13,31);
        glScaled(5,3,5);
       cube(0, 0.4, 0);
       glPopMatrix();

        glPushMatrix();
        glTranslated(34,16,32);
        glScaled(3,2,3);
       cube(0, 0.4, 0);
       glPopMatrix();

    glPopMatrix();

    //tree r6
    glPushMatrix();

    glTranslated(20,0,105);
    //second tree

        glPushMatrix();
        glTranslated(35,0.3,32);
        glScaled(1.5,10,1.5);
       cube(0.44, 0.33, 0.23);
       glPopMatrix();

        glPushMatrix();
        glTranslated(32,10,29);
        glScaled(8,3,8);
       cube(0, 0.4, 0);
       glPopMatrix();

        glPushMatrix();
        glTranslated(33,13,31);
        glScaled(5,3,5);
       cube(0, 0.4, 0);
       glPopMatrix();

        glPushMatrix();
        glTranslated(34,16,32);
        glScaled(3,2,3);
       cube(0, 0.4, 0);
       glPopMatrix();

    glPopMatrix();



    glPopMatrix();





    //3rd line tree r
    glPushMatrix();


    glTranslated(40,0,0);
    // my code

    //tree r1

    glPushMatrix();

    glTranslated(20,0,30);
    //second tree

        glPushMatrix();
        glTranslated(35,0.3,32);
        glScaled(1.5,10,1.5);
       cube(0.44, 0.33, 0.23);
       glPopMatrix();

        glPushMatrix();
        glTranslated(32,10,29);
        glScaled(8,3,8);
       cube(0, 0.4, 0);
       glPopMatrix();

        glPushMatrix();
        glTranslated(33,13,31);
        glScaled(5,3,5);
       cube(0, 0.4, 0);
       glPopMatrix();

        glPushMatrix();
        glTranslated(34,16,32);
        glScaled(3,2,3);
       cube(0, 0.4, 0);
       glPopMatrix();

    glPopMatrix();


    //tree r2
    glPushMatrix();

    glTranslated(20,0,45);
    //second tree

        glPushMatrix();
        glTranslated(35,0.3,32);
        glScaled(1.5,10,1.5);
       cube(0.44, 0.33, 0.23);
       glPopMatrix();

        glPushMatrix();
        glTranslated(32,10,29);
        glScaled(8,3,8);
       cube(0, 0.4, 0);
       glPopMatrix();

        glPushMatrix();
        glTranslated(33,13,31);
        glScaled(5,3,5);
       cube(0, 0.4, 0);
       glPopMatrix();

        glPushMatrix();
        glTranslated(34,16,32);
        glScaled(3,2,3);
       cube(0, 0.4, 0);
       glPopMatrix();

    glPopMatrix();


    //tree r3
    glPushMatrix();

    glTranslated(20,0,60);
    //second tree

        glPushMatrix();
        glTranslated(35,0.3,32);
        glScaled(1.5,10,1.5);
       cube(0.44, 0.33, 0.23);
       glPopMatrix();

        glPushMatrix();
        glTranslated(32,10,29);
        glScaled(8,3,8);
       cube(0, 0.4, 0);
       glPopMatrix();

        glPushMatrix();
        glTranslated(33,13,31);
        glScaled(5,3,5);
       cube(0, 0.4, 0);
       glPopMatrix();

        glPushMatrix();
        glTranslated(34,16,32);
        glScaled(3,2,3);
       cube(0, 0.4, 0);
       glPopMatrix();

    glPopMatrix();


    //tree r4
    glPushMatrix();

    glTranslated(20,0,75);
    //second tree

        glPushMatrix();
        glTranslated(35,0.3,32);
        glScaled(1.5,10,1.5);
       cube(0.44, 0.33, 0.23);
       glPopMatrix();

        glPushMatrix();
        glTranslated(32,10,29);
        glScaled(8,3,8);
       cube(0, 0.4, 0);
       glPopMatrix();

        glPushMatrix();
        glTranslated(33,13,31);
        glScaled(5,3,5);
       cube(0, 0.4, 0);
       glPopMatrix();

        glPushMatrix();
        glTranslated(34,16,32);
        glScaled(3,2,3);
       cube(0, 0.4, 0);
       glPopMatrix();

    glPopMatrix();

    //tree r5
    glPushMatrix();

    glTranslated(20,0,90);
    //second tree

        glPushMatrix();
        glTranslated(35,0.3,32);
        glScaled(1.5,10,1.5);
       cube(0.44, 0.33, 0.23);
       glPopMatrix();

        glPushMatrix();
        glTranslated(32,10,29);
        glScaled(8,3,8);
       cube(0, 0.4, 0);
       glPopMatrix();

        glPushMatrix();
        glTranslated(33,13,31);
        glScaled(5,3,5);
       cube(0, 0.4, 0);
       glPopMatrix();

        glPushMatrix();
        glTranslated(34,16,32);
        glScaled(3,2,3);
       cube(0, 0.4, 0);
       glPopMatrix();

    glPopMatrix();

    //tree r6
    glPushMatrix();

    glTranslated(20,0,105);
    //second tree

        glPushMatrix();
        glTranslated(35,0.3,32);
        glScaled(1.5,10,1.5);
       cube(0.44, 0.33, 0.23);
       glPopMatrix();

        glPushMatrix();
        glTranslated(32,10,29);
        glScaled(8,3,8);
       cube(0, 0.4, 0);
       glPopMatrix();

        glPushMatrix();
        glTranslated(33,13,31);
        glScaled(5,3,5);
       cube(0, 0.4, 0);
       glPopMatrix();

        glPushMatrix();
        glTranslated(34,16,32);
        glScaled(3,2,3);
       cube(0, 0.4, 0);
       glPopMatrix();

    glPopMatrix();


    glPopMatrix();




    //4th line tree r
    glPushMatrix();


    glTranslated(60,0,0);
    // my code

    //tree r1

    glPushMatrix();

    glTranslated(20,0,30);
    //second tree

        glPushMatrix();
        glTranslated(35,0.3,32);
        glScaled(1.5,10,1.5);
       cube(0.44, 0.33, 0.23);
       glPopMatrix();

        glPushMatrix();
        glTranslated(32,10,29);
        glScaled(8,3,8);
       cube(0, 0.4, 0);
       glPopMatrix();

        glPushMatrix();
        glTranslated(33,13,31);
        glScaled(5,3,5);
       cube(0, 0.4, 0);
       glPopMatrix();

        glPushMatrix();
        glTranslated(34,16,32);
        glScaled(3,2,3);
       cube(0, 0.4, 0);
       glPopMatrix();

    glPopMatrix();


    //tree r2
    glPushMatrix();

    glTranslated(20,0,45);
    //second tree

        glPushMatrix();
        glTranslated(35,0.3,32);
        glScaled(1.5,10,1.5);
       cube(0.44, 0.33, 0.23);
       glPopMatrix();

        glPushMatrix();
        glTranslated(32,10,29);
        glScaled(8,3,8);
       cube(0, 0.4, 0);
       glPopMatrix();

        glPushMatrix();
        glTranslated(33,13,31);
        glScaled(5,3,5);
       cube(0, 0.4, 0);
       glPopMatrix();

        glPushMatrix();
        glTranslated(34,16,32);
        glScaled(3,2,3);
       cube(0, 0.4, 0);
       glPopMatrix();

    glPopMatrix();


    //tree r3
    glPushMatrix();

    glTranslated(20,0,60);
    //second tree

        glPushMatrix();
        glTranslated(35,0.3,32);
        glScaled(1.5,10,1.5);
       cube(0.44, 0.33, 0.23);
       glPopMatrix();

        glPushMatrix();
        glTranslated(32,10,29);
        glScaled(8,3,8);
       cube(0, 0.4, 0);
       glPopMatrix();

        glPushMatrix();
        glTranslated(33,13,31);
        glScaled(5,3,5);
       cube(0, 0.4, 0);
       glPopMatrix();

        glPushMatrix();
        glTranslated(34,16,32);
        glScaled(3,2,3);
       cube(0, 0.4, 0);
       glPopMatrix();

    glPopMatrix();


    //tree r4
    glPushMatrix();

    glTranslated(20,0,75);
    //second tree

        glPushMatrix();
        glTranslated(35,0.3,32);
        glScaled(1.5,10,1.5);
       cube(0.44, 0.33, 0.23);
       glPopMatrix();

        glPushMatrix();
        glTranslated(32,10,29);
        glScaled(8,3,8);
       cube(0, 0.4, 0);
       glPopMatrix();

        glPushMatrix();
        glTranslated(33,13,31);
        glScaled(5,3,5);
       cube(0, 0.4, 0);
       glPopMatrix();

        glPushMatrix();
        glTranslated(34,16,32);
        glScaled(3,2,3);
       cube(0, 0.4, 0);
       glPopMatrix();

    glPopMatrix();

    //tree r5
    glPushMatrix();

    glTranslated(20,0,90);
    //second tree

        glPushMatrix();
        glTranslated(35,0.3,32);
        glScaled(1.5,10,1.5);
       cube(0.44, 0.33, 0.23);
       glPopMatrix();

        glPushMatrix();
        glTranslated(32,10,29);
        glScaled(8,3,8);
       cube(0, 0.4, 0);
       glPopMatrix();

        glPushMatrix();
        glTranslated(33,13,31);
        glScaled(5,3,5);
       cube(0, 0.4, 0);
       glPopMatrix();

        glPushMatrix();
        glTranslated(34,16,32);
        glScaled(3,2,3);
       cube(0, 0.4, 0);
       glPopMatrix();

    glPopMatrix();

    //tree r6
    glPushMatrix();

    glTranslated(20,0,105);
    //second tree

        glPushMatrix();
        glTranslated(35,0.3,32);
        glScaled(1.5,10,1.5);
       cube(0.44, 0.33, 0.23);
       glPopMatrix();

        glPushMatrix();
        glTranslated(32,10,29);
        glScaled(8,3,8);
       cube(0, 0.4, 0);
       glPopMatrix();

        glPushMatrix();
        glTranslated(33,13,31);
        glScaled(5,3,5);
       cube(0, 0.4, 0);
       glPopMatrix();

        glPushMatrix();
        glTranslated(34,16,32);
        glScaled(3,2,3);
       cube(0, 0.4, 0);
       glPopMatrix();

    glPopMatrix();


    glPopMatrix();




    //5th line tree r
    glPushMatrix();


    glTranslated(80,0,0);
    // my code

    //tree r1

    glPushMatrix();

    glTranslated(20,0,30);
    //second tree

        glPushMatrix();
        glTranslated(35,0.3,32);
        glScaled(1.5,10,1.5);
       cube(0.44, 0.33, 0.23);
       glPopMatrix();

        glPushMatrix();
        glTranslated(32,10,29);
        glScaled(8,3,8);
       cube(0, 0.4, 0);
       glPopMatrix();

        glPushMatrix();
        glTranslated(33,13,31);
        glScaled(5,3,5);
       cube(0, 0.4, 0);
       glPopMatrix();

        glPushMatrix();
        glTranslated(34,16,32);
        glScaled(3,2,3);
       cube(0, 0.4, 0);
       glPopMatrix();

    glPopMatrix();


    //tree r2
    glPushMatrix();

    glTranslated(20,0,45);
    //second tree

        glPushMatrix();
        glTranslated(35,0.3,32);
        glScaled(1.5,10,1.5);
       cube(0.44, 0.33, 0.23);
       glPopMatrix();

        glPushMatrix();
        glTranslated(32,10,29);
        glScaled(8,3,8);
       cube(0, 0.4, 0);
       glPopMatrix();

        glPushMatrix();
        glTranslated(33,13,31);
        glScaled(5,3,5);
       cube(0, 0.4, 0);
       glPopMatrix();

        glPushMatrix();
        glTranslated(34,16,32);
        glScaled(3,2,3);
       cube(0, 0.4, 0);
       glPopMatrix();

    glPopMatrix();


    //tree r3
    glPushMatrix();

    glTranslated(20,0,60);
    //second tree

        glPushMatrix();
        glTranslated(35,0.3,32);
        glScaled(1.5,10,1.5);
       cube(0.44, 0.33, 0.23);
       glPopMatrix();

        glPushMatrix();
        glTranslated(32,10,29);
        glScaled(8,3,8);
       cube(0, 0.4, 0);
       glPopMatrix();

        glPushMatrix();
        glTranslated(33,13,31);
        glScaled(5,3,5);
       cube(0, 0.4, 0);
       glPopMatrix();

        glPushMatrix();
        glTranslated(34,16,32);
        glScaled(3,2,3);
       cube(0, 0.4, 0);
       glPopMatrix();

    glPopMatrix();


    //tree r4
    glPushMatrix();

    glTranslated(20,0,75);
    //second tree

        glPushMatrix();
        glTranslated(35,0.3,32);
        glScaled(1.5,10,1.5);
       cube(0.44, 0.33, 0.23);
       glPopMatrix();

        glPushMatrix();
        glTranslated(32,10,29);
        glScaled(8,3,8);
       cube(0, 0.4, 0);
       glPopMatrix();

        glPushMatrix();
        glTranslated(33,13,31);
        glScaled(5,3,5);
       cube(0, 0.4, 0);
       glPopMatrix();

        glPushMatrix();
        glTranslated(34,16,32);
        glScaled(3,2,3);
       cube(0, 0.4, 0);
       glPopMatrix();

    glPopMatrix();

    //tree r5
    glPushMatrix();

    glTranslated(20,0,90);
    //second tree

        glPushMatrix();
        glTranslated(35,0.3,32);
        glScaled(1.5,10,1.5);
       cube(0.44, 0.33, 0.23);
       glPopMatrix();

        glPushMatrix();
        glTranslated(32,10,29);
        glScaled(8,3,8);
       cube(0, 0.4, 0);
       glPopMatrix();

        glPushMatrix();
        glTranslated(33,13,31);
        glScaled(5,3,5);
       cube(0, 0.4, 0);
       glPopMatrix();

        glPushMatrix();
        glTranslated(34,16,32);
        glScaled(3,2,3);
       cube(0, 0.4, 0);
       glPopMatrix();

    glPopMatrix();

    //tree r6
    glPushMatrix();

    glTranslated(20,0,105);
    //second tree

        glPushMatrix();
        glTranslated(35,0.3,32);
        glScaled(1.5,10,1.5);
       cube(0.44, 0.33, 0.23);
       glPopMatrix();

        glPushMatrix();
        glTranslated(32,10,29);
        glScaled(8,3,8);
       cube(0, 0.4, 0);
       glPopMatrix();

        glPushMatrix();
        glTranslated(33,13,31);
        glScaled(5,3,5);
       cube(0, 0.4, 0);
       glPopMatrix();

        glPushMatrix();
        glTranslated(34,16,32);
        glScaled(3,2,3);
       cube(0, 0.4, 0);
       glPopMatrix();

    glPopMatrix();


    glPopMatrix();

    //6th line tree r
    glPushMatrix();


    glTranslated(100,0,0);
    // my code

    //tree r1

    glPushMatrix();

    glTranslated(20,0,30);
    //second tree

        glPushMatrix();
        glTranslated(35,0.3,32);
        glScaled(1.5,10,1.5);
       cube(0.44, 0.33, 0.23);
       glPopMatrix();

        glPushMatrix();
        glTranslated(32,10,29);
        glScaled(8,3,8);
       cube(0, 0.4, 0);
       glPopMatrix();

        glPushMatrix();
        glTranslated(33,13,31);
        glScaled(5,3,5);
       cube(0, 0.4, 0);
       glPopMatrix();







        glPushMatrix();
        glTranslated(34,16,32);
        glScaled(3,2,3);
       cube(0, 0.4, 0);
       glPopMatrix();

    glPopMatrix();





    //tree r2
    glPushMatrix();

    glTranslated(20,0,45);
    //second tree

        glPushMatrix();
        glTranslated(35,0.3,32);
        glScaled(1.5,10,1.5);
       cube(0.44, 0.33, 0.23);
       glPopMatrix();

        glPushMatrix();
        glTranslated(32,10,29);
        glScaled(8,3,8);
       cube(0, 0.4, 0);
       glPopMatrix();

        glPushMatrix();
        glTranslated(33,13,31);
        glScaled(5,3,5);
       cube(0, 0.4, 0);
       glPopMatrix();

        glPushMatrix();
        glTranslated(34,16,32);
        glScaled(3,2,3);
       cube(0, 0.4, 0);
       glPopMatrix();

    glPopMatrix();


    //tree r3
    glPushMatrix();

    glTranslated(20,0,60);
    //second tree

        glPushMatrix();
        glTranslated(35,0.3,32);
        glScaled(1.5,10,1.5);
       cube(0.44, 0.33, 0.23);
       glPopMatrix();

        glPushMatrix();
        glTranslated(32,10,29);
        glScaled(8,3,8);
       cube(0, 0.4, 0);
       glPopMatrix();

        glPushMatrix();
        glTranslated(33,13,31);
        glScaled(5,3,5);
       cube(0, 0.4, 0);
       glPopMatrix();

        glPushMatrix();
        glTranslated(34,16,32);
        glScaled(3,2,3);
       cube(0, 0.4, 0);
       glPopMatrix();

    glPopMatrix();


    //tree r4
    glPushMatrix();

    glTranslated(20,0,75);
    //second tree

        glPushMatrix();
        glTranslated(35,0.3,32);
        glScaled(1.5,10,1.5);
       cube(0.44, 0.33, 0.23);
       glPopMatrix();

        glPushMatrix();
        glTranslated(32,10,29);
        glScaled(8,3,8);
       cube(0, 0.4, 0);
       glPopMatrix();

        glPushMatrix();
        glTranslated(33,13,31);
        glScaled(5,3,5);
       cube(0, 0.4, 0);
       glPopMatrix();

        glPushMatrix();
        glTranslated(34,16,32);
        glScaled(3,2,3);
       cube(0, 0.4, 0);
       glPopMatrix();

    glPopMatrix();

    //tree r5
    glPushMatrix();

    glTranslated(20,0,90);
    //second tree

        glPushMatrix();
        glTranslated(35,0.3,32);
        glScaled(1.5,10,1.5);
       cube(0.44, 0.33, 0.23);
       glPopMatrix();

        glPushMatrix();
        glTranslated(32,10,29);
        glScaled(8,3,8);
       cube(0, 0.4, 0);
       glPopMatrix();

        glPushMatrix();
        glTranslated(33,13,31);
        glScaled(5,3,5);
       cube(0, 0.4, 0);
       glPopMatrix();

        glPushMatrix();
        glTranslated(34,16,32);
        glScaled(3,2,3);
       cube(0, 0.4, 0);
       glPopMatrix();

    glPopMatrix();

    //tree r6
    glPushMatrix();

    glTranslated(20,0,105);
    //second tree

        glPushMatrix();
        glTranslated(35,0.3,32);
        glScaled(1.5,10,1.5);
       cube(0.44, 0.33, 0.23);
       glPopMatrix();

        glPushMatrix();
        glTranslated(32,10,29);
        glScaled(8,3,8);
       cube(0, 0.4, 0);
       glPopMatrix();

        glPushMatrix();
        glTranslated(33,13,31);
        glScaled(5,3,5);
       cube(0, 0.4, 0);
       glPopMatrix();

        glPushMatrix();
        glTranslated(34,16,32);
        glScaled(3,2,3);
       cube(0, 0.4, 0);
       glPopMatrix();

    glPopMatrix();


    glPopMatrix();

//welcome
//w

glPushMatrix();
        glTranslated(-30,40,80);
        glScaled(1,10,1);
       cube(0.0, 0.3922, 0.0);
       glPopMatrix();


       glPushMatrix();
        glTranslated(-29,40,80);
        glRotated(45,0,0,1);
        glScaled(7,1,1);
       cube(0.0, 0.3922, 0.0);
       glPopMatrix();

        glPushMatrix();
       glTranslated(-21,40,80);
        glScaled(1,10,1);
       cube(0.0, 0.3922, 0.0);
       glPopMatrix();

glPushMatrix();
        glTranslated(-20,40,80);
        glRotated(130,0,0,1);
        glScaled(6.4,1.5,1);
       cube(0.0, 0.3922, 0.0);
       glPopMatrix();


//E
glPushMatrix();
        glTranslated(-15,40,80);
        glScaled(7,1,1);
       cube(0.0, 0.3333, 0.0);
       glPopMatrix();

       glPushMatrix();
        glTranslated(-15,40,80);
        glScaled(1,10,1);
       cube(0.0, 0.3333, 0.0);
       glPopMatrix();

       glPushMatrix();
        glTranslated(-15,45,80);
        glScaled(7,1,1);
       cube(0.0, 0.3333, 0.0);
       glPopMatrix();

       glPushMatrix();
        glTranslated(-15,49,80);
        glScaled(7,1,1);
       cube(0.0, 0.3333, 0.0);
       glPopMatrix();


       //L

       glPushMatrix();
        glTranslated(-5,40,80);
        glScaled(1,10,1);
       cube(0.0, 0.3333, 0.0);
       glPopMatrix();

       glPushMatrix();
        glTranslated(-4,40,80);
        glScaled(7,1,1);
       cube(0.0, 0.3333, 0.0);
       glPopMatrix();


       //C
       glPushMatrix();
        glTranslated(6,40,80);
        glScaled(8,1,1);
       cube(0.0, 0.3333, 0.0);
       glPopMatrix();

       glPushMatrix();
        glTranslated(6,40,80);
        glScaled(1,10,1);
       cube(0.0, 0.3333, 0.0);
       glPopMatrix();


       glPushMatrix();
        glTranslated(6,50,80);
        glScaled(7,1,1);
       cube(0.0, 0.3333, 0.0);
       glPopMatrix();

       //O

       glPushMatrix();
        glTranslated(16,40,80);
        glScaled(8,1,1);
       cube(0.0, 0.3333, 0.0);
       glPopMatrix();

       glPushMatrix();
        glTranslated(16,40,80);
        glScaled(1,10,1);
       cube(0.0, 0.3333, 0.0);
       glPopMatrix();


       glPushMatrix();
        glTranslated(16,50,80);
        glScaled(7,1,1);
       cube(0.0, 0.3333, 0.0);
       glPopMatrix();

       glPushMatrix();
        glTranslated(23,51,80);
        glScaled(1,-10,1);
       cube(0.0, 0.3333, 0.0);
       glPopMatrix();

//m
glPushMatrix();
        glTranslated(27,40,80);
        glScaled(1,10,1);
       cube(0.0, 0.3922, 0.0);
       glPopMatrix();


       glPushMatrix();
        glTranslated(27,50,80);
        glRotated(-45,0,0,1);
        glScaled(7,1,1);
       cube(0.0, 0.3922, 0.0);
       glPopMatrix();

        glPushMatrix();
       glTranslated(35,40,80);
        glScaled(1,10,1);
       cube(0.0, 0.3922, 0.0);
       glPopMatrix();

glPushMatrix();
        glTranslated(34.8,50,80);
        glRotated(-130,0,0,1);
        glScaled(5.4,1.5,1);
       cube(0.0, 0.3922, 0.0);
       glPopMatrix();

//E

glPushMatrix();
        glTranslated(39,40,80);
        glScaled(7,1,1);
       cube(0.0, 0.3333, 0.0);
       glPopMatrix();

       glPushMatrix();
        glTranslated(39,40,80);
        glScaled(1,10,1);
       cube(0.0, 0.3333, 0.0);
       glPopMatrix();

       glPushMatrix();
        glTranslated(39,45,80);
        glScaled(7,1,1);
       cube(0.0, 0.3333, 0.0);
       glPopMatrix();

       glPushMatrix();
        glTranslated(39,49,80);
        glScaled(7,1,1);
       cube(0.0, 0.3333, 0.0);
    glPopMatrix();





   //entry

   glPushMatrix();
   glTranslated(-30,-5,130);
   glRotated(-25,0,0,1);
        glScaled(10,95.5,-10);
cube(0.5451, 0.0, 0.0);
    glPopMatrix();

    glPushMatrix();
   glTranslated(50,-5,130);
   glRotated(25,0,0,1);
        glScaled(10,92,-10);
cube(0.5451, 0.0, 0.0);
    glPopMatrix();


     glPushMatrix();
   glTranslated(-15,78,140);
        glScaled(60,5,-20);
cube(0.5, 0.2, 0.1);
    glPopMatrix();

    //gold

    glPushMatrix();
   glTranslated(5,82,130);
        glScaled(20,10,-10);
       cube(0.8039, 0.6706, 0.1765);
    glPopMatrix();

    glPushMatrix();
   glTranslated(7.5,91,130);
        glScaled(15,10,-10);
       cube(0.8039, 0.6706, 0.1765);
    glPopMatrix();


    //big water pool

    glPushMatrix();
   glTranslated(-100,0.1,160);
        glScaled(70,1,-50);
cube(8 / 255.0, 66 / 255.0, 134 / 255.0);
    glPopMatrix();


    glPushMatrix();
   glTranslated(-80,1.1,130);
        glScaled(5,1,-5);
cube(0.0,0.4,0.0);
    glPopMatrix();

    glPushMatrix();
   glTranslated(-70,1.1,120);
        glScaled(5,1,-5);
cube(0.0,0.4,0.0);
    glPopMatrix();


    glPushMatrix();
   glTranslated(-60,1.1,140);
        glScaled(5,1,-5);
cube(0.0,0.4,0.0);
    glPopMatrix();

    glPushMatrix();
   glTranslated(-50,1.1,150);
        glScaled(5,1,-5);
cube(0.0,0.4,0.0);
    glPopMatrix();























    glPopMatrix();
    glutSwapBuffers();
}




static void key(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 'w':
            eyeY += 0.1;
            break;
        case 's':
            eyeY -= 0.1;
            break;
        case 'd':
            eyeX += 0.1;
            break;
        case 'a':
            eyeX -= 0.1;
            break;
        case 'i':
            lookY += 0.1;
            break;
        case 'k':
            lookY -= 0.1;
            break;
        case 'j':
            lookX += 0.1;
            break;
        case 'l':
            lookX -= 0.1;
            break;
            case '-':
        eyeZ=eyeZ+0.1;
        break;
    case '=':
        eyeZ=eyeZ-0.1;
        break;
    }

    glutPostRedisplay();
}















int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    glutInitWindowPosition(100, 100);
    glutInitWindowSize(1000, 1000);
    glutCreateWindow("City Of Gold");

    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);

    glutDisplayFunc(display);
    glutKeyboardFunc(key);
PlaySound("giga.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
    glutMainLoop();

    return 0;
}

