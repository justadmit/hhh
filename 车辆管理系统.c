#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct person                               //����ṹ��
{
    char num[10];   //�ͺ�
    char name[15];  //Ʒ��
    char changjia[10];   //����
    char jiage[10];      //�۸�
    char lianxi[10];     //��ϵ��
}person;
person per[100];  //����100
char filename[20];                                  //����ȫ�ֱ���
  logon()                                            //��½����
{
 printf("\n\n\n\t\t  ������Ϣ����ϵͳ\n\n");
 printf("                    2018��1��5��\n\n");

 system("pause");
}
int menu_filename()
   {
      system("cls");
      printf("������һ���ļ���:");
      scanf("\t%s",filename);
    }

int menu_select()                              //�˵�ѡ��ϵͳ����//
{
     char c;
      do{
        system("cls");
        printf("\t\t         ������Ϣ����ϵͳ         \n");
        printf ("\t\t---------------------------------\n");
        printf("\t\t    1. ��Ӽ�¼    2. ��ʾ��¼ \n");
        printf ("\t\t---------------------------------\n");
        printf("\t\t    3. ��Ϣ��ѯ    4.�޸ļ�¼ \n");
        printf ("\t\t---------------------------------\n");
        printf("\t\t    5. ɾ����¼    0. �˳����� \n");
        printf ("\t\t---------------------------------\n");
        printf("\t\t��ѡ������(0��5):");
        c=getchar();
     }while(c<'0'||c>'6');
        return (c-'0');                                      //�ַ���ȥ��0���õ�������������//
}



void add()                             //��Ϣ��Ӻ���//
  {
    FILE *fp;              //����һ��ָ���ļ�����ָ��ͨ���������ָ������ļ���д�򿪹ر�//
    int i=0,n=0;
    char sign='y';                              //���ȶ���sign='y'//
    system("cls");                                //��������  ϵͳ�е���//
    while(sign!='n'&&sign!='N')                    //��ʵֻ�е�����N��nʱ������ѭ��//
      {
        printf("             ----������Ϣ���----\n");
        printf("�ͺţ�\n");
        scanf("\t%s",per[i].num);
        printf("Ʒ��:\n");
        scanf("\t%s",per[i].name);
        printf("���ң�\n");
        scanf("\t%s",&per[i].changjia);
        printf("�۸�\n");
        scanf("\t%s",&per[i].jiage);
        printf("��ϵ�ˣ�\n");
        scanf("\t%s",&per[i].lianxi);
        printf("�Ƿ�������?(y/n)");
        scanf("\t%c",&sign);
        i++;
        n=n+1;
        system( "cls ");
   }system("pause");                                     //�ȴ�����//

   if((fp=fopen(filename,"a"))==NULL)                    //��2������ʽ�����ļ�β׷��//
      {
         printf("cannot open the files\n");
         system("pause");
         return;                                         //����ļ����ִ���ͷ���//
       }
        for(i=0;i<n;i++)
        if(fwrite(&per[i],sizeof(person),1,fp)!=1)      //��2������ʽд���ļ���һ��д��һ������//
        printf("file write error\n");
        fclose(fp);                                       //�ر��ļ�//
        system("pasue");
  }

  void scan()                        //��ʾ��¼����//
   {
    void amend();                         //�����޸ĺ���//
    char sign='y';
    FILE *fp;
    int i=0,n;
    system("cls");
      if((fp=fopen(filename,"r"))==NULL)             //��2���Ʒ�ʽ��ȡ�ļ���Ϣ//
      {
         printf("cannot open the files\n");
         system("pause");
         return;
       }
    while(!feof(fp))                              //һֱ��ȡ֪���ļ�β����//
    {
        fread(&per[i],sizeof(person),1,fp);     //��2���Ʒ�ʽ���ļ���Ϣ���������ڴ���һ�ζ�ȡһ��//
         i++;
     }
    fclose(fp);                                         //���ڰ�fpָ����ļ��йرմ˺�fp����ָ����ļ���//
     printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
     printf("      �ͺ�     Ʒ��    ����   �۸�   ��ϵ��\n");
     printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
    for(n=0;n<i-1;n++)                             //ѭ��ȫ�����
     printf("\t%s \t%s \t\t%s \t%s \t%s\n",per[n].num,per[n].name,per[n].changjia,per[n].jiage,per[n].lianxi);
     printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
     system("pause");
     system("cls");
     printf("�Ƿ���Ҫ�޸�?(y/n)");
     scanf("\t%c",&sign);
    if(sign!='n'&&sign!='N')                    //ѡ���Ƿ������������޸�//
     amend();
     system("pause");

  }


  void query()                        //���ݲ�ѯ����//
   {
    FILE *fp;
    int i=0,n=0;
    int m;
    system("cls");
    printf("\t\n��ѡ���ѯ��ʽ:\n");
    printf ("\t-------------\n");

    printf("\t1------Ʒ�� \n");
    printf("\t2------�ͺ� \n");
    printf("\t3------���� \n");
    printf("\t-------------\n");
    printf("��������Ҫ��ѯ�ķ�ʽ\n");
    scanf("%d",&m);
    while(m!=1&&m!=2&&m!=3&&m!=4)
        {
            printf("������������²�ѯ\n");
            scanf("%d",&m);
        }
      if((fp=fopen(filename,"r"))==NULL)                 //��2���Ʒ�ʽ��ȡ�ļ���Ϣ//
      {
         printf("cannot open the files\n");
         system("pause");
         return;
       }

    while(!feof(fp))     //û�е���ĩβ//
    {
        fread(&per[i],sizeof(person),1,fp);                      //��2���Ʒ�ʽ���ļ���Ϣ���������ڴ���һ�ζ�ȡһ��//
        i++;n=n+1;
     }



    if(m==1)                                            //Ʒ�Ʋ�ѯ//
       {
        char s[20];
        int i=0;
        printf("\t���������ѯ��Ʒ��:");
        scanf("\t%s",s);
        while(strcmp(per[i].name,s)!=0&&i<n) i++;            //�Ƚ�per[i].name�������������Ƿ���ͬ���ǱȽ�per��������Ƿ���һ����Ԫ��number��s��ͬ�����ͬ�����ѭ������һֱѭ����i=n��ʱ����//
        if(i==n)
        {
            printf("\t���ݿ���û�д���!\n");
            system("pause");
            return;
        }
          printf("\t�ͺ�: %s\n",per[i].num);
          printf("\tƷ��: %s\n",per[i].name);
          printf("\t����: %s\n",per[i].changjia);
          printf("\t�۸�: %s\n",per[i].jiage);
          printf("\t��ϵ��: %s\n",per[i].lianxi);
         }
    if(m==2)                                                            //�ͺŲ�ѯ//
        {
          char s[15];
          int i=0;
          printf("���������ѯ���ͺţ�");
          scanf("\t%s",s);
         while(strcmp(per[i].num,s)!=0&&i<n)i++;   //�Ƚ�per[i].name���������ͺ��Ƿ���ͬ�Ƚ�per����������Ƿ���һ����Ԫ��number��s��ͬ�����ͬ�����ѭ��������һֱѭ����i=n��ʱ����//
            if(i==n)
            {
                printf("\t���ݿ���û�д���!\n");
                system("pause");
                return;
            }
            printf("\t�ͺ�: %s\n",per[i].num);
            printf("\tƷ��: %s\n",per[i].name);
            printf("\t����: %s\n",per[i].changjia);
            printf("\t�۸�: %s\n",per[i].jiage);
            printf("\t��ϵ��: %s\n",per[i].lianxi);
          }
          fclose(fp);
          system("pause");
  }


