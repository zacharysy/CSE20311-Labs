// Zachary Sy
// Some Grades Statistics

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// prototypes ...
int count(int*);
float mean(int*, int);
float stdDev(int*, int);

int main(){
	int grades[50] = 
		{ 96,73,62,87,80,63,93,79,71,99,
		82,83,80,97,89,82,93,92,95,89,
      71,97,91,95,63,81,76,98,64,86,
      74,79,98,82,77,68,87,70,75,97,
      71,94,68,87,79, -1 };

  	// rest of program goes here ...
  	int gradeCount = count(grades);
  	
  	cout << fixed << setprecision(2);
  	cout << "There are " << count(grades) << " grades" << endl;
	cout << "Average: " << mean(grades, gradeCount) << endl;
	cout << "Standard Deviation: " << stdDev(grades,gradeCount) << endl;

  return 0;
}

// Get array size
int count(int *arr){
	int i = 0;
	while(arr[i] >= 0){
		i++;
	}
	
	return i;
}

// Average
float mean(int *nums, int arrSize){
	float sum = 0;
	
	for(int i = 0; i < arrSize; i++){
		sum += nums[i];	
	}
	
	return sum/arrSize;
}

// Standard Deviation
float stdDev(int *nums, int arrSize){
	float sum = 0;
	float avg = mean(nums, arrSize);
	
	for(int i = 0; i < arrSize; i++){
		sum += pow(nums[i]-avg,2);
	}
	
	return sqrt(sum/arrSize);
}