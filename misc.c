//
// Created by ilya on 18.05.2020.
//

#include "all.h"

void MakePixelBlack(int x, int y){
    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    float x_halfRes = (float) x/halfRes;
    float y_halfRes = (float) y/halfRes;
    glColor3f(0.0f, 0.0f, 0.0f);
    glRectf(x_halfRes,y_halfRes, x_halfRes + resolution_1,y_halfRes - resolution_1);
}

void MakePixelWhite(int x, int y){
    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    float x_halfRes = (float) x/halfRes;
    float y_halfRes = (float) y/halfRes;
    glColor3f(1.0f, 1.0f, 1.0f);
    glRectf(((float)x)/halfRes,((float)y)/halfRes, ((float)x)/halfRes + 1/resolution,((float)y)/halfRes - 1/resolution);
    glRectf(x_halfRes,y_halfRes, x_halfRes + resolution_1,y_halfRes - resolution_1);
}

void quit(int sig){
    time_to_finish = 1;
    int numOfProcs, myRank;
    MPI_Comm_size(MPI_COMM_WORLD, &numOfProcs);
    MPI_Comm_rank(MPI_COMM_WORLD, &myRank);
    //fprintf(stdout, "Wee\n");
    if(myRank != 0 && multiProc == 0){
        exit(0);
    }
}

void quit_key(unsigned char key, int x, int y){
    if(key == 27){
        time_to_finish = 1;
    }
}

