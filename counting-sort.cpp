/*This program performs counting sort for an array containing only single digit decimal values (i.e, range of 10).
The same can be implemented for an array containing hexadecimal values, or any custom range of values*/
#include <iostream>
#include <limits>
#include <new>
using namespace std;

int integerInput();
int getSize();
void countingSort(int[], int, int);
void displayArray(int[], int);

int main()
{
	int size, * arr;

	cout << "Enter the size of the array: ";
	size = getSize();
	arr = new (nothrow) int[size];
	if (arr == nullptr)
	{
		cout << endl << "Failed to allocate memory! Please restart the application.";
		exit(0);
	}

	cout << endl << "Enter all the elements of the array: ";
	for (int i = 0; i < size; i++)
	{
		arr[i] = integerInput();
		if (size - i - 1 == 0)
			break;
		cout << "Elements remaining to be entered: " << size - i - 1 << endl;
	}

	countingSort(arr, 10, size);		// Here range of 10 means that there are 10 unique elements, i.e, 0-9
	displayArray(arr, size);

	return 0;
}

int integerInput()
{
	int n;

	while (!(cin >> n) || n < 0 || n > 9)
	{
		cin.clear();
		cin.ignore(numeric_limits <streamsize>::max(), '\n');
		cout << endl << "Invalid input! Please try again with correct input (single digit values between 0 and 9): ";
	}

	return n;
}

int getSize()
{
	int size = integerInput();

	if (size <= 0)
	{
		cout << endl << "Invalid size! Please try again: ";
		size = getSize();
	}

	return size;
}

void countingSort(int arr[], int range, int size)
{
	int* sortedArr = new (nothrow) int[size];
	int* count = new (nothrow) int[range];
	if (sortedArr == nullptr || count == nullptr)
	{
		cout << endl << "Failed to allocate memory! Please restart the application.";
		exit(0);
	}

	for (int i = 0; i < range; i++)
	{
		count[i] = 0;
	}

	for (int i = 0; i < size; i++)			// Counting all unique elements in the array
	{
		count[arr[i]]++;
	}

	for (int i = 1; i < range; i++)			// Cumulatively adding all the counting values
	{
		count[i] += count[i - 1];
	}

	for (int i = size - 1; i >= 0; i--)
	{
		sortedArr[count[arr[i]] - 1] = arr[i];// Assigning the values to the output array in ascending order
		count[arr[i]]--;
	}

	for (int i = 0; i < size; i++)
	{
		arr[i] = sortedArr[i];
	}
}

void displayArray(int arr[], int size)
{
	cout << endl << "The sorted array is: ";

	for (int i = 0; i < size; i++)
	{
		cout << "|" << arr[i] << "|";
	}
}