char s1[500][100];
char s2[500][100];
int l1,l2;

void spilt(char *s,int* p,int index){
	int l = strlen(s);
	int j = 0,k = 0;
	for(int i = 0;i <= l;i++){
		if(i >= l || *(s+i) == '.')
		{
			if(index == 1)
				s1[j][k++] = '\0';
			else s2[j][k++] = '\0';

			j++;
			k = 0;
		}
		else{
			if(index == 1)
				s1[j][k++] = *(s+i);
			else s2[j][k++] = *(s+i);
		}
	}
	*p = j;
}

int compareVersion(char *version1, char *version2){
	spilt(version1,&l1,1);
	spilt(version2,&l2,2);

	if(l1 > l2){
		for(int i = l2;i < l1;i++)
		{
			s2[i][0] = '0';
			s2[i][1] = '\0';
		}
		l2 = l1;
	}

	if(l1 < l2){
		for(int i = l1;i < l2;i++)
		{
			s1[i][0] = '0';
			s1[i][1] = '\0';
		}
		l1 = l2;
	}


	int i = 0;
	while(i < l1 && i < l2)
	{
	
		int len1 = strlen(s1[i]);
		int len2 = strlen(s2[i]);

		//printf("%d %d\n",len1,len2);

		char c1,c2;
		if(len1 > len2){
			for(int j = 0;j < len1;j++){

				if(j < len1 - len2) c2 = '0';
				else c2 = s2[i][j - len1 + len2];
				c1 = s1[i][j];

				if(c1 > c2) return 1;
				else if(c1 < c2) return -1;
			}
		}
		else if(len1 < len2){
			for(int j = 0;j < len2;j++){

				if(j < len2 - len1) c1 = '0';
				else c1 = s1[i][j - len2 + len1];
				c2 = s2[i][j];

				if(c1 > c2) return 1;
				else if(c1 < c2) return -1;
			}
		}
		else{
			for(int j = 0;j < len1;j++)
			{
				//printf("%c %c\n",s1[i][j],s2[i][j]);
				if(s1[i][j] > s2[i][j]) return 1;
				else if(s1[i][j] < s2[i][j]) return -1;  
			}
		}

		i++;
	}

	return 0;
}