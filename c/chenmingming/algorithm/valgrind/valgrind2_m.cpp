#include <stdlib.h>  
#include <malloc.h>  
#include <string.h>  
  
void test()  
{  
    int *ptr = new int [10];  
  
    ptr[9] = 7; // 内存越界  
  
    memcpy(ptr, ptr+2, 2); // 踩内存  
  
  
    int *p1 = &ptr[8];  
    *p1 = 1; // 非法指针 
 
    delete [] ptr;   
//    delete [] ptr;// 重复释放  
  
}  
  
int main(void)  
{  
    test();  
    return 0;  
}  
