#include <iostream>
using namespace std;
#include <sys/time.h>
#include<stdlib.h>

const size_t G_BigSize    = 1000000;
const size_t G_SmallSize  = 1000;
const int    G_CycleTimes = 1000;

void myexchange(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}
/*
 * 冒泡排序(bubble sort)，第零版实现（亲自实现swap）
 */
void bsort0(size_t dsize, int *arr) {
	// 不需要排序的情况（也是为了防止在排序中内存溢出）
	if (dsize <= 1)
		return;
	for (size_t i = 0; i != dsize; ++i) {
		for (size_t j = dsize - 1; j > i; --j) {
			if (arr[j] < arr[j-1]) {
				myexchange(arr[j], arr[j-1]);
			}
		}
	}
}
/*
 * 冒泡排序(bubble sort)，第一版实现
 */
void bsort1(size_t dsize, int *arr) {
	// 不需要排序的情况（也是为了防止在排序中内存溢出）
	if (dsize <= 1)
		return;
	for (size_t i = 0; i != dsize; ++i) {
		for (size_t j = dsize - 1; j > i; --j) {
			if (arr[j] < arr[j-1]) {
				swap(arr[j], arr[j-1]);
			}
		}
	}
}
/*
 * 冒泡排序(bubble sort)，第二版实现（避免调用swap）
 */
void bsort2(size_t dsize, int *arr) {
	// 不需要排序的情况（也是为了防止在排序中内存溢出）
	if (dsize <= 1)
		return;
	for (size_t i = 0; i != dsize; ++i) {
		for (size_t j = dsize - 1; j > i; --j) {
			if (arr[j] < arr[j-1]) {
				int tmp   = arr[j];
				arr[j]   = arr[j-1];
				arr[j-1] = tmp;
			}
		}
	}
}
/*
 * 冒泡排序(bubble sort)，第三版实现（避免临时变量的o(n*n)次分配）
 */
void bsort3(size_t dsize, int *arr) {
	// 不需要排序的情况（也是为了防止在排序中内存溢出）
	if (dsize <= 1)
		return;
	int tmp = 0;
	for (size_t i = 0; i != dsize; ++i) {
		for (size_t j = dsize - 1; j > i; --j) {
			if (arr[j] < arr[j-1]) {
				tmp       = arr[j];
				arr[j]   = arr[j-1];
				arr[j-1] = tmp;
			}
		}
	}
}
/*
 * 冒泡排序(bubble sort)，第四版实现（避免o(n*n)次交换）
 */
void bsort4(size_t dsize, int *arr) {
	// 不需要排序的情况（也是为了防止在排序中内存溢出）
	if (dsize <= 1)
		return;
	size_t min_indx = 0;
	for (size_t i = 0; i != dsize; ++i) {
		size_t j = dsize - 1;
		min_indx = j;
		for (; j > i; --j) {
			if (arr[min_indx] > arr[j-1]) {
				min_indx = j - 1;
			}
		}
		if (min_indx != i) {
			swap(arr[min_indx], arr[i]);
		}
	}
}
void rand4data(int i, size_t dsize, int *arr) {
	int flag = i%5;
	if (flag == 0) {
		for (size_t i = 0; i != dsize; ++i) {
			arr[i] = i;
		}
	} else if (flag == 1) {
		for (size_t i = 0; i != dsize; ++i) {
			arr[i] = (int)dsize - i;
		}
	} else if (flag == 2) {
		for (size_t i = 0; i != dsize; ++i) {
			if (i%5 == 0) {
				arr[i] = rand();
			} else {
				arr[i] = 7;
			}
		}
	} else {
		for (size_t i = 0; i != dsize; ++i) {
			arr[i] = rand();
		}
	}
}
long getCurrentTime() {
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return tv.tv_sec * 1000000 + tv.tv_usec;
}
bool right4sorted(const int *arr, size_t dsize) {
	for (size_t i = 1; i < dsize; ++i) {
		if (arr[i-1] > arr[i]) {
			return false;
		}
	}
	return true;
}
void test4sort(size_t dsize, void (*mysort)(size_t dsize, int *arr)) {
	int *arr        = new int[dsize];
	long total_time = 0;
	
	for (int i = 0; i != G_CycleTimes; ++i) {
		rand4data(i, dsize, arr);
		
		long start_time = getCurrentTime();
		mysort(dsize, arr);
		long end_time   = getCurrentTime();
		total_time     += end_time - start_time;
		
		if (!right4sorted(arr, dsize)) {
			cerr << "sort for ints failed" << endl;
			return;
		}
	}
	cout << "You have completed for sort testing!" << endl;
	cout << "And the total time is " 
		<< float(total_time)/1000000.0 << " seconds." << endl;

	delete [] arr;
	arr = NULL;
}
// 随着算法的引入，帮助信息也在不断丰富，需要不断改动，因此抽象为函数
void myhelp(char *argv[]) {
	cerr << "\t ./" << argv[0] << " type4data(big|small) method4sort(bsort0|bsort1|bsort2|bsort3|bsort4)" << endl;
}
int main(int argc, char *argv[]) {
	if (argc < 3) {
		myhelp(argv);
		return -1;
	} else {
		size_t dsize = 0;
		if (string(argv[1]) == "small") {
			dsize = G_SmallSize;
		} else if (string(argv[1]) == "big") {
			dsize = G_BigSize;
		} else {
			myhelp(argv);
			return -2;
		}
		if (string(argv[2]) == "bsort0") {
			test4sort(dsize, bsort0);
		} else if (string(argv[2]) == "bsort1") {
			test4sort(dsize, bsort1);
		} else if (string(argv[2]) == "bsort2") {
			test4sort(dsize, bsort2);
		} else if (string(argv[2]) == "bsort3") {
			test4sort(dsize, bsort3);
		} else if (string(argv[2]) == "bsort4") {
			test4sort(dsize, bsort4);
		} else {
			cerr << "unknown method for sorting : " << argv[2] << endl;
			return -3;
		}
	}
}

