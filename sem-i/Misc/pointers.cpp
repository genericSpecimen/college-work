//learning pointers
#include<iostream>
/* pointer: a data type that points to another value stored in memory
   declaration: int* p; (preferred) p is a pointer to an int, emphasis on type
                int *p; *p is what is the int, empahasis on syntax
& : address of operator
* : content of operator
using & operator
int x = 25;
int* p = &x;  &x means address of x
cout<<p<<endl;  //output is the address of x

using the * operator
the contents of or dereference operator allows us to get the value stored at 
the address held by the pointer
int x = 25;
int* p = &x;
cout<<*p<<endl;  //output is the value of x; i.e. 25
*p is an alias for x;
x = x + 5;
x = *p + 5;
*p = *p + 5;
cout<<&*p << endl; //output is the address of *p (x)
*/
int main()
{
	int a = 9;
	int* ma = &a;
	std::cout<<"\nMemory location = "<< ma;
	std::cout<<"\nvalue via pointer = "<< *ma;
	std::cout<<"\nValue = "<< a;
}