int calculateHash(const string& str,int start,int end)
{
	int prime = 101;
	for(int i=start;i<=end;++i)
	{
		int hashvalue;
		hashvalue = (hashvalue *prime + str[i]) % INT_MAX;
	}
}

void rabinkarp(const string& text,const string& pattern)
{
	int patternlength=pattern.length();
	int textlength=text.length();
	int patternhash=calculatehash(pattern,0,patternlength-1);
	int texthash=calculatehash(text,0,patternlength-1);
	
	for(int i=0;i<=textlength;i++)
	{
		if(patternhash==texthash)
		{
			int j;
		for(int j=0;j<patternlength;j++)
		{
			if(text[i+j]!=pattern[j])
			{
				break;
			}
		}
		if(j==patternlength)
		{
			cout<<"Found"<<endl;	
		}
	}
	if (i < textLength - patternLength)
	{
        textHash = (prime * (textHash - text[i] * pow(prime, patternLength - 1))) % INT_MAX;
        if (textHash < 0) 
		{
            textHash += INT_MAX;
        }
            textHash = (textHash + text[i + patternLength]) % INT_MAX;
    }
}