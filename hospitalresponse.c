#include <stdio.h>
#include <string.h> //Allows for use of %s

//input the name of the local emergency team
//output total response time in seconds

int main()
{
    char team_name[100]; //initialisation of a string
    int total_time; //Total response time
    int total_min; //Total response time in minutes
    int total_sec; //Total response time in seconds
    int triage_time; //Time to identify patient medical issues
    int assess_time; //Time to assess Patient
    int assign_time;
    int transfer_time;
    int triage_min;
    int triage_sec;
    int assess_min;
    int assess_sec;
    int assign_min;
    int assign_sec;
    int transfer_min;
    int transfer_sec;
    int fastest_team[100]; 

    printf("\nTeam name: ");
    scanf("%s", &team_name); //INPUT (Data Type,Variable that input is assigned to)

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
    transfer_sec = transfer_sec%60;

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
    else if (total_min > 7) //IF Total response time is greater than 7 minutes the team is not emergency ready
    {
        printf("Team %s is NOT Emergency Ready, with a total response time of %d minutes and %d seconds.", team_name, total_min, total_sec);
    }
    
    return 0;
}