#include<stdio.h>            
//#include<termio.h>          
#include<stdlib.h>           
#include<iostream>
using namespace std;
  
typedef struct Chrom                             
{  
    short int bit[6];  
    int fit;  
}chrom;                                          
  
void *evpop(chrom popcurrent[4]);              
int x(chrom popcurrent);  
int y(int x);  
void *pickchroms(chrom popcurrent[4]);  
void *crossover(chrom popnext[4]);  
void *mutation(chrom popnext[4]);  
  
int main()                                     
{  
   int num;                                      
   int i,j,l,Max,k;  
   Max=0;                                      
  
   printf("/nWelcome to the Genetic Algorithm coded by Luay Al-wesi,editd by xujinpeng/n");  // introduction to the program，欢迎词；  
   printf("The Algorithm is based on the function y = -x^2 + 5 to find the maximum value of the function./n");  
  
   enter:printf("/nPlease enter the no. of iterations/n 请输入您要设定的迭代数: ");   
   scanf("%d",&num);                             
  
   chrom popcurrent[4];                        
   chrom popnext[4];                            
  
  
   if(num<1)                                     
   goto enter;                                 
  
   evpop(popcurrent);                         
     
   for(i=0;i<num;i++)                            
   {  
  
       printf("/ni = %d/n",i);                  
  
       for(j=0;j<4;j++)   
       {  
           popnext[j]=popcurrent[j];            
       }  
  
       pickchroms(popnext);                    
       crossover(popnext);                      
       mutation(popnext);                        
  
       for(j=0;j<4;j++)    
       {  
        popcurrent[j]=popnext[j];                
       }  
  
   }                                             
     
   for(l=0;l<3;l++)  
   {  
       if(popcurrent[l].fit > Max)  
       {  
           Max=popcurrent[l].fit;  
           k=l;  
       }  
  
   }  
   printf("/n当x等于%d时，函数得到最大值为：%d ",k,Max);  
   printf("/nPress any key to end ! ");  
     
//   flushall();                                 
//   getche();                                   
  return 0;
}                                                
  
   
  
void *evpop(chrom popcurrent[4])              
{  
   int i,j,value;  
   int random;  
   for(j=0;j<4;j++)                              
   {  
        for(i=0;i<6;i++)                         
        {  
            random=rand();                     
            random=(random%2);                
            popcurrent[j].bit[i]=random;         
        }     
        
        value=x(popcurrent[j]);                  
        popcurrent[j].fit=y(x(popcurrent[j]));  
        printf("/n popcurrent[%d]=%d%d%d%d%d%d  value=%d  fitness = %d",j,popcurrent[j].bit[5],popcurrent[j].bit[4],popcurrent[j].bit[3],popcurrent[j].bit[2],popcurrent[j].bit[1],popcurrent[j].bit[0],value,popcurrent[j].fit);                                cout<<endl;
   }                                                                          
   return(0);                   
}                                          
  
  
int x(chrom popcurrent)                          
{  
   int z;  
   z=(popcurrent.bit[0]*1)+(popcurrent.bit[1]*2)+(popcurrent.bit[2]*4)+(popcurrent.bit[3]*8)+(popcurrent.bit[4]*16);  
  
   if(popcurrent.bit[5]==1)  
   {  
       z=z*(-1);                               
   }  
  
   return(z);                              
}                                        
   
int y(int x)                                     
{  
    int y;  
    y=-(x*x)+5;                                  
    return(y);                
}                                       
  
void *pickchroms(chrom popcurrent[4])            
{  
    int i,j;  
    chrom temp;                                 
  
    for(i=0;i<3;i++)                           
    {  
        for(j=0;j<3;j++)  
         {  
             if(popcurrent[j+1].fit>popcurrent[j].fit)  
               {  
                 temp=popcurrent[j+1];  
                 popcurrent[j+1]=popcurrent[j];  
                 popcurrent[j]=temp;  
  
               }     
         }                  
    }  
    for(i=0;i<4;i++)  
    {  
        printf("/nSorting:popnext[%d] fitness=%d",i,popcurrent[i].fit);
	cout<<endl;   
        //printf("/n");                        
    }  
//    flushall();                             
    return(0);  
}                                            
  
void *crossover(chrom popnext[4])               
{  
  
    int random;  
    int i;  
    random=rand();                             
    random=((random%5)+1);                       
    for(i=0;i<random;i++)                      
    {  
        popnext[2].bit[i]=popnext[0].bit[i];   
        popnext[3].bit[i]=popnext[1].bit[i];    
    }   
  
    for(i=random;i<6;i++)                       
    {  
       popnext[2].bit[i]=popnext[1].bit[i];    
       popnext[3].bit[i]=popnext[0].bit[i];   
    }     
  
    for(i=0;i<4;i++)  
    {  
       popnext[i].fit=y(x(popnext[i]));          
    }  
  
    for(i=0;i<4;i++)   
    {  
       printf("/nCrossOver popnext[%d]=%d%d%d%d%d%d    value=%d    fitness = %d",i,popnext[i].bit[5],popnext[i].bit[4],popnext[i].bit[3],popnext[i].bit[2],popnext[i].bit[1],popnext[i].bit[0],x(popnext[i]),popnext[i].fit);    
       cout<<endl;                                          
    }  
    return(0);  
}                                             
  
void *mutation(chrom popnext[4])                
{  
    
   int random;  
   int row,col,value;                                        
   random=rand()%50;                            
  
   if(random==25)                                
   {  
      col=rand()%6;                           
      row=rand()%4;                              
        
      if(popnext[row].bit[col]==0)              
      {  
          popnext[row].bit[col]=1 ;  
      }  
      else if(popnext[row].bit[col]==1)        
      {  
          popnext[row].bit[col]=0;  
      }  
      popnext[row].fit=y(x(popnext[row]));      
      value=x(popnext[row]);  
      printf("/nMutation occured in popnext[%d] bit[%d]:=%d%d%d%d%d%d    value=%d   fitness=%d",row,col,popnext[row].bit[5],popnext[row].bit[4],popnext[row].bit[3],popnext[row].bit[2],popnext[row].bit[1],popnext[row].bit[0],value,popnext[row].fit);                              
	cout<<endl;
   }                                             
   
   return(0);  
}     

