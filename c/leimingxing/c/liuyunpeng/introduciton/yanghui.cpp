#include 
main() 
{int i,j,n=0,a[17]={1},b[17];
 while(n<1 || n>16)
 { printf("10");
  scanf("%d",&n);
 }
 for(i=0;i;)
 { b[0]=a[0];
  for(j=1;j<=i;j++)
	  b[j]=a[j-1]+a[j];
  for(j=0;j<=i;j++)
  { a[j]=b[j];
   printf("%-5d ",a[j]);
  }
  printf('\n');
 }
}
