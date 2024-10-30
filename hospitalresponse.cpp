#include <stdio.h>
#include <string.h>

//input the name of the local emergency team
//output total response time in seconds

int main()
{
#define MAX_TEAMNAME_SIZE 100
#define MAX_NUM_OF_TEAMS 100

    char team_name[MAX_TEAMNAME_SIZE]; //initialisation of a string
    int total_time = 0; //Total response time
    int total_min = 0; //Total response time in minutes
    int total_sec = 0; //Total response time in seconds
    int triage_time = 0; //Time to identify patient medical issues
    int assess_time = 0; //Time to assess Patient
    int assign_time = 0;
    int transfer_time = 0;
    int triage_min = 0;
    int triage_sec = 0;
    int assess_min = 0;
    int assess_sec = 0;
    int assign_min = 0;
    int assign_sec = 0;
    int transfer_min = 0;
    int transfer_sec = 0;
    int fastest_team[MAX_NUM_OF_TEAMS];

    // the sizeof() gets the size in bytes of the object.
    // `(sizeof(fastest_team)/sizeof(int))` calculates the number of elements, which is 5.
    for (size_t i = 0U; i < (sizeof(fastest_team)/sizeof(int)); ++i)
    {
        fastest_team[i] = 0;
    }
    // strings or arrays or chars are normally terminated with a '\0'.
    team_name[0] = '\0';

    printf("\nTeam name: ");
    // see https://en.cppreference.com/w/c/io/fscanf
    // always specify a max size and char * arrays should not have a pointer taken.
    scanf("%99s", team_name); //INPUT (Data Type,Variable that input is assigned to)
    team_name[MAX_TEAMNAME_SIZE-1] = '\0'; // allways terminate and don't forget counting starts at Zero.

    printf("\nAll times to be entered in Seconds.\n");

    printf("\nTime taken for Identification of Patient's medical issues: ");
    scanf("%d", &triage_time);

    printf("\nTime taken for Patient Assessment: ");
    scanf("%d", &assess_time);

    printf("\nTime taken for Patient to be assigned to a Doctor/Ward: ");
    scanf("%d", &assign_time);

    printf("\nTime taken for Patient to be transferred to assigned Doctor/Ward: ");
    scanf("%d", &transfer_time);

    triage_min = triage_time/60; //Converts triage_time to minutes
    triage_sec = triage_time%60; //Converts triage_time to seconds

    assess_min = assess_time/60;
    assess_sec = assess_time%60;

    assign_min = assign_time/60;
    assign_sec = assign_time%60;

    transfer_min = transfer_time/60;
    transfer_sec = transfer_min%60;

    total_min = (triage_time+assess_time+assign_time+transfer_time)/60; //Calculates Total Response time in mins using the sum of the 4 variables which is then divided by 60 to convert to mins
    total_sec = (triage_time+assess_time+assign_time+transfer_time)%60; //Calculates Total Response time in secs using the sum of the 4 variables which is then applied to modulus 60 to give the remainder which is secs


    if (total_min < 1) //IF Total response time is less than 1 minute the team is CLT ready
    {
        printf("Team %s is Emergency Ready for CLT Patients, with a total response time of %d minutes and %d seconds.", team_name, total_min, total_sec);
    }
    else if (total_min < 3) //IF Total response time is less than 3 minutes the team is SLT ready
    {
        printf("Team %s is Emergency Ready for SLT Patients, with a total response time of %d minutes and %d seconds.", team_name, total_min, total_sec);
    }
    else if (total_min < 5) //IF Total response time is less than 5 minutes the team is PLT ready
    {
        printf("Team %s is Emergency Ready for PLT Patients, with a total response time of %d minutes and %d seconds.", team_name, total_min, total_sec);
    }
    else if (total_min < 7) //IF Total response time is less than 7 minutes the team is NLT ready
    {
        printf("Team %s is Emergency Ready for NLT Patients, with a total response time of %d minutes and %d seconds.", team_name, total_min, total_sec);
    }
// DD note the use of >=.
// you could change to just an else clause.
    else if (total_min >= 7) //IF Total response time is greater than 7 minutes the team is not emergency ready
    {
        printf("Team %s is NOT Emergency Ready, with a total response time of %d minutes and %d seconds.", team_name, total_min, total_sec);
    }

    return 0;
}
