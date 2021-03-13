#include <stdio.h>

void takeDerivative(int *sourceArray, int *targetArray, int length);
int getArrayLength(int *arr);
void takeSigns(int *sourceArray, int *targetArray, int length);

// Create signal
//  int[] sinwave = [
//     0,   285,   571,   857,  1142,  1427,  1712,  1996,  2280,  2563,
//     2845,  3126,  3406,  3685,  3963,  4240,  4516,  4790,  5062,  5334,
//     5603,  5871,  6137,  6401,  6663,  6924,  7182,  7438,  7691,  7943,
//     8191,  8438,  8682,  8923,  9161,  9397,  9630,  9860, 10086, 10310,
//     10531, 10748, 10963, 11173, 11381, 11585, 11785, 11982, 12175, 12365,
//     12550, 12732, 12910, 13084, 13254, 13420, 13582, 13740, 13894, 14043,
//     14188, 14329, 14466, 14598, 14725, 14848, 14967, 15081, 15190, 15295,
//     15395, 15491, 15582, 15668, 15749, 15825, 15897, 15964, 16025, 16082,
//     16135, 16182, 16224, 16261, 16294, 16321, 16344, 16361, 16374, 16381,
//     16384
// ];



void takeDerivative(int *sourceArray, int *derivative, int length){

	for (int i=0; i<length; i++) {
		derivative[i] = sourceArray[i+1] - sourceArray[i];
	}
}

void takeSigns(int *sourceArray, int *signs, int length){

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

int getArrayLength(int &arr[]) {
	return sizeof(arr)/sizeof(arr[0]);
}

void main()
{
	int simpleSignal[24] = {0,0,1,1,2,4,5,7,12,10,5,4,4,3,1,0,0,0,2,3,5,2,1,0};
	int firstDerivative[getArrayLength(simpleSignal)-1];
	int secondDerivative[getArrayLength(firstDerivative)-1];
	int signsOf2ndDeriv[getArrayLength(secondDerivative)];
	
	takeDerivative(simpleSignal, firstDerivative, getArrayLength(simpleSignal)); 
	takeDerivative(firstDerivative, secondDerivative, getArrayLength(firstDerivative));
	
	// simplify the problem, we just care about signs of the slopes to get the peak
	takeSigns(secondDerivative, signsOf2ndDeriv, getArrayLength(secondDerivative));
	
	
	printf(simpleSignal);
	printf(firstDerivative);
	printf(secondDerivative);
	printf(signsOf2ndDeriv);
	
}

