#ifndef DAY_SYCLE_C
#define DAY_SYCLE_C

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "day_sycle.h"
#include "ga.h"

static int kansensya_counter[9] = {0,0,0,0,0,0,0,0,0}; //
static int day_counter = 0; //
static int kansensya_history[9][14];
static int kansensya_history_count = 0; //
static int i;
static int counter;
static int histry_flag = 0; //
static int histry_sedai;
static int sougou_kansensya = 0; //

struct people_date people[9] = {
    {77724,0.00000,0},//一才以上十才未満
    {89429,0.00000,0},//十才以上二十才未満
    {77618,0.00107,0},//二十才以上三十才未満
    {106621,0.00197,0},//三十才以上四十才未満
    {133826,0.00197,0},//四十才以上五十才未満
    {111224,0.00523,0},//五十才以上六十才未満
    {152592,0.01838,0},//六十才以上七十才未満
    {107870,0.06575,0},//七十才以上八十才未満
    {95468,0.15286,0}//八十才以上
};

int day_sycle (){
    people[3].day_kansensya = 5;
    while(day_counter != 180){
        for(i=0;i<9;i++){
                switch (i)
                {
                case 0:
                counter = 0;
                while(counter < people[i].day_kansensya){
                    if(ransuu(0.10)){
                        people[3].day_kansensya++;//親に感染
                        history(1,3);
                    }
                    counter++;
                }
                break;

                case 1:
                counter = 0;
                while(counter < people[i].day_kansensya){
                    if(ransuu(0.005)){
                        people[4].day_kansensya++;//親に感染
                        history(1,4);
                    }
                    if(ransuu(0.0001)){
                        people[1].day_kansensya += 5;//同世代の友達に感染
                        history(5,1);
                    }
                    counter++;
                }
                break;

                case 2:
                counter = 0;
                while(counter < people[i].day_kansensya){
                    if(ransuu(0.01)){
                        people[6].day_kansensya ++;//同居している親に感染
                        history(1,6);
                    }
                    if(ransuu(0.005)){
                        people[0].day_kansensya ++;//子供（小さい）に感染
                        history(1,0);
                    }
                    if(ransuu(0.005)){
                        people[2].day_kansensya ++;//同じ大学の人or職場の人に感染
                        history(1,2);
                    }
                    counter++;
                }
                break;

               case 3:
               counter = 0;
               while(counter < people[i].day_kansensya){
                   haigusya(3);//夫or妻に感染
                   syokuba_claster();//職場でクラスター
                   if(ransuu(0.01)){
                       people[1].day_kansensya ++;//子供に感染
                       history(1,1);
                       }
                       counter++;
                }
               break;

               case 4:
               counter = 0;
               while(counter < people[i].day_kansensya){
                   haigusya(4);
                   syokuba_claster();
                   if(ransuu(0.005)){
                       people[3].day_kansensya ++;//大きなお友だちに感染
                       history(1,3);
                       }
                       counter++;
               }
               break;

               case 5:
               counter = 0;
               while(counter < people[i].day_kansensya){
                   haigusya(5);
                   syokuba_claster();
                   counter++;
               }
               break;

               case 6:
               counter = 0;
               while(counter < people[i].day_kansensya){
                   haigusya(6);
                   syokuba_claster();
                   counter++;
               }
               break;

               case 7:
               counter = 0;
               while(counter < people[i].day_kansensya){
                   haigusya(7);
                   counter++;
               }
               break;

               case 8:
               counter = 0;
               while(counter < people[i].day_kansensya){
                   haigusya(8);
                   counter++;
               }
               break;

               default:
               printf("おかしなエラーだ。このメッセージは誰にも読まれないはずなのだが\n");
               break;
            }
        }
        for(i=0;i<9;i++){
            humei(i);
        }
        output();
        day_counter++;
        kansensya_history_count++;
        if(kansensya_history_count == 14){
            kansensya_history_count = 0;
            int history_flag = 1;
        }
        if(histry_flag){
            for(histry_sedai=0;histry_sedai<9;histry_sedai++){
                    people[histry_sedai].day_kansensya -= kansensya_history[histry_sedai][13];
                    //TODO配列をずらしてきちんとするように
            }
        }
        histry_kanri();
    }
    return sougou_kansensya;
}
int ransuu (double wariai){
    double num;
    num = (double)rand()/RAND_MAX;
    printf("%lf",wariai );
    if (num < wariai /* ga_kai[day_counter][ga_sedai] */){
        return 1;
    }else
    {
        return 0;
    };
}

void history (int huetakazu,int utusaretasedai){
    //kansensya_history[i][kansensya_history_count] ++;
    kansensya_history[utusaretasedai][kansensya_history_count] += huetakazu;
    kansensya_counter[utusaretasedai] += huetakazu;
    sougou_kansensya += huetakazu;
}

void syokuba_claster (){
    if(ransuu(0.005)){
        people[2].day_kansensya +=2;
        people[3].day_kansensya +=2;//職場でクラスター感染
        people[4].day_kansensya +=2;
        people[5].day_kansensya +=2;
        history(2,3);
        history(2,4);
        history(2,2);
        history(2,5);
    }
}

void haigusya (int haigusya_sedai){
    if(ransuu(0.01)){
        people[haigusya_sedai].day_kansensya ++;//夫or妻に感染
        history(1,haigusya_sedai);
    }
}

void humei(int sedai){
    if(ransuu(0.01 * (sougou_kansensya++))){
        people[sedai].day_kansensya += 1;
    }
}

int output (){
    int n;

    for(n=0;n<9;n++){
        fprintf(fp,"%d ",kansensya_counter[n]);
    }
    fprintf(fp,"%d\n",day_counter);
    fprintf(fp_sougou,"%d %d\n",sougou_kansensya,day_counter);

    return 0;
}
void histry_kanri (){
    int a;
    int b;
    for(a=0;a<9;a++){
        for(b=13;b!=0;b--){
            kansensya_history[a][b] = kansensya_history[a][b-1];
        }
    }
}

#endif