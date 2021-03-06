#include "../platonic.h"

#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#define PHI        1.61803398874989484820458683436563811   /* (1+sqrt(5))/2  */
#define M_2PI      6.28318530717958647693528676655900576
#define SQRT_p_5   0.707106781186547524400844362104849     /* sqrt(.5)  */
#define SQRT_1_p_5 1.224744871391589049098642037352946     /* sqrt(1.5)  */

// this was used to help generate the geometry included in this project
// to do:  the hexahedron, and the faces on the dodecahedron

void _generate_tetrahedron(long double **po, unsigned int *numPoints,
                           unsigned short **li, unsigned int *numLines,
                           unsigned short **fa, unsigned int *numFaces){
    long double side = SQRT_p_5;
    long double f = SQRT_1_p_5;
    *numPoints = 4;
    *numLines = 6;
    *numFaces = 4;
    long double *points = malloc(sizeof(long double)*(*numPoints)*3);
    points[0+3*0] = 0.0;     points[1+3*0] = 1.0/f;   points[2+3*0] = side/f;
    points[0+3*1] = 0.0;     points[1+3*1] = -1.0/f;  points[2+3*1] = side/f;
    points[0+3*2] = 1.0/f;   points[1+3*2] = 0.0;     points[2+3*2] = -side/f;
    points[0+3*3] = -1.0/f;  points[1+3*3] = 0.0;     points[2+3*3] = -side/f;
    unsigned short *lines = malloc(sizeof(unsigned short)*(*numLines)*2);
    lines[0+2*0] = 0;  lines[1+2*0] = 1;
    lines[0+2*1] = 0;  lines[1+2*1] = 2;
    lines[0+2*2] = 0;  lines[1+2*2] = 3;
    lines[0+2*3] = 1;  lines[1+2*3] = 2;
    lines[0+2*4] = 1;  lines[1+2*4] = 3;
    lines[0+2*5] = 2;  lines[1+2*5] = 3;
    unsigned short *faces = malloc(sizeof(unsigned short)*(*numFaces)*3);
    faces[0+3*0] = 0;  faces[1+3*0] = 3;  faces[2+3*0] = 2;
    faces[0+3*1] = 0;  faces[1+3*1] = 1;  faces[2+3*1] = 3;
    faces[0+3*2] = 0;  faces[1+3*2] = 2;  faces[2+3*2] = 1;
    faces[0+3*3] = 1;  faces[1+3*3] = 2;  faces[2+3*3] = 3;
    // rotate and align one point to X axis
    long double offset = 0.615479708670387;
    long double distance, angle;
    for(int i = 0; i < *numPoints; i++){
        angle = atan2(points[i*3+2], points[i*3+0]);
        distance = sqrt( pow(points[i*3+2], 2) + pow(points[i*3+0], 2) );
        points[i*3+2] = distance*sin(angle+offset);
        points[i*3+0] = distance*cos(angle+offset);
        //points[i*3+Z] stays the same
    }
    *po = points;
    *li = lines;
    *fa = faces;
}

