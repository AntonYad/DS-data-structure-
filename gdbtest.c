#include<stdio.h>
int nGlbVar=0;
int mFunc(int a,int b)
{
printf("mFunc is called,a=%d,b=%d\n",a,b);
return(a+b);
}
int main()
{
int n;
n=1;
n++;
n--;
nGlbVar+=100;
nGlbVar-=12;
printf("n=%d, nGlbVar=%d\n",n,nGlbVar);
n=mFunc(1,2);
printf("n=%d",n);
return 0;
}
