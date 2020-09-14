#include"public.h"
#include"admin.h"
#include"lgfunc.h"


/*****************************************
admin.c
COPYRIGHT:	weijingmin
FUNCTION:	admin_login
ABSTRACT:
		A.login for admin
		B.button lightning and recovering
DATE:2019/9/8
******************************************/


void admin_login(int *func)	//����Ա��¼����
{
	int state = 0;
	char A[15] = { '\0' };	//����Ա�˺�
	char P[10] = { '\0' };	//����Ա����
	int state1 = 0;
	int state2 = 0;
	clrmous(MouseX, MouseY);
	delay(100);
	cleardevice();

	drawadmin();

	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if (MouseX > 230 && MouseX < 230 + 380 && MouseY > 120 + 30 && 120 + 60)
		{
			if (mouse_press(230, 120 + 30, 230 + 380, 120 + 60) == 2)//����Ա��δ���
			{
				MouseS = 2;
				if (state == 0 && state1 == 0)//��ֹ���ظ�����
				{
					lightbutton_admin(230, 120 + 30, 230 + 380, 120 + 60, WHITE, DARKGRAY, 1);//color1Ϊ�߿�ɫ��color2Ϊ���ɫ
					state = 1;
				}
				continue;

				//��������
			}
			else if (mouse_press(230, 120 + 30, 230 + 380, 120 + 60) == 1)//����Ա����
			{
				MouseS = 0;
				lightbutton_admin(230, 120 + 30, 230 + 380, 120 + 60, WHITE, DARKGRAY, 1);
				A[0] = '\0';
				inputadmin(A, 230, 120 + 30, 12, DARKGRAY);
				//���뺯��
				if(strlen(A) != 0)
					state1 = 1;
				else 
					state1 = 0;
				continue;
			}
		}
		if (MouseX > 230 && MouseX < 230 + 380 && MouseY>240 + 30 && 240 + 60)
		{
			if (mouse_press(230, 240 + 30, 230 + 380, 240 + 60) == 2)//�����δ���
			{
				MouseS = 2;
				if (state == 0 && state2 == 0)
				{
					lightbutton_admin(230, 240 + 30, 230 + 380, 240 + 60, WHITE, DARKGRAY, 2);//��������
					state = 2;
				}
				continue;
			}
			else if (mouse_press(230, 240 + 30, 230 + 380, 240 + 60) == 1)//�������
			{
				MouseS = 0;
				lightbutton_admin(230, 240 + 30, 230 + 380, 240 + 60, WHITE, DARKGRAY, 2);
				P[0] = '\0';
				inputpassword(P, 230, 240 + 30, 8, DARKGRAY);
				if(strlen(P) != 0)
					state2 = 1;
				else 
					state2 = 0;
				continue;
				//���뺯��
			}
		}
		if (MouseX > 200 + 220 - 120 && MouseX < 200 + 220 - 50 && MouseY>360 + 30 && 360 + 30 + 35)
		{
			if (mouse_press(200 + 220 - 120, 360 + 30, 200 + 220 - 50, 360 + 30 + 35) == 2)//��¼��δ���
			{
				MouseS = 1;
				if (state == 0)
				{
					lightbutton_admin(200 + 220 - 120, 360 + 30, 200 + 220 - 50, 360 + 30 + 35, WHITE, RED, 3);//��������
					state = 3;
				}
				continue;
			}
			else if (mouse_press(200 + 220 - 120, 360 + 30, 200 + 220 - 50, 360 + 30 + 35) == 1)//��¼����
			{
				MouseS = 0;
				if (admin_judge(A, P))
				{
					//admin_control();
				}
				else
				{
					continue;
				}
				continue;
				//����Ƿ���¼�����ݿ�Ĺ���Ա������

			}
		}
		if (MouseX > 200 + 220 + 50 && MouseX < 200 + 220 + 120 && MouseY>360 + 30 && 360 + 30 + 35)
		{
			if (mouse_press(200 + 220 + 50, 360 + 30, 200 + 220 + 120, 360 + 30 + 35) == 2)//���ؿ�δ���
			{
				MouseS = 1;
				if (state == 0)
				{
					lightbutton_admin(200 + 220 + 50, 360 + 30, 200 + 220 + 120, 360 + 30 + 35, WHITE, BLUE, 4);//��������
					state = 4;
				}
				continue;
			}
			else if (mouse_press(200 + 220 + 50, 360 + 30, 200 + 220 + 120, 360 + 30 + 35) == 1)//���ؿ���
			{
				MouseS = 0;
				*func = 0;
				return;
				//�л�����ʼ������
			}
		}
		if (state != 0)
		{
			MouseS = 0;
			if (state1 == 0)
			{
				recoverbutton_admin(1);//�ָ���ť��ɫ
			}
			if (state2 == 0)
			{
				recoverbutton_admin(2);
			}
			if (state == 3 || state == 4 || state == 5)
			{
				recoverbutton_admin(state);
			}
			state = 0;
		}
		if (MouseS != 0)
		{
			MouseS = 0;
		}
	}
}


