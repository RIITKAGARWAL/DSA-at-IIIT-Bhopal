#include <stdio.h>


int isPossible(int* arr,int mid , int lengthOfArr , int numberOfStudents){
    int pages = 0;
    int students = 1;
    for(int idx = 0; idx < lengthOfArr ; idx++){
        if(pages + arr[idx] <= mid)
        pages += arr[idx];
        else{
            students++;
            pages = arr[idx];
        }

    }
    return (students <= numberOfStudents);
}



int main(){
    int arr[] = {40,10,20,30};

    int lengthOfArr = sizeof(arr) / sizeof(int);
    int numberOfStudents = 2;

    for(int x = 0; x < lengthOfArr; x++){
        printf("%d",x);
    }

    // book allocation problem
    // here lengthOfArr represents number of pockets
    // numberOfStudents
    
    // TC : O(log n)
    
    // now assume maximum pages or burden which we can give is to a single person only. else burden will be divided among more number of students
    // hypothetically if we think, minimum page burdern will be when , we have as many peoples as we can have to distribute the burdern
    int low = arr[0];
    int high = 0;
    for(int x : arr){
        high += x;
        if(low < x){
            low = x;
        }
    }

    // we get our high low

int mid;
    while(low <= high){
    // now we will find our mid
    mid = low + (high - low)/2 ;
    if(isPossible(arr,mid,lengthOfArr,numberOfStudents)){
        // true 
        high = mid -1;
    }
    else{
        // false
        low = mid + 1;
    }

    }
   printf("%d",low);



    return 0;
}
