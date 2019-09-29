/*
 * =====================================================================================
 * 
 *     Modulename:
 *       Filename:  theMoon.c
 *
 *    Description:  指针表盘
 *    Corporation:
 * 
 *         Author:  ensb1234,QQ470707134
 *        Created:  2019年09月15日 10时12分12秒
 *
 * =====================================================================================
 *
 * =====================================================================================
 * 
 *   MODIFICATION HISTORY :
 *    
 *		     DATE :
 *		     DESC :
 * =====================================================================================
 */	
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "maibu_res.h"
#include "maibu_sdk.h"

//static uint8_t minid=0,hourid=0;
//static uint8_t moonlid=0,moonrid=0;
static uint32_t winid=0;

#define BGXY	0
#define BGHW	176

#define CENXY	85
#define CENHW	7

#define MOONLX	63
#define MOONRX	88
#define MOONLRY	95
#define MOONH	50
#define MOONW	25

static const uint8_t pos[60][4][2] =
{
//近轴角1坐标,近轴角2坐标,时针尖角坐标,分针尖角坐标
//第0刻度:
{{84,88},{92,88},{88,49},{88,16}},
//第1刻度:
{{84,88},{92,88},{93,49},{97,17}},
//第2刻度:
{{84,87},{92,89},{98,50},{106,19}},
//第3刻度:
{{84,87},{92,89},{103,51},{114,22}},
//第4刻度:
{{84,86},{92,90},{107,53},{122,25}},
//第5刻度:
{{84,86},{92,90},{110,55},{128,28}},
//第6刻度:
{{85,85},{91,91},{113,57},{133,32}},
//第7刻度:
{{85,85},{91,91},{115,59},{137,35}},
//第8刻度:
{{85,85},{91,91},{117,61},{141,39}},
//第9刻度:
{{85,85},{91,91},{119,63},{144,43}},
//第10刻度:
{{86,84},{90,92},{121,66},{148,48}},
//第11刻度:
{{86,84},{90,92},{123,69},{151,54}},
//第12刻度:
{{87,84},{89,92},{125,73},{154,62}},
//第13刻度:
{{87,84},{89,92},{126,78},{157,70}},
//第14刻度:
{{88,84},{88,92},{127,83},{159,79}},
//第15刻度:
{{88,84},{88,92},{127,88},{160,88}},
//第16刻度:
{{88,84},{88,92},{127,93},{159,97}},
//第17刻度:
{{89,84},{87,92},{126,98},{157,106}},
//第18刻度:
{{89,84},{87,92},{125,103},{154,114}},
//第19刻度:
{{90,84},{86,92},{123,107},{151,122}},
//第20刻度:
{{90,84},{86,92},{121,110},{148,128}},
//第21刻度:
{{91,85},{85,91},{119,113},{144,133}},
//第22刻度:
{{91,85},{85,91},{117,115},{141,137}},
//第23刻度:
{{91,85},{85,91},{115,117},{137,141}},
//第24刻度:
{{91,85},{85,91},{113,119},{133,144}},
//第25刻度:
{{92,86},{84,90},{110,121},{128,148}},
//第26刻度:
{{92,86},{84,90},{107,123},{122,151}},
//第27刻度:
{{92,87},{84,89},{103,125},{114,154}},
//第28刻度:
{{92,87},{84,89},{98,126},{106,157}},
//第29刻度:
{{84,88},{92,88},{93,127},{97,159}},
//第30刻度:
{{84,88},{92,88},{88,127},{88,160}},
//第31刻度:
{{84,88},{92,88},{83,127},{79,159}},
//第32刻度:
{{84,87},{92,89},{78,126},{70,157}},
//第33刻度:
{{84,87},{92,89},{73,125},{62,154}},
//第34刻度:
{{84,86},{92,90},{69,123},{54,151}},
//第35刻度:
{{84,86},{92,90},{66,121},{48,148}},
//第36刻度:
{{85,85},{91,91},{63,119},{43,144}},
//第37刻度:
{{85,85},{91,91},{61,117},{39,141}},
//第38刻度:
{{85,85},{91,91},{59,115},{35,137}},
//第39刻度:
{{85,85},{91,91},{57,113},{32,133}},
//第40刻度:
{{86,84},{90,92},{55,110},{28,128}},
//第41刻度:
{{86,84},{90,92},{53,107},{25,122}},
//第42刻度:
{{87,84},{89,92},{51,103},{22,114}},
//第43刻度:
{{87,84},{89,92},{50,98},{19,106}},
//第44刻度:
{{88,84},{88,92},{49,93},{17,97}},
//第45刻度:
{{88,84},{88,92},{49,88},{16,88}},
//第46刻度:
{{88,84},{88,92},{49,83},{17,79}},
//第47刻度:
{{89,84},{87,92},{50,78},{19,70}},
//第48刻度:
{{89,84},{87,92},{51,73},{22,62}},
//第49刻度:
{{90,84},{86,92},{53,69},{25,54}},
//第50刻度:
{{90,84},{86,92},{55,66},{28,48}},
//第51刻度:
{{91,85},{85,91},{57,63},{32,43}},
//第52刻度:
{{91,85},{85,91},{59,61},{35,39}},
//第53刻度:
{{91,85},{85,91},{61,59},{39,35}},
//第54刻度:
{{91,85},{85,91},{63,57},{43,32}},
//第55刻度:
{{92,86},{84,90},{66,55},{48,28}},
//第56刻度:
{{92,86},{84,90},{69,53},{54,25}},
//第57刻度:
{{92,87},{84,89},{73,51},{62,22}},
//第58刻度:
{{92,87},{84,89},{78,50},{70,19}},
//第59刻度:
{{84,88},{92,88},{83,49},{79,17}}
};

