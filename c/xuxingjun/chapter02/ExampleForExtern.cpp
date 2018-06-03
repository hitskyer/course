#include "ExampleForExtern.h"
int g_example_for_extern = 123456;
//int g_example            = 234567;
extern const int g_example_for_const = 2; //加上extern，可被extern.cpp访问
const int g_negative_example_for_const = 3;
int g_example_for_int = 4;
