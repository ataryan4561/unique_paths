#include"header.h"
void unique_paths(int *n,int *m,int *ans)
{
	#pragma HLS INTERFACE s_axilite port=return
	#pragma HLS INTERFACE s_axilite port=n
	#pragma HLS INTERFACE s_axilite port=m
	#pragma HLS INTERFACE s_axilite port=ans
	int a =*n;
	int b =*m;
	int dp[100][100];
	#pragma HLS ARRAY_PARTITION variable=dp complete dim=1
	int i,j;
	loop(i,a)
	{
		#pragma HLS UNROLL factor=2
		#pragma HLS PIPELINE
		dp[i][0] = 1;
	}
	loop(i,b)
	{
		#pragma HLS UNROLL factor=2
		#pragma HLS PIPELINE
		dp[0][i] = 1;
	}
	loop(i,a)
	{
		loop(j,b)
		{
			#pragma HLS UNROLL factor=2
			#pragma HLS PIPELINE
			if(i==0 && j==0)
			{
				continue;
			}
			int r=0;
			int l=0;
			if(i-1>=0)
			{
			  r=dp[i-1][j];
			}
			if(j-1>=0)
			{
			  l=dp[i][j-1];
			}
			dp[i][j]=r+l;
		}
	}
	*ans = dp[a-1][b-1];
}
