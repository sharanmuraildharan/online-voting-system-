#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_VOTERS 1000 // maximum number of voters
#define MAX_CANDIDATES 10 // maximum number of candidates

// structure to store voter information
struct Voter {
    char name[50];
    char dob[11]; // date of birth in format DD/MM/YYYY
    int age;
    
    char voterID[10];
    char area[50];
    char block[50];
    int voted; // 0 if not voted, 1 if voted
    int candidateSelected; // index of candidate selected
};

// structure to store candidate information
struct Candidate {
    char name[50];
    char symbol[10];
    int votes; // number of votes received
    char area[50];
    char block[50];
};

int main() {
    struct Voter voters[MAX_VOTERS];
    struct Candidate candidates[MAX_CANDIDATES];
    int numVoters = 0;
    int numCandidates = 0;
    int i;
    
    // read the number of voters and candidates
    printf("Enter the number of voters: ");
    scanf("%d", &numVoters);
    printf("Enter the number of candidates: ");
    scanf("%d", &numCandidates);
    
    // read voter information
    for (i = 0; i < numVoters; i++) {
        printf("Enter name of voter %d: ", i+1);
        scanf("%s", voters[i].name);
        printf("Enter date of birth of voter %d (DD/MM/YYYY): ", i+1);
        scanf("%s", voters[i].dob);
        printf("Enter area of voter %d: ", i+1);
        scanf("%s", voters[i].area);
        printf("Enter block of voter %d: ", i+1);
        scanf("%s", voters[i].block);
        voters[i].voted = 0;
        voters[i].candidateSelected = -1;
        // generate a unique voter ID based on index
        sprintf(voters[i].voterID, "V%d", i+1);
        // calculate age based on DOB
        time_t now = time(NULL);
        struct tm *t = localtime(&now);
        int currentYear = t->tm_year + 1900;
        int currentMonth = t->tm_mon + 1;
        int currentDay = t->tm_mday;
        int dobYear, dobMonth, dobDay;
        sscanf(voters[i].dob, "%d/%d/%d", &dobDay, &dobMonth, &dobYear);
        voters[i].age = currentYear - dobYear;
        if (currentMonth < dobMonth || (currentMonth == dobMonth && currentDay < dobDay)) {
            voters[i].age--;
        }
        // check age eligibility
        if (voters[i].age < 18) {
            printf("Voter %d is not eligible to vote!\n", i+1);
            i--;
            numVoters--;
        }
    }
    
    // read candidate information
    for (i = 0; i < numCandidates; i++) {
        printf("Enter name of candidate %d: ", i+1);
        scanf("%s", candidates[i].name);
        printf("Enter symbol of candidate %d: ", i+1);
        scanf("%s", candidates[i].symbol);
        printf("Enter area of candidate %d: ", i+1);
        scanf("%s", candidates[i].area);
    }
}
