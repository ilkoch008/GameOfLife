//
// Created by ilya on 18.05.2020.
//
#include "all.h"

void singleProc()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    int numOfWhite = 0;
    int numOfNeighbours = 0;

    field_1 = malloc(res * sizeof(int *));
    for(int i = 0; i < res; i++){
        field_1[i] = malloc(res * sizeof(int));
    }

    field_2 = malloc(res * sizeof(int *));
    for(int i = 0; i < res; i++){
        field_2[i] = malloc(res * sizeof(int));
    }

    for(int i = 0; i < res; i++){
        for(int j = 0; j < res; j++){
            field_1[i][j] = (int) random() % 2;
        }
    }

    for(int i = 0; i < res; i++){
        for(int j = 0; j < res; j++){
            field_2[i][j] = field_1[i][j];
        }
    }

    for (int i = -hRes; i < hRes; i++) {
        for (int j = -hRes; j < hRes; j++) {
            if (field_1[i + hRes][j + hRes] == MY_WHITE) {
                MakePixelWhite(i, j);
                numOfWhite++;
            } else {
                MakePixelBlack(i, j);
            }
        }
    }
    glutSwapBuffers();
    numOfWhite = 0;
    char fps_str[30];
    float fps;
    int frames = 0;
    double dTime = MPI_Wtime();

    while(1) {

        for(int i = 0; i < res; i++){
            for(int j = 0; j < res; j++){
                if(i + 1 < res){
                    if(field_1[i+1][j] == MY_WHITE){
                        numOfNeighbours++;
                    }
                }
                if(i - 1 >= 0){
                    if(field_1[i-1][j] == MY_WHITE){
                        numOfNeighbours++;
                    }
                }
                if(j + 1 < res){
                    if(field_1[i][j+1] == MY_WHITE){
                        numOfNeighbours++;
                    }
                }
                if(j - 1 >= 0){
                    if(field_1[i][j-1] == MY_WHITE){
                        numOfNeighbours++;
                    }
                }


                if(i + 1 < res && j + 1 < res){
                    if(field_1[i+1][j+1] == MY_WHITE){
                        numOfNeighbours++;
                    }
                }
                if(i - 1 >= 0 && j - 1 >= 0){
                    if(field_1[i-1][j-1] == MY_WHITE){
                        numOfNeighbours++;
                    }
                }
                if(i + 1 < res && j - 1 >= 0){
                    if(field_1[i+1][j-1] == MY_WHITE){
                        numOfNeighbours++;
                    }
                }
                if(i - 1 >= 0 && j + 1 < res){
                    if(field_1[i-1][j+1] == MY_WHITE){
                        numOfNeighbours++;
                    }
                }
                if(numOfNeighbours == 3){
                    field_2[i][j] = MY_WHITE;
                }
                if(numOfNeighbours != 2 && numOfNeighbours != 3){
                    field_2[i][j] = MY_BLACK;
                }
                numOfNeighbours = 0;
            }
        }

        for(int i = 0; i < res; i++){
            for(int j = 0; j < res; j++){
                field_1[i][j] = field_2[i][j];
            }
        }

        for (int i = -hRes; i < hRes; i++) {
            for (int j = -hRes; j < hRes; j++) {
                if(visual) {
                    if (field_1[i + hRes][j + hRes] == MY_WHITE) {
                        MakePixelWhite(i, j);
                        numOfWhite++;
                    } else {
                        MakePixelBlack(i, j);
                    }
                }
            }
        }
        numOfWhite = 0;
        glutSwapBuffers();

        if(MPI_Wtime() - dTime > 1){
            fps = (float)frames;
            gcvt(fps, 3, fps_str);
            strcat(fps_str, " fps");
            glutSetWindowTitle(fps_str);
            frames = 0;
            dTime = MPI_Wtime();
        } else{
            frames++;
        }

        if(time_to_finish){
            break;
        }
    }

}

