int majorityElement(int* arr, int n) {
    
    int max=arr[0];   
    for(i=0;i<n;i++){
        if(arr[i]/n>n/2)
        max=arr[i];
    }
    if(n==1){
        printf("%d", max=arr[0]);
    }
    else if(n==0){
        printf("%d", 0);
    }
    else {
    printf("%d", max);
    }
    return 0;
}

