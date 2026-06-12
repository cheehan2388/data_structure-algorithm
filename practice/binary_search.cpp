#include <stdio.h>
#include <stdbool.h>



int binary_search(int b[],int len, int target){ // 這裏有回傳值所以我用int（我要回傳索引位置）
    int l = 0 ;
    int e = len - 1 ;
    int a = 1 ;
    
    while ( l <= e){
        
        a = (e + l) / 2 ;

        if(target == b[a]) {
            return a ;
        }
        else if (target > b[a]){
                l = a +1;
        
    
        }
        else
        { 
                e = a - 1 ;
        }
    
        
        

    
    }
    return -1;
}

int main()
{
    int array[10] ={2,3,4,5,7,8,9} ;
    int le  = 7;
    int find = 6 ;
    int num = binary_search(array,le, find);
    if (num != -1) {
        printf("the number is available in %d", num ) ;

    }
        else if (num == -1)
        {
            printf("no number %d available in array",find) ;
            /* code */
        }
        
   
    return 0 ;
}