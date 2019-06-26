#include<iostream>
int main()
{
	int tv,vcr,rc,cd,tr;
	const float taxrate=8.25,unittv=400.00,unitvcr=220.00,unitrc=35.20,unitcd=300.00,unittr=150.00;
	float totaltv,totalvcr,totalrc,totalcd,totaltr,subtotal;
	std::cout<<"\nHow many TVs were sold?";
	std::cin>>tv;
	totaltv = unittv*tv;
	std::cout<<"\nHow many VCRs were sold?";
	std::cin>>vcr;
	totalvcr = unitvcr*vcr;
	std::cout<<"\nHow many Remote Controllers were sold?";
	std::cin>>rc;
	totalrc = unitrc*rc;
	std::cout<<"\nHow many CDs were sold?";
	std::cin>>cd;
	totalcd = unitcd*cd;
	std::cout<<"\nHow many tape recorders were sold?";
	std::cin>>tr;
	totaltr = unittr*tr;
	subtotal = totaltv+totalvcr+totalrc+totalcd+totaltr;
	 std::cout<<"QTY   DESCRIPTION    UNIT PRICE   TOTAL PRICE\n";
	 std::cout<<"---   -----------    ----------   -----------\n";
	 std::cout<<tv<<"     TV             400          "<<totaltv<<std::endl;
	std::cout<<vcr<<"     VCR            220          "<<totalvcr<<std::endl;
	 std::cout<<rc<<"     REMOTE CTRLR   35.20        "<<totalrc<<std::endl;
	 std::cout<<cd<<"     CD PLAYER      300          "<<totalcd<<std::endl;
	 std::cout<<tr<<"     TAPE RECORDER  150          "<<totaltr<<std::endl;
	 std::cout<<"                                  -----------\n";
	 std::cout<<"                        SUBTOTAL     "<<subtotal<<std::endl;
	 std::cout<<"                        TAX          "<<(taxrate/100)*subtotal<<std::endl;
	 std::cout<<"                        TOTAL        "<<taxrate*subtotal+subtotal<<std::endl;


}