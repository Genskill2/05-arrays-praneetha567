#include<stdio.h>
#include<assert.h>
#include<math.h>



int max(int a[],int n1)
{int max1,i;
 max1=a[0];
 for(i=1;i<n1;i++)
  {if(a[i]>max1)
   max1=a[i];
  }
 return max1;
}

int min(int b[],int n2)
{int min1,i;
 min1=b[0];
 for(i=1;i<n2;i++)
  {if(b[i]<min1)
   min1=b[i];
  }
 return min1;
} 

float average(int c[],int n3)
 {float avsum=0,av;
  for(int i=0;i<n3;i++)
   {avsum+=c[i];
   }
  av=avsum/n3;
  return av;
 }
 
int mode(int d[],int n4)
{int maxvalue=0,maxcount=0;
 for(int i=0;i<n4;++i)
 {int count;
  for(int j=0;j<n4;++j)
   {if(d[j]==d[i])
    ++count;
   }
  if(count>maxcount)
  {maxcount=count;
   maxvalue=d[i];)
  }
 }
 return maxvalue;
}

int isprime(int);

int isprime(int i)
{ int flag=0;
  for(int j=2;j<1;++j)
   { if(i%j==0)
     {flag=1;
      break;
     }
   }  
   if(flag==0)
     return 1;
   else
     return 0;
}

       
int factors(int n5,int f[])
 {int count=0;
   int i=2;
   while(i<n5)
   {
     if(n5%i==0)
     if(isprime(i)==1)
     { f[count]=i;
       count++;
          n5=n5/i;
          if(isprime(n5)==1)
          {
           f[count++]=n5;
           break;
          }
          i=2;
     }
     else continue;
     else;
     i++;
   }
   return count;
  }         
  
 
 
 
 
  
         
