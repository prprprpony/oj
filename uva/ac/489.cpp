#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main()
{
	int num_round;
	while( scanf("%d",&num_round)==1 && num_round != -1)
	{
		getchar(); 

		bool puzzle[26]={0},guessed[26]={0};
		char c;
		int num_puzzle=0,stroke=0;

		while( (c=getchar()) !='\n')
		{
			c-='a';
			if(puzzle[c] == false)
			{
				puzzle[c]=true;
				num_puzzle++;
			}
		}

		bool judged = false;
		string state="chickened out";
		while( (c=getchar()) !='\n')
		{
			if(judged)continue;	
			c-='a';
			if(guessed[c] == false)
			{
				guessed[c]=true;
				if(puzzle[c]==true)
				{
					num_puzzle--;
					if(num_puzzle==0)
					{
						state="win";
						judged = true;
					}
				
				}
				else
				{
					stroke++;
					if(stroke==7)
					{
						state="lose";
						judged = true;
					}
				}
			}	
		}

		cout<<"Round "<<num_round<<endl;
		cout<<"You "<<state<<"."<<endl;



	}

	return 0;
}
