# Signal Processing Sandbox

## Peak Detection 

This script shows how local peaks can be identified out of a simple data signal. 

Program Output
``` 
Peak Detection Example 
Signal:     0 0 1 1 2 4 5 7 12 10 5 4 4 3 1 0 0 0 2 3 5 2 1 0 
f'(x):      0 1 0 1 2 1 2 5 -2 -5 -1 0 -1 -2 -1 0 0 2 1 2 -3 -1 -1 
f'(x) +/-:  0 1 0 1 1 1 1 1 -1 -1 -1 0 -1 -1 -1 0 0 1 1 1 -1 -1 -1 
f'(f'(x)+/-):1 -1 1 0 0 0 0 -2 0 0 1 -1 0 0 1 0 1 0 0 -2 0 0 
Peak Found at index 8, value of 12 
Peak Found at index 20, value of 5 
```
