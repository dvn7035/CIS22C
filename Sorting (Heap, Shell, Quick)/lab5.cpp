/*
This program will make two arrays with random elements and sort them using the heap sort, shell sort, and quick sort. 
CIS 22C Clare Nguyen 
Lab 5

Created by: David Nguyen
Date: 05 June 2014
*/


#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <time.h>
#define SMALLARRAYSIZE 100
#define BIGARRAYSIZE 7500
#define MINQSORTSIZE 16
using namespace std;

void Populate_Array (int to_populate[], int arraySize);
void Copy_Array (int destination[], const int source[], int arraySize);
void Print_Array_If_100 (const int to_print[], int arraySize);

void HeapSort (const int original_array[],  int arraySize);
void _heapsort (int arr[], int arraySize, int* comparisons, int* moves);
void _heapcreate (int heap[], int arraySize, int* comparisons, int* moves);
void _rebuildheap (int heap[], int index, int lastIndex, int* comparisons, int* moves);

void ShellSort (const int orignal_array[], int arraySize);
void _shellsort(int arr[], int arraySize, int* comparisons, int* moves);

void QuickSort (const int original_array[], int arraySize);
void _medianleft (int array_to_pivot[], int LeftIndex, int RightIndex, int* comparisons, int* moves);
void _quicksort (int arr[], int LeftIndex, int RightIndex, int* comparisons, int* moves);
void _insertionSort(int arr[], int FirstIndex, int LastIndex, int* comparisons, int* moves);

int main ()
{
	//Local Declarations
	int array1[SMALLARRAYSIZE];
	int array2[BIGARRAYSIZE];

	//Statements
	//Iteration 1
	Populate_Array(array1, SMALLARRAYSIZE);
	HeapSort(array1, SMALLARRAYSIZE);
	ShellSort(array1, SMALLARRAYSIZE);
	QuickSort(array1, SMALLARRAYSIZE);
	//Iteration 2
	Populate_Array(array2, BIGARRAYSIZE);
	HeapSort(array2, BIGARRAYSIZE);
	ShellSort(array2, BIGARRAYSIZE);
	QuickSort(array2, BIGARRAYSIZE);

	return 0;
}

//Populate_Array will populate an arary with random integers from 0 to 7500
void Populate_Array (int to_populate[], int arraySize)
{
	srand (time(NULL));
	int i;

	for (i=0; i < arraySize; i++)
		to_populate[i] = rand() % 7501;
	return;
}

//Copy_Array will make a duplicate of and array of a fixed size
void Copy_Array (int destination[], const int source[], int arraySize)
{
	int i;
	for (i=0; i < arraySize; i++)
		destination[i] = source[i];
	return;
}

//Print_Array_If_100 will print an array 10 elements to a line if the array is of size 100
void Print_Array_If_100 (const int to_print[], int arraySize)
{
	int i;
	int newline;
	if (arraySize == 100)
		for (i=0, newline =1; i < arraySize; i++, newline++)
		{
			cout << setw(4) << setfill('0');
			cout << to_print[i] << " ";
			if ( !(newline % 10 ) )
				cout << endl;
		}
	return;
}

//HeapSort is a wrapper function that calls upon the internal _heapsort and sorts the array, 
//it then swaps two pairs of elements to make it nearly sorted and sort it again.
//it also prints how many comparisons and moves it took for each sort
void HeapSort (const int original_array[], int arraySize)
{
	//make a copy of the original array
	int* array_copy = new int[arraySize];
	Copy_Array(array_copy, original_array, arraySize);
	int comparisons = 0;
	int moves = 0;

	cout << "This is the Heap Sort for an array of " << arraySize << ":" << endl;

	//Heap sort the copy
	_heapsort(array_copy, arraySize, &comparisons, &moves);
	Print_Array_If_100 (array_copy, arraySize);
	cout << endl << "A random sort took " << comparisons << " comparisons and " << moves << " moves." << endl;
	//reset the comparisons and moves, swap swap two pairs of elements
	swap (array_copy[20], array_copy[21]);
	swap (array_copy[90], array_copy[91]);
	comparisons = 0; moves = 0;
	//do the shellsort on the nearly ordered array
	_heapsort(array_copy, arraySize, &comparisons, &moves);
	cout << "A nearly ordered sort took " << comparisons << " comparisons and " << moves << " moves." << endl << endl;
	delete[] array_copy;
	return;
}

