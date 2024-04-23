#include "sort.h"

int List1[1000000];  //声明全局变量数组
int List2[1000000];
int *Flist1,*Flist2,*Flist3;//1和2分别是完全随机和几乎有序的数组，3为对照数组
char* name[]={"Bubble","Selection","Insert","Merge","Quick","Shell"};
int* (*function[6])(int*,int)={Bubble,Selection,Insert,Merge,Quick,Shell};


int main()
{
    int number;
    int a;
    while(1)
    {
        system("cls");
        printf("本次待排序的数组长度：");
        scanf("%d",&number);
        if(number==0){break;}
        for(int i=1;i<6;i++)
        {
        srand(time(0));
        for(int j=0;j<number;j++)
        {
            a=rand();
            List1[j]=a;List2[j]=a;
        }
        Flist1=Cut(List1,number);
        Flist2=Cut(List1,number);
        Flist3=Cut(List2,number);
        Disor(Flist2,number);
        printf("（完全随机） %s 排序用时分别为：\n",name[i]);
        Count(function[i],Flist1,Flist3,number);
        printf("(几乎有序) %s 排序用时分别为：\n ",name[i]);
        Count(function[i],Flist2,Flist3,number);
        }
        system("pause");
    }

    return 0;
}