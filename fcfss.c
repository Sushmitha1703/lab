#include <stdio.h>

struct process
{
    int pno;
    int at;
    int bt;
    int wt;
    int tat;
};

int main()
{
    int n, twt = 0, ttt = 0;
    printf("enter no.of processes\n");
    scanf("%d", &n);
    struct process p[n];
    for (int i = 0; i < n; i++)
    {
        p[i].pno = i + 1;
        printf("enter the details of process %d\n", p[i].pno);
        printf("enter burst time \n");
        scanf("%d", &p[i].bt);
    }
    p[0].wt = 0;
    p[0].tat = p[0].bt;
    for (int j = 1; j < n; j++)
    {
        p[j].wt = p[j - 1].bt + p[j - 1].wt;
        p[j].tat = p[j].bt + p[j].wt;
    }

    printf("Processes Burst time Waiting time Turn around time\n");
    for (int i = 0; i < n; i++)
    {
        twt = twt + p[i].wt;
        ttt = ttt + p[i].tat;
        printf(" %d ", (i + 1));
        printf("	\t %d ", p[i].bt);
        printf("	 \t%d", p[i].wt);
        printf("	 \t%d\n", p[i].tat);
    }
    return 0;
}
