#include<iostream>
int main()
{
	long double e=1;//einitial=1,enext=0;    //2.718281828459
	for(int i=1;i<=20;i++)
		{
			int fact=1;
			long double h;
			for(int j=i;j>0;j--)
				fact= fact*j;
			h = (1/(long double)fact);
			if(h<0.0000001)
				break;
			e = e+h;

			/*enext=einitial+h;
			if((enext-einitial)==0)
			break;
			*/
		}
	std::cout<<e;		
}