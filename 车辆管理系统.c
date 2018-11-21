#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct person                               //定义结构体
{
    char num[10];   //型号
    char name[15];  //品牌
    char changjia[10];   //厂家
    char jiage[10];      //价格
    char lianxi[10];     //联系人
}person;
person per[100];  //定义100
char filename[20];                                  //定义全局变量
  logon()                                            //登陆函数
{
 printf("\n\n\n\t\t  车辆信息管理系统\n\n");
 printf("                    2018年1月5日\n\n");

 system("pause");
}
int menu_filename()
   {
      system("cls");
      printf("请输入一个文件名:");
      scanf("\t%s",filename);
    }

int menu_select()                              //菜单选择系统函数//
{
     char c;
      do{
        system("cls");
        printf("\t\t         车辆信息管理系统         \n");
        printf ("\t\t---------------------------------\n");
        printf("\t\t    1. 添加记录    2. 显示记录 \n");
        printf ("\t\t---------------------------------\n");
        printf("\t\t    3. 信息查询    4.修改记录 \n");
        printf ("\t\t---------------------------------\n");
        printf("\t\t    5. 删除记录    0. 退出程序 \n");
        printf ("\t\t---------------------------------\n");
        printf("\t\t请选择输入(0—5):");
        c=getchar();
     }while(c<'0'||c>'6');
        return (c-'0');                                      //字符减去’0‘得到的是数字整型//
}



void add()                             //信息添加函数//
  {
    FILE *fp;              //定义一个指向文件流的指针通过操作这个指针进行文件读写打开关闭//
    int i=0,n=0;
    char sign='y';                              //首先定义sign='y'//
    system("cls");                                //清屏函数  系统中调用//
    while(sign!='n'&&sign!='N')                    //其实只有当输入N或n时才跳出循环//
      {
        printf("             ----车辆信息添加----\n");
        printf("型号：\n");
        scanf("\t%s",per[i].num);
        printf("品牌:\n");
        scanf("\t%s",per[i].name);
        printf("厂家：\n");
        scanf("\t%s",&per[i].changjia);
        printf("价格：\n");
        scanf("\t%s",&per[i].jiage);
        printf("联系人：\n");
        scanf("\t%s",&per[i].lianxi);
        printf("是否继续添加?(y/n)");
        scanf("\t%c",&sign);
        i++;
        n=n+1;
        system( "cls ");
   }system("pause");                                     //等待命令//

   if((fp=fopen(filename,"a"))==NULL)                    //以2进制形式进行文件尾追加//
      {
         printf("cannot open the files\n");
         system("pause");
         return;                                         //如果文件出现错误就返回//
       }
        for(i=0;i<n;i++)
        if(fwrite(&per[i],sizeof(person),1,fp)!=1)      //以2进制形式写入文件中一次写入一个数组//
        printf("file write error\n");
        fclose(fp);                                       //关闭文件//
        system("pasue");
  }

  void scan()                        //显示记录函数//
   {
    void amend();                         //声明修改函数//
    char sign='y';
    FILE *fp;
    int i=0,n;
    system("cls");
      if((fp=fopen(filename,"r"))==NULL)             //以2进制方式读取文件信息//
      {
         printf("cannot open the files\n");
         system("pause");
         return;
       }
    while(!feof(fp))                              //一直读取知道文件尾结束//
    {
        fread(&per[i],sizeof(person),1,fp);     //以2进制方式将文件信息读到数组内存中一次读取一个//
         i++;
     }
    fclose(fp);                                         //现在把fp指向的文件夹关闭此后fp不再指向该文件夹//
     printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
     printf("      型号     品牌    厂家   价格   联系人\n");
     printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
    for(n=0;n<i-1;n++)                             //循环全部输出
     printf("\t%s \t%s \t\t%s \t%s \t%s\n",per[n].num,per[n].name,per[n].changjia,per[n].jiage,per[n].lianxi);
     printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
     system("pause");
     system("cls");
     printf("是否需要修改?(y/n)");
     scanf("\t%c",&sign);
    if(sign!='n'&&sign!='N')                    //选择是否在浏览后进行修改//
     amend();
     system("pause");

  }


  void query()                        //数据查询函数//
   {
    FILE *fp;
    int i=0,n=0;
    int m;
    system("cls");
    printf("\t\n请选择查询方式:\n");
    printf ("\t-------------\n");

    printf("\t1------品牌 \n");
    printf("\t2------型号 \n");
    printf("\t3------返回 \n");
    printf("\t-------------\n");
    printf("请输入你要查询的方式\n");
    scanf("%d",&m);
    while(m!=1&&m!=2&&m!=3&&m!=4)
        {
            printf("输入错误请重新查询\n");
            scanf("%d",&m);
        }
      if((fp=fopen(filename,"r"))==NULL)                 //以2进制方式读取文件信息//
      {
         printf("cannot open the files\n");
         system("pause");
         return;
       }

    while(!feof(fp))     //没有到达末尾//
    {
        fread(&per[i],sizeof(person),1,fp);                      //以2进制方式将文件信息读到数组内存中一次读取一个//
        i++;n=n+1;
     }



    if(m==1)                                            //品牌查询//
       {
        char s[20];
        int i=0;
        printf("\t请输入想查询的品牌:");
        scanf("\t%s",s);
        while(strcmp(per[i].name,s)!=0&&i<n) i++;            //比较per[i].name与所输入姓名是否相同就是比较per这个数中是否有一个单元的number于s相同如果相同则结束循环否则一直循环到i=n此时跳出//
        if(i==n)
        {
            printf("\t数据库中没有此项!\n");
            system("pause");
            return;
        }
          printf("\t型号: %s\n",per[i].num);
          printf("\t品牌: %s\n",per[i].name);
          printf("\t厂家: %s\n",per[i].changjia);
          printf("\t价格: %s\n",per[i].jiage);
          printf("\t联系人: %s\n",per[i].lianxi);
         }
    if(m==2)                                                            //型号查询//
        {
          char s[15];
          int i=0;
          printf("请输入想查询的型号：");
          scanf("\t%s",s);
         while(strcmp(per[i].num,s)!=0&&i<n)i++;   //比较per[i].name与所输入型号是否相同比较per这个数组中是否有一个单元的number于s相同如果相同则结束循环，否则一直循环到i=n此时跳出//
            if(i==n)
            {
                printf("\t数据库中没有此项!\n");
                system("pause");
                return;
            }
            printf("\t型号: %s\n",per[i].num);
            printf("\t品牌: %s\n",per[i].name);
            printf("\t厂家: %s\n",per[i].changjia);
            printf("\t价格: %s\n",per[i].jiage);
            printf("\t联系人: %s\n",per[i].lianxi);
          }
          fclose(fp);
          system("pause");
  }


