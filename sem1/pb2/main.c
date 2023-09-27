// this will only work in a C file
// a C++ array decays if you pass a function a pointer / reference to it
// and the replaceLargestThree fn will error on compile

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int replaceLargestThree(int* arr, int size) {
	if (size < 3) {
		// there are not enough elements in the vector to compute the 3 largest
		return -1;
	}
	int top[3] = { -999, -999, -999};
	// iterate 3 times, can be swapped for n with a bit of effort
	for (int iter = 0; iter < 3; iter++) {
		for (int i = 0; i < size; i++) {
			// for each element that is larger than the currently occupied position
			if (arr[i] > top[iter]) {
				bool uniq = true;
				// we check if it has been added to our array of highest numbers yet
				for (int j = 0; j < iter; j++) {
					if (top[j] == arr[i]) uniq = false;
				}
				// and if it's unique, we add it to the end
				if (uniq) {
					top[iter] = arr[i];
				}
			}
		}
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < 3; j++) {
			if (top[j] == arr[i]) arr[i] = -1;
		}
	}

	return 0;
}

int main(void)
{
	int size = 7, v[] = {10, 1, 3, 1, 7, 5, 5};

	const int ret = replaceLargestThree(&v, size);
	
	if (ret) {
		printf_s("Error in replace function -- static allocation");
		return -100;
	}

	printf_s("Static array after replacement is: \n");
	for (int i = 0; i < size; i++) {
		printf_s("%d ", v[i]);
	}
	printf_s("\n");

	int* dynamicArr = (int*)malloc(sizeof(int) * size);
	if (dynamicArr) {
		dynamicArr[0] = 10;
		dynamicArr[1] = 1;
		dynamicArr[2] = 3;
		dynamicArr[3] = 1;
		dynamicArr[4] = 7;
		dynamicArr[5] = 5;
		dynamicArr[6] = 5;
	}
	
	const int ret2 = replaceLargestThree(dynamicArr, size);

	if (ret2) {
		printf_s("Error in replace function -- dynamic allocation");
		return -101;
	}

	printf_s("Dynamic array after replacement is: \n");
	for (int i = 0; i < size; i++) {
		printf_s("%d ", dynamicArr[i]);
	}
	printf_s("\n");

	return 0;
}