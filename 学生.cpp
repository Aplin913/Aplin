#include <iostream.h>
#include <iomanip.h>
#include <fstream.h>            //���ļ�������Ҫ���Ӱ����ļ���ͷ�ļ�
#include <string.h>
struct college{                 //ѧԺ�ṹ��
	int No;						//ѧԺ���
	char Name[21];				//ѧԺ����
	char deanName[11];          //Ժ������   
	struct college*next;
};
struct major{                   //רҵ�ṹ��
	int majorNo;                //רҵ���
	int collegeNo;              //רҵ����ѧԺ���
	char majorName[21];         //רҵ����
	struct major*next;
};
struct student{                 //ѧ���ṹ��
	int studNo;                 //ѧ��
	int majorNo;                //רҵ���
	char Name[11];              //ѧ������
	char sex[3];                //ѧ���Ա�
	char phoneNumber[12];       //ѧ����ϵ�绰
	struct student*next;
};
struct course{                  //�γ̽ṹ��
    int No;                     //�γ̱��
	char Name[11];				//�γ�����
	char Sort[5];				//�γ����ʣ����ޡ���ѡ����ѡ��
	double creditHour;			//ѧ��
	int Time;					//��ѧʱ
	int theoryTime;				//����ѧϰ
	int testTime;				//ʵ��ѧʱ
	struct course*next;
};
struct grade{
	int studentNo;				//ѧ��
	int courseNo;				//�γ̱��
	double Grade;				//�ɼ�
	struct grade*next;
};
struct optional{
	int studentNo;				//ѧ��
	int courseNo;				//�γ̱��
	struct optional*next;
};
college *menu1sr()
{
	college *p,*head;
	static college *q;
	int n;
	head=new college;
	head->next=NULL;
	q=head;
	cout<<":������ѧԺ���";
	cin>>n;
	while(n)
	{
		p=new college;
		if(p==NULL)
			cout<<"�ڴ治�㣬�������룡\n";
		else
		{
			p->No=n;
			cout<<"ѧԺ����\n";
			cin>>p->Name;
			cout<<"Ժ������\n";
			cin>>p->deanName;
			head->next=p;
			head=p;
		}
		cout<<":������ѧԺ���";
		cin>>n;
	}
	p->next=NULL;
	return q;

}
void menu1xs(college *q)
{
	college *p;
	p=q;
	while(p->next!=NULL)
	{
		cout<<"ѧԺ��ţ�"<<(p->next)->No<<endl;
		cout<<"ѧԺ���ƣ�"<<(p->next)->Name<<endl;
		cout<<"Ժ��������"<<(p->next)->deanName<<endl;
		p=p->next;
	}
	cout<<"�Ѿ������ϣ�\n";
}
void menu1cx(college *q)
{
	cout<<"��������Ҫ���ҵ�ѧԺ��ţ�\n";
	int n;
	college *p;
	p=q;
	cin>>n;
	while(p->next!=NULL)
	{
		if((p->next)->No==n)
		{
			cout<<"���Ҹ�ѧԺ��Ϣ����:\n";
			cout<<"ѧԺ��ţ�"<<(p->next)->No<<endl;
			cout<<"ѧԺ���ƣ�"<<(p->next)->Name<<endl;
			cout<<"Ժ��������"<<(p->next)->deanName<<endl;
			break;
		}
		else
			p=p->next;
	}
	if(p->next==NULL)
		cout<<"δ�ҵ��ó�Ա��\n";
}
void menu1sc(college *q,major *x)
{
	cout<<"��������Ҫɾ����ѧԺ��ţ�\n";
	int n;
	college *p;
	p=q;
	cin>>n;
	while(p->next!=NULL)
	{
		if((p->next)->No==n)
		{
			while(x->next!=NULL)
			{
				if((x->next)->collegeNo==n)
				{
					cout<<"��ѧԺ����ɾ����";
					break;
				}	
				else
					x=x->next;
					
			}
			if(x->next==NULL)
			{
				p->next=(p->next)->next;break;
			}
		}
		else
			p=p->next;
	}
	if(p->next==NULL)
		cout<<"δ�ҵ��ó�Ա��\n";
}
void menu1xg(college *q)
{
	cout<<"��������Ҫ�޸ĵ�ѧԺ��ţ�\n";
	int n;
	college *p;
	p=q;
	cin>>n;
	while(p->next!=NULL)
	{
		if((p->next)->No==n)
		{
			cout<<"ѧԺ���ƣ�\n";
			cin>>(p->next)->Name;
			cout<<"Ժ��������\n";
			cin>>(p->next)->deanName;
			break;
		}
		else
			p=p->next;
	}
	if(p->next==NULL)
		cout<<"δ�ҵ��ó�Ա��\n";
}
void menu1tj(college *q)
{
	college *p,*x;
	int n;
	x=q;
	while(x->next!=NULL)
		x=x->next;
	cout<<"������ѧԺ���:";
	cin>>n;
	while(n)
	{
		p=new college;
		if(p==NULL)
			cout<<"�ڴ治�㣬�������룡\n";
		else
		{
			p->No=n;
			cout<<"ѧԺ����:\n";
			cin>>p->Name;
			cout<<"Ժ������:\n";
			cin>>p->deanName;
			x->next=p;
			x=p;
		}
		cout<<":������ѧԺ���";
		cin>>n;
		p->next=NULL;
	}	
}
void menu1(college *p1,major *p2)
{
	int n=1;
	while(n)
	{
		cout<<"  ѧԺ��Ϣ����"<<endl;
		cout<<"----------------"<<endl;
		cout<<"1. ѧԺ��Ϣ����"<<endl;
		cout<<"2. ѧԺ��Ϣ���"<<endl;
		cout<<"3. ѧԺ��Ϣ��ʾ"<<endl;
		cout<<"4. ѧԺ��Ϣ��ѯ"<<endl;
		cout<<"5. ѧԺ��Ϣɾ��"<<endl;
		cout<<"6. ѧԺ��Ϣ�޸�"<<endl;
		cout<<"0. �˳�"<<endl;
		cout<<"----------------"<<endl;
		cin>>n;
		switch(n)
		{
			case 1:p1=menu1sr();break;
			case 2:menu1tj(p1);break;
			case 3:menu1xs(p1);break;
			case 4:menu1cx(p1);break;
			case 5:menu1sc(p1,p2);break;
			case 6:menu1xg(p1);break;
			case 0:break;
			default:cout<<"ѡ�����\n";break;
		}
	}
}
major *menu2sr()
{
	major *p,*head;
	static major *q;
	int n;
	head=new major;
	head->next=NULL;
	q=head;
	cout<<":������רҵ���";
	cin>>n;
	while(n)
	{
		p=new major;
		if(p==NULL)
			cout<<"�ڴ治�㣬�������룡\n";
		else
		{
			p->majorNo=n;
			cout<<"����ѧԺ���\n";
			cin>>p->collegeNo;
			cout<<"רҵ����\n";
			cin>>p->majorName;
			head->next=p;
			head=p;
		}
		cout<<":������רҵ���";
		cin>>n;
	}
	p->next=NULL;
	return q;

}
void menu2xs(major *q)
{
	major *p;
	p=q;
	while(p->next!=NULL)
	{
		cout<<"רҵ��ţ�"<<(p->next)->majorNo<<endl;
		cout<<"����ѧԺ��ţ�"<<(p->next)->collegeNo<<endl;
		cout<<"רҵ���ƣ�"<<(p->next)->majorName<<endl;
		p=p->next;
	}
	cout<<"�Ѿ������ϣ�\n";
}
void menu2cx(major *q)
{
	cout<<"��������Ҫ���ҵ�רҵ��ţ�\n";
	int n;
	major *p;
	p=q;
	cin>>n;
	while(p->next!=NULL)
	{
		if((p->next)->majorNo==n)
		{
			cout<<"���Ҹ�רҵ��Ϣ����:\n";
			cout<<"רҵ��ţ�"<<(p->next)->majorNo<<endl;
			cout<<"����ѧԺ��ţ�"<<(p->next)->collegeNo<<endl;
			cout<<"רҵ���ƣ�"<<(p->next)->majorName<<endl;
			break;
		}
		else
			p=p->next;
	}
	if(p->next==NULL)
		cout<<"δ�ҵ��ó�Ա��\n";
}
void menu2sc(major *q,student *p4)
{
	cout<<"��������Ҫɾ����רҵ��ţ�\n";
	int n;
	major *p;
	student *x;
	x=p4;
	p=q;
	cin>>n;
	while(p->next!=NULL)
	{
		if((p->next)->majorNo==n)
		{
			while(x->next!=NULL)
			{
				if((x->next)->majorNo==n)
				{
					cout<<"��רҵ����ɾ����";
					break;
				}	
				else
					x=x->next;
					
			}
			if(x->next==NULL)
			{
				p->next=(p->next)->next;break;
			}
		}
		else
			p=p->next;
	}
	if(p->next==NULL)
		cout<<"δ�ҵ��ó�Ա��\n";
}
void menu2xg(major *q)
{
	cout<<"��������Ҫ�޸ĵ�רҵ��ţ�\n";
	int n;
	major *p;
	p=q;
	cin>>n;
	while(p->next!=NULL)
	{
		if((p->next)->majorNo==n)
		{
			cout<<"����ѧԺ��ţ�\n";
			cin>>(p->next)->collegeNo;
			cout<<"רҵ���ƣ�\n";
			cin>>(p->next)->majorName;
			break;
		}
		else
			p=p->next;
	}
	if(p->next==NULL)
		cout<<"δ�ҵ��ó�Ա��\n";
}
void menu2tj(major *q)
{
	major *p,*x;
	int n;
	x=q;
	while(x->next!=NULL)
		x=x->next;
	cout<<"������רҵ���:";
	cin>>n;
	while(n)
	{
		p=new major;
		if(p==NULL)
			cout<<"�ڴ治�㣬�������룡\n";
		else
		{
			p->majorNo=n;
			cout<<"����ѧԺ���:\n";
			cin>>p->collegeNo;
			cout<<"רҵ����:\n";
			cin>>p->majorName;
			x->next=p;
			x=p;
		}
		cout<<"������רҵ���:";
		cin>>n;
		p->next=NULL;
	}	
}
void menu2(major*p2,student *p4)
{
	int n=1;
	while(n)
	{
		cout<<"  רҵ��Ϣ����"<<endl;
		cout<<"----------------"<<endl;
		cout<<"1. רҵ��Ϣ����"<<endl;
		cout<<"2. רҵ��Ϣ���"<<endl;
		cout<<"3. רҵ��Ϣ��ʾ"<<endl;
		cout<<"4. רҵ��Ϣ��ѯ"<<endl;
		cout<<"5. רҵ��Ϣɾ��"<<endl;
		cout<<"6. רҵ��Ϣ�޸�"<<endl;
		cout<<"0. �˳�"<<endl;
		cout<<"----------------"<<endl;
		cin>>n;
		switch(n)
		{
			case 1:p2=menu2sr();break;
			case 2:menu2tj(p2);break;
			case 3:menu2xs(p2);break;
			case 4:menu2cx(p2);break;
			case 5:menu2sc(p2,p4);break;
			case 6:menu2xg(p2);break;
			case 0:break;
			default:cout<<"ѡ�����\n";break;
		}
	}
}
course *menu3sr()
{
	course *p,*head;
	static course *q;
	int n;
	head=new course;
	head->next=NULL;
	q=head;
	cout<<":������γ̱��";
	cin>>n;
	while(n)
	{
		p=new course;
		if(p==NULL)
			cout<<"�ڴ治�㣬�������룡\n";
		else
		{
			p->No=n;
			cout<<"�γ�����\n";
			cin>>p->Name;
			cout<<"�γ����\n";
			cin>>p->Sort;
			cout<<"�γ�ѧ��\n";
			cin>>p->creditHour;
			cout<<"�γ���ѧʱ\n";
			cin>>p->Time;
			cout<<"����ѧʱ\n";
			cin>>p->theoryTime;
			cout<<"ʵ��ѧʱ\n";
			cin>>p->testTime;
			head->next=p;
			head=p;
		}
		cout<<":������γ̱��";
		cin>>n;
	}
	p->next=NULL;
	return q;

}
void menu3xs(course *q)
{
	course *p;
	p=q;
	while(p->next!=NULL)
	{
		cout<<"�γ̱��:"<<(p->next)->No<<endl;
		cout<<"�γ�����:"<<(p->next)->Name<<endl;
		cout<<"�γ����:"<<(p->next)->Sort<<endl;
		cout<<"�γ�ѧ��:"<<(p->next)->creditHour<<endl;
		cout<<"�γ���ѧʱ:"<<(p->next)->Time<<endl;
		cout<<"����ѧʱ:"<<(p->next)->theoryTime<<endl;
		cout<<"ʵ��ѧʱ:"<<(p->next)->testTime<<endl;
		p=p->next;
	}
	cout<<"�Ѿ������ϣ�\n";
}
void menu3cx(course *q)
{
	cout<<"��������Ҫ���ҵĿγ̱�ţ�\n";
	int n;
	course *p;
	p=q;
	cin>>n;
	while(p->next!=NULL)
	{
		if((p->next)->No==n)
		{
			cout<<"�γ̱��:"<<(p->next)->No<<endl;
			cout<<"�γ�����:"<<(p->next)->Name<<endl;
			cout<<"�γ����:"<<(p->next)->Sort<<endl;
			cout<<"�γ�ѧ��:"<<(p->next)->creditHour<<endl;
			cout<<"�γ���ѧʱ:"<<(p->next)->Time<<endl;
			cout<<"����ѧʱ:"<<(p->next)->theoryTime<<endl;
			cout<<"ʵ��ѧʱ:"<<(p->next)->testTime<<endl;
			break;
		}
		else
			p=p->next;
	}
	if(p->next==NULL)
		cout<<"δ�ҵ��ó�Ա��\n";
}
void menu3sc(course *q,optional *p5)
{
	cout<<"��������Ҫɾ���Ŀγ̱�ţ�\n";
	int n;
	course *p;
	optional *x;
	x=p5;
	p=q;
	cin>>n;
	while(p->next!=NULL)
	{
		if((p->next)->No==n)
		{
			while(x->next!=NULL)
			{
				if((x->next)->courseNo==n)
				{
					cout<<"�ÿγ̲���ɾ����";
					break;
				}	
				else
					x=x->next;
					
			}
			if(x->next==NULL)
			{
				p->next=(p->next)->next;break;
			}
		}
		else
			p=p->next;
	}
	if(p->next==NULL)
		cout<<"δ�ҵ��ó�Ա��\n";
}
void menu3xg(course *q)
{
	cout<<"��������Ҫ�޸ĵĿγ̱�ţ�\n";
	int n;
	course *p;
	p=q;
	cin>>n;
	while(p->next!=NULL)
	{
		if((p->next)->No==n)
		{
			cout<<"�γ�����\n";
			cin>>(p->next)->Name;
			cout<<"�γ����\n";
			cin>>(p->next)->Sort;
			cout<<"�γ�ѧ��\n";
			cin>>(p->next)->creditHour;
			cout<<"�γ���ѧʱ\n";
			cin>>(p->next)->Time;
			cout<<"����ѧʱ\n";
			cin>>(p->next)->theoryTime;
			cout<<"ʵ��ѧʱ\n";
			cin>>(p->next)->testTime;
			break;
		}
		else
			p=p->next;
	}
	if(p->next==NULL)
		cout<<"δ�ҵ��ó�Ա��\n";
}
void menu3tj(course *q)
{
	course *p,*x;
	int n;
	x=q;
	while(x->next!=NULL)
		x=x->next;
	cout<<"������γ̱��:";
	cin>>n;
	while(n)
	{
		p=new course;
		if(p==NULL)
			cout<<"�ڴ治�㣬�������룡\n";
		else
		{
			p->No=n;
			cout<<"�γ�����\n";
			cin>>p->Name;
			cout<<"�γ����\n";
			cin>>p->Sort;
			cout<<"�γ�ѧ��\n";
			cin>>p->creditHour;
			cout<<"�γ���ѧʱ\n";
			cin>>p->Time;
			cout<<"����ѧʱ\n";
			cin>>p->theoryTime;
			cout<<"ʵ��ѧʱ\n";
			cin>>p->testTime;
			x->next=p;
			x=p;
		}
		cout<<"������γ̱��:";
		cin>>n;
		p->next=NULL;
	}	
}
void menu3(course*p3,optional *p5)
{
	int n=1;
	while(n)
	{
		cout<<"  �γ���Ϣ����"<<endl;
		cout<<"----------------"<<endl;
		cout<<"1. �γ���Ϣ����"<<endl;
		cout<<"2. �γ���Ϣ��ʾ"<<endl;
		cout<<"3. �γ���Ϣ��ѯ"<<endl;
		cout<<"4. �γ���Ϣɾ��"<<endl;
		cout<<"5. �γ���Ϣ�޸�"<<endl;
		cout<<"0. �˳�"<<endl;
		cout<<"----------------"<<endl;
		cin>>n;
		switch(n)
		{
			case 1:p3=menu3sr();break;
			case 2:menu3xs(p3);break;
			case 3:menu3cx(p3);break;
			case 4:menu3sc(p3,p5);break;
			case 5:menu3xg(p3);break;
			case 0:break;
			default:cout<<"ѡ�����\n";break;
		}
	}
}
student *menu4sr()
{
	student *p,*head;
	static student *q;
	int n;
	head=new student;
	head->next=NULL;
	q=head;
	cout<<":������ѧ��";
	cin>>n;
	while(n)
	{
		p=new student;
		if(p==NULL)
			cout<<"�ڴ治�㣬�������룡\n";
		else
		{
			p->studNo=n;
			cout<<"רҵ���\n";
			cin>>p->majorNo;
			cout<<"ѧ������\n";
			cin>>p->Name;
			cout<<"ѧ���Ա�\n";
			cin>>p->sex;
			cout<<"��ϵ�绰\n";
			cin>>p->phoneNumber;
			head->next=p;
			head=p;
		}
		cout<<":������ѧ��";
		cin>>n;
	}
	p->next=NULL;
	return q;

}
void menu4xs(student *q)
{
	student *p;
	p=q;
	while(p->next!=NULL)
	{
		cout<<"ѧ��:"<<(p->next)->studNo<<endl;
		cout<<"רҵ���:"<<(p->next)->majorNo<<endl;
		cout<<"ѧ������:"<<(p->next)->Name<<endl;
		cout<<"ѧ���Ա�:"<<(p->next)->sex<<endl;
		cout<<"��ϵ�绰:"<<(p->next)->phoneNumber<<endl;
		p=p->next;
	}
	cout<<"�Ѿ������ϣ�\n";
}
void menu4cx(student *q)
{
	cout<<"��������Ҫ���ҵ�ѧ�ţ�\n";
	int n;
	student *p;
	p=q;
	cin>>n;
	while(p->next!=NULL)
	{
		if((p->next)->studNo==n)
		{
			cout<<"ѧ��:"<<(p->next)->studNo<<endl;
			cout<<"רҵ���:"<<(p->next)->majorNo<<endl;
			cout<<"ѧ������:"<<(p->next)->Name<<endl;
			cout<<"ѧ���Ա�:"<<(p->next)->sex<<endl;
			cout<<"��ϵ�绰:"<<(p->next)->phoneNumber<<endl;
			break;
		}
		else
			p=p->next;
	}
	if(p->next==NULL)
		cout<<"δ�ҵ��ó�Ա��\n";
}
void menu4sc(student *q,optional *p5)
{
	cout<<"��������Ҫɾ����ѧ�ţ�\n";
	int n;
	student *p;
	optional *x;
	x=p5;
	p=q;
	cin>>n;
	while(p->next!=NULL)
	{
		if((p->next)->studNo==n)
		{
			while(x->next!=NULL)
			{
				if((x->next)->studentNo==n)
				{
					cout<<"��ѧ������ɾ����";
					break;
				}	
				else
					x=x->next;
					
			}
			if(x->next==NULL)
			{
				p->next=(p->next)->next;break;
			}
		}
		else
			p=p->next;
	}
	if(p->next==NULL)
		cout<<"δ�ҵ��ó�Ա��\n";
}
void menu4xg(student *q)
{
	cout<<"��������Ҫ�޸ĵ�ѧ�ţ�\n";
	int n;
	student *p;
	p=q;
	cin>>n;
	while(p->next!=NULL)
	{
		if((p->next)->studNo==n)
		{
			cout<<"רҵ���\n";
			cin>>(p->next)->majorNo;
			cout<<"ѧ������\n";
			cin>>(p->next)->Name;
			cout<<"ѧ���Ա�\n";
			cin>>(p->next)->sex;
			cout<<"��ϵ�绰\n";
			cin>>(p->next)->phoneNumber;
			break;
		}
		else
			p=p->next;
	}
	if(p->next==NULL)
		cout<<"δ�ҵ��ó�Ա��\n";
}
void menu4(student*p4,optional *p5)
{
	int n=1;
	while(n)
	{
		cout<<"  ѧ����Ϣ����"<<endl;
		cout<<"----------------"<<endl;
		cout<<"1. ѧ����Ϣ����"<<endl;
		cout<<"2. ѧ����Ϣ��ʾ"<<endl;
		cout<<"3. ѧ����Ϣ��ѯ"<<endl;
		cout<<"3. ѧ����Ϣɾ��"<<endl;
		cout<<"3. ѧ����Ϣ�޸�"<<endl;
		cout<<"0. �˳�"<<endl;
		cout<<"----------------"<<endl;
		cin>>n;
		switch(n)
		{
			case 1:p4=menu4sr();break;
			case 2:menu4xs(p4);break;
			case 3:menu4cx(p4);break;
			case 4:menu4sc(p4,p5);break;
			case 5:menu4xg(p4);break;
			case 0:break;
			default:cout<<"ѡ�����\n";break;
		}
	}
}
optional *menu5sr()
{
	optional *p,*head;
	static optional *q;
	int n;
	head=new optional;
	head->next=NULL;
	q=head;
	cout<<":������ѧ��";
	cin>>n;
	while(n)
	{
		p=new optional;
		if(p==NULL)
			cout<<"�ڴ治�㣬�������룡\n";
		else
		{
			p->studentNo=n;
			cout<<"�γ̱��\n";
			cin>>p->courseNo;
			head->next=p;
			head=p;
		}
		cin>>n;
	}
	p->next=NULL;
	return q;

}
void menu5xs(optional *q)
{
	optional *p;
	p=q;
	while(p->next!=NULL)
	{
		cout<<"ѧ��:"<<(p->next)->studentNo<<endl;
		cout<<"�γ̱��:"<<(p->next)->courseNo<<endl;
		p=p->next;
	}
	cout<<"�Ѿ������ϣ�\n";
}
void menu5cx(optional *q)
{
	cout<<"��������Ҫ���ҵ�ѧ�ţ�\n";
	int n;
	optional *p;
	p=q;
	cin>>n;
	while(p->next!=NULL)
	{
		if((p->next)->studentNo==n)
		{
			cout<<"�γ̱��:"<<(p->next)->courseNo<<endl;
		}
		else
			p=p->next;
	}
	if(p->next==NULL)
		cout<<"δ�ҵ��ó�Ա��\n";
}
void menu5sc(optional *q)
{
	cout<<"��������Ҫɾ����ѧ�ţ�\n";
	int n;
	optional *p;
	p=q;
	cin>>n;
	while(p->next!=NULL)
	{
		if((p->next)->studentNo==n)
		{
			p->next=(p->next)->next;
			break;
		}
		else
			p=p->next;
	}
	if(p->next==NULL)
		cout<<"δ�ҵ��ó�Ա��\n";
}
void menu5(optional*p5)
{
	int n=1;
	while(n)
	{
		cout<<"  ѧ��ѡ�ι���"<<endl;
		cout<<"----------------"<<endl;
		cout<<"1. ѧ��ѡ������"<<endl;
		cout<<"2. ѧ��ѡ����ʾ"<<endl;
		cout<<"3. ѧ��ѡ�β�ѯ"<<endl;
		cout<<"4. ѧ��ѡ��ɾ��"<<endl;
		cout<<"0. �˳�"<<endl;
		cout<<"----------------"<<endl;
		cin>>n;
		switch(n)
		{
			case 1:p5=menu5sr();break;
			case 2:menu5xs(p5);break;
			case 3:menu5cx(p5);break;
			case 4:menu5sc(p5);break;
			case 0:break;
			default:cout<<"ѡ�����\n";break;
		}
	}
}
grade *menu6sr()
{
	grade *p,*head;
	static grade *q;
	int n;
	head=new grade;
	head->next=NULL;
	q=head;
	cout<<":������ѧ��";
	cin>>n;
	while(n)
	{
		p=new grade;
		if(p==NULL)
			cout<<"�ڴ治�㣬�������룡\n";
		else
		{
			p->studentNo=n;
			cout<<"�γ̱��\n";
			cin>>p->courseNo;
			cout<<"�γ̳ɼ�\n";
			cin>>p->Grade;
			head->next=p;
			head=p;
		}
		cout<<":������ѧ��";
		cin>>n;
	}
	p->next=NULL;
	return q;

}
void menu6xs(grade *q)
{
	grade *p;
	p=q;
	while(p->next!=NULL)
	{
		cout<<"ѧ��:"<<(p->next)->studentNo<<endl;
		cout<<"�γ̱��:"<<(p->next)->courseNo<<endl;
		cout<<"�γ̳ɼ�:"<<(p->next)->Grade<<endl;
		p=p->next;
	}
	cout<<"�Ѿ������ϣ�\n";
}
void menu6cx(grade *q)
{
	cout<<"��������Ҫ���ҵ�ѧ�ţ�\n";
	int n;
	grade *p;
	p=q;
	cin>>n;
	while(p->next!=NULL)
	{
		if((p->next)->studentNo==n)
		{
			cout<<"�γ̱��:"<<(p->next)->courseNo<<endl;
			cout<<"�γ̳ɼ�:"<<(p->next)->Grade<<endl;
		}
		else
			p=p->next;
	}
	if(p->next==NULL)
		cout<<"δ�ҵ��ó�Ա��\n";
}
void menu6sc(grade *q)
{
	cout<<"��������Ҫɾ����ѧ�ţ�\n";
	int n,m;
	grade *p;
	p=q;
	cin>>n;
	cout<<"��������Ҫɾ���Ŀγ̱�ţ�\n";
	cin>>m;
	while(p->next!=NULL)
	{
		if((p->next)->studentNo==n||(p->next)->courseNo==m)
		{
			p->next=(p->next)->next;
			break;
		}
		else
			p=p->next;
	}
	if(p->next==NULL)
		cout<<"δ�ҵ��ó�Ա��\n";
}
void menu6xg(grade *q)
{
	cout<<"��������Ҫ�޸ĵ�ѧ�ţ�\n";
	int n,m;
	grade *p;
	p=q;
	cin>>n;
	cout<<"��������Ҫ�޸ĵĿγ̱�ţ�\n";
	cin>>m;
	while(p->next!=NULL)
	{
		if((p->next)->studentNo==n||(p->next)->courseNo==m)
		{
			cout<<"�γ̳ɼ�\n";
			cin>>p->Grade;
			break;
		}
		else
			p=p->next;
	}
	if(p->next==NULL)
		cout<<"δ�ҵ��ó�Ա��\n";
}
void menu6(grade*p6)
{
	int n=1;
	while(n)
	{
		cout<<"  ѧ���ɼ�����"<<endl;
		cout<<"----------------"<<endl;
		cout<<"1. ѧ���ɼ�����"<<endl;
		cout<<"2. ѧ���ɼ���ʾ"<<endl;
		cout<<"3. ѧ���ɼ���ѯ"<<endl;
		cout<<"4. ѧ���ɼ�ɾ��"<<endl;
		cout<<"5. ѧ���ɼ��޸�"<<endl;
		cout<<"0. �˳�"<<endl;
		cout<<"----------------"<<endl;
		cin>>n;
		switch(n)
		{
			case 1:p6=menu6sr();break;
			case 2:menu6xs(p6);break;
			case 3:menu6cx(p6);break;
			case 4:menu6sc(p6);break;
			case 5:menu6xg(p6);break;
			case 0:break;
			default:cout<<"ѡ�����\n";break;
		}
	}
}
void menu()
{
	int n=1;
	grade*p6;
	p6=NULL;
	optional*p5;
	p5=NULL;
	student*p4;
	p4=NULL;
	course*p3;
	p3=NULL;
	major*p2;
	p2=NULL;
	college *p1;
	p1=NULL;
	while(n)
	{
		cout<<"ѧ��������Ϣ����"<<endl;
		cout<<"----------------"<<endl;
		cout<<"1. ѧԺ��Ϣ����"<<endl;
		cout<<"2. רҵ��Ϣ����"<<endl;
		cout<<"3. �γ���Ϣ����"<<endl;
		cout<<"4. ѧ����Ϣ����"<<endl;
		cout<<"5. ѧ��ѡ�ι���"<<endl;
		cout<<"6. ѧ���ɼ�����"<<endl;
		cout<<"0. �˳�ϵͳ"<<endl;
		cout<<"----------------"<<endl;
		cin>>n;
		switch(n)
		{
			case 1:menu1(p1,p2);break;
			case 2:menu2(p2,p4);break;
			case 3:menu3(p3,p5);break;
			case 4:menu4(p4,p5);break;
			case 5:menu5(p5);break;
			case 6:menu6(p6);break;
			case 0:break;
			default:cout<<"ѡ�����\n";break;
		}
	}
}
void main()
{
	menu();
}