void amend()                      //信息修改函数//
  {
    FILE *fp;
    int i=0,n=0;
    char s[15];
    int m;
    system("cls");
    printf("\t\n请选择修改方式:\n");
    printf ("\t\t--------------\n");
    printf("\t1------品牌 \n");
    printf("\t2------型号 \n");
    printf("\t3------返回 \n");
    printf ("\t\t--------------\n");
    printf("请输入你要修改的方式\n");
    scanf("%d",&m);
    while(m!=1&&m!=2&&m!=3)  //m不等于1不等于2不等于3//
        {
            printf("输入错误请重新修改\n");
            scanf("%d",&m);
        }
     if((fp=fopen(filename,"r"))==NULL)     //打开文件名为filename的文件,根据fopen的返回值(fp),判断该文件是否打开//
      {
         printf("cannot open the files\n");
         system("pause");
         return;
       }
    while(!feof(fp))                       //当没有到文件尾就循环否则退出//
    {
        fread(&per[i],sizeof(person),1,fp);          //将文件信息读取到数组中//
        i++;n=n+1;
    }i=0;
    fclose(fp);
    system("cls");
  if(m==1)                   //按品牌修改//
    {
      char s[20];
      int i=0;
      printf("\t请输入想修改的品牌:");
      scanf("\t%s",s);
      while(strcmp(per[i].name,s)!=0&&i<n) i++;             //比较per[i].name与所输入型号是否相同比较per这个数组中是否有一个单元的number于s相同如果相同则结束循环，否则一直循环到i=n此时跳出//
        if(i==n)
         {
            printf("\t数据库中没有此项!\n");
            return;
         }
        else{
             printf("型号：\n");
             scanf("\t%s",per[i].num);
             printf("品牌:\n");
             scanf("\t%s",per[i].name);
             printf("厂家：\n");
             scanf("\t%s",&per[i].changjia);
             printf("价格：\n");
             scanf("\t%s",&per[i].jiage);
             printf("联系人：\n");
             scanf("\t%s",&per[i].lianxi);
          }
      }
    if(m==2)                        //按型号修改//
       {
        char s[15];
        int i=0;
        printf("请输入想修改的型号：");
        scanf("\t%s",s);
        while(strcmp(per[i].num,s)!=0&&i<n)i++;   //比较per[i].name与所输入型号是否相同比较per这个数组中是否有一个单元的number于s相同如果相同则结束循环，否则一直循环到i=n此时跳出//
           if(i==n)
            {
             printf("\t数据库中没有此项!\n");
             return;
            }
            else{
                 printf("型号：\n");
                 scanf("\t%s",per[i].num);
                 printf("品牌:\n");
                 scanf("\t%s",per[i].name);
                 printf("厂家：\n");
                 scanf("\t%s",&per[i].changjia);
                 printf("价格：\n");
                 scanf("\t%s",&per[i].jiage);
                 printf("联系人：\n");
                 scanf("\t%s",&per[i].lianxi);
                }
        }
     if((fp=fopen(filename,"w"))==NULL)                            //进行修改后将信息重新写入文件中//
          {
            printf("cannot open the files\n");
            return;
           }
        for(i=0;i<n-1;i++)
          if(fwrite(&per[i],sizeof(person),1,fp)!=1)               //以2进制方式将信息从内存中写入文件//
          printf("file write error\n");
          fclose(fp);
          printf("信息已经修改成功\n");
          system("pause");
}

                                //信息删除函数//
