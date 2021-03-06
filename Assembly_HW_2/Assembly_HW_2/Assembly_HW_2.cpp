// Assembly_HW_2.cpp : Defines the entry point for the console application.
//

// Assembly_HW_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstdio>
#include <cassert>

// :::

// NOTE:
//   char  data type is signed  8-bit integer (DB in assembler)
//   int data type is signed 16-bit integer (DW in assembler)
//   int   data type is signed 32-bit integer (DD in assembler)

// You can use any integer data type for input values.
// Update the given template code appropriately.

int solution_for_grade_4(int x, int y, int z)
{
	int result;
	__asm
	{
		// Your Inline Assembler instructions for grade 5 go here
		// :::
		mov eax, x;
		add eax, y;
		sub eax, z;
		mov[result], eax; save the result assuming it is in the processor register AX
	}
	return result;
}


int solution_for_grade_5(int x, int y, int z)
{
	int result2;
	__asm
	{
		mov eax, x;
		imul eax, -5;
		mov ebx, y;
		imul ebx, z;
		imul ebx, 2;
		add eax, ebx;
		mov[result2], eax; saves the result
	}
	return result2;
}

int solution_for_grade_6(int x, int y, int z)
{
	int result3;
	__asm
	{
		// X / Y + (Z + 1)3
		xor eax, edx
		xor edx, edx
		mov eax, x;
		mov ebx, y;
		idiv word ptr y;
		push eax;

		mov eax, z;
		add eax, 1;
		mov ebx, eax;
		imul eax, ebx
		imul eax, ebx;

		pop ebx;
		add eax, ebx;



		mov[result3], eax;

	}
	return result3;
}

int solution_for_grade_7(int x, int y, int z)
{
	int result4;
	__asm
	{
		
	//	if (A > 0)
	//	then calculate and save A * B
	//	else calculate and save A * C

		mov eax, x;
		imul eax, -5;
		mov ebx, y;
		imul ebx, z;
		imul ebx, 2;
		add eax, ebx;
		mov ebx,eax ; 

		xor eax, edx
		xor edx, edx
		mov eax, x;
		mov ebx, y;
		idiv word ptr y;
		push eax;

		mov eax, z;
		add eax, 1;
		mov ebx, eax;
		imul eax, ebx
		imul eax, ebx;
		mov ecx,eax; 
		
		
		mov eax, x;
		add eax, y;
		sub eax, z;


		cmp eax, 0;
		
		imul eax, ebx;


		mov[result4], eax;
		

	}
	return result4;
}

int solution_for_grade_8(int x, int y, int z)
{
	int result5;
	__asm
	{





		mov[result5], eax;

	}
	return result5;
}



// :::

int main()
{
	int first = 1;  // Note the int data type range is -32768..32767
	int second = 2;
	int third = 3;

	int result = solution_for_grade_4(first, second, third);
	int result2 = solution_for_grade_5(first, second, third);
	int result3 = solution_for_grade_6(first, second, third);
	int result4 = solution_for_grade_7(first, second, third);
	int result5 = solution_for_grade_8(first, second, third);


	printf("solution_for_grade_5(%d, %d, %d) = %d\n", first, second, third, result);
	printf("solution_for_grade_6(%d, %d, %d) = %d\n", first, second, third, result2);
	printf("solution_for_grade_7(%d, + , %d,) = %d\n", result, result2, result3);
	printf("solution_for_grade_8(%d, * , %d,) = %d\n", result, result2, result4);
	printf("solution_for_grade_9(%d, / , %d,) = %d\n", result, result2, result5);

	// You might need to invoke solution_for_grade_X() functions several times 
	// with different parameter values (e.g., to demonstrate branching).
	// :::

	getchar(); // Wait for the Enter key
	return 0;
}

