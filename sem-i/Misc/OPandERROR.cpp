//OUTPUT AND ERROR CLASS QUESTIONS
#include<iostream>
/*
long bfun(int x, int y = 5, float z = 3)
{
	return (++x*++y+(int)++z);
} 
int main()
{
	std::cout<<bfun(20,10); //235
}
*/

/*
int bfun(int a, int b = 3, int c = 3)
{
	std::cout<<++a*++b*--c;
	return 0;
}
int main()
{
	bfun(5,0,0); //-6
	return 0;
}
*/

/*
long getnumber(long int no)
{
	return --no;
}
float getnumber(int no)  //if this function wouldn't have been there it'd get self typecasted and the op will be 19 29
{
	return ++no;
}
int main()
{
	int x = 20, y = 30;
	std::cout<<getnumber(x)<<'\n';//19
	std::cout<<getnumber(y);//29
}
*/


/*
long factf(long = 5); //default value to be given here
int main()
{
	for(int i = 0;i<=0;i++)
		std::cout<<factf()<<std::endl;
	return 0;
}
long factf(long x)
{
	if(x<2)
		return 1;
	long fact = 1;
	for(long i=1;i<=x-1;i++)
		fact*=i;
	return fact;
}
*/

/*
int i;
int fun();
int main()
{
	while(i)
		fun();
	std::cout<<"\nHello\n";
	return 0;
}
int fun()
{
	std::cout<<"Hi";
}
*/

/*
int fun(int);
int main()
{
	int i = fun(10);
	std::cout<<--i;//9
	return 0;
}
int fun(int i)
{
	return i++;
}
*/


/*int f(int a)
{
	a>20?:return 10: return 20; //error because operands must be expressions in ternary (conditional) operator
}	
int f(int);
int main()
{
	int b;
	b=f(20);
	std::cout<<b;
	return 0;
}
*/

