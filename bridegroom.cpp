#include<iostream>
using namespace std;
string groom[3] = {"X", "Y", "Z"};
int match()
{
	string match_A,match_B;
	for(int i=0; i<3; i++)
	{
		if(groom[i] == "X")
			continue;
		match_A = groom[i];

		for(int j=0; j<3; j++)
		{

                        if(groom[j] == match_A)
				continue;
			match_B = groom[j];

			for(int k=0; k<3; k++)
			{
				if(groom[k] == "X"||groom[k] == "Z")
					continue;
                                if(groom[k] == match_A || groom[k] == match_B)
					continue;

				cout<<"A"<<match_A<<endl;
				cout<<"B"<<match_B<<endl;
				cout<<"C"<<groom[k]<<endl;

			}
		
		
		}
	}
}
int main()
{
	match();
	return 0;
}
