#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXK 100

int duplicateSmallestK(int* arr, int size, int k)
{
	if (size < k) {
		// the array's size is not greater than k
		return -10;
	}

	if (size == 0 || k == 0) {
		// the size of the array or the size of k cannot be 0
		return -20;
	}

	// this will work for a k up to 100, maybe try and make this into a dynamic allocation
	//     for better flexibility
	int smallest[MAXK];
	for (int i = 0; i < MAXK; i++) {
		// we use the INT_MAX macro to make sure that every element can be smaller
		smallest[i] = INT_MAX;
	}

	for (int iter = 0; iter < k; iter++) {
		for (int i = 0; i < size; i++) {
			// for each element that is smaller than the currently occupied position
			if (arr[i] < smallest[iter]) {
				bool uniq = true;
				// we check if it has been added to our array of highest numbers yet
				for (int j = 0; j < iter; j++) {
					if (smallest[j] == arr[i]) uniq = false;
				}
				// and if it's unique, we add it to the end
				if (uniq) {
					smallest[iter] = arr[i];
				}
			}
		}
	}

	for (int i = 0; i < k; i++) {
		if (smallest[i] == INT_MAX) {
			// there are less than k distinct elements in the array
			return -30;
		}
	}

	printf_s("Contents of smallest are: \n");
	for (int i = 0; i < k; i++) {
		printf_s("%d ", smallest[i]);
	}
	printf_s("\n");
	
	return 0;

}

int main(void)
{
	int size = 6;
	int v[] = { 10, 1, 3, 1, 7, 5 };

	int* dynamicArr = (int*)malloc(sizeof(int) * size);
	if (!dynamicArr) {
		printf_s("No memory to allocate");
		return -1;
	}
	dynamicArr[0] = 10;
	dynamicArr[1] = 1;
	dynamicArr[2] = 3;
	dynamicArr[3] = 1;
	dynamicArr[4] = 7;
	dynamicArr[5] = 5;

	printf_s("Static array before: \n");
	for (int i = 0; i < size; i++) {
		printf_s("%d ", v[i]);
	}
	printf_s("\n");

	printf_s("Dynamic array before: \n");
	for (int i = 0; i < size; i++) {
		printf_s("%d ", dynamicArr[i]);
	}
	printf_s("\n");

	const int staticReturnCode = duplicateSmallestK(v, size, 6);

	return 0;
}

