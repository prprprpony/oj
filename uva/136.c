#include <stdio.h>

int min(int a,int b)
{
	return ( a > b )? b : a ;
}

int main()
{
        int request=1500;
	int factor[]={2,3,5},ugly_number[request+1];
	ugly_number[1]=1;
	int num_factor=sizeof(factor)/sizeof(int);
	int* cur[]={&ugly_number[1],&ugly_number[1],&ugly_number[1]};

	int i;	
	for(i=2;i<=request;i++)
	{
		int j;
		ugly_number[i]=factor[0] * (*cur[0]);
		for(j=1;j<num_factor;j++)
			ugly_number[i]=min(ugly_number[i],factor[j] * (*cur[j]) );
		for(j=0;j<num_factor;j++)
			if(factor[j] * (*cur[j]) == ugly_number[i]) cur[j]++;
	}


	printf("The %d'th ugly number is %d.\n", request , ugly_number[request] );

	return 0;
}
