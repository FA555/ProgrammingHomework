//��ƺ�������ά����M��ÿ�е���СԪ�أ����η���һά����x�У���ά����M������Ϊn,����Ϊm
#include<stdio.h>

#define MAX 100

void findMin(int M[][MAX],int x[],int n,int m);

int main()
{
    int        matrix[MAX][MAX] ; 
    int        x[MAX] ;
    int        n, m, i, j ;


    scanf( "%d%d" , &n , &m );
    for( i = 0 ; i < n ; i++ )
    {    
        for( j = 0 ; j < m ; j++ )
        {
            scanf("%d", &matrix[i][j]) ;
        }
    }

    findMin(matrix,x,n,m);

    for( i = 0 ; i < m - 1 ; i++ )
        printf( "%d " , x[i] ) ;
    printf( "%d\n" , x[i] ) ;

    return 0 ;
}

/* ����������д�� */ 

 
void findMin(int M[][MAX],int x[],int n,int m)
{
	for (int l=0;l<m;l++){
		int min=M[0][l];
		for (int i=1;i<n;i++){
			if(M[i][l]<min){
				min=M[i][l];
			}
		}
		x[l]=min;
	}
} 