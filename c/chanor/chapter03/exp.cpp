#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <bitset>

//exp3.1
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using namespace std;

int main()
{
	//exp3.2
	string s1;
	s1 = "OK!";
	string s2(s1);
	string s3("hello!");
	string s4(5,'a');
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
/*	
	//exp3.5, 3.8	
	string word;
	string words;
	string words2;
	while (cin >> word)
	{
		words += word;
		words2 = words2 + " " + word;
	}
	cout << words << endl;
	cout << words2 << endl;

	string line;
	while (getline(cin,line))
	{
		cout << line << endl;
	}
	//exp3.7
	string ina; cin >> ina;	
	string inb; cin >> inb;
	if (ina > inb)//string
	{
		cout << "the first one is bigger." << endl;
	}	
	else if (ina == inb)
	{
		cout << "the two are equal." << endl;
	}
	else
	{
		cout << "the second one is bigger." << endl;
	}
	if (ina.size() > inb.size())//length
	{
		cout << "the first one is longer." << endl;
	}	
	else if (ina.size() == inb.size())
	{
		cout << "the two are equal." << endl;
	}
	else
	{
		cout << "the second one is longer." << endl;
	}
*/
	//exp3.9
	string s;
	cout << "s0:" <<s[0] << endl;//true
	vector<int> x;
	//x[0] = 42;
	x.push_back(42);
	cout << x[0] << endl;
/*	
	//exp3.10
	string ln;
	cin >> ln;
	for (int i=0; i<ln.size(); i++)
	{
		if(ispunct(ln[i]))
		//	replace(ln[i],'');
		ln[i] =' ';
	}
	cout << ln << endl;
	
	//exp3.11
	//vector < vector<int> > ivec;//true
//	vector<string> svec = ivec;//false
	//vector< vector<int> > svec = ivec;//false
	vector<string> ssvec(10,"null");//ture

	//exp3.12
	vector<int> ivec1; cout << ivec1.size() << endl;
	vector<int> ivec2(10); cout << ivec2.size() << endl;
	vector<int> ivec3(10,42); cout << ivec3.size() << endl;
	vector<string> svec1; cout << svec1.size() << endl;
	vector<string> svec2(10); cout << svec2.size() << endl;
	vector<string> svec3(10,"hello"); cout << svec3.size() << endl;
	
	//exp3.13
	vector<int> ivec;
	int num;
	while (cin >> num)
	{
		ivec.push_back(num);
	}
	for (int i = 1; i<ivec.size(); i+=2)
	{
		cout << i <<"+"<< i+1 << ":" <<ivec[i-1]+ivec[i] << endl;
	}
	if (ivec.size()%2==1)
		cout <<"最后一个没有求和：" <<ivec[ivec.size()-1] << endl;

	int len = ivec.size();
	for (int i = 0; i<len/2; i++)
	{
		cout << i+1 <<"+"<< len-i << ":" <<ivec[i]+ivec[len-1-i] << endl;
	}
	if (len%2==1)
		cout <<"中间一个没有求和：" <<ivec[(len-1)/2] << endl;
	
	//exp3.14
	vector<string> text;
	string ci;
	
	while (cin >> ci)
	{
		text.push_back(ci);
	}
	for (int i = 0; i<text.size(); i++)
	{
		for (int j=0;j<text[i].size();j++)
		{
			text[i][j] = toupper(text[i][j]);
		}
		cout << text[i] << " ";
		if (i%8==7)
			cout << endl;
	}
	cout << endl;
*/
	//exp3.15
	vector<int> intvec;
	intvec.push_back(42);
	//intvec[0]= 42;
	
	vector<int> a(10,42);

	string h = "Hello";
	string w = "Word";
	cout << h+w << endl;
	cout << h.size() << endl;
	for (int i=0; i<h.size(); i++)
	{
		cout << h[i] << " ";
		h[i] = '*';
	}
	cout << h << endl;

}

