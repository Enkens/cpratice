#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
typedef struct Account
{
	char name[12];//用户名
	char password[14];//密码
	char sex[8];//性别
	char phone[12];//手机号
	char mail[20];//邮箱
	int  buycar[100];//购物车记录
	int  order[1000];//订单信息
}account;//用户基本信息
typedef struct Ware
{
	int name;//商品名称
	int consequence;//商品序号
	char kind[15];//商品类别
	int num;//库存数量
	double price;//商品价格
}ware;//商品基本信息
int menu();//初始菜单界面
int chose(int n);//菜单选项
void account_register();//(用户)注册
int account_entry();//（用户）登陆界面
void modify_information(int i);//修改用户信息
void item();//自动录入初始商品信息
int browse_merchandise(); //按种类浏览商品信息
int shop_trolley(char ph[]);//购物车信息
void manage_user_information();//用户信息管理（后台管理员）
void manage_goods_kinds();//商品类别管理（后台管理员）
void manage_order();//订单管理（后台管理员）
void manage_ware_message();//商品信息管理（后台管理员）
void line(int a);//排序函数（后台管理员）
void leave();//结束界面
account reg[200];//定义用户信息存储数组
ware items[2000];//定义商品信息存储数组
char wk[30][15];//商品类别存储数组
int kindb=0;//商品类别数目
int main()//主函数
{
	int n,a,b,k=0;
	char ph[12];
		FILE *fp;
		if((fp = fopen("guke.txt","r")) == NULL)
		{
			printf("文件打开失败！\n");
			leave();
		}
			for(a = 0;!feof(fp);a++)
		{
			fscanf(fp,"%12s",reg[a].name );
			fscanf(fp,"%14s",reg[a].password);
			fscanf(fp,"%8s",reg[a].sex);
			fscanf(fp,"%12s",reg[a].phone );
			fscanf(fp,"%20s",reg[a].mail);
		}
		fclose(fp);
	do{
				n = menu();//初始菜单栏
				if(n!=1 && n!=2 && n!=3)
				{
					chose(n);
					printf("        .........................\n请输入你的选择\n");
					scanf("%d",&n);
				}
		if(n == 1)
			{
			item();//初始化商品信息
				do{
								chose(n);//选择菜单栏
							printf("        .........................\n请输入你的选择\n");
							scanf("%d",&a);
						if(a == 1)
								account_register();//用户注册
						else if(a == 2)
								account_entry();//用户登录
						else if(a == 3)
								browse_merchandise();//浏览商品
						else if(a == 4)
						{
							printf("请输入你的手机号：");
							scanf("%s",ph);
							while(strcmp(reg[k].phone ,ph))
							{
								k++;
								if(k ==200)
									break;
							}
							if(k == 200)
							{
								printf("你的手机号不存在或者输入有误！\n你不是我们的用户，请您注册以后再来。\n");
								leave();
							}
							else
							shop_trolley(ph);//购物车信息
						}
						else if(a == 5)
						{	
								printf("返回选择菜单请输入5\n返回初始界面请输入6\n");
								scanf("%d",&a);
								if(a == 6)
								{
									b = a;
									goto screen;
								}
						}
					}while(a == 5);
			}
		else if(n == 2)
		{
			item();//初始化商品信息
				do{
					chose(n);//选择菜单栏
					
					printf("      ...........................\n请输入你的选择\n");
					scanf("%d",&a);
					if(a == 1)
						 manage_user_information();//用户信息管理
					if(a ==2)
					{
						manage_goods_kinds();//商品类别管理
				           printf("返回选择菜单请输入5\n返回初始界面请输入6\n");
							scanf("%d",&a);
							if(a == 5)
								continue;
							if(a == 6)
								{
									b = a;
									goto screen;
								}
					}
					if(a == 3)
						manage_order();//订单信息管理
					if(a == 4)
						manage_ware_message();//商品信息管理
					if(a == 5)//返回初始界面
					{
							printf("返回选择菜单请输入5\n返回初始界面请输入6\n");
							scanf("%d",&a);
							if(a == 6)
								{
									b = a;
									goto screen;
								}
					}
				}while(a == 5);
		}
		else if(n == 3)
				leave();
		printf("返回初始界面请输入6，\n输入其他任意数字退出系统\n");
		scanf("%d",&b);
screen: printf("..................................................................\n\n\n");
	}while(b == 6);
}
int chose(int n)//选择菜单栏，传入选择参数n的值。
{
	
    do{
		if(n!=1 && n!=2)
		{
		printf("看不见是吧。\n给我重新输!\n");

		 n = menu();
		}
		  if(n ==1)
	 {
		 printf("                顾客   \n        ........................\n");
		 printf("            1.用户注册\n            2.用户登录\n            3.在线浏览商品\n");
		 printf("            4.购物车和购买商品（必须先登录）\n            5.返回初始界面\n");
	 }
			else if(n == 2)
	 {
		 printf("                老板        \n       ..........................\n");
		 printf("            1.用户信息管理\n            2.商品类别管理\n            3.订单管理\n");
		 printf("            4.商品信息管理\n            5.返回初始界面\n");
	 }	 
		 }while(n!=1 && n!=2);
	return 0;
}
int menu()//初始界面
{
	int c;

	 printf("    |\\　　　  ／|\n   /  |     ∠   /　\n  │  | ＿, ＜  ／　　 /`\n  /　　　　　ヽ　　/  /　\n Y　　　　　   `　 /  /\nｲ●　､　●　　⊂⊃〈 〈  /\n()　 へ　　　　|　＼ /\n　>ｰ ､_　 ィ　 ) ／／\n / へ　　 /　ﾉ  ＼＼\nヽ_ﾉ　　(_／　 │／／\n　7　　　　　　|／\n　＞―r ￣`ｰ―＿/\n");
	printf(" JD皮卡丘超市         \n");

	printf(" 1.顾客             \n");

	printf(" 2.老板              \n");

	printf(" 3.退出              \n");
	
	
	scanf("%d",&c);
	return c;
}
void account_register()//用户注册
{
	
	char pw[14];
	int n,j,k=0,m;
	FILE *fp;
	for(j=0;j<200;j++)
	{
		if(reg[j].phone[0]!='1')
		{
			n = j;
			break;
		}
	}
	if(j == 200)
	{
		printf("用户注册已满");
		 leave();
	}
	printf("你是第%d名注册用户\n",n+1);
			printf("..............................................................................\n");
			printf("温馨提示：\n          1.用户名为汉字，大小写字母，数字均可，长度1~12个空格。\n          ");
			printf("2.密码可以包含大小写字母，数字，特殊字符（不建议，怕你会忘记）\n          长度6~~14个空格");
			printf("\n          3.性别为(男或女)\n             4.手机号位11位，且均为1开头！");
			printf("\n.......................................................................\n");
			printf("输入你的用户名：");
			scanf("\n");
			gets(reg[n].name);
			while(k<n)
			{
				if(strcmp(reg[k].name,reg[n].name) == 0)
				{
					printf("此用户名重复，请重新输入其他用户名");
					gets(reg[n].name);
						if(strcmp(reg[0].name,reg[n].name) == 0)//判断输入的用户名和第一位用户的用户名是否重合，因为下一次判断用户名是否重合是从第二位用户开始判断的。
						{
						printf("此用户名重复，请重新输入其他用户名");
						gets(reg[n].name);
						}
					k = 0;
				}
					k++;
			}
			printf("请输入你的密码:");
			scanf("%s",reg[n].password);
			printf("再次输入你的密码:");
			scanf("%s",&pw);
			while(strcmp(reg[n].password,pw))//比较两次输入密码是否相同！
			{
			printf("第二次输入的密码与第一次不一样，请再次输入你的密码:");
			scanf("%s",&pw);
			}
			printf("请输入你的性别:");
			scanf("%s",reg[n].sex);
			printf("请输入你的手机号");
			scanf("%s",reg[n].phone);
			printf("请输入你的私人邮箱:");
			scanf("%s",reg[n].mail);
			printf("完成注册!\n请用手机号进行登录!\n");	
			m = n;
			if(n == 0)
			{
			if((fp = fopen("guke.txt","w")) == NULL)
				{
					printf("Wrong !\n");
					exit(0);
				} 
				fprintf(fp,"%12s%14s%8s%12s%20s\n",reg[m].name,reg[m].password,reg[m].sex,reg[m].phone,reg[m].mail);
				fclose(fp);
			}
			else
			{
				if((fp = fopen("guke.txt","a")) == NULL)
				{
					printf("Wrong !\n");
					exit(0);
				} 
				fprintf(fp,"%12s%14s%8s%12s%20s\n",reg[m].name,reg[m].password,reg[m].sex,reg[m].phone,reg[m].mail);
				fclose(fp);
			}
}
int account_entry()//用户登录
{
	char num[12],pass[18],ch,an[12],sex[8],ma[20];
	int i=0,j,mo,k=0,a;
	FILE *fp;
		if((fp = fopen("guke.txt","r")) == NULL)
		{
			printf("文件打开失败！\n");
			leave();
		}
		for(a = 0;!feof(fp);a++)
		{
			for(a = 0;!feof(fp);a++)
		{
			fscanf(fp,"%12s",reg[a].name );
			fscanf(fp,"%14s",reg[a].password);
			fscanf(fp,"%8s",reg[a].sex);
			fscanf(fp,"%12s",reg[a].phone );
			fscanf(fp,"%20s",reg[a].mail);
		}
		}
		fclose(fp);

	printf("请输入你的登录手机号\n");
	scanf("%s",num);
	while(strcmp(reg[i].phone,num))//查找相应手机号！
	{
	i++;
	if(i == 200)
		break;
	}
	if(i == 200)//判断手机号不存在！
	{
			printf("你输入的手机号不存在或者错误\n");
			printf("返回选择菜单栏目，请重新选择！\n");
			printf("-----------------------------------------------------------\n");
			return 0;
	}
		printf("请输入你的密码:");
		scanf("%s",pass);
	if(strcmp(reg[i].password,pass) == 0)//检验密码是否和之前注册时该手机号用户的密码一致！
	{
		printf("登录成功!\n");
	}
	else 
	{
		printf("登录失败,密码错误\n");
		do{
			printf("请重新输入密码:");
			scanf("%s",pass);
			if(strcmp(reg[i].password,pass) == 0)
			{
			printf("登录成功!\n");
			break;
			}
			printf("登录失败,密码错误\n");
			printf("-----------------------------------------------------------\n");
			printf("1.输入Y/y 我们会帮助你找回密码.\n2.输入'N/n'返回上一级菜单界面!\n");
			printf("4.退出登录界面，离开应用，请输入'N/n'!\n");
			printf("如果你想再次尝试输入你的密码，请输入其他任意字符!\n");
			scanf(" %c",&ch);//通过用户的其他信息来帮助用户找回密码！
			if(ch == 'Y' || ch == 'y')
			{
				printf("请输入你的用户名");
				scanf("%s",an);
				printf("请输入你的性别，男或女!");
				scanf("%s",sex);
				printf("请输入你的私人注册邮箱 :");
				scanf("%s",ma);
				for(j =0 ;j<200;j++)
				{
					if(strcmp(reg[j].name,an) == 0  && strcmp(reg[j].sex,sex) == 0 && strcmp(reg[j].mail,ma) == 0)//当用户名、性别、邮箱都正确的时候，可以找回密码
						break;
				}
				if(j <200)
				printf("祝贺你！你的密码已找回\n 你的密码是 %s\n",reg[j].password);
				else 
				{
							printf("抱歉！我们没能找到你的密码，或许是你已经输入的信息不正确！");
				}

			}
			else if(ch == 'R' || ch == 'r')
			{
			printf("返回选择菜单栏目，请重新选择！\n");
			printf("-----------------------------------------------------------\n");
			return 0;
			}
			else if(ch == 'N' || ch == 'n')
				leave();
		}while(strcmp(reg[i].password,pass));
	}
	printf("用户名:%s\n性别:%s\n手机号:%s\n私人邮箱:%s\n",reg[i].name,reg[i].sex,reg[i].phone,reg[i].mail);
		printf("如果你想修改个人信息，请输入1，否则输入2！");
		scanf("%d",&mo);
		if(mo == 1)//修改个人信息。
		{
			 modify_information(i);

		}
		return 0;
}
void modify_information(int i)//修改个人信息
{
	int b,k =0,m;
	FILE*fp;
	 char pass[18];
	 printf("-------------------------------------------------------------------------\n");
		printf("1.用户名\n2.密码\n3.性别\n");
			printf("4.手机号\n5.邮箱\n");
			printf("---------------------------------------------------------------------\n");
			printf("选择你想要修改的条目，输入相应的序号");
			scanf("%d",&b);
			printf("..............................................................................\n");
			printf("温馨提示：\n          1.用户名为汉字，大小写字母，数字均可，长度1~12个空格。\n          ");
			printf("2.密码可以包含大小写字母，数字，特殊字符（不建议，怕你会忘记）\n          长度6~~14个空格");
			printf("\n          3.性别为(男或女)");
			printf("\n.......................................................................\n");
			switch(b)
			{
				case 1:
					printf("请输入你的新的用户名");
					scanf("%s",reg[i].name);
					while(k<i)
					{
					if(strcmp(reg[k].name,reg[i].name) == 0)//设置循环k,来比较之前的用户名是否与第i+1位用户的用户名重合。
					{
						printf("此用户名重复，请重新输入其他用户名");
						gets(reg[i].name);
						if(strcmp(reg[0].name,reg[i].name) == 0)//判断输入的用户名和第一位用户的用户名是否重合，因为下一次判断用户名是否重合是从第二位用户开始判断的。
						{
						printf("此用户名重复，请重新输入其他用户名");
						gets(reg[i].name);
						}
						k = 0;
					}
						k++;
					}
					printf("修改成功！\n" );
					break;
				case 2:
					printf("输入你的新密码:");
					fgets(reg[i].password,sizeof(reg[i].password),stdin);
					printf("请再次输入你的密码");
					fgets(pass,sizeof(pass),stdin);
					while(strcmp(reg[i].password,pass)!=0)//比较两次输入密码是否相同！
					{
					printf("这一次的密码与上一次输入不符！\n");
					printf("再次输入你的密码:");
					scanf("%s",&pass);
					}
					printf("修改成功！\n");
					break;
				case 3:
					printf("请输入你的性别");
					scanf("%s",reg[i].sex);
					printf("修改成功！\n");
					break;
				case 4:
					printf("请输入你的新手机号");
					scanf("%s",reg[i].phone);
					printf("修改成功！\n");
					break;
				case 5:
					printf("请输入你新的私人邮箱：");
					scanf("%s",reg[i].mail);
					printf("修改成功！\n");
					break;
				default:
					printf("错误！输入不合法！\n");
			}
				m=0;
				if((fp = fopen("guke.txt","w")) == NULL)
				{
					printf("Wrong !\n");
					exit(0);
				} 
				for(m=0;reg[m].phone[0] =='1';m++)
				{
				fprintf(fp,"%12s%14s%8s%12s%20s\n",reg[m].name,reg[m].password,reg[m].sex,reg[m].phone,reg[m].mail);
				}
				fclose(fp);
}
void item()//自动录入随机初始商品信息
{
	int i;
	srand(1);
	for(i=0;i<8;i++)
	{
		items[i].name = i+1;
		items[i].consequence = i+1;
		strcpy(items[i].kind, "生活用品");
		items[i].num = (i+1)*10+i;
		items[i].price = (rand() % 500 + 2)+0.5;
	}
	for(i=8;i<15;i++)
	{
		items[i].name = i+1;
	     items[i].consequence = i+1;
		strcpy(items[i].kind,"学习用品");
		items[i].num = i*10+i;
		items[i].price = (rand() % 30 + 1)+0.5;
	}
	for(i=15;i<27;i++)
	{
		items[i].name = i+1;
			items[i].consequence = i+1;
		strcpy(items[i].kind,"衣服装饰");
		items[i].num = i*10+i;
		items[i].price = (rand() % 1000 + 10)+0.6;
	}
	for(i =27;i<38;i++)
	{
		items[i].name = i+1;
			items[i].consequence = i+1;
		strcpy(items[i].kind,"运动产品");
		items[i].num = i*10+i;
		items[i].price = (rand() % 700 + 10)+0.4;
	}
	for(i=38;i<50;i++)
	{
		items[i].name = i+1;
			items[i].consequence = i+1;
		strcpy(items[i].kind,"居家生活");
		items[i].num = i*10+i;
		items[i].price = (rand() % 3000 + 100)+0.2;
	}
	for(i=50;i<55;i++)
	{
		items[i].name = i+1;
			items[i].consequence = i+1;
		strcpy(items[i].kind,"食用产品");
		items[i].num = i*10+i;
		items[i].price = (rand() % 100 + 1)+0.3;
	}
	for(i=55;i<63;i++)
	{
		items[i].name = i+1;
			items[i].consequence = i+1;
		strcpy(items[i].kind,"饮用产品");
		items[i].num = i*10+i;
		items[i].price = (rand() % 400 + 1)+0.5;
	}
	for(i=63;i<71;i++)
	{
		items[i].name = i;
		items[i].consequence = i+1;
		strcpy(items[i].kind,"电子产品");
		items[i].num = i*10+i;
		items[i].price = (rand() % 10000 + 1200)+0.5;
	}
	for(i=71;i<90;i++)
	{
		items[i].name = i+1;
			items[i].consequence = i+1;
		strcpy(items[i].kind,"智能推荐");
		items[i].num = i*10+i;
		items[i].price = (rand() % 100000 + 1)+0.8;
	}
}
int browse_merchandise()//按种类浏览商品
{
	int a,i,b,m,k,c;
	char ph[12],ch[15];
	printf("--------------------------------------------\n");
	printf("1.生活用品     2.学习用品\n3.衣服装饰     4.运动产品\n5.居家生活     6.食用产品\n7.饮用产品     8.电子产品\n9.智能推荐     10.全部商品\n");
	printf("11.搜索\n");
	printf("--------------------------------------------\n");
	printf("请输入你的选择,对应选项前面的序号:");
	scanf("%d",&a);
	switch(a)
	{
		case 1:
			printf("商品名称\t商品序号\t商品种类\t商品数目\t商品价格\n");	
			for(i = 0;i<2000;i++)
			{
				if(strcmp(items[i].kind,"生活用品") == 0)
				printf("%5d\t       %5d\t        %s\t%5d\t     %10.2lf\n",items[i].name,items[i].consequence,items[i].kind,items[i].num,items[i].price);
			}
			break;
		case 2:
			printf("商品名称\t商品序号\t商品种类\t商品数目\t商品价格\n");	
				for(i=0;i<2000;i++)
				{
						if(strcmp(items[i].kind,"学习用品") == 0)
						printf("%5d\t       %5d\t        %s\t%5d\t     %10.2lf\n",items[i].name,items[i].consequence,items[i].kind,items[i].num,items[i].price);
				}
			break;
		case 3:
		
			printf("商品名称\t商品序号\t商品种类\t商品数目\t商品价格\n");	
				for(i=0;i<2000;i++)
				{
					if(strcmp(items[i].kind,"衣服装饰") == 0)
			printf("%5d\t       %5d\t        %s\t%5d\t     %10.2lf\n",items[i].name,items[i].consequence,items[i].kind,items[i].num,items[i].price);
				}
			break;
		case 4:
		
			printf("商品名称\t商品序号\t商品种类\t商品数目\t商品价格\n");	
				for(i=0;i<2000;i++)
				{
					if(strcmp(items[i].kind,"运动产品") == 0)
				printf("%5d\t       %5d\t        %s\t%5d\t     %10.2lf\n",items[i].name,items[i].consequence,items[i].kind,items[i].num,items[i].price);
				}
			break;
		case 5:
				printf("商品名称\t商品序号\t商品种类\t商品数目\t商品价格\n");	
				for(i=0;i<2000;i++)
				{
					if(strcmp(items[i].kind,"居家生活") == 0)
			printf("%5d\t       %5d\t        %s\t%5d\t     %10.2lf\n",items[i].name,items[i].consequence,items[i].kind,items[i].num,items[i].price);
				}
			break;
		case 6:
			printf("商品名称\t商品序号\t商品种类\t商品数目\t商品价格\n");	
				for(i=0;i<2000;i++)
				{
					if(strcmp(items[i].kind,"食用产品") == 0)
			printf("%5d\t       %5d\t        %s\t%5d\t     %10.2lf\n",items[i].name,items[i].consequence,items[i].kind,items[i].num,items[i].price);
				}
			break;
		case 7:
				printf("商品名称\t商品序号\t商品种类\t商品数目\t商品价格\n");	
					for(i=0;i<2000;i++)
					{
						if(strcmp(items[i].kind,"饮用产品") == 0)
			printf("%5d\t       %5d\t        %s\t%5d\t     %10.2lf\n",items[i].name,items[i].consequence,items[i].kind,items[i].num,items[i].price);
					}
			break;
		case 8:
				printf("商品名称\t商品序号\t商品种类\t商品数目\t商品价格\n");	
					for(i=0;i<2000;i++)
					{
						if(strcmp(items[i].kind,"电子产品") == 0)
				printf("%5d\t       %5d\t        %s\t%5d\t     %10.2lf\n",items[i].name,items[i].consequence,items[i].kind,items[i].num,items[i].price);
					}
			break;
		case 9:
				printf("商品名称\t商品序号\t商品种类\t商品数目\t商品价格\n");	
				for(i = 0;i<2000;i++)
				{
					if(strcmp(items[i].kind,"智能推荐") == 0)
				printf("%5d\t       %5d\t        %s\t%5d\t     %10.2lf\n",items[i].name,items[i].consequence,items[i].kind,items[i].num,items[i].price);
				}
			break;
		case 10:
			printf("商品名称\t商品序号\t商品种类\t商品数目\t商品价格\n");	
				for(i=0;i<2000;i++)
				{
					if(items[i].name<1000 &&items[i].name>0)
				printf("%5d\t       %5d\t        %s\t%5d\t     %10.2lf\n",items[i].name,items[i].consequence,items[i].kind,items[i].num,items[i].price);
				}
				break;
		case 11:
			printf("1.按类别搜索\n2.按商品名称搜索\n");
			printf("请输入你的选择（对应选项前面的序号）:");
			scanf("%d",&c);
			if(c == 1)
			{
				printf("请输入你想要浏览的商品类别！");
				gets(ch);
				printf("商品名称\t商品序号\t商品种类\t商品数目\t商品价格\n");	
				for(i = 0 ;i<2000;i++)
				{
					if(strcmp(items[i].kind,ch) == 0)
					{		
					printf("%5d\t       %5d\t        %s\t%5d\t     %10.2lf\n",items[i].name,items[i].consequence,items[i].kind,items[i].num,items[i].price);
					}
				}
			}
			else if(c == 2)
			{
					printf("请输入你想要浏览的商品类别！");
					scanf("%d",&b);
						printf("商品名称\t商品序号\t商品种类\t商品数目\t商品价格\n");
					for(i = 0;i<2000;i++)
					{
						if(items[i].consequence == b)
							{
										
									printf("%5d\t       %5d\t        %s\t%5d\t     %10.2lf\n",items[i].name,items[i].consequence,items[i].kind,items[i].num,items[i].price);
							}
					}
			}
				break;
		default:
			printf("错误！输入不合法");
	}
	printf("....................................................................\n");
	printf("温馨提示:\n         1.商品浏览过程中，您可以把喜欢的商品加入到你的购物车。\n");
	printf("         2.若不是我们的用户，请先注册账户才可以添加物品到购物车。\n");
	printf("         3.浏览完商品后，可进入购物车查看你的已经添加的商品。\n");
	printf("         4.选择购物车中你想要购买的商品，然后进行在线付款。\n");
	printf("         5.完成购物。\n");
	printf("....................................................................\n");
	printf("如果你喜欢任何商品你可以把它加入你的购物车\n");
	printf("1.添加物品到你的购物车\n2.继续浏览商品\n");
	printf("3.返回上级选择菜单\n4.离开这个应用\n");
	printf("....................................................................\n");
	printf("请输入你的选择（相应选项前面的序号）\n");
	scanf("%d",&m);
		if(m == 1)
		{
			k = 0;
			printf("如果你是一个游客请你先注册一个用户\n ");
			printf("请输入你的账户手机号，我们会验证你是否为我们的用户！n");
			scanf("%s",ph);
			while(k<200)
			{
			
			if(strcmp(reg[k].phone,ph) == 0)//通过验证手机号来判断是否为已注册用户。
			{
				printf("你已经注册!\n\n\n\n\n\n\n");
				break;
			}
				k++;
			}
			if(k == 200)
			{
				printf("请进入注册界面进行注册！返回选择菜单！");
				return 0;
			}
			shop_trolley(ph); 
		}
		else if(m == 2)
				browse_merchandise();
		else if(m == 3)
				return 0;
		else if(m == 4)
				leave();
		return 0;
}
int shop_trolley(char ph[])//购物车信息管理
{
	int n,i=0,m=0,b[20],j = 0,e,h,k,r=0,f,count=0,q=0;
	double sum=0;
	char c;
	FILE *fp;
	while(strcmp(reg[m].phone,ph))
	{
		m++;
		if(m == 200)
			break;
	}
		if(m == 200)
		{
			printf("未找到你的手机号，您的输入有误！");
			leave();
		}
	while(reg[m].order[q]>0 && reg[m].order[q]<2000)
	{
		q++;
	}
	while(reg[m].buycar[i]>0 && reg[m].buycar[i]<2000 )
	{
		i++;
	}
	while(r<20)
	{
		b[r] = 0;
		r++;
	}
	do{
		printf(".........................\n");
		printf("1.添加物品到购物车\n2.查看购物车中商品\n3.选择购物车中商品结账\n4.删除购物车中的物品\n5.退出应用!\n");
		printf(".........................\n");
			printf("请输入你的选择！");
			scanf("%d",&n);
		if(n == 1)//添加物品到购物车
			{
		
				do{
						printf("(请输入你想要加入购物车的商品序号)!");
						scanf("%d",&reg[m].buycar[i]);
						printf("添加成功！\n");

						printf("(如果你想要再次添加物品到你的购物车，请输入'Y/y',否则输入'N/n'):\n");
						scanf("\n");
						c = getchar();
						i++;
						if(i == 100)
						{
										printf("(你的购物车已满，你不能再向你的购物车添加任何商品)!");
										break;
						}
					}while(c == 'y' || c =='Y');
					for(i = 0;reg[m].buycar[i]>0 && reg[m].buycar[i]<2000;i++)
			{
					if((fp = fopen("car.txt","w")) == NULL)
				{
				printf("文件打开失败！\n");
				leave();
				}
				fscanf(fp,"%4d",&reg[m].buycar[i]);
				fclose(fp);
			}
			}
		else if(n == 2)//查看购物车中的商品
		{
			printf("这是你购物车中的所有商品！\n");
			printf("商品名称\t商品序号\t商品种类\t商品数目\t商品价格\n");		
			for(j = 0;reg[m].buycar[j]>0 && reg[m].buycar[j]<2000;j++)
			{
				h = reg[m].buycar[j];
				if(reg[m].buycar[j-1] == reg[m].buycar[j])
					break;
				printf("%5d\t       %5d\t        %s\t%5d\t     %10.2lf\n",items[h-1].name,items[h-1].consequence,items[h-1].kind,items[h-1].num,items[h-1].price);
			}
		}
		else if(n == 3)//商品在线支付，生成订单信息。
		{
			j=0;
			do{
				printf("请输入你想要购买的物品名称!\n");
				scanf("%d",&b[j]);
				printf("1.继续选择要购买的商品,请输入'Y/y',\n2.选择完毕，进行支付！请输入'N/n'\n");
				getchar();
				c = getchar();
				if(c == 'n' || c == 'N')
					break;
				j++;
			}while(c == 'Y' || c == 'y');
			printf("这是您要购买的物品:\n");
			printf("商品名称\t商品序号\t商品种类\t商品数目\t商品价格\n");
			for(j = 0;b[j]>0 && b[j]<=2000;j++)
			{
				e = b[j]-1;	
				count++;
				sum+=items[e].price;
				printf("%5d\t       %5d\t        %s\t%5d\t     %10.2lf\n",items[e].name,items[e].consequence,items[e].kind,items[e].num,items[e].price);
			}
			printf("总共购买%d件商品\n总价钱为%.2lf元!\n",count,sum);
			printf("输入1，确认支付，输入其他数字退出支付");
			scanf("%d",&f);
			if(f == 1)
			{
					for(j = 0;b[j]>0 && b[j]<=2000;j++,q++)
						{
						e = b[j]-1;	//购买的商品在数组中的下标
						reg[m].order[q] = b[j];//生成订单信息，存储到用户的账号里。
						items[e].num-=1;//用户购买的商品，在库存中减去相应的数目
						}
					printf("\n恭喜你支付成功，请等待快递小哥联系你取货！\n");
			}
		}
		else if(n == 4)//删除购物车中不需要的商品
		{
			do{
			printf("请输入你要删除的商品名称\n");
			scanf("%d",&r);
			for(k = 0;k<100;k++)
			{
				if(reg[m].buycar[k] == r)
				{
					do{
						if(reg[m].buycar[k+1]<2000 && reg[m].buycar[k+1]>0)
						reg[m].buycar[k] = reg[m].buycar[k+1] ;
						k++;
						}while(k<99 || (reg[m].buycar[k+1]<2000 && reg[m].buycar[k+1]>0));
					break;
				}
			}
			printf("如果你想要继续删除购物车中的商品请输入'Y/y',否则输入'N/n'");
			getchar();
			c =getchar();
			}while(c == 'Y' || c == 'y');
		}
		else if(n == 5)//退出应用。
			leave();
		printf("返回上一级菜单,请输入6!输入其他任意数字退出该界面!");
		scanf("%d",&n);
		}while(n == 6);	
	return 0;
}
void manage_user_information()//用户信息管理
{
	FILE *fp1,*fp;
	int a,m=0,e,i;
	char ph[12],c;
		while(reg[m].phone[0] =='1')
		{
			m++;
		}
		if(m==200)
		{
			printf("wrong!\n");
			leave();
		}
			
	for(i = 0;reg[m].buycar[i]>0 && reg[m].buycar[i]<2000;i++)
			{
			if((fp1 = fopen("car.txt","r")) == NULL)
			{
				printf("文件打开失败！\n");
				leave();
			}
			fscanf(fp1,"%4d",&reg[m].buycar[i]);
			fclose(fp1);
			}
	do{
		printf("............................................\n");
		printf("1.查看所有用户信息\n2.修改用户信息\n");
		printf("3.搜索用户信息\n4.保存入文档\n");
		printf(".............................................\n");
		printf("请输入你的选择(对应选项前面的序号):");
		scanf("%d",&a);
		if(a ==1)//打印所有用户信息
		{
			for(m = 0;reg[m].phone[0] =='1';m++)
			{
				printf("第%d位用户信息！\n",m+1);
				printf("用户名:%s\n",reg[m].name);
				printf("用户账号密码:%s\n",reg[m].password);
				printf("用户性别:%s\n",reg[m].sex);
				printf("用户手机号:%s\n",reg[m].phone);
				printf("用户私人邮箱:%s\n",reg[m].mail);
				printf("------------------------------------------------------------------\n");
				printf("此用户的购物车商品如下:\n");
				printf("商品名称\t商品序号\t商品类别\t商品数目\t商品价格\n");
				for(i=0;reg[m].buycar[i]>0 && reg[m].buycar[i]<1000;i++)
				{
					e =reg[m].buycar[i]-1;//商品在数组存储中的下标
					printf("%5d\t       %5d\t        %s\t%5d\t     %10.2lf\n",items[e].name,items[e].consequence,items[e].kind,items[e].num,items[e].price);
				}
					printf("------------------------------------------------------------------\n");
			}
		}
		else if(a == 2)//修改用户信息
		{
			do{
					printf("若你想修改用户的信息，请输入该用户的手机号，来验证该用户是否存在\n");
					scanf("%s",ph);
				for(m=0;m<200;m++)
				{
				if(strcmp(reg[m].phone,ph)==0)
					{
					printf("验证成功！\n");
					modify_information(m);
					break;
					}
				}
				printf("修改其他用户信息请输入'Y/y'，否则输入‘N/n’");
				scanf("%c",&c);
			}while(c == 'Y' || c =='y');
		}
		else if(a ==3)//通过用户手机号，搜索用户信息。
		{
			do{
			printf("请输入你想要搜索的用户的手机号：");
			scanf("%s",ph);
			for(m=0;m<200;m++)
				{
					if(strcmp(reg[m].phone,ph)==0)
						{
						printf("搜索成功！\n");
						printf("第%d位用户信息！\n",m+1);
						printf("用户名:%s\n",reg[m].name);
						printf("用户账号密码%s\n",reg[m].password);
						printf("用户性别%s\n",reg[m].sex);
						printf("用户手机号：%s\n",reg[m].phone);
						printf("用户私人邮箱：%s\n",reg[m].mail);
						printf("此用户的购物车商品如下:\n");
						printf("商品名称\t商品序号\t商品类别\t商品数目\t商品价格\n");
							for(i=0;reg[m].buycar[i]>0 && reg[m].buycar[i]<2000;i++)
								{
									e =reg[m].buycar[i]-1;//商品在数组存储中的下标。
									printf("%5d\t       %5d\t        %s\t%5d\t     %10.2lf\n",items[e].name,items[e].consequence,items[e].kind,items[e].num,items[e].price);
								}
							break;
						}
				}
			if(m == 200)
			{
				printf("你输入的手机号有误\n");
				leave();
			}
			printf("若要继续搜索其他用户信息，请输入‘y/Y’，否则输入‘N/n’\n");
			c = getchar();
			}while(c == 'y' || c == 'Y');
		}
			else if(a == 4)//将所有的用户信息存入文档保存。
			{
				m=0;
				if((fp = fopen("guke.txt","w")) == NULL)
				{
					printf("文件打开错误！\n");
					exit(0);
				} 
				for(m=0;reg[m].phone[0] =='1';m++)
				{
				fprintf(fp,"%12s%14s%8s%12s%20sn",reg[m].name,reg[m].password,reg[m].sex,reg[m].phone,reg[m].mail);
				}
				fclose(fp);
			}
			printf("返回上一个界面请输入：5，\n输入其他任意数字退出该界面");
			scanf("%d",&a);
	}while(a == 5);
}
void manage_goods_kinds()//商品类别管理
{
	char c;
	int i,n;
	strcpy(wk[0],"生活用品");
	strcpy(wk[1],"学习用品");
	strcpy(wk[2],"衣服装饰");
	strcpy(wk[3],"运动产品");
	strcpy(wk[4],"居家生活");
	strcpy(wk[5],"食用产品");
	strcpy(wk[6],"饮用产品");
	strcpy(wk[7],"电子产品");
	if(kindb == 0)
	n = 8;
	else 
		n =kindb;
	printf("目前已有的商品类别有：\n");
	for(i =0;i<n;i++)
	{
		printf("\t\t\t%s\n",wk[i]);
	}
	printf("增加商品类别，请输入'Y/y',否则输入‘N/n’\n");
	scanf(" %c",&c);
	getchar();
	if(c == 'Y' || c == 'y')
	{
		do{
		printf("请输入你要新增加的商品类别:");
	
		gets(wk[i]);
		n++;
		i++;
		printf("添加成功！继续添加，请输入'Y/y',否则输入‘N/n’\n");
		scanf(" %c",&c);
		}while(c == 'Y' || c == 'y');
	}
	kindb = n;
}
void manage_order()//订单信息管理
{
	int a,m,i,e,b,sum = 0,sn=0,order[8000];
	double in=0,si=0;
	char ph[12];
	FILE *fp,*fp1;
	do{
	printf("------------------------------------------\n");
	printf("1.查看系统全部订单\n2.搜索某位用户的订单信息\n");
	printf("3.搜索某件商品的销量\n4.查看所有订单的收入和销售的商品总数\n");
	printf("5.保存所有订单信息到文件中\n");
	printf("------------------------------------------\n");
	printf("请输入你的选择（输入对应选项前面的序号）：");
	scanf("%d",&a);
	if(a == 1)
	{
		printf("所有订单：\n");
		printf("----------------------------------------------------------------------\n");
		printf("商品名称\t商品序号\t商品类别\t商品数目\t商品价格\n");
		if(reg[0].order[0]>0 && reg[0].order[0]<2000)
		{
		for(m = 0 ;reg[m].phone[0]=='1';m++)
		{
			for(i = 0;reg[m].order[i]>0 && reg[m].order[i]<2000;i++)
			{
				e = reg[m].order[i]-1;			
				printf("%5d\t       %5d\t        %s\t%5d\t     %10.2lf\n",items[e].name,items[e].consequence,items[e].kind,items[e].num,items[e].price);
			}
		}
		}
		else
		{
			if((fp1 = fopen("order.txt","r")) == NULL)
			{
				printf("wrong!\n");
				leave();
			}
			for(i=0;!feof(fp1);i++)
			{
				fscanf(fp1,"%4d",&order[i]);
			}
			for(i=0;order[i]<2000 && order[i]>=0;i++)
			{
				e = order[i];
				printf("%5d\t       %5d\t        %s\t%5d\t     %10.2lf\n",items[e].name,items[e].consequence,items[e].kind,items[e].num,items[e].price);
			}
		}
	}
	else if(a ==2)
	{
		printf("请输入你想要查找用户的手机号");
		getchar();
		gets(ph);
		for(m = 0 ;reg[m].phone[0]=='1';m++)
		{
		if(strcmp(reg[m].phone,ph) == 0)
		{
			printf("搜索成功!\n");
			printf("%s的订单信息：\n",reg[m].name);
				printf("商品名称\t商品序号\t商品类别\t商品数目\t商品价格\n");
				for(i = 0;reg[m].order[i]>0 && reg[m].order[i]<1000;i++)
					{
						e = reg[m].order[i]-1;			
						printf("%5d\t       %5d\t        %s\t%5d\t     %10.2lf\n",items[e].name,items[e].consequence,items[e].kind,items[e].num,items[e].price);
					}
				break;
		}

		}
		if(m == 200)
			printf("搜索失败，您输入的手机号有误！\n");

	}
	else if(a == 3)//查看某件商品销量。
	{
		printf("请输入您要了解的商品的名称，来查看该商品的销量！");
		scanf("%d",&b);
			for(m = 0 ;reg[m].phone[0]!='1';m++)
		{
			for(i = 0;reg[m].order[i]>0 && reg[m].order[i]<2000;i++)
			{
					e = reg[m].order[i];
					if(e == b)
					{
						sum++;
					in += items[e-1].price;
					}
			}
		}
			printf("已卖出%d件\n总销售额%.2lf元\n",sum,in);
	}
	else if(a == 4)
	{
			for(m = 0 ;reg[m].phone[0]!='1';m++)
				{
					for(i = 0;reg[m].order[i]>0 && reg[m].order[i]<1000;i++)
						{
							e = reg[m].order[i]-1;
							sn++;
							si += items[e].price;
						}
				}	
			printf("截止目前，平台总共卖出%d件商品\n总销售额%.2lf元!\n",sn,si);	
	}
	else if(a == 5)
	{
		if((fp = fopen("order.txt","w")) == NULL)
				{
					printf("Wrong !\n");
					exit(0);
				} 
				for(m = 0 ;reg[m].phone[0] =='1';m++)
				{
					for(i = 0;reg[m].order[i]>0 && reg[m].order[i]<2000;i++)
					{
						e = reg[m].order[i]-1;
						fprintf(fp,"%4d",e);
					}
				}
				fclose(fp);
	}
	printf("返回上一页菜单输入6！输入其他任意数字退出该界面");
	scanf("%d",&a);
	}while(a==6);
}
void manage_ware_message()//商品信息管理
{
	FILE *fp;
	int a,i=0,j,b,k,s=0,h;
	char c;
	do{
	printf("....................................................\n");
	printf("1.添加商品信息\n2.删除商品信息\n");
	printf("3.查看所有商品信息\n");
	printf("4.保存所用商品信息到文件中\n5.修改商品信息\n");
	printf("....................................................\n");
	printf("请输入你的选择（输入对应选项前面的序号）:");
	scanf("%d",&a);
	if(a ==1)//添加商品信息
	{
		do{
		while(items[i].consequence<2000 && items[i].consequence>0)
		{
			i++;
		}
			printf("请输入新的商品名称(建议输入%d!):",i+1);
			scanf("%d",&items[i].name);
			for(j =0 ;j<i;j++)
			{
				if(items[i].name == items[j].name )
				{
					printf("你输入的商品名已存在！系统错误，退出应用！\n");
					leave();
				}
			}
			items[i].consequence = i+1;
			printf("请输入商品类别:");
			getchar();
			gets(items[i].kind);
			printf("请输入商品库存量:");
			scanf("%d",&items[i].num);
			printf("请输入商品单价:");
			scanf("%lf",&items[i].price);
			printf("添加成功！继续添加请输入'Y/y'，否则输入'N/n'");
			scanf(" %c",&c);
		}while(c == 'Y' || c == 'y');
	}
	else if(a == 2)//删除商品信息
	{
		do{
		printf("请输入你要删除的商品的序号");
		scanf("%d",&b);
		for(k = 0;k<2000;k++)
		{
			if(items[k].consequence == b)
			{
				do{
					if(items[k+1].consequence>0 && items[k+1].consequence<2000 )
					items[k] = items[k+1];
					}while(k<1999);
				break;
			}
		}
		if(k<2000)
			printf("删除成功！继续添加请输入'Y/y'，否则输入'N/n'");
		else 
			printf("您的输入有误！系统未找到你要删除的商品");
		scanf("%c",&c);
		}while(c == 'Y' || c == 'y');
	}
	else if(a == 3)//查看所有商品
	{
		printf("系统中的所有商品:\n");
		printf(".................................................\n");
		printf("商品名称\t商品序号\t商品类别\t商品数目\t商品价格\n");
		for(j = 0;items[j].consequence>0 && items[j].consequence<2000;j++)
		{
				printf("%5d\t       %5d\t        %s\t%5d\t     %10.2lf\n",items[j].name,items[j].consequence,items[j].kind,items[j].num,items[j].price);
			s++;
		}
		printf("共计%d件商品!\n",s);
	}
	else if(a == 4)
	{
	if((fp = fopen("things.txt","w")) == NULL)
				{
					printf("Wrong !\n");
					exit(0);
				} 
				for(j = 0;items[j].consequence>0 && items[j].consequence<2000;j++)
				{
				fprintf(fp,"%5d\t       %5d\t        %s\t%5d\t     %10.2lf\n",items[j].name,items[j].consequence,items[j].kind,items[j].num,items[j].price);
				}
				fclose(fp);
	}
	else if(a == 5)
	{
		printf("请输入你要修改商品的序号：");
		scanf("%d",&j);
		printf("1.商品名称\n2.商品序号\n3.商品类别\n");
		printf("4.商品数目\n5.商品价格\n");
		printf("请输入你要修改的选项（输入对应选项前面的数字！）:");
			scanf("%d",&b);
		switch(b)
		{
		case 1:
			printf("请输入新的商品名称:\n");
			scanf("%d",&items[j-1].name);
			break;
			case 2:
			printf("请输入新的商品序号:\n");
			scanf("%d",&items[j-1].consequence);
			break;
			case 3:
			printf("请输入新的商品类别:\n");
			scanf("%s",items[j-1].kind);
			break;
			case 4:
			printf("请输入新的商品数目:\n");
			scanf("%d",&items[j-1].num);
			break;
			case 5:
			printf("请输入新的商品价格（保留小数点后两位）:\n");
			scanf("%lf",&items[j-1].price );
			break;
		default:
			printf("Wrong!\n");
		}
	}
	printf("返回上一页菜单，请输入7！输入其他任意数字退出该界面！");
	scanf("%d",&a);
	}while(a == 6);
}
void line(int a)//排序函数a代表排序的选项
{
	 ware t;
	 int i,j,k;
	if(a == 1)
	{
		for(i=0;items[i].consequence >0 && items[i].consequence <1000;i++)
		{
			k = i;
			if(items[i+2].consequence <0 || items[i+2].consequence >1000)//判断是否到了后面的空数组
				break;
				for(j=i+1;items[j].consequence >0 && items[j].consequence <1000;j++)
				{
					if(items[k].name>items[j].name)
						k = j;
				}
				if(k!=i)
				{
					t = items[k];
					items[k] = items[i];
					items[i] = t;
				}
		}
	}
	if(a == 2)
		{
		for(i=0;items[i].consequence >0 && items[i].consequence <1000;i++)
		{
			k = i;
			if(items[i+2].consequence <0 || items[i+2].consequence >1000)//判断是否到了后面的空数组
				break;
				for(j=i+1;items[j].consequence >0 && items[j].consequence <1000;j++)
				{
					if(items[k].name<items[j].name)
						k = j;
				}
				if(k!=i)
				{
					t = items[k];
					items[k] = items[i];
					items[i] = t;
				}
		}
	}
	else if(a ==3)
			{
		for(i=0;items[i].consequence >0 && items[i].consequence <1000;i++)
		{
			k = i;
			if(items[i+2].consequence <0 || items[i+2].consequence >1000)//判断是否到了后面的空数组
				break;
				for(j=i+1;items[j].consequence >0 && items[j].consequence <1000;j++)
				{
					if(items[k].price>items[j].price)
						k = j;
				}
				if(k!=i)
				{
					t = items[k];
					items[k] = items[i];
					items[i] = t;
				}
		}
	}
		else if(a ==4)
			{
		for(i=0;items[i].consequence >0 && items[i].consequence <1000;i++)
		{
			k = i;
			if(items[i+2].consequence <0 || items[i+2].consequence >1000)//判断是否到了后面的空数组
				break;
				for(j=i+1;items[j].consequence >0 && items[j].consequence <1000;j++)
				{
					if(items[k].price<items[j].price)
						k = j;
				}
				if(k!=i)
				{
					t = items[k];
					items[k] = items[i];
					items[i] = t;
				}
		}
	}

}
void leave()//结束界面
{
 printf("    |\\　　　  ／|\n   /  |     ∠   /　\n  │  | ＿, ＜  ／　　 /`\n  /　　　　　ヽ　　/  /　\n Y　　　　　   `　 /  /\nｲ●　､　●　　⊂⊃〈 〈  /\n()　 へ　　　　|　＼ /\n　>ｰ ､_　 ィ　 ) ／／\n / へ　　 /　ﾉ  ＼＼\nヽ_ﾉ　　(_／　 │／／\n　7　　　　　　|／\n　＞―r ￣`ｰ―＿/\n");

	printf(" JD皮卡丘超市         \n");

	printf(" 欢迎下次光临!");


	exit(0);
}