void amend()                      //��Ϣ�޸ĺ���//
  {
    FILE *fp;
    int i=0,n=0;
    char s[15];
    int m;
    system("cls");
    printf("\t\n��ѡ���޸ķ�ʽ:\n");
    printf ("\t\t--------------\n");
    printf("\t1------Ʒ�� \n");
    printf("\t2------�ͺ� \n");
    printf("\t3------���� \n");
    printf ("\t\t--------------\n");
    printf("��������Ҫ�޸ĵķ�ʽ\n");
    scanf("%d",&m);
    while(m!=1&&m!=2&&m!=3)  //m������1������2������3//
        {
            printf("��������������޸�\n");
            scanf("%d",&m);
        }
     if((fp=fopen(filename,"r"))==NULL)     //���ļ���Ϊfilename���ļ�,����fopen�ķ���ֵ(fp),�жϸ��ļ��Ƿ��//
      {
         printf("cannot open the files\n");
         system("pause");
         return;
       }
    while(!feof(fp))                       //��û�е��ļ�β��ѭ�������˳�//
    {
        fread(&per[i],sizeof(person),1,fp);          //���ļ���Ϣ��ȡ��������//
        i++;n=n+1;
    }i=0;
    fclose(fp);
    system("cls");
  if(m==1)                   //��Ʒ���޸�//
    {
      char s[20];
      int i=0;
      printf("\t���������޸ĵ�Ʒ��:");
      scanf("\t%s",s);
      while(strcmp(per[i].name,s)!=0&&i<n) i++;             //�Ƚ�per[i].name���������ͺ��Ƿ���ͬ�Ƚ�per����������Ƿ���һ����Ԫ��number��s��ͬ�����ͬ�����ѭ��������һֱѭ����i=n��ʱ����//
        if(i==n)
         {
            printf("\t���ݿ���û�д���!\n");
            return;
         }
        else{
             printf("�ͺţ�\n");
             scanf("\t%s",per[i].num);
             printf("Ʒ��:\n");
             scanf("\t%s",per[i].name);
             printf("���ң�\n");
             scanf("\t%s",&per[i].changjia);
             printf("�۸�\n");
             scanf("\t%s",&per[i].jiage);
             printf("��ϵ�ˣ�\n");
             scanf("\t%s",&per[i].lianxi);
          }
      }
    if(m==2)                        //���ͺ��޸�//
       {
        char s[15];
        int i=0;
        printf("���������޸ĵ��ͺţ�");
        scanf("\t%s",s);
        while(strcmp(per[i].num,s)!=0&&i<n)i++;   //�Ƚ�per[i].name���������ͺ��Ƿ���ͬ�Ƚ�per����������Ƿ���һ����Ԫ��number��s��ͬ�����ͬ�����ѭ��������һֱѭ����i=n��ʱ����//
           if(i==n)
            {
             printf("\t���ݿ���û�д���!\n");
             return;
            }
            else{
                 printf("�ͺţ�\n");
                 scanf("\t%s",per[i].num);
                 printf("Ʒ��:\n");
                 scanf("\t%s",per[i].name);
                 printf("���ң�\n");
                 scanf("\t%s",&per[i].changjia);
                 printf("�۸�\n");
                 scanf("\t%s",&per[i].jiage);
                 printf("��ϵ�ˣ�\n");
                 scanf("\t%s",&per[i].lianxi);
                }
        }
     if((fp=fopen(filename,"w"))==NULL)                            //�����޸ĺ���Ϣ����д���ļ���//
          {
            printf("cannot open the files\n");
            return;
           }
        for(i=0;i<n-1;i++)
          if(fwrite(&per[i],sizeof(person),1,fp)!=1)               //��2���Ʒ�ʽ����Ϣ���ڴ���д���ļ�//
          printf("file write error\n");
          fclose(fp);
          printf("��Ϣ�Ѿ��޸ĳɹ�\n");
          system("pause");
}

                                //��Ϣɾ������//
