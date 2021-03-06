#include<stdio.h>

#define MAXN 2000000

int RecurBinarySearch( int a[] , int key , int left , int right ) ;

int main()
{
    int        a[MAXN];//这个数组比较大，如果在你的电脑中无法分配这么大的内存，请改小后测试。
    int        n , m , i , key ;

    scanf("%d %d",&n , &m );    
    for( i = 0 ; i < n ; i++ )
        scanf("%d", &a[i]);

    for( i =0 ; i < m ; i++ )
    {
        scanf("%d",&key);
        printf( "%d" , RecurBinarySearch( a , key , 0 , n - 1 ) );
        if ( i != m - 1 ) printf(" ") ;
        else printf("\n") ; 
    }

    return 0;
}

/* 请在这里填写答案 */
int RecurBinarySearch( int a[] , int key , int left , int right )
{
	int middle;
	while(left <= right){
      middle = (left + right)/2;
      if (key == a[middle])
         return middle;
      else if(key < a[middle])
          right = middle - 1;
      else
          left = middle + 1;

	}
	return -1;
}
