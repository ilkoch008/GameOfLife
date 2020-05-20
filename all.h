//
// Created by ilya on 18.05.2020.
//

#ifndef GAMEOFLIFE_ALL_H
#define GAMEOFLIFE_ALL_H

#include <stdio.h>
#include <graphics.h>
#include <math.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include "mpi.h"
#include <string.h>

#define MY_WHITE 1
#define MY_BLACK 0

int * * field_1;
int * * field_2;

int * f_field_1;
int * f_field_2;

float resolution;
float halfRes;
float resolution_1;
int res;
int hRes;
int multiProc;
int time_to_finish;
int visual;

void MakePixelBlack(int x, int y);
void MakePixelWhite(int x, int y);
void singleProc();
void multiProcess();
void quit(int sig);
void quit_key(unsigned char key, int x, int y);


#endif //GAMEOFLIFE_ALL_H