void _generate_octahedron(long double **po, unsigned int *numPoints,
                          unsigned short **li, unsigned int *numLines,
                          unsigned short **fa, unsigned int *numFaces){
    *numPoints = 6;
    *numLines = 12;
    *numFaces = 8;
    long double *points = malloc(sizeof(long double)*(*numPoints)*3);
    points[0+3*0] = 0.0;   points[1+3*0] = 1.0;   points[2+3*0] = 0.0;
    points[0+3*1] = 1.0;   points[1+3*1] = 0.0;   points[2+3*1] = 0.0;
    points[0+3*2] = 0.0;   points[1+3*2] = 0.0;   points[2+3*2] = -1.0;
    points[0+3*3] = -1.0;  points[1+3*3] = 0.0;   points[2+3*3] = 0.0;
    points[0+3*4] = 0.0;   points[1+3*4] = 0.0;   points[2+3*4] = 1.0;
    points[0+3*5] = 0.0;   points[1+3*5] = -1.0;  points[2+3*5] = 0.0;
    unsigned short *lines = malloc(sizeof(unsigned short)*(*numLines)*2);
    lines[0+2*0] = 0;  lines[1+2*0] = 1;
    lines[0+2*1] = 0;  lines[1+2*1] = 4;
    lines[0+2*2] = 0;  lines[1+2*2] = 2;
    lines[0+2*3] = 0;  lines[1+2*3] = 3;
    lines[0+2*4] = 3;  lines[1+2*4] = 4;
    lines[0+2*5] = 4;  lines[1+2*5] = 1;
    lines[0+2*6] = 1;  lines[1+2*6] = 2;
    lines[0+2*7] = 2;  lines[1+2*7] = 3;
    lines[0+2*8] = 5;  lines[1+2*8] = 4;
    lines[0+2*9] = 5;  lines[1+2*9] = 3;
    lines[0+2*10] = 5; lines[1+2*10] = 2;
    lines[0+2*11] = 5; lines[1+2*11] = 1;
    unsigned short *faces = malloc(sizeof(unsigned short)*(*numFaces)*3);
    faces[0+3*0] = 0;  faces[1+3*0] = 1;  faces[2+3*0] = 4;
    faces[0+3*1] = 0;  faces[1+3*1] = 2;  faces[2+3*1] = 1;
    faces[0+3*2] = 0;  faces[1+3*2] = 3;  faces[2+3*2] = 2;
    faces[0+3*3] = 0;  faces[1+3*3] = 4;  faces[2+3*3] = 3;
    faces[0+3*4] = 5;  faces[1+3*4] = 4;  faces[2+3*4] = 1;
    faces[0+3*5] = 5;  faces[1+3*5] = 3;  faces[2+3*5] = 4;
    faces[0+3*6] = 5;  faces[1+3*6] = 2;  faces[2+3*6] = 3;
    faces[0+3*7] = 5;  faces[1+3*7] = 1;  faces[2+3*7] = 2;
    *po = points;
    *li = lines;
    *fa = faces;
}

