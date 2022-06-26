#include <iostream>
using namespace std;
int main()
{
	long int A = 0x11'22'33'44;
	int B = 0x55'66;
	std::cout.unsetf(std::ios::dec);
	std::cout.setf(std::ios::hex);
	std::cout << A << "\n" << B << "\n";
	__asm 
	{
		mov AL, byte ptr A + 2;
		xchg byte ptr B + 1, AL;
		xchg byte ptr A + 3, AL;
		xchg byte ptr B, AL;
		mov byte ptr A+2, AL

		mov AL, byte ptr A;
		xchg byte ptr B, AL;
		mov byte ptr A, AL
	}

	printf("\nByte numbering after permutations: \n");
	printf("A = %lx\nB = %x\n", A, B);
	return 0;
}
