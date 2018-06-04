#include <iostream.h>
#include <iomanip.h>
#include <fstream.h>            //有文件操作需要增加包含文件流头文件
#include <string.h>
struct college{                 //学院结构体
	int No;						//学院编号
	char Name[21];				//学院名称
	char deanName[11];          //院长姓名   
	struct college*next;
};
struct major{                   //专业结构体
	int majorNo;                //专业编号
	int collegeNo;              //专业所属学院编号
	char majorName[21];         //专业名称
	struct major*next;
};
struct student{                 //学生结构体
	int studNo;                 //学号
	int majorNo;                //专业编号
	char Name[11];              //学生姓名
	char sex[3];                //学生性别
	char phoneNumber[12];       //学生联系电话
	struct student*next;
};
struct course{                  //课程结构体
    int No;                     //课程编号
	char Name[11];				//课程名称
	char Sort[5];				//课程性质（必修、限选、任选）
	double creditHour;			//学分
	int Time;					//总学时
	int theoryTime;				//理论学习
	int testTime;				//实验学时
	struct course*next;
};
struct grade{
	int studentNo;				//学号
	int courseNo;				//课程编号
	double Grade;				//成绩
	struct grade*next;
};
struct optional{
	int studentNo;				//学号
	int courseNo;				//课程编号
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
	cout<<":请输入学院编号";
	cin>>n;
	while(n)
	{
		p=new college;
		if(p==NULL)
			cout<<"内存不足，不能输入！\n";
		else
		{
			p->No=n;
			cout<<"学院名称\n";
			cin>>p->Name;
			cout<<"院长姓名\n";
			cin>>p->deanName;
			head->next=p;
			head=p;
		}
		cout<<":请输入学院编号";
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
		cout<<"学院编号："<<(p->next)->No<<endl;
		cout<<"学院名称："<<(p->next)->Name<<endl;
		cout<<"院长姓名："<<(p->next)->deanName<<endl;
		p=p->next;
	}
	cout<<"已经输出完毕！\n";
}
void menu1cx(college *q)
{
	cout<<"请输入需要查找的学院编号：\n";
	int n;
	college *p;
	p=q;
	cin>>n;
	while(p->next!=NULL)
	{
		if((p->next)->No==n)
		{
			cout<<"查找该学院信息如下:\n";
			cout<<"学院编号："<<(p->next)->No<<endl;
			cout<<"学院名称："<<(p->next)->Name<<endl;
			cout<<"院长姓名："<<(p->next)->deanName<<endl;
			break;
		}
		else
			p=p->next;
	}
	if(p->next==NULL)
		cout<<"未找到该成员！\n";
}
void menu1sc(college *q,major *x)
{
	cout<<"请输入需要删除的学院编号：\n";
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
					cout<<"该学院不能删除！";
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
		cout<<"未找到该成员！\n";
}
void menu1xg(college *q)
{
	cout<<"请输入需要修改的学院编号：\n";
	int n;
	college *p;
	p=q;
	cin>>n;
	while(p->next!=NULL)
	{
		if((p->next)->No==n)
		{
			cout<<"学院名称：\n";
			cin>>(p->next)->Name;
			cout<<"院长姓名：\n";
			cin>>(p->next)->deanName;
			break;
		}
		else
			p=p->next;
	}
	if(p->next==NULL)
		cout<<"未找到该成员！\n";
}
void menu1tj(college *q)
{
	college *p,*x;
	int n;
	x=q;
	while(x->next!=NULL)
		x=x->next;
	cout<<"请输入学院编号:";
	cin>>n;
	while(n)
	{
		p=new college;
		if(p==NULL)
			cout<<"内存不足，不能输入！\n";
		else
		{
			p->No=n;
			cout<<"学院名称:\n";
			cin>>p->Name;
			cout<<"院长姓名:\n";
			cin>>p->deanName;
			x->next=p;
			x=p;
		}
		cout<<":请输入学院编号";
		cin>>n;
		p->next=NULL;
	}	
}
void menu1(college *p1,major *p2)
{
	int n=1;
	while(n)
	{
		cout<<"  学院信息管理"<<endl;
		cout<<"----------------"<<endl;
		cout<<"1. 学院信息输入"<<endl;
		cout<<"2. 学院信息添加"<<endl;
		cout<<"3. 学院信息显示"<<endl;
		cout<<"4. 学院信息查询"<<endl;
		cout<<"5. 学院信息删除"<<endl;
		cout<<"6. 学院信息修改"<<endl;
		cout<<"0. 退出"<<endl;
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
			default:cout<<"选择错误！\n";break;
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
	cout<<":请输入专业编号";
	cin>>n;
	while(n)
	{
		p=new major;
		if(p==NULL)
			cout<<"内存不足，不能输入！\n";
		else
		{
			p->majorNo=n;
			cout<<"所属学院编号\n";
			cin>>p->collegeNo;
			cout<<"专业名称\n";
			cin>>p->majorName;
			head->next=p;
			head=p;
		}
		cout<<":请输入专业编号";
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
		cout<<"专业编号："<<(p->next)->majorNo<<endl;
		cout<<"所属学院编号："<<(p->next)->collegeNo<<endl;
		cout<<"专业名称："<<(p->next)->majorName<<endl;
		p=p->next;
	}
	cout<<"已经输出完毕！\n";
}
void menu2cx(major *q)
{
	cout<<"请输入需要查找的专业编号：\n";
	int n;
	major *p;
	p=q;
	cin>>n;
	while(p->next!=NULL)
	{
		if((p->next)->majorNo==n)
		{
			cout<<"查找该专业信息如下:\n";
			cout<<"专业编号："<<(p->next)->majorNo<<endl;
			cout<<"所属学院编号："<<(p->next)->collegeNo<<endl;
			cout<<"专业名称："<<(p->next)->majorName<<endl;
			break;
		}
		else
			p=p->next;
	}
	if(p->next==NULL)
		cout<<"未找到该成员！\n";
}
void menu2sc(major *q,student *p4)
{
	cout<<"请输入需要删除的专业编号：\n";
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
					cout<<"该专业不能删除！";
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
		cout<<"未找到该成员！\n";
}
void menu2xg(major *q)
{
	cout<<"请输入需要修改的专业编号：\n";
	int n;
	major *p;
	p=q;
	cin>>n;
	while(p->next!=NULL)
	{
		if((p->next)->majorNo==n)
		{
			cout<<"所属学院编号：\n";
			cin>>(p->next)->collegeNo;
			cout<<"专业名称：\n";
			cin>>(p->next)->majorName;
			break;
		}
		else
			p=p->next;
	}
	if(p->next==NULL)
		cout<<"未找到该成员！\n";
}
void menu2tj(major *q)
{
	major *p,*x;
	int n;
	x=q;
	while(x->next!=NULL)
		x=x->next;
	cout<<"请输入专业编号:";
	cin>>n;
	while(n)
	{
		p=new major;
		if(p==NULL)
			cout<<"内存不足，不能输入！\n";
		else
		{
			p->majorNo=n;
			cout<<"所属学院编号:\n";
			cin>>p->collegeNo;
			cout<<"专业名称:\n";
			cin>>p->majorName;
			x->next=p;
			x=p;
		}
		cout<<"请输入专业编号:";
		cin>>n;
		p->next=NULL;
	}	
}
void menu2(major*p2,student *p4)
{
	int n=1;
	while(n)
	{
		cout<<"  专业信息管理"<<endl;
		cout<<"----------------"<<endl;
		cout<<"1. 专业信息输入"<<endl;
		cout<<"2. 专业信息添加"<<endl;
		cout<<"3. 专业信息显示"<<endl;
		cout<<"4. 专业信息查询"<<endl;
		cout<<"5. 专业信息删除"<<endl;
		cout<<"6. 专业信息修改"<<endl;
		cout<<"0. 退出"<<endl;
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
			default:cout<<"选择错误！\n";break;
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
	cout<<":请输入课程编号";
	cin>>n;
	while(n)
	{
		p=new course;
		if(p==NULL)
			cout<<"内存不足，不能输入！\n";
		else
		{
			p->No=n;
			cout<<"课程名称\n";
			cin>>p->Name;
			cout<<"课程类别\n";
			cin>>p->Sort;
			cout<<"课程学分\n";
			cin>>p->creditHour;
			cout<<"课程总学时\n";
			cin>>p->Time;
			cout<<"理论学时\n";
			cin>>p->theoryTime;
			cout<<"实验学时\n";
			cin>>p->testTime;
			head->next=p;
			head=p;
		}
		cout<<":请输入课程编号";
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
		cout<<"课程编号:"<<(p->next)->No<<endl;
		cout<<"课程名称:"<<(p->next)->Name<<endl;
		cout<<"课程类别:"<<(p->next)->Sort<<endl;
		cout<<"课程学分:"<<(p->next)->creditHour<<endl;
		cout<<"课程总学时:"<<(p->next)->Time<<endl;
		cout<<"理论学时:"<<(p->next)->theoryTime<<endl;
		cout<<"实验学时:"<<(p->next)->testTime<<endl;
		p=p->next;
	}
	cout<<"已经输出完毕！\n";
}
void menu3cx(course *q)
{
	cout<<"请输入需要查找的课程编号：\n";
	int n;
	course *p;
	p=q;
	cin>>n;
	while(p->next!=NULL)
	{
		if((p->next)->No==n)
		{
			cout<<"课程编号:"<<(p->next)->No<<endl;
			cout<<"课程名称:"<<(p->next)->Name<<endl;
			cout<<"课程类别:"<<(p->next)->Sort<<endl;
			cout<<"课程学分:"<<(p->next)->creditHour<<endl;
			cout<<"课程总学时:"<<(p->next)->Time<<endl;
			cout<<"理论学时:"<<(p->next)->theoryTime<<endl;
			cout<<"实验学时:"<<(p->next)->testTime<<endl;
			break;
		}
		else
			p=p->next;
	}
	if(p->next==NULL)
		cout<<"未找到该成员！\n";
}
void menu3sc(course *q,optional *p5)
{
	cout<<"请输入需要删除的课程编号：\n";
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
					cout<<"该课程不能删除！";
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
		cout<<"未找到该成员！\n";
}
void menu3xg(course *q)
{
	cout<<"请输入需要修改的课程编号：\n";
	int n;
	course *p;
	p=q;
	cin>>n;
	while(p->next!=NULL)
	{
		if((p->next)->No==n)
		{
			cout<<"课程名称\n";
			cin>>(p->next)->Name;
			cout<<"课程类别\n";
			cin>>(p->next)->Sort;
			cout<<"课程学分\n";
			cin>>(p->next)->creditHour;
			cout<<"课程总学时\n";
			cin>>(p->next)->Time;
			cout<<"理论学时\n";
			cin>>(p->next)->theoryTime;
			cout<<"实验学时\n";
			cin>>(p->next)->testTime;
			break;
		}
		else
			p=p->next;
	}
	if(p->next==NULL)
		cout<<"未找到该成员！\n";
}
void menu3tj(course *q)
{
	course *p,*x;
	int n;
	x=q;
	while(x->next!=NULL)
		x=x->next;
	cout<<"请输入课程编号:";
	cin>>n;
	while(n)
	{
		p=new course;
		if(p==NULL)
			cout<<"内存不足，不能输入！\n";
		else
		{
			p->No=n;
			cout<<"课程名称\n";
			cin>>p->Name;
			cout<<"课程类别\n";
			cin>>p->Sort;
			cout<<"课程学分\n";
			cin>>p->creditHour;
			cout<<"课程总学时\n";
			cin>>p->Time;
			cout<<"理论学时\n";
			cin>>p->theoryTime;
			cout<<"实验学时\n";
			cin>>p->testTime;
			x->next=p;
			x=p;
		}
		cout<<"请输入课程编号:";
		cin>>n;
		p->next=NULL;
	}	
}
void menu3(course*p3,optional *p5)
{
	int n=1;
	while(n)
	{
		cout<<"  课程信息管理"<<endl;
		cout<<"----------------"<<endl;
		cout<<"1. 课程信息输入"<<endl;
		cout<<"2. 课程信息显示"<<endl;
		cout<<"3. 课程信息查询"<<endl;
		cout<<"4. 课程信息删除"<<endl;
		cout<<"5. 课程信息修改"<<endl;
		cout<<"0. 退出"<<endl;
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
			default:cout<<"选择错误！\n";break;
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
	cout<<":请输入学号";
	cin>>n;
	while(n)
	{
		p=new student;
		if(p==NULL)
			cout<<"内存不足，不能输入！\n";
		else
		{
			p->studNo=n;
			cout<<"专业编号\n";
			cin>>p->majorNo;
			cout<<"学生姓名\n";
			cin>>p->Name;
			cout<<"学生性别\n";
			cin>>p->sex;
			cout<<"联系电话\n";
			cin>>p->phoneNumber;
			head->next=p;
			head=p;
		}
		cout<<":请输入学号";
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
		cout<<"学号:"<<(p->next)->studNo<<endl;
		cout<<"专业编号:"<<(p->next)->majorNo<<endl;
		cout<<"学生姓名:"<<(p->next)->Name<<endl;
		cout<<"学生性别:"<<(p->next)->sex<<endl;
		cout<<"联系电话:"<<(p->next)->phoneNumber<<endl;
		p=p->next;
	}
	cout<<"已经输出完毕！\n";
}
void menu4cx(student *q)
{
	cout<<"请输入需要查找的学号：\n";
	int n;
	student *p;
	p=q;
	cin>>n;
	while(p->next!=NULL)
	{
		if((p->next)->studNo==n)
		{
			cout<<"学号:"<<(p->next)->studNo<<endl;
			cout<<"专业编号:"<<(p->next)->majorNo<<endl;
			cout<<"学生姓名:"<<(p->next)->Name<<endl;
			cout<<"学生性别:"<<(p->next)->sex<<endl;
			cout<<"联系电话:"<<(p->next)->phoneNumber<<endl;
			break;
		}
		else
			p=p->next;
	}
	if(p->next==NULL)
		cout<<"未找到该成员！\n";
}
void menu4sc(student *q,optional *p5)
{
	cout<<"请输入需要删除的学号：\n";
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
					cout<<"该学生不能删除！";
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
		cout<<"未找到该成员！\n";
}
void menu4xg(student *q)
{
	cout<<"请输入需要修改的学号：\n";
	int n;
	student *p;
	p=q;
	cin>>n;
	while(p->next!=NULL)
	{
		if((p->next)->studNo==n)
		{
			cout<<"专业编号\n";
			cin>>(p->next)->majorNo;
			cout<<"学生姓名\n";
			cin>>(p->next)->Name;
			cout<<"学生性别\n";
			cin>>(p->next)->sex;
			cout<<"联系电话\n";
			cin>>(p->next)->phoneNumber;
			break;
		}
		else
			p=p->next;
	}
	if(p->next==NULL)
		cout<<"未找到该成员！\n";
}
void menu4(student*p4,optional *p5)
{
	int n=1;
	while(n)
	{
		cout<<"  学生信息管理"<<endl;
		cout<<"----------------"<<endl;
		cout<<"1. 学生信息输入"<<endl;
		cout<<"2. 学生信息显示"<<endl;
		cout<<"3. 学生信息查询"<<endl;
		cout<<"3. 学生信息删除"<<endl;
		cout<<"3. 学生信息修改"<<endl;
		cout<<"0. 退出"<<endl;
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
			default:cout<<"选择错误！\n";break;
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
	cout<<":请输入学号";
	cin>>n;
	while(n)
	{
		p=new optional;
		if(p==NULL)
			cout<<"内存不足，不能输入！\n";
		else
		{
			p->studentNo=n;
			cout<<"课程编号\n";
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
		cout<<"学号:"<<(p->next)->studentNo<<endl;
		cout<<"课程编号:"<<(p->next)->courseNo<<endl;
		p=p->next;
	}
	cout<<"已经输出完毕！\n";
}
void menu5cx(optional *q)
{
	cout<<"请输入需要查找的学号：\n";
	int n;
	optional *p;
	p=q;
	cin>>n;
	while(p->next!=NULL)
	{
		if((p->next)->studentNo==n)
		{
			cout<<"课程编号:"<<(p->next)->courseNo<<endl;
		}
		else
			p=p->next;
	}
	if(p->next==NULL)
		cout<<"未找到该成员！\n";
}
void menu5sc(optional *q)
{
	cout<<"请输入需要删除的学号：\n";
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
		cout<<"未找到该成员！\n";
}
void menu5(optional*p5)
{
	int n=1;
	while(n)
	{
		cout<<"  学生选课管理"<<endl;
		cout<<"----------------"<<endl;
		cout<<"1. 学生选课输入"<<endl;
		cout<<"2. 学生选课显示"<<endl;
		cout<<"3. 学生选课查询"<<endl;
		cout<<"4. 学生选课删除"<<endl;
		cout<<"0. 退出"<<endl;
		cout<<"----------------"<<endl;
		cin>>n;
		switch(n)
		{
			case 1:p5=menu5sr();break;
			case 2:menu5xs(p5);break;
			case 3:menu5cx(p5);break;
			case 4:menu5sc(p5);break;
			case 0:break;
			default:cout<<"选择错误！\n";break;
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
	cout<<":请输入学号";
	cin>>n;
	while(n)
	{
		p=new grade;
		if(p==NULL)
			cout<<"内存不足，不能输入！\n";
		else
		{
			p->studentNo=n;
			cout<<"课程编号\n";
			cin>>p->courseNo;
			cout<<"课程成绩\n";
			cin>>p->Grade;
			head->next=p;
			head=p;
		}
		cout<<":请输入学号";
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
		cout<<"学号:"<<(p->next)->studentNo<<endl;
		cout<<"课程编号:"<<(p->next)->courseNo<<endl;
		cout<<"课程成绩:"<<(p->next)->Grade<<endl;
		p=p->next;
	}
	cout<<"已经输出完毕！\n";
}
void menu6cx(grade *q)
{
	cout<<"请输入需要查找的学号：\n";
	int n;
	grade *p;
	p=q;
	cin>>n;
	while(p->next!=NULL)
	{
		if((p->next)->studentNo==n)
		{
			cout<<"课程编号:"<<(p->next)->courseNo<<endl;
			cout<<"课程成绩:"<<(p->next)->Grade<<endl;
		}
		else
			p=p->next;
	}
	if(p->next==NULL)
		cout<<"未找到该成员！\n";
}
void menu6sc(grade *q)
{
	cout<<"请输入需要删除的学号：\n";
	int n,m;
	grade *p;
	p=q;
	cin>>n;
	cout<<"请输入需要删除的课程编号：\n";
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
		cout<<"未找到该成员！\n";
}
void menu6xg(grade *q)
{
	cout<<"请输入需要修改的学号：\n";
	int n,m;
	grade *p;
	p=q;
	cin>>n;
	cout<<"请输入需要修改的课程编号：\n";
	cin>>m;
	while(p->next!=NULL)
	{
		if((p->next)->studentNo==n||(p->next)->courseNo==m)
		{
			cout<<"课程成绩\n";
			cin>>p->Grade;
			break;
		}
		else
			p=p->next;
	}
	if(p->next==NULL)
		cout<<"未找到该成员！\n";
}
void menu6(grade*p6)
{
	int n=1;
	while(n)
	{
		cout<<"  学生成绩管理"<<endl;
		cout<<"----------------"<<endl;
		cout<<"1. 学生成绩输入"<<endl;
		cout<<"2. 学生成绩显示"<<endl;
		cout<<"3. 学生成绩查询"<<endl;
		cout<<"4. 学生成绩删除"<<endl;
		cout<<"5. 学生成绩修改"<<endl;
		cout<<"0. 退出"<<endl;
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
			default:cout<<"选择错误！\n";break;
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
		cout<<"学生基本信息管理"<<endl;
		cout<<"----------------"<<endl;
		cout<<"1. 学院信息管理"<<endl;
		cout<<"2. 专业信息管理"<<endl;
		cout<<"3. 课程信息管理"<<endl;
		cout<<"4. 学生信息管理"<<endl;
		cout<<"5. 学生选课管理"<<endl;
		cout<<"6. 学生成绩管理"<<endl;
		cout<<"0. 退出系统"<<endl;
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
			default:cout<<"选择错误！\n";break;
		}
	}
}
void main()
{
	menu();
}


