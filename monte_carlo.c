#include<assert.h>
#include<stdlib.h>
#include<math.h>
#include<stdio.h>

#define random rand
#define srandom srand

float montecarlo(int);

float frandom()
{ long int z=random();
  float ret=(float)z/(float)RAND_MAX;
  return ret;
}  

int main(void)
{ float pi1;
  float pi2;
  pi1=montecarlo(10000);
  pi2=montecarlo(10000);
  printf("%f,%f\n",pi1,pi2);
  
  if(pi1==pi2)
  {printf("Two seperate estimates of pi are exactly the same, which is impossible.\n");
   abort();
  }
  
  if(fabs(pi1-pi2)>0.05)
  {printf("Two seperate estimates of pi %f and %f are too different, which is impossible.\n",pi1,pi2);
   abort();
  }
  
  for (int i=0;i<5;i++)
    {
    pi1=montecarlo(i);
     if(!fabs(pi1-M_PI)<0.15)
       {printf("Estimate with just %d iterations is %f which is too accurate.\n",i,pi1);
       abort();
       }
    }
    
  for(int i=2000;i<5000;i++)
    {pi1=montecarlo(i);
     if(!fabs(pi1-M_PI)<0.4)
      {printf("Estimate with even %d iterations is %f which is not accurate enough.\n",i,pi1);
      abort();
      }
     } 
    
   
   for(int i=5;i<500;i++)
    {pi1=montecarlo(i);
    if(fabs(pi1-M_PI)<0.005)
     printf("The value of pi by wallis estimate is %f",pi1);
    }    
    
} 

float montecarlo(int n)
{ float pi,x,y;
  double z,z1;
  int circle=0,square=0;
  for(int i=0;i<n;i++)
   {x=frandom();
    y=frandom();
    z=x*x+y*y;
    z1=pow(z,0.5);
    if(z1<=1)
      circle++;
    else
      square++;
    }
   pi=4*(circle/square);
   return pi;
  }    
