#include<iostream>
//learning typedef declarations      syntax : typedef fundamental_data_type new_name;
/*
typedef int hello;
int main()
{
	hello x,y;           //x and y are of int type
	std::cout<<sizeof(x)<<std::endl;  
}
*/

//learning #define preprocessor      syntax : #define identifier value
#define length 10
#define width 5
#define newline '\n'
int main()
{
	std::cout<<"area="<<length*width<<newline;
}
