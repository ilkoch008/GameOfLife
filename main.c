#include "all.h"

void setup() {   glClearColor(0.0f, 0.0f, 0.0f, 0.0f); }



int main(int argc, char *argv[]){
    time_to_finish = 0;
    signal(SIGINT, quit);
    MPI_Init(&argc, &argv);
    resolution = 512;
    multiProc = 0;
    visual = 0;

    for(int i = 1; i < argc; i++){
        if(strstr(argv[i], "-m") != NULL){
            multiProc = 1;
        } else if(strstr(argv[i], "-v") != NULL){
            visual = 1;
        } else if(strstr(argv[i], "-r") != NULL){
            resolution = atoi(argv[i+1]);
        }
    }

    halfRes = resolution/2;
    resolution_1 = 1/resolution;
    res = (int) resolution;
    hRes = (int) halfRes;

    int numOfProcs, myRank, namelen, size;
    MPI_Status status;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_size(MPI_COMM_WORLD, &numOfProcs);
    MPI_Comm_rank(MPI_COMM_WORLD, &myRank);

    glutInit(&argc, argv);
    glutKeyboardFunc(quit_key);

    if(myRank == 0) {
        glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
        glutInitWindowSize(1024, 1024);
        glutCreateWindow("Hello World");
        setup();
    }

    //fprintf(stdout, "lol %d\n", myRank);

    if(multiProc){
        if(myRank == 0) {
            glutDisplayFunc(multiProcess);
        } else {
            multiProcess();
        }
    } else {
        if(myRank == 0) {
            glutDisplayFunc(singleProc);
        } else {
            sleep(INT32_MAX);
        }
    }
    glutMainLoop();

    if(multiProc == 0) {
        for (int i = 0; i < res; i++) {
            free(field_1[i]);
        }
        for (int i = 0; i < res; i++) {
            free(field_2[i]);
        }
        free(field_1);
        free(field_2);
    }

    MPI_Finalize();
    return 0;
}
