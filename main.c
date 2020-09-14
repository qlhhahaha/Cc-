#include"main.h"
#include"public.h"

/*****************************************
main.c
COPYRIGHT:	weijingmin
FUNCTION:	main
ABSTRACT:
		A.skip among interface
DATE:2019/9/9
******************************************/


/*********************************************
FUNCTION:main
DESCRIPTION��������
INPUT:void
RETURN:��
***********************************************/
void main(void)
{
	int func = 0;
	int gd = VGA;
	int gm = VGAHI;
	USER u;
	memset(&u,'\0',sizeof(USER));
	initgraph(&gd, &gm, "C:\\STOCK\\BGI");
	welcome_page();	//��ӭ����

	mouseinit();
	//freopen("Database//Debug.txt", "w", stdout); //debug
	while (1)
	{
		switch (func)
		{
			case 0:		//��ʼ��ѡ�����
			{
				initmenu_set(&func);    //��ı�func��ֵ����
				memset(&u,'\0',sizeof(USER));
				break;                  //Ҳ���ص�����ͳ�Ϊ�޵�¼״̬
			}
			case 1:		//�˳���ť
				delay(1000);
				closegraph();
				exit(1);
			case 2:		//�û���¼����
				user_login(&func,&u);
				break;
			case 3:		//�û�ע�����
				user_register(&func);
				break;
			case 4:		//�����������
				user_forgetpass(&func);
				break;
			case 5:		//����Ա��¼����
				admin_login(&func);
				break;
			case 6:		//���������غ���
				control_main(&func,&u);
				break;
		}
	}
}