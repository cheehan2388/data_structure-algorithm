#include <stdio.h>
#include <stdbool.h>


void order_array(int b[],int* len,int a)//用int* 是希望他直接該全局的（指向該地址，而不是複製）
//int b[] 本身就是指地址，如果之後不要更改裏面的就加一個 const
 {
   int i = *len - 1 ; //*len 前面定義了 int* len ，所以*len 是取出地址的值
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
