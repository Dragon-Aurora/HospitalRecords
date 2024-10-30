#include <stdio.h>
#include <string.h> //Allows for use of %s

//input the name of the local emergency team
//output total response time in seconds

int main()
{
    int Team_Times[10][6]; //[Rows][Columns], rows are for team names, columns for category times 
    int team_name; //team name is numbers from 1-10
    int total_time; //[3]; //Total response time array, mins will be placed in [1] and secs in [2]
    int triage_time; //Time array for the time to identify patient medical issues, mins will be placed in [1] and secs in [2]
    int assess_time; //Time array for time to assess Patient,  mins will be placed in [1] and secs in [2]
    int assign_time;
    int transfer_time;
    int fastest_team[5]; //array contains fastest time for each category
    int n;
    int x;
    int y;

    //START OF LOOP
    n = 0;
    x = 0;
    y = 0;
    while (n != 11)
    {
        printf("\nTeam names are numbers 1-10.");
        printf("\nTeam name: ");
        scanf("%d", &Team_Times[n][0]); //INPUT (Data Type,Variable that input is assigned to)

        printf("\nAll times to be entered in Seconds.\n");

        printf("\nTime taken for Identification of Patient's medical issues: ");
        scanf("%d", &triage_time);

        Team_Times[0][2] = triage_time;

        printf("\nTime taken for Patient Assessment: ");
        scanf("%d", &assess_time);

        Team_Times[n][3] = assess_time;

        printf("\nTime taken for Patient to be assigned to a Doctor/Ward: ");
        scanf("%d", &assign_time);

        Team_Times[n][4] = assign_time;

        printf("\nTime taken for Patient to be transferred to assigned Doctor/Ward: ");
        scanf("%d", &transfer_time);

        Team_Times[n][5] = transfer_time;


        total_time = (triage_time+assess_time+assign_time+transfer_time); //Calculates Total Response time in secs
        //total_time[1] = (triage_time+assess_time+assign_time+transfer_time)/60; //Calculates Total Response time in mins using the sum of the 4 variables which is then divided by 60 to convert to mins
        //total_time[2] = (triage_time+assess_time+assign_time+transfer_time)%60; //Calculates Total Response time in secs in regards to the mins using the sum of the 4 variables which is then applied to modulus 60 to give the remainder which is secs

        Team_Times[n][1] = total_time;

        while (x != 7)
        {
            if (Team_Times[n+1][x] < Team_Times[n+1][x]) //[ROW][COLUMN]
            {
                while (y != 7)
                {
                    fastest_team[y] = Team_Times[x][y];

                    y = y + 1;
                } 
            }
        }
        n++;
        //maybe add a continuation choice; Y: n=n, N: n=11
    //END OF LOOP
    }
    x = 0;
    y = 0;
    n = 0;
    while (x != 5)
    {
        if (x==0);
        {
            printf("Fastest Total Time: ",fastest_team[x],"seconds");
        }
        if (x==1);
        {
            printf("Fastest Triage Time: ",fastest_team[x],"seconds");
        }
        if (x==2);
        {
            printf("Fastest Assessment time: ",fastest_team[x],"seconds");
        }
        if (x==3);
        {
            printf("Fastest Assignment time: ",fastest_team[x],"seconds");
        }
        if (x==4);
        {
            printf("Fastest Transfer time: ",fastest_team[x],"seconds");
        }
        x = x + 1;
    }

    return 0;
}