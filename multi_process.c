//
// Created by ilya on 19.05.2020.
//

#include "all.h"

void multiProcess() {
    int numOfWhite;
    int size = 0;
    int numOfNeighbours = 0;
    double dTime = 0;
    double pTime = 0;
    float fps = 0;
    char fps_str[30];
    int frames = 0;
    int local_i = 0;
    int hResRes = hRes * res;

    int numOfProcs, myRank;
    MPI_Status status;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_size(MPI_COMM_WORLD, &numOfProcs);
    MPI_Comm_rank(MPI_COMM_WORLD, &myRank);

    if (myRank == 0) {
        if (res % (numOfProcs - 1) != 0) {
            fprintf(stderr, "Wrong ratio resolution/numberOfSlaves\n");
            exit(1);
        }
    }


    int rowsForEachProc = res / (numOfProcs - 1);

    if (myRank == 0) {

        f_field_1 = malloc(res * res * sizeof(int));
        for (int j = 0; j < res * res; j++) {
            f_field_1[j] = (int) random() % 2;
        }
        for (int i = 1; i < numOfProcs; i++) {
            MPI_Send(&f_field_1[(i-1) * res * rowsForEachProc], res * rowsForEachProc, MPI_INT, i, 1, MPI_COMM_WORLD);
        }


        for (int i = -hRes; i < hRes; i++) {
            for (int j = -hRes; j < hRes; j++) {
                if (f_field_1[(i + hRes) * res + j + hRes] == MY_WHITE) {
                    MakePixelWhite(i, j);
                    numOfWhite++;
                } else {
                    MakePixelBlack(i, j);
                }
            }
        }
        numOfWhite = 0;
        glutSwapBuffers();

        while (1) {

            for (int i = 1; i < numOfProcs; i++) {
                MPI_Recv(&f_field_1[(i-1) * res * rowsForEachProc], res * rowsForEachProc, MPI_INT, i, 1, MPI_COMM_WORLD, &status);
            }

            if(time_to_finish){
                break;
            }

            pTime = MPI_Wtime();
            for (int i = -hRes; i < hRes; i++) {
                local_i = i * res;
                for (int j = -hRes; j < hRes; j++) {
                    if(visual) {
                        if (f_field_1[(local_i + hResRes) + j + hRes] == MY_WHITE) {
                            MakePixelWhite(i, j);
                            numOfWhite++;
                        } else {
                            MakePixelBlack(i, j);
                        }
                    }
                }
            }
            //fprintf(stdout, "painting %f\n", MPI_Wtime()-pTime);
            glutSwapBuffers();

            numOfWhite = 0;

            if (MPI_Wtime() - dTime > 1) {
                fps = (float) frames;
                gcvt(fps, 3, fps_str);
                strcat(fps_str, " fps");
                glutSetWindowTitle(fps_str);
                frames = 0;
                dTime = MPI_Wtime();
            } else {
                frames++;
            }
        }
        free(f_field_1);
    } else {
        f_field_1 = calloc(res * (2 + rowsForEachProc), sizeof(int));
        f_field_2 = calloc(res * (2 + rowsForEachProc), sizeof(int));
        MPI_Recv(&f_field_1[res], res * rowsForEachProc, MPI_INT, 0, 1, MPI_COMM_WORLD, &status);

        while (1) {
            dTime = MPI_Wtime();
            if (myRank == 1 && numOfProcs != 2) {
                MPI_Send(&f_field_1[rowsForEachProc * res], res, MPI_INT, 2, 1, MPI_COMM_WORLD);
                MPI_Recv(&f_field_1[(rowsForEachProc + 1) * res], res, MPI_INT, 2, 1, MPI_COMM_WORLD, &status);
            } else if (myRank == numOfProcs - 1 && numOfProcs != 2) {
                MPI_Recv(f_field_1, res, MPI_INT, numOfProcs - 2, 1, MPI_COMM_WORLD, &status);
                MPI_Send(&f_field_1[res], res, MPI_INT, numOfProcs - 2, 1, MPI_COMM_WORLD);
            } else if (numOfProcs > 2) {
                MPI_Recv(f_field_1, res, MPI_INT, myRank - 1, 1, MPI_COMM_WORLD, &status);
                MPI_Send(&f_field_1[res], res, MPI_INT, myRank - 1, 1, MPI_COMM_WORLD);
                MPI_Send(&f_field_1[rowsForEachProc * res], res, MPI_INT, myRank + 1, 1, MPI_COMM_WORLD);
                MPI_Recv(&f_field_1[(rowsForEachProc + 1) * res], res, MPI_INT, myRank + 1, 1, MPI_COMM_WORLD, &status);
            }
            if (f_field_1[0] == -1) {
                break;
            }


            dTime = MPI_Wtime();
            for (int i = 1; i < rowsForEachProc + 1; i++) {
                for (int j = 0; j < res; j++) {
                    local_i = i * res;
                    if (i + 1 < rowsForEachProc + 1) {
                        if (f_field_1[local_i + res + j] == MY_WHITE) {
                            numOfNeighbours++;
                        }
                    }
                    if (i - 1 >= 1) {
                        if (f_field_1[local_i - res + j] == MY_WHITE) {
                            numOfNeighbours++;
                        }
                    }
                    if (j + 1 < res) {
                        if (f_field_1[local_i + j + 1] == MY_WHITE) {
                            numOfNeighbours++;
                        }
                    }
                    if (j - 1 >= 0) {
                        if (f_field_1[local_i + j - 1] == MY_WHITE) {
                            numOfNeighbours++;
                        }
                    }


                    if (i + 1 < rowsForEachProc + 1 && j + 1 < res) {
                        if (f_field_1[local_i + res + j + 1] == MY_WHITE) {
                            numOfNeighbours++;
                        }
                    }
                    if (i - 1 >= 1 && j - 1 >= 0) {
                        if (f_field_1[local_i - res + j - 1] == MY_WHITE) {
                            numOfNeighbours++;
                        }
                    }
                    if (i + 1 < rowsForEachProc + 1 && j - 1 >= 0) {
                        if (f_field_1[local_i + res + j - 1] == MY_WHITE) {
                            numOfNeighbours++;
                        }
                    }
                    if (i - 1 >= 1 && j + 1 < res) {
                        if (f_field_1[local_i - res + j + 1] == MY_WHITE) {
                            numOfNeighbours++;
                        }
                    }
                    if (numOfNeighbours == 3) {
                        f_field_2[i * res + j] = MY_WHITE;
                    }
                    if (numOfNeighbours != 2 && numOfNeighbours != 3) {
                        f_field_2[i * res + j] = MY_BLACK;
                    }
                    numOfNeighbours = 0;
                }
            }

            for (int i = 0; i < res * (2 + rowsForEachProc); i++) {
                f_field_1[i] = f_field_2[i];
            }

            //fprintf(stdout, "computing %f\n", MPI_Wtime()-dTime);

            MPI_Send(&f_field_1[res], res * rowsForEachProc, MPI_INT, 0, 1, MPI_COMM_WORLD);

            if(time_to_finish){
                break;
            }
        }

        free(f_field_1);
        free(f_field_2);
    }

}
