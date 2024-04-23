#include <stdio.h>
#include <time.h>

// 定义 Func 类型
typedef int* (*Func)(int*, int);

void Quicksort(int* l,int start,int end)
{
    int flag=0;//flag为0表示j递减，1表示i递增
    if(start>=end){return ;}
    int i=start,j=end;
    int basic=l[start];
    while(i<j)
    {
        if(flag==0&&l[j]<=basic)
        {
            l[i]=l[j];
            flag=1;
        }
        else if(flag==1&&l[i]>=basic)
        {
            l[j]=l[i];
            flag=0;
        }
        if(flag==0){j--;}
        else {i++;}
    }
    l[i]=basic;
    Quicksort(l,start,i);
    Quicksort(l,i+1,end);
}




int* Quick(int* list,int num)
{
    Quicksort(list,0,num-1);
    return list;
}


// Count 函数：用来计算某个函数运行的时间
long long int Count(Func func, int* List, int num) {
    int *Oput;
    long long int start, end;
    start = time(NULL);
    Oput = func(List, num);
    end = time(NULL);
    return end - start;
}

int main() {
    // 示例用法
    int Flist[] = {5,4,3,2,1,6,7};
    int number = 7;

    // 调用 Count 函数计算 Bubble 函数运行的时间
    long long int time_taken = Count(Quick, Flist, number);
    printf("函数运行时间：%lld 秒\n", time_taken);
    for(int i=0;i<number;i++)
    {
        printf("%d ",Flist[i]);
    }
    system("pause");
    return 0;
}