void _heapsort (int arr[], int arraySize, int* comparisons, int* moves)
{
	int lastIndex = arraySize-1;
	_heapcreate(arr, arraySize, comparisons, moves);
	while (lastIndex >= 1)
	{
		swap(arr[0], arr[lastIndex]); //move greatest element to the end
		(*moves)+=3;
		lastIndex--;
		_rebuildheap (arr, 0, lastIndex, moves, comparisons);		//build the heap leaving the last element
	}
	return;
}

void _heapcreate (int heap[], int arraySize, int* comparisons, int* moves)
{
	int i;
	for (i = arraySize/2-1; i >= 0; i--)
		_rebuildheap (heap, i, arraySize-1, comparisons, moves);
	return;
}

void _rebuildheap (int heap[], int index, int lastIndex, int* comparisons, int* moves)
{
	int largeChildIndex;
	int leftkey;
	int rightkey;
	if (index*2+1 <= lastIndex)		//in the case there is no left child
	{
		leftkey = heap[index*2+1]; (*moves)++;
		if (index*2+2 > lastIndex)	//in case there is no right child
			largeChildIndex = index*2+1;
		else
		{
			rightkey = heap[index*2+2]; (*moves)++;
			if (leftkey > rightkey)  //if the left child is bigger than the right
				largeChildIndex = index*2+1;
			else					//vice versa
				largeChildIndex = index*2+2;
		}
		if ((*comparisons)++, heap[index] < heap[largeChildIndex])
		{
			swap (heap[index], heap[largeChildIndex]); (*moves)+=3;
			_rebuildheap (heap, largeChildIndex, lastIndex, moves, comparisons);
		}
	}
	return;
}

//ShellSort is a wrapper function that does the same thing as HeapSort except with the Shell Sort Algorithm
void ShellSort (const int orignal_array[], int arraySize)
{
	//make a copy of the original array
	int* array_copy = new int[arraySize];
	int comparisons = 0;
	int moves = 0;
	//Do the shell sort on randomized array
	cout << "This is the Shell Sort for an array of " << arraySize << ":" << endl;
	Copy_Array (array_copy, orignal_array, arraySize);
	_shellsort(array_copy, arraySize, &comparisons, &moves);
	Print_Array_If_100 (array_copy, arraySize);
	cout << endl << "A random sort took " << comparisons << " comparisons and " << moves << " moves." << endl;
	//Swap 2 pairs of elements
	swap (array_copy[20], array_copy[21]);
	swap (array_copy[90], array_copy[91]);
	//reset the comparisons and moves
	comparisons = 0; moves = 0; 
	_shellsort(array_copy, arraySize, &comparisons, &moves);  //do the shellsort on the nearly ordered array
	cout << "A nearly ordered sort took " << comparisons << " comparisons and " << moves << " moves." << endl << endl;
	delete[] array_copy;
	return;
}

void _shellsort(int arr[], int arraySize, int* comparisons, int* moves)
{
	int lastIndex = arraySize -1;
	int incre = (arraySize)/2;  //size of the segment
	int temp;
	int walker;
	while (incre)
	{
		for (int current = incre; current <= lastIndex; current++) //beginning of the insertion sort
		{
			temp = arr[current]; (*moves)++;
			walker = current - incre;
			while ((*comparisons)++, walker >=0 && temp < arr[walker])
				///////////// comparisons++ should be next to the temp compare because that's where
					///////// the array data are compared    -1/2pt
			{
				arr[walker+incre] = arr[walker]; (*moves)++;
				walker -= incre;
			}
			arr[walker+incre] = temp; (*moves)++;
		}
		incre /= 2;				//half the segment
	}
}

