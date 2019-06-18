/**
 * @description: 字符匹配BM算法
 * @author: michael ming
 * @date: 2019/6/18 22:19
 * @modified by: 
 */
#define SIZE 256    //字符集字符数
void generateHash(char *b, int m, int *hash)//(模式串字符b，模式串长度m，模式串的哈希表)
{
    int i, ascii;
    for(i = 0; i < SIZE; ++i)
    {
        hash[i] = -1;//哈希表初始化为-1
    }
    for(i = 0; i < m; ++i)
    {
        ascii = int(b[i]);  //计算字符的ASCII值
        hash[ascii] = i;
    }
}

int str_bm(char *a, int n, char *b, int m)
{
    int *hash = new int [SIZE];//记录模式串中每个字符最后出现的位置
    generateHash(b,m,hash);     //构建坏字符哈希表
    int i = 0, j;
    while(i < n-m+1)
    {
        for(j = m -1; j >= 0; --j)  //模式串从后往前匹配
        {
            if(a[i+j] != b[j])
                break;  //坏字符对应模式串中的下标是j
        }
        if(j < 0)   //匹配成功
        {
            return i;   //返回主串与模式串第一个匹配的字符的位置
        }
        //这里等同于将模式串往后滑动 j-hash[int(a[i+j])] 位
        i = i + (j - hash[int(a[i+j])]);
    }
    return -1;
}