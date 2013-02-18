// Programmer: Anthony Mascia
// Course: CMPT 238
// Due Date: November 15, 2012
//
// Program 7: Binary Search
//
// The purpose of this program is to demonstrate the use of the
// binary search method. This program will implement the method both
// iteratively and recursively and will demonstrate finding valid
// and invalid values in the array list.


// Preprocessor Directives
#include <iostream>
using namespace std;

// Function prototypes
int binarySearchIterative(int array[], int size, int value);
int binarySearchRecursive(int array[], int value, int first, int last);

int main()
{
	const int size = 100;
	int myArrayList[size];
	
	// Set array list
	for(int i = 0; i < size; i++)
		myArrayList[i] = i;


	// Display array list
	cout << 
		"### Here is your array list ###\n" <<
		"-------------------------------\n\n";
	for(int i = 0; i < size; i++)
		cout << myArrayList[i] << endl;
	cout << endl << endl;



	//***************************
	//** SEARCHING ITERATIVELY **
	//***************************
	cout << " ---- SEARCHING ITERATIVELY ----\n\n";

	/** ITERATIVE SEARCH FOR VALID VALUE **/
	cout << "Searching for 5..." << endl;
	if(binarySearchIterative(myArrayList, size, 5) != -1)
	{
		 cout << "5 is FOUND and is at position: "
			  << binarySearchIterative(myArrayList, size, 5)
			  << endl << endl;
	}
	else
		cout << "5 is NOT FOUND in this array list." << endl << endl;


	/** ITERATIVE SEARCH FOR INVALID VALUE **/
	cout << "Searching for 250..." << endl;
	if(binarySearchIterative(myArrayList, size, 250) != -1)
	{
		 cout << "250 is FOUND and is at position: "
			  << binarySearchIterative(myArrayList, size, 250)
			  << endl << endl;
	}
	else
		cout << "250 is NOT FOUND in this array list." << endl << endl;


	cout << endl << endl;


	//***************************
	//** SEARCHING RECURSIVELY **
	//***************************
	cout << " ---- SEARCHING RECURSIVELY ----\n\n";

	/** RECURSIVE SEARCH FOR VALID VALUE **/
	cout << "Searching for 66..." << endl;
	if(binarySearchRecursive(myArrayList, 66, 0, size - 1) != -1)
	{
		 cout << "66 is FOUND and is at position: "
			  << binarySearchRecursive(myArrayList, 66, 0, size - 1)
			  << endl << endl;
	}
	else
		cout << "66 is NOT FOUND in this array list." << endl << endl;


	/** RECURSIVE SEARCH FOR INVALID VALUE **/
	cout << "Searching for 100..." << endl;
	if(binarySearchRecursive(myArrayList, 100, 0, size - 1) != -1)
	{
		 cout << "100 is FOUND and is at position: "
			  << binarySearchRecursive(myArrayList, 100, 0, size - 1)
			  << endl << endl;
	}
	else
		cout << "100 is NOT FOUND in this array list." << endl << endl;




	return 0;
}


//****************************************************
// Function that performs binary search iteratively **
//****************************************************
int binarySearchIterative(int array[], int size, int value)
{
	int first = 0, // First array element
		last = size - 1, // Last array element
		middle, // Mid point of search
		position = -1; // Position of search value
	bool found = false; // Flag
		
	while (!found && first <= last)
	{
		middle = (first + last) / 2; // Calculate mid point
		if (array[middle] == value) // If value is found at mid
		{
			found = true;
			position = middle;
		}
		else if (array[middle] > value) // If value is in lower half
			last = middle - 1;
		else
			first = middle + 1; // If value is in upper half
	}
	return position;

} 


//*****************************************************
// Function that performs binary search recursively  **
// - Takes in the array, value to be found, and uses **
// the first and last indexes of the array. These    **
// indexes are what is changed during the recursive  **
// step.											 **
//*****************************************************
int binarySearchRecursive(int array[], int value, int first, int last)
{
	bool found = false; // Set flag

	if(!found && last < first){ // Base case. When value not found
		return -1;
	}
	else
	{
		int middle = (first + last) / 2; // Set midpoint of array

		/* 
		   Next two recursive steps determine general position the value
		   is in and splits the array accordingly
	    */
		if(array[middle] > value)
			return binarySearchRecursive(array, value, first, last-1);
		else if(array[middle] < value)
			return binarySearchRecursive(array, value, first+1, last);
		/* 
		   This last step is when middle = value.
		   Meaning we have found the value in the array list and can return
		   its position to the user
	    */
		else 
		{
			found = true;
			return middle;
		}
	}
}