#include<iostream>
void determineQuadrant(float angle)
{
	if(angle>0 && angle<90)
		std::cout<<"\nAngle is in quadrant: "<<"I";
	else if(angle>90 && angle<180)
		std::cout<<"\nAngle is in quadrant: "<<"II";
	else if(angle>180 && angle<270)
		std::cout<<"\nAngle is in quadrant: "<<"III";
	else if(angle>270 && angle<360)
		std::cout<<"\nAngle is in quadrant: "<<"IV";
	else if(angle == 0 || angle == 360)
		std::cout<<"\nIt lies on the positive x-axis\n";
	else if(angle == 90)
		std::cout<<"\nIt lies on the positive y-axis\n";
	else if(angle == 180)
	    std::cout<<"\nIt lies on the negative x-axis\n";
	else if(angle == 270)
	    std::cout<<"\nIt lies on the negative y-axis\n";				
}
int main()
{
	float angle;
	std::cout<<"\nEnter an angle in degrees\n";
	std::cin>>angle;
	determineQuadrant(angle);
}