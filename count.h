#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>

typedef int*(*Func)(int*,int);

int cmp(const void *a, const void *b)//qsort的比较函数
{
	return *(int *)a - *(int *)b;//升序
}



int* Cut(int* l,int num)//将数组按指定长度切片
{
    int* a=(int*)malloc(num*sizeof(int));
    for(int i=0;i<num;i++)
    {
        a[i]=l[i];
    }
    return a;
}

int Check(int* l1,int* l2,int num)//数组比对函数
{
    for(int i=0;i<num;i++)
    {
        if(l1[i]!=l2[i]){return 0;}
    }
    return 1;
}

void Disor(int* list, int num) {
   
    int numToDisor = num / 100; // 只乱序约 10% 的元素
    if(num>=10000)
    {
        num/=10;
    }
    for (int i = 0; i < numToDisor; ++i) {
        int index1 = rand() % num;
        int index2 = rand() % num;

        int temp = list[index1];
        list[index1] = list[index2];
        list[index2] = temp;
    }
}







void Count(Func func,int* List1,int* List2,int num)//函数运行计时函数
{
    int flag;
    int* Oput,*Com;
    Com=List2;
    clock_t start,end;
    start=clock();
    Oput=func(List1,num);
    end=clock();
    qsort(Com,num,sizeof(List2[0]),cmp);
    flag=Check(Com,Oput,num);
    if(flag==0){printf("排序错误！\n\n");}
    else 
    {
        printf("排序正确！\n");
        printf("总用时为：%f\n\n",(double)(end-start)/CLK_TCK);
    }
}

