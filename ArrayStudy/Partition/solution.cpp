#include <iostream>
#include <vector>

using namespace std;

/**
 * function that finds count the number of ways to split all the elements 
 * of the array into 3 contiguous parts so that the sum of elements 
 * in each part is the same.
 *
 * @param[in] A number of elements in B
 * @param[in] B 1D integer array
 *
 * @return count the number of ways. 
 *
 */
int solve(int A, vector<int>& B)
{
	int result = 0;
	
	// number of elements in B should be equal or greater than 3
	if(A < 3)
	{
		cout << "WARNING: Element count should be equal or greater than 3" << endl;
		return result;
	}

	// find the sum of elements in B
	int sum = 0;
	for(int i = 0; i < A; ++i)
	{
		sum += B[i];
	}

	// sum should be multiple of 3
	if(sum % 3 != 0)
	{
		cout << "WARNING: Sum of array should be multiple of 3" << endl;
		return result;
	}

	// each subset sum
	int subsetSum = sum / 3;

	// prefix array which holds cumulative sum of elements 
	// between 0 to ith in each index
	int* prefixArray = new int[A];
	if(prefixArray == NULL)
	{
		cout << "WARNING: Memory problem!\nPrefix array can not be created." << endl;
		return result;
	}
	
	// suffix array which holds cumulative sum of elements 
	// between ith to A - 1 in each index
	int* suffixArray = new int[A];
	if(suffixArray == NULL)
	{
		cout << "WAWNING: Memory problem!\nSuffix array can not be created." << endl;
		delete prefixArray;
		return result;
	}
	
	// filling prefix and suffix arrays with cumulative sums
	int prefixSum = 0;
	int suffixSum = 0;
	int suffixIndex = A - 1;
	for(int i = 0; i < A; ++i)
	{
		prefixSum += B[i];
		prefixArray[i] = prefixSum;
		
		suffixSum += B[suffixIndex];
		suffixArray[suffixIndex] = suffixSum;
		--suffixIndex;
	}

	// traverse prefix and suffix array
	// and calculating ways
	for(int i = 0; i < A; ++i)
	{
		if(subsetSum == prefixArray[i])
		{
			for(int j = i + 2; j < A; ++j)
			{
				if(suffixArray[j] == subsetSum)
				{
					++result;
				}
			}
			break;
		}
	}
			 
	// release memory 
	if(prefixArray != NULL)
	{
		delete prefixArray;
	}
	// release memory
	if(suffixArray != NULL)
	{
		delete suffixArray;
	}

	return result;
}

int main(int argc, char* argv[])
{
	vector<int> B = {1, 2, 3, 0, 3};
	int A = B.size();

	int result = solve(A, B);
	cout << "result: " << result << endl;
	return 0;

}