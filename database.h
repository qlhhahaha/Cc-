#ifndef _DATA_H_
#define _DATA_H_
typedef struct userinfo
{
	char user[15];           //6-12λ���û���
	char ID[20];             //18λ�����֤
	char password[20];       //8-16λ������
	char bankcard[21];       //19λ�����п�
	char bankpassword[8];    //6λ,���п�����
	char balance[15];        //���п����
}USER;	//��װ�û���Ϣ

typedef struct admininfo
{
	char user[15];//6-12λ������Ա�˺�
	char password[10];//8λ����
}ADMIN;


typedef struct				  //ÿֻ��Ʊ�Ļ�����Ϣ
{
	char code[7];	//��Ʊ����
	char name[10];	//��Ʊ����
	char dat1[6];	//�Ƿ�
	char dat2[6];	//�ּ�
	char dat3[6];	//�ǵ�
	char dat4[6];	//���
	char dat5[6];	//����
	char dat6[8];	//����
	char dat7[6];	//����
	char dat8[6];	//����
	char dat9[6];	//����
	char dat10[6];	//��
}Stodata;

typedef struct stockday_char
{
	//����	    ����	    ���	    ���	    ����	    �ɽ���	    �ɽ���
	char date[12];//����
	char open[6];//����
	char high[6];//���
	char low[6];//���
	char close[6];//����
	char VOL[10];//�ɽ��� volume
	char VOT[15];//�ɽ��� volume of transaction
}STODAYCHAR;//ĳһ���Ʊ���ַ�����Ϣ


typedef struct stockday_float
{
	//����	    ����	    ���	    ���	    ����	    �ɽ���	    �ɽ���
	int Year;//��
	int Month;//��
	int Day;//��
	float Open;//����
	float High;//���
	float Low;//���
	float Close;//����
	float VOL;//�ɽ���
	float VOT;//�ɽ���
}STODAYFLOAT;//ĳһ���Ʊת�����������Ϣ


typedef struct techline_major
{
	float first[90];
	float second[90];
	float third[90];
	float forth[90];
}UPLINE;//������ͼ������


typedef struct techline_vice
{
	float first[90];
	float second[90];
	float third[90];
}DOWNLINE;//���鸱ͼ������


typedef struct priceinfo
{
	float Open[90];
	float Close[90];
	float High[90];
	float Low[90];
	float VOL[90];
}PRICEINFO;//���ĳһ֧90��۸���Ϣ�Ľṹ�壬��������

typedef struct fundamental
{
	char PE[7];//��ӯ�� price earning ratio
	char LEV[7];//�ʲ���ծ�� asset-liability ratio
	char PB[7];//�о��� price/book value ratio
	char NP[7];//�������� net profit rate
	char DE[7];//Ȩ��� debt-equity ratio
}FUND;//���ĳһ֧��Ʊ�Ļ�������Ϣ

typedef struct
{
	char sto_date[12];    //�ɽ�����
	char sto_code[7];     //֤ȯ����
	char sto_name[10];    //֤ȯ����
	char sto_flag[2];  	  //�������
	char sto_num[10];     //�ɽ�����
	char sto_price[7];    //�ɽ�����
	char sto_amount[20];  //�ɽ����
}Hstdata;//��ʷ�ɽ�


typedef struct
{
	char sto_date[11];       //�ֲ�����
	char sto_code[7];        //֤ȯ����
	char sto_name[10];       //֤ȯ����
	char sto_num[10];        //�ֹ���
	char sto_price[7];       //�ɱ���num
	char sto_day[4];         //�ֲ�����
}Hold;//�ֲ�
	

#endif