void delet()
  {
    FILE *fp;
    char s[10];
    int i=0,n=0;
      if((fp=fopen(filename,"r"))==NULL)                  //��2���Ʒ�ʽ��ȡ�ļ���Ϣ//
      {
         printf("cannot open the files\n");
         system("pause");
         return;
       }

    while(!feof(fp))               //��û�е��ļ�β��ѭ�������˳�//
    {
      fread(&per[i],sizeof(person),1,fp);               //���ļ���Ϣ��ȡ��������//
      i++;n=n+1;
     }
    fclose(fp);
     if((fp=fopen(filename,"w"))==NULL)                 //��2����д�뷽ʽ���ļ�//
      {
         printf("cannot open the files\n");
         system("pause");
         return;
       }
    printf("�ͺţ�");
    scanf("%s",s);
    for(i=0;i<n-1;i++)
     if(!(strcmp(per[i].num,s)==0))                    //�ҵ�����ƥ�����Ϣ���в�������������Ͼ�д����������������ݴ����ݾ�������ɾ����//
      fwrite(&per[i],sizeof(person),1,fp)!=1;             //��2���Ʒ�ʽ����Ϣ���ڴ���д���ļ�//
     fclose(fp);
     printf("����ɾ���ɹ�");
     system("pause");
}

                             //����switch�����в˵�ѡ��//
  void main()
  {
      int n=0;
      logon();
      menu_filename();                                         //����ȫ�ֱ����ļ���//
      for(;;)                                                 //ѭ��ʹ��������ֱ��������������//
      {
          switch(menu_select())                               // �����ĵ���//
          {
          case 1:
              printf("\t\t *^_^*��¼��� *^_^*\n");
              add();
              break;
          case 2:
              printf("\t\t *^_^*��Ϣ��� *^_^*\n");
              scan();
              break;
          case 3:
              printf("\t\t *^_^*��Ϣ��ѯ *^_^*\n");
              query();
              break;
          case 4:
            printf("\t\t *^_^*�����޸� *^_^*\n");
            amend();
              break;
          case 5:
              printf("\t\t *^_^*����ɾ�� *^_^*\n");
             delet();
              break;
          case 0:
                printf("\n\t\tллʹ��\n");
                printf("\n\t\t");
                system("pause");
                exit(0);
          }
      }
      system("pause");
  }
