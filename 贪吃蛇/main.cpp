#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:4996)


#include"Snake.h"

using namespace std;

bool SnakeProcess;
int SnakeScore;



void area1() {//��ʼ����ĺ���
	setbkmode(TRANSPARENT);
	setfillcolor(WHITE);//���ñ�����ɫ
	solidrectangle(0, 0, 500, 570);
	settextcolor(GREEN);//����������ɫ
	settextstyle(50, 0, L"����");//����������ʽ;
	outtextxy(110, 100, L"̰������Ϸ");//�������
	settextcolor(BLACK);
	settextstyle(30, 0, L"����");
	outtextxy(200, 200, L"START");
	settextstyle(20, 0, L"����");
	outtextxy(150, 230, L"(�������������һ��)");
	settextcolor(LIGHTGRAY);
	outtextxy(150, 250, L"��������   ��������");
	outtextxy(150, 270, L"��������   ��������");
	FlushBatchDraw();//�����ͼ
	_getch();//ֹͣ���ȴ�����
	system("pause");
	//while (GetKeyState(VK_RETURN) > 0);//�س��ж�
}

void area2() {//��Ϸ����ĺ���
	SnakeProcess = true;
	int s[52][52];
	SnakeScore = 3;//�ߵĳ���
	int way = 1;//�ߵķ���
	int x = 25, y = 25;//�ߵĳ�ʼλ��
	srand(int(time(0)));
	int rx = 1 + rand() % 49;//ʳ��ĺ�����
	int ry = 1 + rand() % 49;//ʳ���������
	for (int i = 1; i <= 50; i++)
		for (int j = 1; j <= 50; j++)
			s[i][j] = 0;//�յص�ֵΪ0
	while (s[rx][ry] != 0) {
		rx = 1 + rand() % 49;
		ry = 1 + rand() % 49;
	}
	s[rx][ry] = -1;//ʳ���ֵΪ-1
	while (1) {//��ѭ����ͷ
		Sleep(80);
		setfillcolor(WHITE);//���ñ�����ɫ
		solidrectangle(0, 0, 500, 500);
		if (GetAsyncKeyState(VK_LEFT) < 0 && way != 2)//a,����ͬʱȷ����������ɱ
			way = 1;
		if (GetAsyncKeyState(VK_RIGHT) < 0 && way != 1)//d,���ң�ͬʱȷ����������ɱ
			way = 2;
		if (GetAsyncKeyState(VK_DOWN) < 0 && way != 4)//s,���£�ͬʱȷ����������ɱ
			way = 3;
		if (GetAsyncKeyState(VK_UP) < 0 && way != 3)//w,���ϣ�ͬʱȷ����������ɱ
			way = 4;
		if (way == 1)x--;
		if (way == 2)x++;
		if (way == 3)y++;
		if (way == 4)y--;
		if (x <= 0 || x > 50 || y <= 0 || y > 50 || s[x][y] > 0)//ײǽ����ʳ����Ϸ����
		{
			SnakeProcess = false;
		}
		if (SnakeProcess == false)
		{
			break;
		}

		s[x][y] = SnakeScore;//�ߵ�ֵΪ����
		for (int i = 1; i <= 50; i++) {
			for (int j = 1; j <= 50; j++) {
				if (s[i][j] > 0) {
					s[i][j]--;
					setfillcolor(GREEN);//���õ�ǰ��ɫΪ��ɫ(��)
					solidrectangle((i - 1) * 10, (j - 1) * 10, i * 10, j * 10);//�γ��ޱ߿����
				}
				if (s[i][j] == -1) {
					setfillcolor(RED);//���õ�ǰ��ɫΪ��ɫ(ʳ��)
					solidrectangle((i - 1) * 10, (j - 1) * 10, i * 10, j * 10);//�γ��ޱ߿����
				}
				if (x == rx && y == ry) {//�߳Ե�ʳ��
					SnakeScore++;
					while (s[rx][ry] != 0) {
						rx = 1 + rand() % 49;
						ry = 1 + rand() % 49;
					}//while
					s[rx][ry] = -1;
				}//if
			}//for
		}//for
		FlushBatchDraw();//�����ͼ
	}//��ѭ����β
	cin.sync();//��ջ�����

}

void area3() {//��������ĺ���
	setbkmode(TRANSPARENT);
	setfillcolor(WHITE);//���ñ�����ɫ
	solidrectangle(0, 0, 500, 500);
	settextcolor(BLACK);//����������ɫ
	settextstyle(50, 0, L"����");//����������ʽ;
	outtextxy(120, 200, L"�д���ߣ�");//�������
	settextstyle(20, 0, L"����");
	outtextxy(150, 270, L"(3����Զ��ر�)");
	FlushBatchDraw();//�����ͼ
	Sleep(3000);//��λ�Ժ������
	_getch();
	closegraph();
}

int main() {

	initgraph(500, 570);//��ʼһ��ͼ�����򣨿�500����500��
	BeginBatchDraw();//��ʼ��ͼ
	area1();//��ʼ����
	area2();//��Ϸ����
	area3();//��������
	return 0;
}