void delet()
  {
    FILE *fp;
    char s[10];
    int i=0,n=0;
      if((fp=fopen(filename,"r"))==NULL)                  //以2进制方式读取文件信息//
      {
         printf("cannot open the files\n");
         system("pause");
         return;
       }

    while(!feof(fp))               //当没有到文件尾就循环否则退出//
    {
      fread(&per[i],sizeof(person),1,fp);               //将文件信息读取到数组中//
      i++;n=n+1;
     }
    fclose(fp);
     if((fp=fopen(filename,"w"))==NULL)                 //以2进制写入方式打开文件//
      {
         printf("cannot open the files\n");
         system("pause");
         return;
       }
    printf("型号：");
    scanf("%s",s);
    for(i=0;i<n-1;i++)
     if(!(strcmp(per[i].num,s)==0))                    //找到与其匹配的信息进行操作如果条件符合就写入否者跳过这组数据此数据就是所需删除的//
      fwrite(&per[i],sizeof(person),1,fp)!=1;             //以2进制方式将信息从内存中写入文件//
     fclose(fp);
     printf("数据删除成功");
     system("pause");
}

                             //运用switch语句进行菜单选择//
  void main()
  {
      int n=0;
      logon();
      menu_filename();                                         //引用全局变量文件名//
      for(;;)                                                 //循环使用主界面直到遇到结束命令//
      {
          switch(menu_select())                               // 函数的调用//
          {
          case 1:
              printf("\t\t *^_^*记录添加 *^_^*\n");
              add();
              break;
          case 2:
              printf("\t\t *^_^*信息浏览 *^_^*\n");
              scan();
              break;
          case 3:
              printf("\t\t *^_^*信息查询 *^_^*\n");
              query();
              break;
          case 4:
            printf("\t\t *^_^*数据修改 *^_^*\n");
            amend();
              break;
          case 5:
              printf("\t\t *^_^*数据删除 *^_^*\n");
             delet();
              break;
          case 0:
                printf("\n\t\t谢谢使用\n");
                printf("\n\t\t");
                system("pause");
                exit(0);
          }
      }
      system("pause");
  }
