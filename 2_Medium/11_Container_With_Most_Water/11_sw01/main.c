#define _CRT_SECURE_NO_WARNINGS	

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int height1[] = { 1,8,6,2,5,4,8,3,7 }, heightSize1 = 9;
	int height2[] = { 1,2 }, heightSize2 = 2;
	int expected[] = { 49,1 };
	int result;

	result = maxArea(height1, heightSize1);
	if (result == expected[0])
		printf("Test 1: PASSED - %d", result);
	else
		printf("Test 1: FAILED - Expected: %d, Received: %d", expected[0], result);

	result = maxArea(height2, heightSize2);
	if (result == expected[1])
		printf("\nTest 1: PASSED - %d\n\n", result);
	else
		printf("\nTest 1: FAILED - Expected: %d, Received: %d\n\n", expected[1], result);


	system("pause");
	return 0;
}

int maxArea(int* height, int heightSize) {
	int max_area = 0, area, i = 0, j = heightSize - 1;

	while (i < j)
	{
		if (height[i] < height[j])
		{
			area = height[i] * (j - i);
			i++;
		}
		else
		{
			area = height[j] * (j - i);
			j--;
		}

		if (area > max_area)
			max_area = area;
	}

	return max_area;
}