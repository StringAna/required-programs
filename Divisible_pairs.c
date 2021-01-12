#include<stdio.h>

// Complete the divisibleSumPairs function below.
int divisibleSumPairs(int n, int k, int* ar) {
    int moduloCount[k];
    int i, sum=0;;
    
    for(i=0; i<k; i++)
       moduloCount[i]=0;
    
    for( i=0 ; i<n ; i++ ){
        moduloCount[ (*(ar+i)) % k ]++;
    }
    
    sum+=( moduloCount[0] * (moduloCount[0] - 1 ))/2;
    
    for( i = 1 ; i <= k/2 && i != k-i ; i++ ){
         sum+= moduloCount[i] * moduloCount[k-i] ;
     }
     
    if( k%2 == 0){
        sum += ( moduloCount[ k/2 ] * ( moduloCount[ k/2 ] - 1 )) / 2;
    }
    
    return sum;
}

int main(){
	
	int n,k;
	
	printf("\nEnter array size (n) :- ");
	scanf("%d",&n);
	printf("\nEnter divisibility (k) :- ");
	scanf("%d",&k);
	int ar[n],i;
	
	for( i=0 ; i<n ; i++){
		scanf("%d",&ar[i]);
	}
	
	printf("\nThe resultant sum is :- %d",divisibleSumPairs(n, k, ar));
	
	return 0;
}