//QuickSort is a function similiar to HeapSort, but it calls upon the Quick Sort Algorithm
void QuickSort (const int original_array[], int arraySize)
{
	int comparisons = 0;
	int moves = 0;
	int* array_copy = new int[arraySize];
	cout << "This is the Quick Sort for an array of " << arraySize << ":" << endl;
	Copy_Array (array_copy, original_array, arraySize);
    _quicksort(array_copy, 0, arraySize-1, &comparisons, &moves);
	Print_Array_If_100(array_copy, arraySize);
	cout << endl << "A random sort took " << comparisons << " comparisons and " << moves << " moves." << endl;
	swap (array_copy[20], array_copy[21]);
	swap (array_copy[90], array_copy[91]);
	comparisons = 0; moves = 0;
	_quicksort(array_copy, 0, arraySize-1, &comparisons, &moves);
	cout << "A nearly ordered sort took " << comparisons << " comparisons and " << moves << " moves." << endl << endl;

	delete[] array_copy;
	return;
}

void _medianleft (int array_to_pivot[], int LeftIndex, int RightIndex, int* comparisons, int* moves)
{
	int MiddleIndex = (LeftIndex + RightIndex) / 2;
	if ((*comparisons)++, array_to_pivot[LeftIndex] > array_to_pivot[MiddleIndex])
	{ 
		swap (array_to_pivot[LeftIndex], array_to_pivot[MiddleIndex]); 
		(*moves)+=3;
	}
    if ((*comparisons)++, array_to_pivot[LeftIndex] > array_to_pivot[RightIndex])
	{
        swap (array_to_pivot[LeftIndex], array_to_pivot[RightIndex]);
		(*moves)+=3;
	}
    if ((*comparisons)++, array_to_pivot[MiddleIndex] > array_to_pivot[RightIndex])
	{
        swap (array_to_pivot[MiddleIndex], array_to_pivot[RightIndex]);
		(*moves)+=3;
	}
    swap (array_to_pivot[LeftIndex], array_to_pivot[MiddleIndex]); (*moves)+=3;
    return;
}

void _quicksort (int arr[], int LeftIndex, int RightIndex, int* comparisons, int* moves)
{
	if ((RightIndex - LeftIndex) > MINQSORTSIZE)
	{
		//Copy out the pivot
		_medianleft(arr, LeftIndex, RightIndex, comparisons, moves);
		int pivot = arr[LeftIndex]; (*moves)++;
		//Set walker from the left and from the right
		int WalkerLeft = LeftIndex + 1;
		int WalkerRight = RightIndex;
		while (WalkerLeft <= WalkerRight)
		{
			while ((*comparisons)++, arr[WalkerLeft] < pivot)
				WalkerLeft++;
			while ((*comparisons)++, arr[WalkerRight] >= pivot)
				WalkerRight--;
			if (WalkerLeft < WalkerRight)
			{
				swap (arr[WalkerLeft], arr[WalkerRight]); (*moves) += 3;
				WalkerLeft++; 
				WalkerRight--;
			}
		}
		//the two walkers have met
		arr[LeftIndex] = arr[WalkerLeft-1]; (*moves)++;
		arr[WalkerLeft-1] = pivot; (*moves)++;
		if (LeftIndex < WalkerRight) //if there is a left side array
			_quicksort(arr, LeftIndex, WalkerRight-1, comparisons, moves);
		if (WalkerLeft < RightIndex) //if there is a right side array
			_quicksort(arr, WalkerLeft, RightIndex, comparisons, moves);
	}
	//If the array is smaller than the minimium size use insertion sort
	else
		_insertionSort(arr, LeftIndex, RightIndex, comparisons, moves);
	return;
}

