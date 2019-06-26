#include<iostream>
#include<cstdlib>
#include<ctime>
int userguess();
void successful();
void unsucessful(int randomnum);
void sorry();
int main()
{
	int i = 0,flag = 0;
	srand(time(0));
		int randomnum = 1 + (rand()%20);
		//std::cout<<"\nRandom number is: "<<randomnum;
		std::cout<<"\nI am thinking of a number between 1 and 20\nCan you guess what it is? ";
		//int guess = userguess();
		while(i<5)
		{
			int guess = userguess();
			if(guess<randomnum)
				std::cout<<"\nYour guess is low. Try again.\n";
			else if(guess>randomnum)
				std::cout<<"\nYour guess is high. Try again.\n";
			else if(guess == randomnum)
				{
					flag = 1;
					successful();
					break;
				}
			i++;		
		}
		if(i=5 && flag!=1)
			unsucessful(randomnum);
}

int userguess()
{
	int userguess;
	std::cin>>userguess;
	return userguess;
}

void successful()
{
	std::cout<<"\nCongratulations! You did it!\n";
}
void unsucessful(int randomnum)
{
	std::cout<<"\nSorry. The number was "<<randomnum<<'\n';
	std::cout<<"You should have gotten it by now. \nBetter luck next time!";
}