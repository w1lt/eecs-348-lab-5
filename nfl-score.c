// Including standard I/O library
#include <stdio.h>

int main() {
    // Variable declaration for user input
    int score;

    // Array of possible score names in NFL
    const char *scoreNames[] = {
        "TD + 2pt", "TD + FG", "TD", "3pt FG", "Safety"
    };

    // Array of corresponding score values
    const int scoreValues[] = {
        8, 7, 6, 3, 2
    };

    // Calculate the number of scores based on the size of the scoreValues array
    const int numScores = sizeof(scoreValues) / sizeof(scoreValues[0]);

    // Prompt user to enter a score or to stop the program
    printf("Enter 0 or 1 to STOP\n");

    // Main loop to keep asking the user for an NFL score
    while(1) {
        printf("Enter the NFL score: ");
        scanf("%d", &score);

        // Condition to break the loop if user enters 0 or 1
        if(score <= 1) {
            break;
        }

        // Display possible scoring play combinations
        printf("possible combinations of scoring plays:\n");

        // Iterating through each scoring combination possibility
        // Using nested loops for each score value to compute all possible combinations
        for (int a = 0; a * scoreValues[0] <= score; a++) {
            for (int b = 0; b * scoreValues[1] <= score; b++) {
                for (int c = 0; c * scoreValues[2] <= score; c++) {
                    for (int d = 0; d * scoreValues[3] <= score; d++) {
                        for (int e = 0; e * scoreValues[4] <= score; e++) {
                            // Check if the current combination sums up to the given score
                            if (a * scoreValues[0] + b * scoreValues[1] + c * scoreValues[2] + d * scoreValues[3] + e * scoreValues[4] == score) {
                                // Print the current combination of scores
                                printf("%d %s, %d %s, %d %s, %d %s, %d %s\n", a, scoreNames[0], b, scoreNames[1], c, scoreNames[2], d, scoreNames[3], e, scoreNames[4]);
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}