void _insertionSort(int arr[], int FirstIndex, int LastIndex, int* comparisons, int* moves)
{
	for (int current = FirstIndex; current <= LastIndex; current++)
	{
		int temp = arr[current]; (*moves)++;
		int walker = current -1;
		while ((*comparisons)++, walker >=0 && temp < arr[walker])
			/////////////// comparisons++ should be next to the temp compare, as explained above
		{
			arr[walker+1] = arr[walker]; (*moves)++;
			walker--;
		}
		arr[walker+1] = temp; (*moves)++;
	}
	return;
}

/*
Output:

This is the Heap Sort for an array of 100:
0008 0160 0374 0376 0468 0477 0508 0509 0512 0674
0751 0842 0846 1018 1047 1119 1210 1523 1524 1579
1758 1901 2037 2193 2198 2205 2255 2350 2387 2446
2522 2550 2661 2808 2898 3052 3239 3261 3324 3359
3384 3462 3537 3550 3588 3615 3706 3715 3716 3808
3829 3833 3913 3944 4089 4156 4199 4343 4616 4648
4756 4824 4919 4970 5039 5073 5103 5172 5181 5232
5375 5456 5463 5491 5509 5603 5603 5620 5639 5954
5987 6243 6274 6355 6413 6418 6419 6460 6848 6889
6929 7011 7012 7063 7186 7306 7308 7424 7442 7473

A random sort took 1553 comparisons and 1731 moves.
A nearly ordered sort took 1647 comparisons and 1894 moves.

This is the Shell Sort for an array of 100:
0008 0160 0374 0376 0468 0477 0508 0509 0512 0674
0751 0842 0846 1018 1047 1119 1210 1523 1524 1579
1758 1901 2037 2193 2198 2205 2255 2350 2387 2446
2522 2550 2661 2808 2898 3052 3239 3261 3324 3359
3384 3462 3537 3550 3588 3615 3706 3715 3716 3808
3829 3833 3913 3944 4089 4156 4199 4343 4616 4648
4756 4824 4919 4970 5039 5073 5103 5172 5181 5232
5375 5456 5463 5491 5509 5603 5603 5620 5639 5954
5987 6243 6274 6355 6413 6418 6419 6460 6848 6889
6929 7011 7012 7063 7186 7306 7308 7424 7442 7473

A random sort took 938 comparisons and 1441 moves.
A nearly ordered sort took 505 comparisons and 1008 moves.

This is the Quick Sort for an array of 100:
0008 0160 0374 0376 0468 0477 0508 0509 0512 0674
0751 0842 0846 1018 1047 1119 1210 1523 1524 1579
1758 1901 2037 2193 2198 2205 2255 2350 2387 2446
2522 2550 2661 2808 2898 3052 3239 3261 3324 3359
3384 3462 3537 3550 3588 3615 3706 3715 3716 3808
3829 3833 3913 3944 4089 4156 4199 4343 4616 4648
4756 4824 4919 4970 5039 5073 5103 5172 5181 5232
5375 5456 5463 5491 5509 5603 5603 5620 5639 5954
5987 6243 6274 6355 6413 6418 6419 6460 6848 6889
6929 7011 7012 7063 7186 7306 7308 7424 7442 7473

A random sort took 748 comparisons and 786 moves.
A nearly ordered sort took 419 comparisons and 230 moves.

This is the Heap Sort for an array of 7500:

A random sort took 255214 comparisons and 270029 moves.
A nearly ordered sort took 265681 comparisons and 286056 moves.

This is the Shell Sort for an array of 7500:

A random sort took 173599 comparisons and 256106 moves.
A nearly ordered sort took 82508 comparisons and 165015 moves.

This is the Quick Sort for an array of 7500:

A random sort took 104984 comparisons and 85566 moves.
A nearly ordered sort took 75789 comparisons and 17663 moves.


Based on the data, barring it not being incorrect, it seems that 
quick sort is the most efficent at sorting large unsorted arrays and 
large nearly sorted arrays. 
*/