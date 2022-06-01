#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Account
{
	char name[100];
	char password[7];
	char idcard[19];
	char tel[12];
	char username[100];//���Ŵ���ѯ
	float money;
	struct Account *next;
};

typedef struct Account Account;
	Account *head=NULL;
	Account *tail=NULL;

void loadDate()//��������
{
	FILE *fp=fopen("E://name.txt","r");
	if(fp!=NULL)
	{
		while(!feof(fp))
		{
			Account *Node=(Account *)malloc(sizeof(Account));
			fscanf(fp,"%s %s %s\n",Node->name,Node->username,Node->password);
			Node->next=NULL;
			if(head==NULL)
			{
				head=Node;
				tail=Node;
			}
			else
			{
				tail->next=Node;
				tail=Node;
			}
		}
	printf("������ϣ�\n");
	fclose(fp);
	}
}
void printAccount(Account a)//��ӡ�˻���Ϣ
{
	printf("%s\t%s\t%s\n",a.name,a.username,a.password);
}
void printLinkedList()//��ӡ����
{
	Account *curp=head;
	while(curp!=NULL)
	{
		printAccount(*curp);
		curp=curp->next;
	}
}
void saveDate()//��������
{
	FILE *fp=fopen("E:/name.txt","w");
	if(fp!=NULL)
	{
		Account *curp=head;
		while(curp!=NULL)
		{
			fprintf(fp,"%s\t%s\t%s\n",curp->name,curp->username,curp->password);
			curp=curp->next;
		}
		fclose(fp);
	}
}

void signUp()//��¼
{
	Account a;
	printf("�����뿨�ţ�\n");
	scanf("%s",a.username);

	printf("���������룺\n");
	scanf("%s",a.password);
	
}

void creataccount()//�����˺�
{
	Account a;
	while(1)
	{
	printf("������������\n���֤�ţ�\n�绰���룺\n");
	scanf("%s %s %s",a.name,a.idcard,a.tel);
	printf("�������ʼ��\n");
	scanf("%f",&a.money);
	printf("���ڴ����˻������Ե�\n");
	//�������
	stand(time(0));
	int m=rand();
	a.username=m%1000+10000000;
	printf("�������Ŀ���\n");
	printf("%s",a.username);
	}
}

void signIn()
{
	Account a,b;
	int n;
	printf("�������˺ţ�\n");
	printf("���������룺\n");
	scanf("%s",a.password);
	printf("��������һ������:\n");
	scanf("%s",b.password);
	if(strcmp(a.password,a.password)==0)
	{
		printf("��ѡ��ҵ��\n");
		printf("=====================================\n");
		printf("1.���\t2.ת��\t3.��ѯ���\n");
		printf("4.�޸�����\t5.���ִ��\t6.�˿�\n");
		printf("=====================================\n");
		while(1)
		{
			printf("��������Ҫѡ�������\n");
			scanf("%d",&n);
			switch(n)
			{
			case 1:cunkuan();break;
			case 2:zhuanzhang();break;
			case 3:chaxun();break;
			case 4:xiugaimima();break;
			case 5:huizhidan();break;
			case 6:tuika();break;
			}
		}
	}

}

void showChinese()
{
	
	printf("����1�������˻�\n");
	printf("����2����¼\n");
	char c;
	
	scanf("%s",&c);
	if(c=='1')
	{
		signUp();
	}
	else if(c=='2')
	{
		signIn();
	}
}

void showEnglish()
{
	//do something...
}

int main()
{
	printf("����1��ѡ������\n");
	printf("Input 2��Show English\n");
	char c;
	scanf("%c",&c);
	if(c=='1')
	{
		showChinese();//��ʾ���Ĳ˵�
	}
	else if(c=='2')
	{
		showEnglish();//��ʾӢ�Ĳ˵�
	}

loadDate();
	return 0;
}
