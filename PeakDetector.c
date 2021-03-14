#include <stdio.h>

#define SIZEOF(arr) sizeof(arr)/sizeof(arr[0])

void takeDerivative(int *sourceArray, int *derivative, int length);
void takeSigns(int *sourceArray, int *targetArray, int length);
void printArray(int *arr, int length);


void takeDerivative(int *sourceArray, int *derivative, int length){
// sourceArray: pointer for source 
// derivative: pointer for target array to store derivative
// length: length of sourceArray

	for (int i=0; i<length; i++) {
		derivative[i] = sourceArray[i+1] - sourceArray[i];
	}
}

void takeSigns(int *sourceArray, int *signs, int length){
// Assign +1 for positive values in a data signal, -1 for negatives, and 0 for 0
	for (int i=0; i<length; i++) {
		if(sourceArray[i] > 0)  {
			signs[i] = 1;
		} else if(sourceArray[i] == 0) {
			signs[i] = 0;
		} else {
			signs[i] = -1;
		}
	} 
}

// Printing output utility
void printArray(int *arr, int length) {
	for(int i=0; i<length; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main()
{
	// Create signal
	int simpleSignal[24] = {0,0,1,1,2,4,5,7,12,10,5,4,4,3,1,0,0,0,2,3,5,2,1,0};

	// allocate memory for arrays
	int firstDerivative[SIZEOF(simpleSignal)-1];
	int signsOfFirstDeriv[SIZEOF(firstDerivative)];
	int secondDerivOfSignsOfFirst[SIZEOF(firstDerivative)-1];

	// Step 1
	takeDerivative(simpleSignal, firstDerivative, SIZEOF(simpleSignal)); 

	// Step 2 simplify the problem, we just care about signs of the f'(x) slopes to get the peak
	takeSigns(firstDerivative, signsOfFirstDeriv, SIZEOF(firstDerivative));

	// Step 3 find derivative of the signs of the first derivative
	takeDerivative(signsOfFirstDeriv, secondDerivOfSignsOfFirst, SIZEOF(secondDerivOfSignsOfFirst));
	
	// Print results
	printf("Peak Detection Example \n");
	printf("Signal:     "); 
	printArray(simpleSignal, SIZEOF(simpleSignal));
	printf("f'(x):      "); 
	printArray(firstDerivative, SIZEOF(firstDerivative));
	printf("f'(x) +/-:  "); 
	printArray(signsOfFirstDeriv,SIZEOF(signsOfFirstDeriv));
	printf("f'(f'(x)+/-):"); 
	printArray(secondDerivOfSignsOfFirst,SIZEOF(secondDerivOfSignsOfFirst));
	
	// Detect the peaks where f''(x) = -2. The peak index from simpleSignal is i+1 of f''(x)
	for(int i=0; i<SIZEOF(secondDerivOfSignsOfFirst); i++){
		if(secondDerivOfSignsOfFirst[i] == -2) {
			printf("Peak Found at index %d, value of %d \n",i+1, simpleSignal[i+1]);
		}
	}

	return 0;
}

