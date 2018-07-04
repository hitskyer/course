#include<iostream>
#include<vector>
using namespace std;

double vectorSum(vector<double>:: const_iterator begin, vector<double>::const_iterator end)
{

	double sum=0;
	while(begin!=end){
		sum += *begin;
		begin++;
	}
	return sum;
}

int main()
{
	vector<double> dvec;
	cout << "Please enter double-type elements for dvec: " << endl;
	double dval;
	while (cin>>dval){
		dvec.push_back(dval);
		if(cin.get()=='\n')
	 		break;	
	}
	cout << "The sum of elements: " << vectorSum(dvec.begin(),dvec.end()) << endl;
	return 0;
}

	
	