static const uint16_t moonArr[30][2] = {
{MOON_1L,MOON_1R},{MOON_1L,MOON_2R},{MOON_1L,MOON_3R},{MOON_1L,MOON_4R},{MOON_1L,MOON_5R},{MOON_1L,MOON_6R},
{MOON_1L,MOON_15R},{MOON_1L,MOON_15R},{MOON_9L,MOON_15R},{MOON_10L,MOON_15R},{MOON_11L,MOON_15R},{MOON_12L,MOON_15R},
{MOON_13L,MOON_15R},{MOON_14L,MOON_15R},{MOON_15L,MOON_15R},{MOON_15L,MOON_15R},{MOON_15L,MOON_17R},{MOON_15L,MOON_18R},
{MOON_15L,MOON_19R},{MOON_15L,MOON_20R},{MOON_15L,MOON_21R},{MOON_15L,MOON_1R},{MOON_15L,MOON_1R},{MOON_24L,MOON_1R},
{MOON_25L,MOON_1R},{MOON_26L,MOON_1R},{MOON_27L,MOON_1R},{MOON_28L,MOON_1R},{MOON_29L,MOON_1R},{MOON_30L,MOON_1R}
};

static const uint16_t lunarArr[81]={
6442,//2019,以下每行十年。0位代表闰年，1闰0平；后12-13位是每月大小月数据，从小到大从右往左排。
10845,2732,5482,11109,3492,7499,3658,3222,6447,6486,
2740,5549,5842,11941,5796,5706,13463,5270,2390,2743,
2906,5844,13989,6948,14923,6730,5290,10587,2412,2922,
6997,7570,15653,7460,6732,5293,5294,2476,3499,3754,
3722,7463,3366,10839,2646,5302,10933,2772,5834,11925,
5780,13611,5418,2650,5467,5482,2900,5963,6986,6804,
14635,6444,12957,2732,5482,11109,3492,7498,7317,3350,
6447,2390,2742,5549,5844,3748,11851,5770,5398,10551
};
static const uint16_t monthSum[12] = {0,31,59,90,120,151,181,212,243,273,304,334};
static uint8_t moonPhase=31;