void lightbutton_admin(int x, int y, int x1, int y1, int color1, int color2, int flag)
{
	clrmous(MouseX, MouseY);
	delay(10);
	setcolor(color1);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	setfillstyle(1, color2);
	bar(x, y, x1, y1);
	rectangle(x, y, x1, y1);	//���߿�
	switch (flag)
	{
	case 1:
		break;
	case 2:
		break;
	case 3:
		puthz(420 - 110, 360 + 35, "��¼", 24, 28, LIGHTRED);
		break;
	case 4:
		puthz(420 + 60, 360 + 35, "����", 24, 28, LIGHTBLUE);
		break;
	default:
		closegraph();
		printf("something runs wrong in lightbutton");
		exit(1);
	}
}


void recoverbutton_admin(int status)
{
	clrmous(MouseX, MouseY);
	if (status == 1 || status == 2)
	{
		setfillstyle(SOLID_FILL, LIGHTGRAY);
		setlinestyle(SOLID_LINE, 0, 1);
	}
	else if (status == 3)
	{
		setfillstyle(SOLID_FILL, RED);
	}
	else if (status == 4)
	{
		setfillstyle(SOLID_FILL, BLUE);
	}
	switch (status)
	{
	case 1:
		bar(230, 120 + 30, 230 + 380, 120 + 60);
		puthz(230 + 15, 120 + 38, "���������Ա�˺�", 16, 20, WHITE);
		break;
	case 2:
		bar(230, 240 + 30, 230 + 380, 240 + 60);
		puthz(230 + 15, 240 + 38, "����������", 16, 20, WHITE);
		break;
	case 3:
		bar(200 + 220 - 120, 360 + 30, 200 + 220 - 50, 360 + 30 + 35);
		puthz(420 - 110, 360 + 35, "��¼", 24, 28, WHITE);
		break;
	case 4:
		bar(200 + 220 + 50, 360 + 30, 200 + 220 + 120, 360 + 30 + 35);
		puthz(420 + 60, 360 + 35, "����", 24, 28, WHITE);
		break;
	}
}

void drawadmin(void)
{
	setbkcolor(BLACK);
	setfillstyle(SOLID_FILL, LIGHTGRAY);
	setcolor(LIGHTGRAY);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
	settextjustify(LEFT_TEXT, CENTER_TEXT);

	bar(230, 120 + 30, 230 + 380, 120 + 60);
	outtextxy(230, 120 + 15, "admin");
	puthz(230 + 15, 120 + 38, "���������Ա�˺�", 16, 20, WHITE);

	bar(230, 240 + 30, 230 + 380, 240 + 60);
	outtextxy(230, 240 + 15, "password");
	puthz(230 + 15, 240 + 38, "����������", 16, 20, WHITE);

	setfillstyle(SOLID_FILL, RED);
	bar(200 + 220 - 120, 360 + 30, 200 + 220 - 50, 360 + 30 + 35);
	puthz(420 - 110, 360 + 35, "��¼", 24, 28, WHITE);

	setfillstyle(SOLID_FILL, BLUE);
	bar(200 + 220 + 50, 360 + 30, 200 + 220 + 120, 360 + 30 + 35);
	puthz(420 + 60, 360 + 35, "����", 24, 28, WHITE);

	setfillstyle(SOLID_FILL, RED);
	setlinestyle(SOLID_LINE, 0, 3);
	setcolor(RED);
	line(200, 0, 200, 480);

	line(100, 50, 30, 280);
	line(100, 50, 200 - 30, 280);
	line(100, 100, 100 - 21, 100 + 70);
	line(100, 100, 100 + 21, 100 + 70);
	line(100 - 21, 100 + 70, 100 + 21, 100 + 70);
	line(100 - 66 + 37, 200, 100 + 66 - 37, 200);
	line(100 - 66 + 37, 200, 55, 260);
	line(100 + 66 - 37, 200, 145, 260);
	line(55, 260, 70, 260);
	line(145, 260, 130, 260);
	line(70, 260, 30, 280);
	line(130, 260, 170, 280);
	floodfill(100, 70, RED);
	puthz(100 - 24, 260, "��", 48, 0, RED);

	setlinestyle(SOLID_LINE, 0, 1);
	setcolor(RED);
	setfillstyle(1, RED);
	fillellipse(420, 45, 25, 25);
	setfillstyle(1, WHITE);
	pieslice(420, 45, 230, 310, 25);
	fillellipse(420, 45 - 5, 12, 12);
	setcolor(WHITE);
	circle(420, 45 - 5, 12);		//����¼С��
}