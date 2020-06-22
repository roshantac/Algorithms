#include <stdio.h>
#include <stdlib.h>

//int n = 6;
//int m=5;
/*int input_arry[10][2]= {{1, 2},
                        {1, 3},
                        {2, 3},
                        {3, 4},
                        {3, 5},
                        {4, 5}};*/


int data[][2]={{1,2},
               {1,3},
               {2,3},
               {2,4},
               {4,5},
               {4,6},
               {5,6}};
int nrsu=6, nconn=7;

int directpath(int x, int y,int s)
{
  int i=0;
  for(i=0;i<nconn;i++)
  { if(!((s==data[i][1])||(s==data[i][0])))
	if(((x==data[i][0])&&(x==data[i][1]))||((x==data[i][1])&&(x==data[i][0])))
		return 1;
  }
  return 0;
}

int InPathFinder(int x , int y, int s)
{
	int i=0;
	//printf("\n %d Start Row 0 data \n", x );
	if (x==y)
		return 1;

	for(i=0;i<nconn;i++)
	{
	    if(!((s==data[i][1])||(s==data[i][0])))
        {
		if(x==data[i][0])
			return InPathFinder(data[i][1],y,s);
       /* if(x==input_arry[i][1])
            return InPathFinder(input_arry[i][0],y,s);*/
        }
	}
	return 0;
}
int checkPath(int x,int y , int s)
{
    if(directpath(x,y,s)==1)
        return 1;
    if(InPathFinder(x,y,s)==1)
        return 1;
    return 0;
}

int findMostVulnarable()
{
    int i,j,k,counter[nrsu],large,vulnode;
    for(i =0;i<nrsu;i++)
        {
        counter[i]=0;
        for(j=1;j<=nrsu;j++)
        {
            for(k=1;k<=nrsu;k++)nrsu
            {
                if((j!=k)&&(i!=j)&&(i!=k))
                {
                    if(checkPath(j,k,i)==0)
                        counter[i]++;
                }
            }
        }
    }
    large=counter[0];
    for(i=1;i<nconn;i++){
        if(counter[i]>large)
        {
            large=counter[i];
            vulnode=i+1;
        }
    }
return vulnode;
}
int main()
{
printf("\n The resutn val is %d \n", findMostVulnarable());
#if 0
	int** array;

	array = malloc(n * sizeof(*array)); /* Assuming `n` is the number of rows */
	if(!array) /* If `malloc` failed */
	{
		fputs(stderr, "Error allocating memory; Bailing out!");
		exit(-1);
	}

	int count = 1;
	int i,j;
	for(i = 0; i < n+1; i++)
	{
		array[i] = malloc(count * sizeof(**array));
		if(!array[i]) /* If `malloc` failed */
		{

			for(j = 0; j < i; j++) /* free previously allocated memory */
			{
				free(array[j]);
			}
			free(array);

			fputs(stderr, "Error allocating memory; Bailing out!");
			exit(-1);
		}
		count++;
	}


	FILE* fp;

	if (argc >= 2)
	{
		fp = fopen(argv[1], "r");
	}
	else
	{
		printf("\nPlease provied the input file name \n");
		return 0;
	}
	if(!fp)
	{
		int ia;
		for(ia = 0; ia < n+1; ia++) /* free previously allocated memory */
		{
			free(array[i]);
		}
		free(array);

		fputs(stderr, "Error opening 'file.txt'; Bailing out!");
		exit(-1);
	}

	int max = 1;
	int ib;
	for(ib = 0; ib < n+1; ib++)
	{
		for(count = 0; count < 2; count++)
		{
			fscanf(fp, "%d", &array[ib][count]);
		}
		max++;
	}

	// Then print the results:

	max = 1;

	for(i = 0; i < n+1; i++)
	{
		for(count = 0; count < 2; count++)
		{
			if(array[i][count]!=0)
			{
				if((i==0)&&(count==0))
				{
					nrsu= array[i][count];
					printf("\n nrsu %d \n ", nrsu);
				}
				if((i==0)&&(count==1))
				{
					nconn=array[i][count];
					printf("\n nconn %d \n ", nconn);
				}
				else
				{
					data[i][count]=array[i][count];
					printf("\ndata array[%d][%d] = %d\n", i, count, data[i][count]);
				}
			}
		}
		max++;
	}

	// And finally, free the allocated memory:
/*
	for(i = 0; i < n+1; i++)
	{
		free(array[i]);
	}
	free(array);
*/
#endif
	return 0;
}
