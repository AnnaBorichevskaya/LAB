#include <iostream>
#include <stdlib.h>
using namespace std;

int* RandomArray(int);
void DisplayArray(int*, int);
void Swap(int &, int &);
int FindMaxNegativeNumber(int*, int);
int FindMinPositiveNumber(int*, int);
void BubbleSort(int*, int);
int* DeleteNumbers(int*, int, int, int);

int main()
{
	int n;
	while (true)
	{
		cout << "Enter n ( amount ) <= " << endl;
		cin >> n;
		if (n > 0) break;
		cout << "Error!";
	}
	system("cls");
	int* a = RandomArray(n);
	cout << " Your array is: ";
	DisplayArray(a, n);
	cout << endl;
	int indexMax = FindMaxNegativeNumber(a, n);
	int indexMin = FindMinPositiveNumber(a, n);
	int* b;
	if (indexMax < indexMin)
		Swap(indexMax, indexMin);
	BubbleSort(a + indexMin, indexMax - indexMin + 1);
	b = DeleteNumbers(a, indexMin, indexMax, n);
	int bn = n - (indexMax - indexMin + 1);
	n = indexMax - indexMin + 1;
	cout << " Your  changed array after sort is: ";
	DisplayArray(a, n);
	cout << endl << " Your new array with remaining numbers is: ";
	DisplayArray(b, bn);
	system("pause");
	return 0;
}

int* RandomArray(int n)
{
	int* a = new int[n];
	for (int* p = a; p < a + n; p++)
		*p = rand() % 200 - 100;
	return a;
}

void DisplayArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " , ";
}

void Swap(int &a, int &b)
{
	int temp = 0;
	temp = a;
	a = b;
	b = temp;
}

int FindMaxNegativeNumber(int* a, int n)
{
	int max, indexMax;
	int flag = 1;
	for (int i = 1; i < n; i += 2)
	{
		if (a[i] < 0)
		{
			max = a[i];
			indexMax = i;
			flag = 0;
			break;
		}
	}
	if (flag)
	{
		cout << " ~ This array doesn't have max negative number ~ This program can't work on ~ ";
		system("pause");
	}
	for (int i = 1; i < n; i += 2)
	{
		if (a[i] < 0 && max < a[i])
		{
			max = a[i];
			indexMax = i;
		}
	}
	cout << " Max Negative Number is: " << max << endl;
	cout << " Index of max negative : " << indexMax + 1 << endl;
	return indexMax;
}

int FindMinPositiveNumber(int* a, int n)
{
	int min, indexMin;
	int flag = 1;
	for (int i = 1; i < n; i += 2)
	{
		if (a[i] > 0)
		{
			min = a[i];
			indexMin = i;
			flag = 0;
			break;
		}
	}
	if (flag)
	{
		cout << " ~ This array doesn't have min positive number ~ This program can't work on ~ ";
		system("pause");
	}
	for (int i = 1; i < n; i += 2)
	{
		if (a[i] > 0 && min > a[i])
		{
			min = a[i];
			indexMin = i;
		}
	}
	cout << " Min Positive Number is: " << min << endl;
	cout << " Index of min positive : " << indexMin + 1 << endl;
	return indexMin;
}

void BubbleSort(int* a, int n)
{
	int count1 = 0, count2 = 0;
	for (int i = n - 1; i; i--)
	for (int j = 0; j < i; j++)
	{
		int num = a[j];
		while (num)
		{
			if ((num % 10) % 2 == 0)
				count1++;
			num /= 10;
		}
		num = a[j + 1];
		while (num)
		{
			if ((num % 10) % 2 == 0)
				count2++;
			num /= 10;
		}
		if (count1 > count2) Swap(a[j], a[j + 1]);
		count1 = count2 = 0;
	}
}

int* DeleteNumbers(int* a, int min, int max, int n)
{
	int i;
	int* b = new int[n - max + min - 1];
	for (i = 0; i < min; i++)
		b[i] = a[i];
	for (i = max + 1; i < n; i++)
		b[min + i - max - 1] = a[i];
	for (i = 0; i < n - min; i++)
		a[i] = a[i + min];
	return b;
}
