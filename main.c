#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "main.h"
#include "ga.h"
#include "day_sycle.h"


int main ()
{
    srand((unsigned int)time(NULL));

    fp = fopen("output.txt","w");
    fp_sougou = fopen("output_.txt","w");


    if(fp == NULL){
        printf("ファイルのオープンに失敗しました\n");
        exit(1);
    }
    if(fp_sougou == NULL){
        printf("ファイルのオープンに失敗しました\n");
        exit(1);
    }   
    ga();
    fclose(fp);
    fclose(fp_sougou);
    return 0;
}
