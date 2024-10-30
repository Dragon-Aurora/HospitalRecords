#include <stdio.h>
#include <string.h>

//input the name of the local emergency team
//output total response time in seconds

int main(int argc, char *argv[])
{
    int Team_Times[10][6]{}; //[Rows][Columns], rows are for team names, columns for category times
    int team_name = 0; //team name is numbers from 1-10
    int total_time = 0; //[3]; //Total response time array, mins will be placed in [1] and secs in [2]
    int triage_time = 0; //Time array for the time to identify patient medical issues, mins will be placed in [1] and secs in [2]
    int assess_time = 0; //Time array for time to assess Patient,  mins will be placed in [1] and secs in [2]
    int assign_time = 0;
    int transfer_time = 0;
    int fastest_team[5]; //array contains fastest time for each category
    int n = 0;
    int x = 0;
    int y = 0;

    // the sizeof() gets the size in bytes of the object.
    // `(sizeof(fastest_team)/sizeof(int))` calculates the number of elements, which is 5.
    for (size_t i = 0U; i < (sizeof(fastest_team)/sizeof(int)); ++i)
    {
        fastest_team[i] = 0;
    }
    // for int type values you can use memset to clear memory. This will not
    // work for float or double.
    memset(Team_Times, 0, sizeof(Team_Times));

    //START OF LOOP
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

        // DD condition x!=7 will always be true so the loop below will never exit.
        while (x != 7)
        {
            // DD you are compaing the same entry here... so you will never enter the if.
            if (Team_Times[n+1][x] < Team_Times[n+1][x]) //[ROW][COLUMN]
            {
                while (y != 7)
                {
                    // DD you will exceed the array size here. Array is declared as containing 5 elements. The range you are using here is: [0..6]
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
        // DD you should not have a ';' at the end of the if. This is likly your problem here.
        // a semi colon is an end of statement so what you end up with is:
        // ```
        // if (x==0)
        //    do something
        // {
        //   printf(...)
        // }
        // ```
        if (x==0)
        {
            // printf is slightly different from python... note the use of %d which is to print a decimal, %f is a float.
            printf("Fastest Total Time: %d seconds",fastest_team[x]);
        }
        // consider switching the check around as shown here... as it is safer
        if (1==x)
        {
            printf("Fastest Triage Time: %d seconds",fastest_team[x]);
        }
        if (x==2)
        {
            printf("Fastest Assessment time: %d seconds",fastest_team[x]);
        }
        if (x==3)
        {
            printf("Fastest Assignment time: %d seconds",fastest_team[x]);
        }
        if (x==4)
        {
            printf("Fastest Transfer time: %d seconds",fastest_team[x]);
        }
        x = x + 1;
    }

    return 0;
}
