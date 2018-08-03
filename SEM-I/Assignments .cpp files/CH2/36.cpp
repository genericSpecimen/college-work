#include<iostream>
int main()
{
    /*
    int a,b,c,d,e,f,g,h,i,j;
	std::cout<<"\nEnter 10 numbers\n";
	std::cin>>a>>b>>c>>d>>e>>f>>g>>h>>i>>j;
	std::cout<<std::endl<<a <<' '<< j;
	std::cout<<std::endl<<b <<' '<< i;
	std::cout<<std::endl<<c <<' '<< h;
	std::cout<<std::endl<<d <<' '<< g;
	std::cout<<std::endl<<e <<' '<< f;
	*/
	//using array
	int a[10];
	std::cout<<"\nEnter 10 numbers\n";
	for(int i=0;i<10;i++)
		std::cin>>a[i];
	for(int i=0;i<5;i++)
		std::cout<<std::endl<<a[i]<<' '<<a[9-i];
    return 0;
}
