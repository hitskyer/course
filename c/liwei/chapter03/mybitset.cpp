#include <iostream>

#include <bitset>

#include <string>



using namespace std;



int main()

{

//初始化
//
//	bitset<10> bvec0;
//
//		bitset<32> bvec1(0xff);
//
//			string sr="0110111";
//
//				bitset<10> bvec2(sr);
//
//					bitset<10> bvec3(sr,3,4);
//
//						cout << bvec0 << endl;
//
//							cout << bvec1 << endl;
//
//								cout << bvec2 << endl;
//
//									cout << bvec3 << endl;
//
//									//对bitset位进行访问
//
//										bitset<20> b1(0xff);
//
//											int cn=0;
//
//												for(size_t i=0; i<b1.size();++i)
//
//													{
//
//															if(b1.test(i))
//
//																	++cn; // 测试1的个数
//
//																			b1.set(i);
//
//																				}
//
//																					cout <<  "原始b1中位置是1的个数是 " << cn << endl;
//
//																						cout << " 将所有非1的位变为1,得到b1: " << b1 << endl;
//
//																						//bitve.flip
//
//																							string st="100011100111";
//
//																								bitset <15> bvec4(st);
//
//																									cout << "bvec4= " << bvec4 << endl;
//
//																										cout << "flip of bvec4: " << bvec4.flip() << endl;
//
//																										}
