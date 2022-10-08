#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:4996)


#include"Snake.h"

using namespace std;

bool SnakeProcess;
int SnakeScore;



void area1() {//开始界面的函数
	setbkmode(TRANSPARENT);
	setfillcolor(WHITE);//设置背景颜色
	solidrectangle(0, 0, 500, 570);
	settextcolor(GREEN);//设置字体颜色
	settextstyle(50, 0, L"楷体");//设置字体样式;
	outtextxy(110, 100, L"贪吃蛇游戏");//输出字体
	settextcolor(BLACK);
	settextstyle(30, 0, L"楷体");
	outtextxy(200, 200, L"START");
	settextstyle(20, 0, L"楷体");
	outtextxy(150, 230, L"(按任意键进入下一步)");
	settextcolor(LIGHTGRAY);
	outtextxy(150, 250, L"←代表左   →代表右");
	outtextxy(150, 270, L"↑代表上   ↓代表下");
	FlushBatchDraw();//输出绘图
	_getch();//停止，等待操作
	system("pause");
	//while (GetKeyState(VK_RETURN) > 0);//回车判断
}

void area2() {//游戏界面的函数
	SnakeProcess = true;
	int s[52][52];
	SnakeScore = 3;//蛇的长度
	int way = 1;//蛇的方向
	int x = 25, y = 25;//蛇的初始位置
	srand(int(time(0)));
	int rx = 1 + rand() % 49;//食物的横坐标
	int ry = 1 + rand() % 49;//食物的纵坐标
	for (int i = 1; i <= 50; i++)
		for (int j = 1; j <= 50; j++)
			s[i][j] = 0;//空地的值为0
	while (s[rx][ry] != 0) {
		rx = 1 + rand() % 49;
		ry = 1 + rand() % 49;
	}
	s[rx][ry] = -1;//食物的值为-1
	while (1) {//主循环开头
		Sleep(80);
		setfillcolor(WHITE);//设置背景颜色
		solidrectangle(0, 0, 500, 500);
		if (GetAsyncKeyState(VK_LEFT) < 0 && way != 2)//a,向左，同时确保不反向自杀
			way = 1;
		if (GetAsyncKeyState(VK_RIGHT) < 0 && way != 1)//d,向右，同时确保不反向自杀
			way = 2;
		if (GetAsyncKeyState(VK_DOWN) < 0 && way != 4)//s,向下，同时确保不反向自杀
			way = 3;
		if (GetAsyncKeyState(VK_UP) < 0 && way != 3)//w,向上，同时确保不反向自杀
			way = 4;
		if (way == 1)x--;
		if (way == 2)x++;
		if (way == 3)y++;
		if (way == 4)y--;
		if (x <= 0 || x > 50 || y <= 0 || y > 50 || s[x][y] > 0)//撞墙或自食则游戏结束
		{
			SnakeProcess = false;
		}
		if (SnakeProcess == false)
		{
			break;
		}

		s[x][y] = SnakeScore;//蛇的值为正数
		for (int i = 1; i <= 50; i++) {
			for (int j = 1; j <= 50; j++) {
				if (s[i][j] > 0) {
					s[i][j]--;
					setfillcolor(GREEN);//设置当前颜色为绿色(蛇)
					solidrectangle((i - 1) * 10, (j - 1) * 10, i * 10, j * 10);//形成无边框矩形
				}
				if (s[i][j] == -1) {
					setfillcolor(RED);//设置当前颜色为红色(食物)
					solidrectangle((i - 1) * 10, (j - 1) * 10, i * 10, j * 10);//形成无边框矩形
				}
				if (x == rx && y == ry) {//蛇吃到食物
					SnakeScore++;
					while (s[rx][ry] != 0) {
						rx = 1 + rand() % 49;
						ry = 1 + rand() % 49;
					}//while
					s[rx][ry] = -1;
				}//if
			}//for
		}//for
		FlushBatchDraw();//输出绘图
	}//主循环结尾
	cin.sync();//清空缓存区

}

void area3() {//死亡界面的函数
	setbkmode(TRANSPARENT);
	setfillcolor(WHITE);//设置背景颜色
	solidrectangle(0, 0, 500, 500);
	settextcolor(BLACK);//设置字体颜色
	settextstyle(50, 0, L"楷体");//设置字体样式;
	outtextxy(120, 200, L"有待提高！");//输出字体
	settextstyle(20, 0, L"楷体");
	outtextxy(150, 270, L"(3秒后自动关闭)");
	FlushBatchDraw();//输出绘图
	Sleep(3000);//单位以毫秒计算
	_getch();
	closegraph();
}

int main() {

	initgraph(500, 570);//初始一个图形区域（宽500，长500）
	BeginBatchDraw();//开始绘图
	area1();//开始界面
	area2();//游戏界面
	area3();//死亡界面
	return 0;
}