void _generate_icosahedron(long double **po, unsigned int *numPoints,
                           unsigned short **li, unsigned int *numLines,
                           unsigned short **fa, unsigned int *numFaces){
    long double f = sqrt( ((1 + sqrt(5)) / 2 ) + 2 );
    *numPoints = 12;
    *numLines = 30;
    *numFaces = 20;
    long double *points = malloc(sizeof(long double)*(*numPoints)*3);
    points[0+3*0] = 0.0;     points[1+3*0] = 1.0/f;    points[2+3*0] = PHI/f;
    points[0+3*1] = 0.0;     points[1+3*1] = -1.0/f;   points[2+3*1] = PHI/f;
    points[0+3*2] = 0.0;     points[1+3*2] = -1.0/f;   points[2+3*2] = -PHI/f;
    points[0+3*3] = 0.0;     points[1+3*3] = 1.0/f;    points[2+3*3] = -PHI/f;
    points[0+3*4] = PHI/f;   points[1+3*4] = 0.0;      points[2+3*4] = 1.0/f;
    points[0+3*5] = -PHI/f;  points[1+3*5] = 0.0;      points[2+3*5] = 1.0/f;
    points[0+3*6] = -PHI/f;  points[1+3*6] = 0.0;      points[2+3*6] = -1.0/f;
    points[0+3*7] = PHI/f;   points[1+3*7] = 0.0;      points[2+3*7] = -1.0/f;
    points[0+3*8] = 1.0/f;   points[1+3*8] = PHI/f;    points[2+3*8] = 0.0;
    points[0+3*9] = -1.0/f;  points[1+3*9] = PHI/f;    points[2+3*9] = 0.0;
    points[0+3*10] = -1.0/f; points[1+3*10] = -PHI/f;  points[2+3*10] = 0.0;
    points[0+3*11] = 1.0/f;  points[1+3*11] = -PHI/f;  points[2+3*11] = 0.0;
    unsigned short *lines = malloc(sizeof(unsigned short)*(*numLines)*2);
    lines[0+2*0] = 0;   lines[1+2*0] = 8;
    lines[0+2*1] = 0;   lines[1+2*1] = 9;
    lines[0+2*2] = 0;   lines[1+2*2] = 1;
    lines[0+2*3] = 0;   lines[1+2*3] = 4;
    lines[0+2*4] = 0;   lines[1+2*4] = 5;
    lines[0+2*5] = 8;   lines[1+2*5] = 3;
    lines[0+2*6] = 8;   lines[1+2*6] = 9;
    lines[0+2*7] = 8;   lines[1+2*7] = 7;
    lines[0+2*8] = 8;   lines[1+2*8] = 4;
    lines[0+2*9] = 9;   lines[1+2*9] = 3;
    lines[0+2*10] = 9;  lines[1+2*10] = 6;
    lines[0+2*11] = 9;  lines[1+2*11] = 5;
    lines[0+2*12] = 7;  lines[1+2*12] = 4;
    lines[0+2*13] = 7;  lines[1+2*13] = 3;
    lines[0+2*14] = 7;  lines[1+2*14] = 2;
    lines[0+2*15] = 7;  lines[1+2*15] = 11;
    lines[0+2*16] = 2;  lines[1+2*16] = 10;
    lines[0+2*17] = 2;  lines[1+2*17] = 11;
    lines[0+2*18] = 2;  lines[1+2*18] = 3;
    lines[0+2*19] = 2;  lines[1+2*19] = 6;
    lines[0+2*20] = 10; lines[1+2*20] = 11;
    lines[0+2*21] = 10; lines[1+2*21] = 5;
    lines[0+2*22] = 10; lines[1+2*22] = 6;
    lines[0+2*23] = 10; lines[1+2*23] = 1;
    lines[0+2*24] = 11; lines[1+2*24] = 1;
    lines[0+2*25] = 11; lines[1+2*25] = 4;
    lines[0+2*26] = 4;  lines[1+2*26] = 1;
    lines[0+2*27] = 5;  lines[1+2*27] = 1;
    lines[0+2*28] = 5;  lines[1+2*28] = 6;
    lines[0+2*29] = 6;  lines[1+2*29] = 3;
    unsigned short *faces = malloc(sizeof(unsigned short)*(*numFaces)*3);
    faces[0+3*0] = 8;    faces[1+3*0] = 7;    faces[2+3*0] = 4;
    faces[0+3*1] = 8;    faces[1+3*1] = 3;    faces[2+3*1] = 7;
    faces[0+3*2] = 8;    faces[1+3*2] = 4;    faces[2+3*2] = 0;
    faces[0+3*3] = 8;    faces[1+3*3] = 0;    faces[2+3*3] = 9;
    faces[0+3*4] = 9;    faces[1+3*4] = 3;    faces[2+3*4] = 8;
    faces[0+3*5] = 9;    faces[1+3*5] = 0;    faces[2+3*5] = 5;
    faces[0+3*6] = 9;    faces[1+3*6] = 5;    faces[2+3*6] = 6;
    faces[0+3*7] = 9;    faces[1+3*7] = 6;    faces[2+3*7] = 3;
    
    faces[0+3*8] = 3;    faces[1+3*8] = 2;    faces[2+3*8] = 7;
    faces[0+3*9] = 3;    faces[1+3*9] = 6;    faces[2+3*9] = 2;
    faces[0+3*10] = 0;   faces[1+3*10] = 4;   faces[2+3*10] = 1;
    faces[0+3*11] = 0;   faces[1+3*11] = 1;   faces[2+3*11] = 5;
    
    faces[0+3*12] = 11;  faces[1+3*12] = 4;   faces[2+3*12] = 7;
    faces[0+3*13] = 11;  faces[1+3*13] = 7;   faces[2+3*13] = 2;
    faces[0+3*14] = 11;  faces[1+3*14] = 2;   faces[2+3*14] = 10;
    faces[0+3*15] = 11;  faces[1+3*15] = 10;  faces[2+3*15] = 1;
    faces[0+3*16] = 11;  faces[1+3*16] = 1;   faces[2+3*16] = 4;
    faces[0+3*17] = 10;  faces[1+3*17] = 6;   faces[2+3*17] = 5;
    faces[0+3*18] = 10;  faces[1+3*18] = 5;   faces[2+3*18] = 1;
    faces[0+3*19] = 10;  faces[1+3*19] = 2;   faces[2+3*19] = 6;
    // align 2 points along the X
    long double offset =  (M_2PI/4.) - atan( (1 + sqrt(5)) / 2 ) + M_2PI*.25;
    long double distance, angle;
    //rotate around the z until points aligned
    for(int i = 0; i < *numPoints; i++){
        angle = atan2(points[i*3+0], points[i*3+1]);
        distance = sqrt( pow(points[i*3+0], 2) + pow(points[i*3+1], 2) );
        points[i*3+0] = distance*sin(angle+offset);
        points[i*3+1] = distance*cos(angle+offset);
        //points[i*3+Z] stays the same
    }
    *po = points;
    *li = lines;
    *fa = faces;
}


