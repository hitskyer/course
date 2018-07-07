#include <stdlib.h>  
#include <malloc.h>  
#include <string.h>  
  
void test()  
{  
    int *ptr = new int [10];  
  
    ptr[10] = 7; // 内存越界  
  
    memcpy(ptr +1, ptr+2, 5); // 踩内存  
  
  
    delete [] ptr;   
    delete [] ptr;// 重复释放  
  
    int *p1;  
    *p1 = 1; // 非法指针  
}  
  
int main(void)  
{  
    test();  
    return 0;  
}  
