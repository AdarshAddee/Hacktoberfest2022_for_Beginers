#include<iostream>
#include<string>
using namespace std;

struct student
{
	string name;
	int age;
	float cgpa;
	int *marks;
};
void inputTDDy(int **&p, int r, int c);
void outputTDDy(int **&p, int r, int c);

void intput(student sarr[], int size);
void output(student sarr[], int size);

int main(){
	
	//int *p[3];
	
	//int *s;
	//s= new int[3];
	
	/*int a, b, c;
	a = 10;
	b = 15;
	c = 20;
	
	int a[2] = { 10, 11 };
	int b[2] = { 15, 16 };
	int c[2] = { 20, 21 };
	*/
	/*
	for (int i = 0; i < 3; i++)
	{
		cout << "Value are " << endl;
		for (int j = 0; j < 2; j++)
		{
			cout<< p[i][j]<<"\t";

		}
		cout << endl;
	}
	
	
	/*student arr[2];
	intput(arr, 2);
	output(arr, 2);
	*/
	/*
	int *p; //occupy 4 bytes in memory
	double *dp;
	char *cp;
	int a = 10;
	int b;
	p = &a;
	cout << "Address of a: " << &a << "     value of a:" << a << endl;
	cout << "Address of p: " << &p << "     Content of p:" << p << "     value at p: " << *p << endl;
	cout << "size of char pointer: " << sizeof(cp)<<endl;
	cout << "size of int pointer: " << sizeof(p) << endl;
	int* q = &b;
	*q = a + *p;
	cout << "value of b: "<< b << endl;

	int *ip = new int;
	*ip = 100;
	delete ip;
	int s;
	cout << "Enter the array size" << endl;
	cin >> s;
	int *arr = new int[s];
	for (int i = 0; i<s; i++)
		cin >> arr[i];
	for (int i = 0; i<s; i++)
		cout << arr[i]<<endl;
	//cout << "content of ip: " << ip << " value at ip address: " << *ip<<endl;
	
	const int a=10;
	int *ip;
	int myarr[3];
	int *q = myarr;
	
	//cout << "address of myarr[0]" <<(int) &myarr[0] << "content of myarr" <<(int) myarr << endl;
	
	int s = 3;
	
	for (int i = 0; i<s; i++)
		cin >> q[i];
	for (int i = 0; i<s; i++)
		cout << q[i] << endl;
	*/

	int **dp=0;
	inputTDDy(dp, 2, 2);

	cout << "Output Data......" << endl;
	
	outputTDDy(dp, 2, 2);
	
	
	system("pause");
	return 0;

}

void inputTDDy(int **&p, int r,int c )
{
	p = new int*[r];
	for (int i = 0; i < r; i++)
	{
		p[i] = new int[c];
	}
	for (int i = 0; i < r; i++)
	{
		cout << "Enter data " << endl;
		for (int j = 0; j < c; j++)
		{
			cin >> p[i][j];

		}

	}


}

void outputTDDy(int **&p, int r, int c)
{
	for (int i = 0; i < r; i++)
	{
		cout << "Value are " << endl;
		for (int j = 0; j < c; j++)
		{
			cout << p[i][j] << "\t";

		}
		cout << endl;
	}
}
void intput(student sarr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "Input data for student" << endl;
		cout << "Enter Name: ";
		getline(cin,sarr[i].name);
		cout << "Enter Age: ";
		cin>>sarr[i].age;
		cout << "Enter CGPA: ";
		cin>>sarr[i].cgpa;
		cout << "Enter Marks: ";
		sarr[i].marks = new int[3];
		for (int j = 0; j < 3; j++)
			cin >> sarr[i].marks[j];
		cin.ignore();
	}
}


void output(student sarr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "Name: " << sarr[i].name << "  Age: " << sarr[i].age << " CGPA: " << sarr[i].cgpa << endl;
		for (int j = 0; j<3; j++)
			cout << sarr[i].marks[j] << "\t";
		cout << "--------------" << endl;
	}
}