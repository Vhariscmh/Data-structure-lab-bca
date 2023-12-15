#include<stdio.h> 
#include<conio.h> 
int LINEAR_SEARCH(int a[10], int n, int key)
 {    
    int i;    
    for(i=0;i<n;i++)    
    {     
        if(key==a[i])     
        {       
            return i+1;     
        }    
    }    
    return -1; 
    } 
    int BINARY_SEARCH(int a[10], int n,int key) 
    {    
        int first,last,mid;    
        first =0;    
        last  =n-1;    
        while(first <=last)    
        {        
            mid=(first+last)/2;        
            if(key == a[mid])       
               return mid+1;        
            else if(key < a[mid])       
               last = mid-1;        
            else if(key > a[mid])       
                  first = mid+1;    
}    
return -1; 
}
 void DISPLAY_ARRAY(int a[10],int n) 
{    
    int i;    
    printf("\n Given array : ");    
    for(i=0;i<n;i++)    
    {     
        printf("%3d",a[i]);    
    } 
} 
void main() 
{    
    int a[8] = {4,7,3,2,1,7,9,0};    
    int sa[8] = {0,1,2,3,4,7,7,9};    
    int n=8;    
    int key=7;    
    int loc;        
    DISPLAY_ARRAY(a,n);    
    loc = LINEAR_SEARCH(a,n,key);    
    if(loc==-1)     
    printf("\nItem not found");    
else     
   printf("\nItem found at location %d",loc);
DISPLAY_ARRAY(sa,n);    
loc = BINARY_SEARCH(sa,n,key);    
if(loc==-1)     
        printf("\nItem not found");    
else     
    printf("\nItem found at location %d",loc);     
}