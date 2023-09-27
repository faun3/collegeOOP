#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXK 100

int staticDuplicateSmallestK(int* arr, int* size, int k)
{
	if (*size < k) {
		// the array's size is not greater than k
		return -10;
	}

	if (*size == 0 || k == 0) {
		// the size of the array or the size of k cannot be 0
		return -20;
	}

	// this will work for a k up to MAXK / 2, maybe try and make this into a dynamic allocation
	//     for better flexibility
	int smallest[MAXK];
	for (int i = 0; i < MAXK; i++) {
		// we use the INT_MAX macro to make sure that every element can be smaller
		smallest[i] = INT_MAX;
	}

	// k^2 * n worst / average case time complexity
	for (int iter = 0; iter < k; iter++) {
		for (int i = 0; i < *size; i++) {
			// for each element that is smaller than the currently occupied position
			if (arr[i] < smallest[iter]) {
				bool uniq = true;
				// we check if it has been added to our array of highest numbers yet
				for (int j = 0; j < iter; j++) {
					if (smallest[j] == arr[i])
					{
						uniq = false;
						break;
					}
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

	int i = 0;
	while (i < (*size)) {
		for (int j = 0; j < k; j++) {
			if (arr[i] == smallest[j]) {
				// shift all elements to the right to make space for duplication
				for (int p = (*size - 1); p >= i; p--) {
					arr[p + 1] = arr[p];
				}
				(*size)++;
				i++;
			}
		}
		i++;
	}

	return 0;
}

 int dynamicDuplicateSmallestK(int** arr, int *size, int k)
{
	if (*size < k) {
		// the array's size is not greater than k
		return -10;
	}

	if (*size == 0 || k == 0) {
		// the size of the array or the size of k cannot be 0
		return -20;
	}

	int* smallest = malloc(sizeof(*smallest) * k);
	if (!smallest) {
		// no memory to allocate
		return -30;
	}
	for (int i = 0; i < k; i++) {
		// we use the INT_MAX macro to make sure that every element can be smaller
		smallest[i] = INT_MAX;
	}

	// k^2 * n worst / average case time complexity
	for (int iter = 0; iter < k; iter++) {
		for (int i = 0; i < *size; i++) {
			// for each element that is smaller than the currently occupied position
			if ((*arr)[i] < smallest[iter]) {
				bool uniq = true;
				// we check if it has been added to our array of highest numbers yet
				for (int j = 0; j < iter; j++) {
					if (smallest[j] == (*arr)[i])
					{
						uniq = false;
						break;
					}
				}
				// and if it's unique, we add it to the end
				if (uniq) {
					smallest[iter] = (*arr)[i];
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

	int* tempArr = (int*)realloc(*arr, (2 * (*size)) * sizeof(int));
	if (!tempArr) {
		// no space to reallocate
		free(*arr);
		return -50;
	}
	*arr = tempArr;

	int i = 0;
	while (i < (*size)) {
		for (int j = 0; j < k; j++) {
			if ((*arr)[i] == smallest[j]) {
			// shift all elements to the right to make space for duplication
			for (int p = ((*size) - 1); p >= i; p--) {
				(*arr)[p + 1] = (*arr)[p];
			}
			(*size)++;
			i++;
			}
		}
		i++;
	}

	free(smallest);
	return 0;
}


int main(void)
{
	int size = 6;
	int dynSize = 6;
	int v[20] = { 10, 1, 3, 1, 7, 5 };

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


	const int staticReturnCode = staticDuplicateSmallestK(v, &size, 3);

	if (staticReturnCode != 0) {
		// errored on static array
		return staticReturnCode;
	}

	printf_s("Static array after: \n");
	for (int i = 0; i < size; i++) {
		printf_s("%d ", v[i]);
	}
	printf_s("\n");


	printf_s("Dynamic array before: \n");
	for (int i = 0; i < dynSize; i++) {
		printf_s("%d ", dynamicArr[i]);
	}
	printf_s("\n");

	const int dynamicReturnCode = dynamicDuplicateSmallestK(&dynamicArr, &dynSize, 2);

	if (dynamicReturnCode != 0) {
		return dynamicReturnCode;
	}

	printf_s("Dynamic array after: \n");
	for (int i = 0; i < dynSize; i++) {
		printf_s("%d ", dynamicArr[i]);
	}
	printf_s("\n");


	free(dynamicArr);

	return 0;
}

