#include<assert.h>
#include<stdlib.h>
#include<math.h>
#include<stdio.h>

float wallis(int);

int main(void)
{
  float pi;
  for (int i=0;i<5;i++)
    {pi=wallis(i);
     if(!fabs(pi-M_PI)<0.15)
       {printf("Estimate with just %d iterations is %f which is too accurate.\n",i,pi);
       abort();
       }
    }
    
  for(int i=500;i<700;i++)
    {pi=wallis(i);
     if(!fabs(pi-M_PI)<0.01)
      {printf("Estimate with even %d iterations is %f which is not accurate enough.\n",i,pi);
      abort();
      }
     } 
   
   for(int i=5;i<500;i++)
    {pi=wallis(i);
    if(fabs(pi-M_PI)<0.005)
     printf("The value of pi by wallis estimate is %f",pi);
    }    
    
} 
    
float wallis(int n)
{ float p=1.0;
  int z=1;
  for(int i=0;i<=n;i++)
  {
    z=4*i*i;
    p*=z/(z-1);
  }
  return(2*p);
}    
