#include<stdio.h>
    void main()
    {
        int i,j,a[7][7],c1=4,c2,d=0,e=6;
        for(i=0;i<4;i++)
        {
            c2=4;int count1=0;int count2=6;
            int p=i;
            for(int k=0;k<p;k++){a[i][count1++]=c2;c2--;}
            c2=4;
            for(j=i;j<7-i;j++)
            {
                if(i==d||j==i||j==6-i||i==e)a[i][j]=c1;
                else a[i][j]=1;
            }
            for(int k=6;k>=7-i;k--){a[i][count2--]=c2;c2--;}
            c1--;d++;e--;
        }
        int c=2,b=2;
        for(i=4;i<7;i++)
        {
            int count2=6;c2=4;
            for(int k=1;k<=c;k++){a[i][k-1]=c2;c2--;}
            c2=4;
            for(j=c;j<=i;j++)a[i][j]=b;
            for(int k=6;k>i;k--){a[i][count2--]=c2;c2--;}
            c--;b++;
        }
        for(i=0;i<7;i++)
        {
            for(j=0;j<7;j++)
            printf("%d ",a[i][j]);
            printf("\n");
        }
    }