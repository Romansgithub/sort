#include "count.h"

int* Bubble(int* list,int n)//冒泡排序
{
    int t;
    int flag;
    for(int i=0;i<n;i++)
    {
        flag=0;
        for(int j=n-1;j>i;j--)
        {
            if(list[j]<list[j-1])
            {
                t=list[j];list[j]=list[j-1];list[j-1]=t;
                flag=1;
            }
        }
        if(!flag){break;}
    }
    return list;
}

int* Selection(int* list,int num)//选择排序
{
    int k;
    int t;
    for(int i=0;i<num;i++)
    {
        k=i;
        for(int j=i+1;j<num;j++)
        {
            if(list[j]<list[k])
            {
                k=j;
            }
        }
    t=list[i];list[i]=list[k];list[k]=t;
    }
    return list;
}

int* Insert(int* list,int num)//插入排序
{
    int t;
    for(int i=1;i<num;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(list[i]<list[j])
            {
                t=list[i];
                for(int k=i;k>j;k--)
                {
                    list[k]=list[k-1];
                }
                list[j]=t;
            }
        }
    }
    return list;
}
int* Shell(int* list,int num )//希尔排序
{
    int h=1;
    while(h<num/3)
    {
        h=3*h+1;
    }
    int t;
    while(h>=1)
    {
        for(int i=h;i<num;i++)
        {
            int j;
            t=list[i];
            for(j=i;j>=h&&list[j-h]>t;j-=h)
            {
                list[j]=list[j-h];
            }
            list[j]=t;
        }
        h/=3;
    }
    return list;
}

void Mergesort(int* l,int start,int mid,int end)//归并排序1
{
    if(end-start==1){return l;}
    Mergesort(l,start,(start+mid)/2,mid);
    Mergesort(l,mid,(mid+end)/2,end);

    int *temp = (int *)malloc((end - start + 1) * sizeof(int));
    int i=start,j=mid,k=0;
    while(i<mid||j<end)
    {
        if(i==mid)
        {
            temp[k++]=l[j++];
        }
        else if(j==end)
        {
            temp[k++]=l[i++];
        }
        else{
            if(l[i]>l[j])
            {
                temp[k]=l[j];
                j++;k++;
            }
            else{
                temp[k]=l[i];
                i++;k++;
            }
        }


    }
    for(int x=start;x<end;x++)
    {
        l[x]=temp[x-start];
    }

}



int* Merge(int* list,int num)//归并排序2
{
    Mergesort(list,0,num/2,num);
    return list;
}


void Quicksort(int* l,int start,int end)
{
    int flag=0;//flag为0表示j递减，1表示i递增
    if(start>=end){return ;}
    int i=start,j=end;
    int basic=l[start];
    while(i<j)
    {
        if(flag==0&&l[j]<basic)
        {
            l[i]=l[j];
            flag=1;
        }
        else if(flag==1&&l[i]>basic)
        {
            l[j]=l[i];
            flag=0;
        }
        if(flag==0){j--;}
        else {i++;}
    }
    l[i]=basic;
    Quicksort(l,start,i-1);
    Quicksort(l,i+1,end);
}




int* Quick(int* list,int num)
{
    Quicksort(list,0,num-1);
    return list;
}