uint8_t toLunar(uint16_t y,uint8_t m,uint8_t d){
	uint16_t tmp=0;
	if(y%4==0 && m<3 && d<30){
		tmp=1;
	}
	unsigned int days=(y-2019)*365+(int)((y-2016)/4)+monthSum[m-1]+d-35-tmp;
	uint8_t subEnd=0;
	uint8_t ly=0;
	uint8_t i,dperm,mpery;
	while(subEnd==0){
		tmp=lunarArr[ly];
		mpery=(tmp%2)+12;
		tmp=tmp/2;
		for(i=1;i<=mpery;i++){
			dperm=(tmp%2)+29;
			if(days<=dperm){
				subEnd=1;
				break;
			}else{
				days=days-dperm;
				tmp=tmp/2;
			}
		}
		ly++;
	}
	return days;
}

//拿位图并返回位图图层
P_Layer getBmpLayer(GRect *rt ,uint16_t key){
	GBitmap bm;
	res_get_user_bitmap(key,&bm);
	LayerBitmap lbl={bm,*rt,GAlignLeft};
	P_Layer lr=app_layer_create_bitmap(&lbl);
	return lr;
}

//画指针并返回多边形图层，参数：刻度，tip（分针3时针2）
P_Layer getZhenLayer(uint8_t kedu,uint8_t tip){
	GPoint p0={pos[kedu][0][0],pos[kedu][0][1]},p1={pos[kedu][1][0],pos[kedu][1][1]},pj={pos[kedu][tip][0],pos[kedu][tip][1]};
	GPoint ps[3]={p0,p1,pj};
	Polygon poly={3,ps};
	Geometry geo={GeometryTypePolygon, FillArea, GColorWhite, (void*)&poly};
	P_Geometry pg[1];
	LayerGeometry lg;
	memset(&lg,0,sizeof(LayerGeometry));
	pg[lg.num++]=&geo;
	lg.p_g=pg;
	
	P_Layer lr=app_layer_create_geometry(&lg);
	return lr;
}

P_Window initWin(void);

//重新载入并刷新窗口所有图层
void winReloading(void)
{
	/*根据窗口ID获取窗口句柄*/
	P_Window oldwin = app_window_stack_get_window_by_id(winid); //获取旧窗口
	if (NULL != oldwin)
	{
		P_Window newwin = initWin();//重新画新窗口，下面就把旧的取代。
		if (NULL != newwin)
		{
			winid = app_window_stack_replace_window(oldwin, newwin);
		}	
	}
	
}

void timeChange(enum SysEventType type, void *context)
{
	/*时间更改*/
	if (type == SysEventTypeTimeChange)
	{
		winReloading();	
	}
}

P_Window initWin(void){
	P_Window win=app_window_create();
	if(NULL==win){
		return NULL;
	}
	P_Layer thebg,ct,hz,mz,moonl,moonr;
	struct date_time dt;
	app_service_get_datetime(&dt);
	GRect grt={ {BGXY,BGXY},{BGHW,BGHW} };
	thebg=getBmpLayer(&grt,BG);
	hz=getZhenLayer(dt.hour%12*5+dt.min/12,2);
	mz=getZhenLayer(dt.min,3);
	grt.origin.x=CENXY;
	grt.origin.y=CENXY;
	grt.size.h=CENHW;
	grt.size.w=CENHW;
	ct=getBmpLayer(&grt,CENTER);
	
	if(moonPhase==31 || (dt.hour==7&&dt.min==0)){
		moonPhase=toLunar(dt.year,dt.mon,dt.mday);
	}
	grt.origin.x=MOONLX;
	grt.origin.y=MOONLRY;
	grt.size.h=MOONH;
	grt.size.w=MOONW;
	moonl=getBmpLayer(&grt,moonArr[moonPhase-1][0]);	
	grt.origin.x=MOONRX;
	moonr=getBmpLayer(&grt,moonArr[moonPhase-1][1]);
	
	app_window_add_layer(win,thebg);
	app_window_add_layer(win,moonl);
	app_window_add_layer(win,moonr);
	app_window_add_layer(win,hz);
	app_window_add_layer(win,mz);
	app_window_add_layer(win,ct);
	
	maibu_service_sys_event_subscribe(timeChange);
	return win;
}

int main()
{
	
	P_Window win = initWin();
	winid = app_window_stack_push(win);//然后把这个窗口显示出去，并把这个窗口的id获取出来。


	return 0;
}


















