#include "Chunk.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <iostream>

// Functions.
void Display();
Chunk GetChunk(int x, int z);
void GetMouseMovement(int x, int y);
void Reshape(int width, int height);
void Timer(int);

// Variables.
float mouse_X;
float mouse_Y;

float render_Angle;

float screen_Aspect = 1.35;
float screen_Fov = 60;
float screen_Max = 500;
int screen_MaxFPS = 60;
float screen_Min = 1;

int window_StartHeight = 768;
int window_StartWidth = 1024;
int window_StartX = 750;
int window_StartY = 350;


void CreateWindow()
{
    glutInitWindowPosition(window_StartX, window_StartY);
    glutInitWindowSize(window_StartWidth, window_StartHeight);

    glutCreateWindow("Voxel Engine");
    glutDisplayFunc(Display);
    glutPassiveMotionFunc(GetMouseMovement);
    glutReshapeFunc(Reshape);
    glutTimerFunc(0, Timer, 0);

    glClearColor(0.1, 0.1, 0.3, 1.0);
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
}

void Display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    for(int x = 0; x < 3; x++)
    {
        for(int z = 0; z < 3; z++)
        {
            glBegin(GL_QUADS);
            Chunk currentChunk = GetChunk(x, z);
            currentChunk.RenderChunk();
            glEnd();
        }
    }

    glutSwapBuffers();
}

void GetMouseMovement(int x, int y)
{
    mouse_X = x / 64;
    mouse_Y = y / 64;
}

void Reshape(int width, int height)
{
    glViewport(0, 0, (GLsizei)width, (GLsizei)height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(screen_Fov, screen_Aspect, screen_Min, screen_Max);

    glMatrixMode(GL_MODELVIEW);
}

void StartRenderer(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    CreateWindow();
}

void Timer(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000 / screen_MaxFPS, Timer, 0);

    if(render_Angle >= 360)
    {
        render_Angle = 0;
    }

    render_Angle += 1;
}
