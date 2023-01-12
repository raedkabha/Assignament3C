#include <stdio.h>
#include <string.h>
#define Max 50
void shift_element(int* arr, int i){
   
    for(int z=i; z>=0;--z){
      *(arr+z)=*(arr+z-1); 
    }
}
void insertion_sort(int* arr, int len){
for(int i=0; i<len-1; ++i)
		for(int j=i+1; j<len; ++j)
			if(*(arr+i) > *(arr+j)) {
				int t = *(arr+i); 
				*(arr+i) = *(arr+j); 
				*(arr+j) = t; 
			}
}
void main(){
 int arr[Max];
 printf("Enter %d numbers please!",Max);
for(int i=0;i<50;++i){
    scanf("%d",&arr[i]);}
int *p=arr;
insertion_sort(p,Max);
for(int i=0;i<Max;++i){
     if (i!=49)
    {
    printf("%d,", arr[i]);
    }
    else
     printf("%d", arr[i]);
}
}

