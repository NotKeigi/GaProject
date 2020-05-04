#ifndef DAY_SYCLE_H
#define DAY_SYCLE_H

/************************************************************/
//型定義
/************************************************************/
FILE *fp;
FILE *fp_sougou;


//人口を10才ごとに区切り、人口、死亡率の順なお、八十歳以上はひとまとめとする
//年齢別の人口
//https://www.pref.kagawa.lg.jp/content/etc/subsite/toukei/jinko/30jinkoido.shtml
//第八表、年齢（5歳階級）別、転入前住所地・転出後住所地別、男女別県外移動者数（県計）（平成29年10月～平成30年9月）より計算

//年齢別の死亡率
//https://toyokeizai.net/sp/visual/tko/covid19/
//厚労省の報道資料より東洋経済編集部計算したデータを利用
struct people_date {
    long peoples; //人口
    float sibouritu; //死亡率
    long day_kansensya; //直近二週間の感染者（この数だけ感染拡大の可能性が試行される)
};

/************************************************************/
//プロトタイプ宣言
/************************************************************/
int ransuu (double wariai); //0 or 1を返す、どちらが返されるかの確率についてはwariaiで決まる
void history(int huetakazu,int utusaretasedai);//感染者が何日前に感染したのか、などを管理する
void syokuba_claster();//一定の確率に応じて職場でクラスターを発生させる。
void haigusya(int haigusya_sedai);//一定の確率に応じて配偶者に感染させる。配偶者の世代については引数で管理する
int output ();//アウトプット、ファイル出力
void humei (int sedai);//確率に応じて世代に感染者を発生させる、確率に関しては0.01 * 感染者数合計で計算する
int day_sycle();//呼び出されると180日分のシュミレーションをする。戻り値として感染者数合計を渡す。
void histry_kanri();//直近二週間の感染者の配列の管理

//////
#endif