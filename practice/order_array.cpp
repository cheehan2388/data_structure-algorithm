#include <stdio.h>
#include <stdbool.h>


void order_array(int b[],int* len,int a)
 {
   int i = *len - 1 ;
   while(i >= 0 && b[i]>a) {
        b[i+1] = b[i] ;
        i -- ;     
   }
   b[i+1] = a ;
   *len = *len +1 ;
   


 }

int main(){

    int array[10] = {1,3,5,7,9} ;
    int len = 5 ;
    order_array(array, &len ,8) ; 
    for(int i = 0; i <len ;i ++){
        printf("%d",array[i]);
    }
}
