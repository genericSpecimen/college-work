//learning storage types: auto(default),register,static,extern
//auto(default)
#include<iostream>
/* AUTO STORAGE TYPE(local scope)
void incr()
{
	auto i=0;
	std::cout<<i<<'\n';
	i++;
}
int main()
{
	incr();//0
	incr();//0
	incr();//0
	return 0;
}
*/

/* REGISTER STORAGE TYPE(local scope)
void incr()
{
	register int i =0;
	std::cout<<i<<'\n';
	i++;
}
int main()
{
	incr();//0
	incr();//0
	incr();//0
	incr();//0
	return 0;
}
*/

/* STATIC STORAGE TYPE(scope is local to file)
void incr()
{
	static int i=0;
	std::cout<<i<<'\n';
	i++;
}
int main()
{
	incr();//0
	incr();//1
	incr();//2
	incr();//3
	return 0;
}
*/

/* EXTERN STORAGE TYPE (global scope)
extern int x;
int x=10;//can initialise before main() also
int main()
{
	extern int i; //cannot initialise value of i here. extern int i = 0 is prohibited.
	i+=10;
	std::cout<<i<<std::endl<<x;
	return 0;
} int i = 12;//can initialise after main() also
*/