void _generate_dodecahedron(long double **po, unsigned int *numPoints,
                            unsigned short **li, unsigned int *numLines){
                         // unsigned short **fa, unsigned int *numFaces){
    long double SQRT3 = sqrt(3);
    *numPoints = 20;
    *numLines = 30;
    // *numFaces = 12;
    long double *points = malloc(sizeof(long double)*(*numPoints)*3);

    points[0+3*0] = 1/SQRT3;          points[1+3*0] = 1/SQRT3;            points[2+3*0] = 1/SQRT3;
    points[0+3*1] = 1/SQRT3;          points[1+3*1] = 1/SQRT3;            points[2+3*1] = -1/SQRT3;
    points[0+3*2] = 1/SQRT3;          points[1+3*2] = -1/SQRT3;           points[2+3*2] = 1/SQRT3;
    points[0+3*3] = 1/SQRT3;          points[1+3*3] = -1/SQRT3;           points[2+3*3] = -1/SQRT3;
    points[0+3*4] = -1/SQRT3;         points[1+3*4] = 1/SQRT3;            points[2+3*4] = 1/SQRT3;
    points[0+3*5] = -1/SQRT3;         points[1+3*5] = 1/SQRT3;            points[2+3*5] = -1/SQRT3;
    points[0+3*6] = -1/SQRT3;         points[1+3*6] = -1/SQRT3;           points[2+3*6] = 1/SQRT3;
    points[0+3*7] = -1/SQRT3;         points[1+3*7] = -1/SQRT3;           points[2+3*7] = -1/SQRT3;      
    points[0+3*8] = 0;                points[1+3*8] = 1/(PHI*SQRT3);      points[2+3*8] = PHI/SQRT3;
    points[0+3*9] = 0;                points[1+3*9] = 1/(PHI*SQRT3);      points[2+3*9] = -PHI/SQRT3;
    points[0+3*10] = 0;               points[1+3*10] = -1/(PHI*SQRT3);   points[2+3*10] = PHI/SQRT3;
    points[0+3*11] = 0;               points[1+3*11] = -1/(PHI*SQRT3);   points[2+3*11] = -PHI/SQRT3;
    points[0+3*12] = PHI/SQRT3;       points[1+3*12] = 0;                points[2+3*12] = 1/(PHI*SQRT3);
    points[0+3*13] = PHI/SQRT3;       points[1+3*13] = 0;                points[2+3*13] = -1/(PHI*SQRT3);
    points[0+3*14] = -PHI/SQRT3;      points[1+3*14] = 0;                points[2+3*14] = 1/(PHI*SQRT3);
    points[0+3*15] = -PHI/SQRT3;      points[1+3*15] = 0;                points[2+3*15] = -1/(PHI*SQRT3);
    points[0+3*16] = 1/(PHI*SQRT3);   points[1+3*16] = PHI/SQRT3;        points[2+3*16] = 0;
    points[0+3*17] = 1/(PHI*SQRT3);   points[1+3*17] = -PHI/SQRT3;       points[2+3*17] = 0;
    points[0+3*18] = -1/(PHI*SQRT3);  points[1+3*18] = PHI/SQRT3;        points[2+3*18] = 0;
    points[0+3*19] = -1/(PHI*SQRT3);  points[1+3*19] = -PHI/SQRT3;       points[2+3*19] = 0;

    unsigned short *lines = malloc(sizeof(unsigned short)*(*numLines)*2);
    lines[0+2*0] = 0  ;    lines[1+2*0] =  12 ;
    lines[0+2*1] = 12 ;    lines[1+2*1] =  13 ;
    lines[0+2*2] = 13 ;    lines[1+2*2] =  1  ;
    lines[0+2*3] = 1  ;    lines[1+2*3] =  16 ;
    lines[0+2*4] = 16 ;    lines[1+2*4] =  0  ;
    lines[0+2*5] = 16 ;    lines[1+2*5] =  18 ;
    lines[0+2*6] = 18 ;    lines[1+2*6] =  4  ;
    lines[0+2*7] = 4  ;    lines[1+2*7] =  8  ;
    lines[0+2*8] = 12 ;    lines[1+2*8] =  2  ;
    lines[0+2*9] = 2  ;    lines[1+2*9] = 17 ;
    lines[0+2*10] = 17 ;    lines[1+2*10] =  3 ;
    lines[0+2*11] = 3  ;    lines[1+2*11] = 13 ;
    lines[0+2*12] = 0  ;    lines[1+2*12] = 8  ;
    lines[0+2*13] = 8  ;    lines[1+2*13] = 10 ;
    lines[0+2*14] = 10 ;    lines[1+2*14] =  2 ;
    lines[0+2*15] = 1  ;    lines[1+2*15] = 9  ;
    lines[0+2*16] = 9  ;    lines[1+2*16] = 11 ;
    lines[0+2*17] = 11 ;    lines[1+2*17] =  3 ;
    lines[0+2*18] = 11 ;    lines[1+2*18] =  7 ;
    lines[0+2*19] = 7  ;    lines[1+2*19] = 19 ;
    lines[0+2*20] = 10 ;    lines[1+2*20] =  6 ;
    lines[0+2*21] = 6  ;    lines[1+2*21] = 19 ;
    lines[0+2*22] = 19 ;    lines[1+2*22] =  17;
    lines[0+2*23] = 18 ;    lines[1+2*23] =  5 ;
    lines[0+2*24] = 5  ;    lines[1+2*24] = 9  ;
    lines[0+2*25] = 5  ;    lines[1+2*25] = 15 ;
    lines[0+2*26] = 15 ;    lines[1+2*26] =  7 ;
    lines[0+2*27] = 15 ;    lines[1+2*27] =  14;
    lines[0+2*28] = 14 ;    lines[1+2*28] =  4 ;
    lines[0+2*29] = 14 ;    lines[1+2*29] = 6  ;

    // unsigned short *faces = malloc(sizeof(unsigned short)*(*numFaces)*3);

    *po = points;
    *li = lines;
    // *fa = faces;
}



int main(){
    // calculating the dodecahedron points
    long double *po;
    unsigned int numPoints;
    unsigned short *li;
    unsigned int numLines;
    _generate_dodecahedron(&po, &numPoints, &li, &numLines);
    for(int i = 0; i < 20; i++){
        printf("%Lf, %Lf, %Lf\n", po[i*3+0], po[i*3+1], po[i*3+2]);
    }
    // for(long double k = 0.553574; k < 0.553575; k+= .0000001){
        long double k = 0.553574 + M_PI;
        printf("+++++++++++++++++++\n");
        printf("+: %Lf\n",k);
        printf("+++++++++++++++++++\n");
        for(int i = 0; i < 20; i++){
            long double xydist = sqrt(pow(po[i*3+0], 2) + pow(po[i*3+1], 2));
            long double angle = atan2(po[i*3+1], po[i*3+0]) + k;
            long double newX = cos(angle) * xydist;
            long double newY = sin(angle) * xydist;
            printf("%Lf, %Lf, %Lf\n", newX, newY, po[i*3+2]);
        }
    // }
    return 0;
}
