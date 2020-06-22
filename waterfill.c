#include<stdio.h>
unsigned int WaterStoredInPlatform(unsigned int **,unsigned int,unsigned int);
void Nullify(unsigned int ,unsigned int **,unsigned int);
void main()
{
unsigned int m,n;
printf("\n Enter the row number : ");
scanf("%d",&m);
printf("\n Enter the row number : ");
scanf("%d",&n);
unsigned int Mat[m][n];
printf("\n Enter the firs row elements ");
for(unsigned int i=0;i<m;i++)
 for(unsigned int j=0;j<n;j++)
    scanf("%d",&Mat[i][j]);
unsigned int k=WaterStoredInPlatform(Mat,m,n);



}



unsigned int WaterStoredInPlatform(unsigned int **platform, unsigned int rows, unsigned int columns)
{
  // rows = Number of rows in that platform ('n' of the matrix)

  // columns = Number of columns in that platform ('m' of the matrix)

  // unsigned int platform[n][m] is your 2d array passed into this function by reference
unsigned int m=rows,n=colums,count=0;
unsigned int Mat2[m,n];
unsigned int min=platform,max=platform;

 // finding minimum and maximum value of the matrix 
for(unsigned int i=0;i<m;i++)
    for(unsigned int j=0;j<n;j++)
        if (min>platform[i][j])
            min=platform[i][j];
for(unsigned int i=0;i<m;i++)
    for(unsigned int j=0;j<n;j++)
        if (max<platform[i][j])
            max=platform[i][j];

//Splitting of layers ,split each layer and form 2D matrix and perform following operations
//find outpath on side
//find conecting lines to side path and replace them with one
//count total number of zeros which is the area
//
//
//

for(int l=0;l<max;l++)
    {
        for (unsigned int i=0;i<m;i++)
            for (unsigned int j=0;j<n;j++)
                {
                    Mat2[i][j]=platform[i][j]-l;
                    if(Mat2[i][j]<0)
                        Mat2[i][j]=0;
                }

        i=0;
        for(j=0;j<n;j++)
            if(Mat2[i][j]==0)
                Nullify(Mat2,i,j);

        i=m;
        for(j=0;j<n;j++)
            if(Mat2[i][j]==0)
                Nullify(Mat2,i,j);

        j=0;
        for(i=0;i<m;i++)
            if(Mat2[i][j]==0)
                Nullify(Mat2,i,j);

        j=n;
        for(unsigned i=0;i<m;i++)
            if(Mat2[i][j]==0)
                Nullify(Mat2,i,j);


   
        for(unsigned int i=0;i<m;i++)
            for(unsigned int j=0;j<n;j++)
                if(Mat2[i][j]==0)
                    count=count+1;
 return count;
    }
       
  //write your code inside this function

}

void Nullify(unsigned int **Mat2,unsigned int row,unsigned int col)
{

    Mat2[row,col]=0;
    if((*(*Mat2+1+row)+col)==0)
        Nullify(Mat2,row+1,col);

    if((*(*Mat2+row-1)+col)==0)
        Nullify(Mat2,row-1,col);

    if((*(*Mat2+row)+col+1)==0)
        Nullify(Mat2,row,col+1);

    if((*(*Mat2+row)+col-1)==0)
        Nullify(Mat2,row,col-1);
}
