void selectionSort(int arr[], int n) {
    // Code here
    int mini = 0;
    for(int i=0; i<=n-2; i++){
        mini = i;
        for(int j=i; j<n; j++){
            if(arr[j] < arr[mini]){
                mini  = j;
            }
        }
        int temp = arr[mini];
        arr[mini] = arr[i];
        arr[i] = temp;
    }
}
