#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int goals_for;
    int goals_against;
    char team_name[60];
    int points;
    int goal_difference;
    int victories;
    int draws;
    int defeats;
} Team;

int main() {

    int num_games;
    scanf("%d", &num_games);
    Team teams[num_games * 2];
    
    for (int i = 0; i < num_games; i++) {
        scanf("%s %d x %d %s", teams[i * 2].team_name, &teams[i * 2].goals_for,
              &teams[i * 2 + 1].goals_for, teams[2 * i + 1].team_name);

        teams[2 * i].goals_against = teams[2 * i + 1].goals_for;
        teams[2 * i + 1].goals_against = teams[2 * i].goals_for;

        teams[2 * i].goal_difference = teams[2 * i].goals_for - teams[2 * i].goals_against;
        teams[i * 2 + 1].goal_difference = teams[i * 2 + 1].goals_for - teams[i * 2 + 1].goals_against;

        if (teams[2 * i].goal_difference > 0) {
            teams[2 * i].points = 3;
            teams[2 * i].victories = 1;
            teams[2 * i].defeats = 0;
            teams[2 * i].draws = 0;
        }
        if (teams[2 * i].goal_difference == 0) {
            teams[2 * i].points = 1;
            teams[2 * i].victories = 0;
            teams[2 * i].defeats = 0;
            teams[2 * i].draws = 1;
        }
        if (teams[2 * i].goal_difference < 0) {
            teams[2 * i].points = 0;
            teams[2 * i].victories = 0;
            teams[2 * i].defeats = 1;
            teams[2 * i].draws = 0;
        }

        if (teams[2 * i + 1].goal_difference > 0) {
            teams[2 * i + 1].points = 3;
            teams[2 * i + 1].victories = 1;
            teams[2 * i + 1].defeats = 0;
            teams[2 * i + 1].draws = 0;
        }
        if (teams[2 * i + 1].goal_difference == 0) {
            teams[2 * i + 1].points = 1;
            teams[2 * i + 1].victories = 0;
            teams[2 * i + 1].defeats = 0;
            teams[2 * i + 1].draws = 1;
        }
        if (teams[2 * i + 1].goal_difference < 0) {
            teams[2 * i + 1].points = 0;
            teams[2 * i + 1].victories = 0;
            teams[2 * i + 1].defeats = 1;
            teams[2 * i + 1].draws = 0;
        }
    }
    printf("\n\n");
    
    for (int i = 0; i < num_games * 2 - 1; i++) {
        for (int j = 0; j < num_games * 2 - 1 - i; j++) {
            if (teams[j].points < teams[j + 1].points) {
                Team temp = teams[j];
                teams[j] = teams[j + 1];
                teams[j + 1] = temp;
            } else if (teams[j].points == teams[j + 1].points && teams[j].victories < teams[j + 1].victories) {
                Team temp = teams[j];
                teams[j] = teams[j + 1];
                teams[j + 1] = temp;
            } else if (teams[j].points == teams[j + 1].points && teams[j].victories == teams[j + 1].victories
                       && teams[j].goal_difference < teams[j + 1].goal_difference) {
                Team temp = teams[j];
                teams[j] = teams[j + 1];
                teams[j + 1] = temp;
            } else if (teams[j].points == teams[j + 1].points && teams[j].victories == teams[j + 1].victories
                       && teams[j].goal_difference == teams[j + 1].goal_difference && teams[j].goals_for < teams[j + 1].goals_for) {
                Team temp = teams[j];
                teams[j] = teams[j + 1];
                teams[j + 1] = temp;
            } else if (teams[j].points == teams[j + 1].points && teams[j].victories == teams[j + 1].victories
                       && teams[j].goal_difference == teams[j + 1].goal_difference && teams[j].goals_for == teams[j + 1].goals_for
                       && strcmp(teams[j].team_name, teams[j + 1].team_name) > 0) {
                Team temp = teams[j];
                teams[j] = teams[j + 1];
                teams[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < num_games * 2; i++) {
        printf("%d. %s %d %d %d %d %d %d %d\n", i + 1, teams[i].team_name, teams[i].points, teams[i].victories, teams[i].draws,
               teams[i].defeats, teams[i].goals_for, teams[i].goals_against, teams[i].goal_difference);
    }
    return 0;
}
