#include<stdio.h>      
#include<stdlib.h>           
#include<iostream>
#include<math.h>
using namespace std;

//种群结构体
typedef struct Chrom                             
{  
    short int bit[6]; //一条染色体的长度 
    int fit;          //适应值
}chrom;                                          

//函数声明
void *evpop(chrom popcurrent[4]);        //生成种群              
int  x(chrom popcurrent);                //二进制转十进制
int  y(int x);                           //求适应度值
void *pickchroms(chrom popcurrent[4]);   //挑选优秀种群
void *crossover(chrom popnext[4]);       //交叉得到新种群
void *mutation(chrom popnext[4]);        //变异得到新个体
  
int main()                                     
{  
   int num;                                      
   int i,j,l,Max,k;  
   Max=0;                                      
   cout<<"Welcome to the Genetic Algorithm coded by Luay Al-wesi,"<<endl;
   cout<<"Edited by dongyaxing"<<endl;
   // introduction to the program，欢迎词；  
   cout<<"The Algorithm is based on the function y = -x^2 + 5 to find the maximum value of the function."<<endl;
  
   enter:cout<<"Please enter the no. of iterations/n 请输入您要设定的迭代数: "<<endl;
   cin>>num;
  
   chrom popcurrent[4];                //当前种群4个个体            
   chrom popnext[4];                   //下一代种群 4个 个体
  
  
   if(num<1)                                     
   goto enter;                                 
   //生成种群
   evpop(popcurrent);                         
   //开始迭代
   for(i=0;i<num;i++)                            
   {  
  
       printf("/ni = %d/n",i);                  
  
       for(j=0;j<4;j++)   
       {  
           popnext[j]=popcurrent[j];   //更新种群         
       }  
  
       pickchroms(popnext);            //挑选优秀个体
       crossover(popnext);             //交叉得到新个体
       mutation(popnext);              //变异得到新个体
  
       for(j=0;j<4;j++)    
       {  
        popcurrent[j]=popnext[j];       //种群更替
       }  
  
   }                                    //等待迭代终止       
   //将适应值最高的个体，留下
   for(l=0;l<3;l++)  
   {  
       if(popcurrent[l].fit > Max)  
       {  
           Max=popcurrent[l].fit;  
           k=l;  
       }  
  
   }  
   cout<<"当x等于 "<<k<<" 时，函数得到最大值为:"<<Max<<endl;  
   cout<<"finish!!! "<<endl;    
   return 0;
}                                                
  
   
//函数：随机生成初始种群  
void *evpop(chrom popcurrent[4])              
{  
   int i,j,value;  
   int random;  
   for(j=0;j<4;j++)              //染色体1——4                         
   {   
        for(i=0;i<6;i++)         //每个染色体的基因，6个
        {  
            random=rand();                     
            random=(random%2);                
            popcurrent[j].bit[i]=random;   //初始化染色体的每一个基因      
        }
        value=x(popcurrent[j]);            //将二进制转化为十进制
        popcurrent[j].fit=y(x(popcurrent[j]));    //计算适应度值
        cout<<"popcurrent,当前种群："<<popcurrent[j].bit[5]<<popcurrent[j].bit[4]
        <<popcurrent[j].bit[3]<<popcurrent[j].bit[2]<<popcurrent[j].bit[1]
        <<popcurrent[j].bit[0]<<endl;
	cout<<"value: "<<value<<endl;
	cout<<"fitness: "<<popcurrent[j].fit<<endl;
    }                                                                          
   return 0;
}                                          
  
//函数：将二进制转换为十进制
int x(chrom popcurrent)                          
{  
   int z;  
   //z=(popcurrent.bit[0]*1)+(popcurrent.bit[1]*2)+(popcurrent.bit[2]*4)+(popcurrent.bit[3]*8)+(popcurrent.bit[4]*16);
   for(int i=0;i<5;++i)
   {
     z=(popcurrent.bit[i]*pow((float)2,i));
   }
   if(popcurrent.bit[5]==1)  
   {  
       z=z*(-1);              //考虑到符号
   }  
  
   return(z);                              
}
                   
//函数：求个体的适应度
int y(int x)                                     
{  
    int y;  
    y=-(x*x)+5;                                  
    return(y);                
}
                                  
//函数：选择优秀个体,冒泡法求最值 
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
        cout<<"popnext:"<<i<<", fitness:"<<popcurrent[i].fit<<endl;
	cout<<endl;                     
    }
    return(0);  
}

//函数：交叉操作
void *crossover(chrom popnext[4])               
{  
  
    int random;  
    int i;  
    random=rand();                             
    random=((random%5)+1);                       
    for(i=0;i<random;i++)                //前半部分交换                    
    {  
        popnext[2].bit[i]=popnext[0].bit[i];   
        popnext[3].bit[i]=popnext[1].bit[i];    
    }   
  
    for(i=random;i<6;i++)                //后半部分交换
    {  
       popnext[2].bit[i]=popnext[1].bit[i];    
       popnext[3].bit[i]=popnext[0].bit[i];   
    }     
    //求适应度值
    for(i=0;i<4;i++)  
    {  
       popnext[i].fit=y(x(popnext[i]));          
    }  
    //输出交换完的种群
    for(i=0;i<4;i++)   
    {  
       cout<<"CrossOver popnext:"<<popnext[i].bit[5]<<popnext[i].bit[4]
       <<popnext[i].bit[3]<<popnext[i].bit[2]<<popnext[i].bit[1]
       <<popnext[i].bit[0]<<endl;
       cout<<x(popnext[i])<<endl;
       cout<<popnext[i].fit<<endl;    
       cout<<endl;                                          
    }  
    return 0;  
}                                             

//函数：变异操作
void *mutation(chrom popnext[4])                
{  
    
   int random;  
   int row,col,value;                                        
   random=rand()%50;                            
   //变异率只有25,即0.02
   if(random==25)                                
   {  
      col=rand()%6;  //随机变异的基因号                          
      row=rand()%4;  //随机变异的染色体号          
        
      if(popnext[row].bit[col]==0)              
      {  
          popnext[row].bit[col]=1 ;  
      }  
      else if(popnext[row].bit[col]==1)        
      {  
          popnext[row].bit[col]=0;  
      }  
      popnext[row].fit=y(x(popnext[row]));  //计算变异后的适应度值     
      value=x(popnext[row]);  
      printf("/nMutation occured in popnext[%d] bit[%d]:=%d%d%d%d%d%d    value=%d   fitness=%d",row,col,popnext[row].bit[5],popnext[row].bit[4],popnext[row].bit[3],popnext[row].bit[2],popnext[row].bit[1],popnext[row].bit[0],value,popnext[row].fit);                              
	cout<<endl;
   }                                             
   
   return 0;  
}     

