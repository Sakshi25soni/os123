include <stdio.h>
struct student
{
    int S_Id;
    int Burst_time;
    int Waiting_time;
    int Turnaround_time;
};

void get(struct student list[], int t);
void show(struct student list[], int t);
void scheduling(struct student list[], int t);
void waiting_Time(struct student list[], int x);
void turnAround_Time(struct student list[], int x);
int main()
{
    struct student input[20];
    int x,y;
    char ch='x';
    do
        {
    printf("Enter how many Students want to eat in mess? : ");
    scanf("%d", &x);
    get(input,x);
    scheduling(input,x);
    waiting_Time(input,x);
    turnAround_Time(input,x);
    show(input,x);
    printf("Want to proceed further? press 'y' :\n if not then press 'n' ");
    scanf("%s",&ch);
    }while(ch=='y');
    return 0;
} 
void get(struct student list[80], int t)
{
    int y;
    for (y=0;y<t;y++)
    {printf("\n\nEnter data for Student #%d",y+1);

        printf("\nEnter Student id : ");
        scanf("%d",&list[y].S_Id);
        printf("Enter how much time taken for food taking in(min):");
        scanf("%d", &list[y].Burst_time);
    } 
}
void show(struct student list[80], int t)
{
    int y,Avg_Waiting_Time=0;
    int Avg_TurnAround_Time=0;
    int Total_Waiting_Time=0;
    int Total_TurnAround_Time=0;
    printf("\n\n\t\t\tOutput according to Longest Remaining Time First\n");
    printf("\n\t\t\t|===============================================================|");
    printf("\n\t\t\t|S_id\tBurst_time\tWaiting_time\tTurnaround_time  |");
    printf("\n\t\t\t|===============================================================|");    
    for (y=0;y<t;y++)
    {
        printf("\n\t\t\t|%d\t\t%d\t\t%d\t\t%d\t\t|", list[y].S_Id,list[y].Burst_time,list[y].Waiting_time,list[y].Turnaround_time);
        printf("\a\n\t\t\t|---------------------------------------------------------------|");
                Total_Waiting_Time=Total_Waiting_Time+list[y].Waiting_time;
                Total_TurnAround_Time=Total_TurnAround_Time+list[y].Turnaround_time;
        } 
        printf("\n\n\t\t\tTotal Waiting Time is: = %d",Total_Waiting_Time);
        printf("\n\t\t\tTotal Turn around Time is: = %d\n\n",Total_TurnAround_Time);
        printf("\n\n\t\t\tAverage Waiting Time is: = %d",Total_Waiting_Time);
        printf("\n\t\t\tAverage Turn around Time is: = %d\n\n",Total_TurnAround_Time);
}
void scheduling(struct student list[80], int t)
{
    int i, j;
    struct student temp;
    
    for(i=0;i<t-1;i++)
    {
        for(j=0;j<(t - 1-i);j++)
        {
            if(list[j].Burst_time<list[j+1].Burst_time)
            {
                temp=list[j];
                list[j]=list[j+1];
                list[j+1]=temp;
            } 
            else if(list[j].Burst_time==list[j+1].Burst_time)
            {
                if(list[j].S_Id>list[j+1].S_Id)
                {
                temp=list[j];
                list[j]=list[j+1];
                list[j+1]=temp;
                }
                        }
        }
    }
}
void waiting_Time(struct student list[80], int x)
{
        int p,total;
    list[0].Waiting_time=0;
    for(p=1;p<x;p++)
    {
      list[p].Waiting_time=list[p-1].Waiting_time+list[p-1].Burst_time;
    }
}
void turnAround_Time(struct student list[80], int x)
{
        int p,total;
    
    for(p=0;p<x;p++)
    {
      list[p].Turnaround_time=list[p].Waiting_time+list[p].Burst_time;
    }
}
