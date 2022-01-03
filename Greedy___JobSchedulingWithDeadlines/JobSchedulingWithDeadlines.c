#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
 
typedef struct {
    char id;
    int deadline;
    int profit;
 
}Job;
 
int compareJob(const void *a, const void *b){
    return ((Job*)a)->profit - ((Job*)a)->profit;
}
 
void bestJob(Job jobs[],int sizeOfJobs){
    char jobsToDo[5]= {'\0'}; 
    int i, k;
    for(i=0; i< sizeOfJobs; i++){
            k= jobs[i].deadline-1;
        while(jobsToDo[k] != '\0' && k >= 0){
            k--;
        }
        if(k != -1)
            jobsToDo[k]= jobs[i].id;
    }
    
    printf("Best order and jobs to do is: ");
    k=0;
    while(jobsToDo[k] != '\0'){
        printf("%c  ",jobsToDo[k]);
        k++;    
    }
    printf("\n\n");
}
 
void display(Job jobs[],int n){
    int i;
    printf("\nJob Scheduling With Deadline Using Dynamic :\n\nJob Id: ");
    for(i=0; i<n; i++){
        printf("%c  ",jobs[i].id);
    }
    printf("\n");
 
    printf("Job Deadline: ");
    for(i=0; i<n; i++){
        printf("%d  ",jobs[i].deadline);
    }
    printf("\n");
 
    printf("Job Profit: ");
    for(i=0; i<n; i++){
         printf("%d  ",jobs[i].profit);
    }
    printf("\n");
}
 
int main()
{
    Job jobs[]=  {{'A', 1, 19}, {'B', 2, 100}, {'C', 2, 27},
                   {'D', 1, 25}, {'E', 3, 15}};
    display(jobs,5);
    qsort(jobs,5,sizeof(jobs[0]),compareJob);
    bestJob(jobs,5);
    return 0;
}