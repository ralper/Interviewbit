#include <iostream>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <map>

using namespace std;

#ifndef __FUNCTION_NAME__
    #ifdef WIN32   //WINDOWS
        #define __FUNCTION_NAME__   __FUNCTION__  
    #else          //*NIX
        #define __FUNCTION_NAME__   __func__ 
    #endif
#endif

// constant global variable to hold r, g, and b characters.
const char* RGB = "rgb";

/**
 * function that creates NxM 2D character matrix 
 * 
 * @param[in/out] A pointer to 2D character matrix
 * @param[in] N number of row count
 * @param[in] M number of column count
 *
 * @return true if matrix creation can be done successfully, otherwise false
 **/
bool createMatrix(char*** A, int N, int M)
{
	bool result = true;

	if(A == NULL)
	{
		cout << "Error: NULL pointer problem!\n[createMatrix] Pointer to matrix can not be NULL." << endl;
		result = false;
	}

	if(result == true)
	{
		*A = new char*[M];
		if(*A == NULL)
		{
			cout << "Error: Memory problem!\n[createMatrix] Rows can not be allocated." << endl;
			result = false;
		}
	}

	if(result == true)
	{
		for(int i = 0; i < N; ++i)
		{
			(*A)[i] = new char[M + 1]; // +1 for \0
			if((*A)[i] == NULL)
			{
				cout << "Error: Memory problem!\n[createMAtrix] " << i <<"'th row can not be created." << endl;
				for(int j = i; j >= 0; --j)
				{
					delete (*A)[j];
				}
				result = false;
				break;
			}
			(*A)[i][M] = '\0'; // set last cell of A to \0 to make it string 
		}
	}
	return result;
}

/**
 * function that releases memory allocated for NxM 2D character matrix
 *
 * @param[in/out] A pointer to 2D character matrix
 * @param[in] N number of row count
 * @param[in] M number of column count
 *
 * @return true if memory release can be done successfully, otherwise false
 **/ 
bool freeMatrix(char** A, int N, int M)
{
	bool result = true;

	if(A == NULL)
        {
                cout << "Error: NULL Pointer!\n[freeMatrix] Pointer to matrix can not be NULL." << endl;
                result = false;
        }

	if(result == true && N <= 0)
	{
		cout << "Error: Dimension problem!\n[freeMatrix] Row count can not be 0." << endl;
		result = false;
	}

	if(result == true && M <= 0)
	{
		cout << "Error: Dimension problem!\n[freeMAtrix] Column count can not be 0." << endl;
		result = false;
	}

	if(result == true)
	{
		for(int i = 0; i < N; ++i)
		{
			if(A[i] != NULL)
			{
				delete A[i];
			}
		}

		delete A;
	}

	return result;

}

/**
 * function that checks error for NxM 2D character matrix
 *
 * @param[in] tag predefined string for log
 * @param[in/out] A pointer to 2D character matrix
 * @param[in] N number of row count
 * @param[in] M number of column count
 *
 * @return true if there is no error, otherwise false
 **/
bool checkErrors(const char* tag, char** A, int N, int M)
{
	bool result = true;

	if(A == NULL)
        {
                cout << "Error: NULL Pointer!\n"<< tag <<"[checkErrors] Pointer to matrix can not be NULL." << endl;
                result = false;
        }

        if(result == true && N < 2)
        {
                cout << "Error: Dimension Problem!\n" << tag << "[checkErrors] Row count can not be less than 2" << endl;
                result = false;
        }

        if(result == true && M < 2)
        {
                cout << "Error: Dimension Problem!\n" << tag << "[checkErrors] Column count can not be less than 2" << endl;
                result = false;
        }

	return result;
}

/**
 * function that fills NxM 2D character matrix with r, g, and b characters, randomly.
 *
 * @param[in/out] A pointer to 2D character matrix
 * @param[in] N number of row count
 * @param[in] M number of column count
 *
 **/
void fillMatrix(char** A, int N, int M)
{
	bool checkResult = checkErrors(__FUNCTION_NAME__, A, N, M);
	
	if(checkResult == true)
	{
        	int rgbStrLen = strlen(RGB);

        	for(int i = 0; i < N; ++i)
        	{
                	for(int j = 0; j < M; ++j)
                	{
                        	A[i][j] = RGB[rand() % rgbStrLen]; // rand() % rgbStrLen will produce random index for RGB array which holds r, g, and b charachters, respectively.
                	}
        	}
	}
}

/**
 * function that prints NxM 2D character matrix cells.
 *
 * @param[in/out] A pointer to 2D character matrix
 * @param[in] N number of row count
 * @param[in] M number of column count
 *
 **/
void printMatrix(char** A, int N, int M)
{
	bool checkResult = checkErrors(__FUNCTION_NAME__, A, N, M);

	if(checkResult == true)
	{
		cout << endl; // new line
		for(int i = 0; i < N; ++i)
		{
			for(int j = 0; j < M; ++j)
			{
				cout << A[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
}

/**
 * function that creates NxM 2D character matrix
 *
 * @param[in/out] A pointer to 2D character matrix
 * @param[in] N number of row count
 * @param[in] M number of column count
 *
 * @return true if matrix creation can be done successfully, otherwise false
 **/
int solve(char** A, int n1)
{
	int result = 0;
	int N = n1;
        int M = strlen(A[0]); // assume that each row contains same number of characters. TODO: What if A is already NULL??

	bool checkResult = checkErrors(__FUNCTION_NAME__, A, n1, sizeof(A));

	if(checkResult == true)
	{
		pair<int, int> vertices[3]; // triangle vertices, so element count is 3
	
	}

	return result;
}

int main(int argc, char* argv[])
{
	char** A;
	int N = 5;
	int M = 6;

	srand(time(NULL)); // to obtain random numbers for each run
	
	bool createResult = createMatrix(&A, N, M);
	if(createResult == true)
	{
		fillMatrix(A, N, M);
		printMatrix(A, N, M);

		int triangleArea = solve(A, N);

		cout << "Area of triangle: " << triangleArea << endl;

		freeMatrix(A, N, M);
	}

	return 0;
}

