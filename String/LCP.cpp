for(int i=1;i<=n;i++)
	{
		for(int j=1;j<i;j++)
		{
			lcs[i][j]=(s[i]==s[j])?lcs[i-1][j-1]+1:0
		}
	}
