#ifndef GA_C
#define GA_C

#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ga.h"
#include "day_sycle.h"

void ga(){
    int i;
    int n;
    for(n=0;n<20;n++){
        for(i=0;i<180;i++){
            ga_kai[i][n] = (double)rand() / RAND_MAX;
        }
    }
    for(i=0;i<20;i++){
        kai_point[i] = kai_hyoka(i);
        printf("%lf\n",kai_point[i]);
    }


}
double kai_hyoka (int kai_number){
    double point;
    ga_sedai = kai_number;
    int i;
    for(i=0;i<180;i++){
        point += ga_kai[i][kai_number];
    }
    point = point / (30000 - day_sycle());

    return point;
}
#endif