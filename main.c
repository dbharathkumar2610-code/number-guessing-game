#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_NUMBER 1
#define MAX_NUMBER 100
#define INPUT_SIZE 128

static int read_guess(void)
{
    char input[INPUT_SIZE];
    char *end;
    long guess;

    for (;;) {
        printf("Your guess (or q to quit): ");
        if (fgets(input, sizeof input, stdin) == NULL) {
            return -1;
        }

        if (input[0] == 'q' || input[0] == 'Q') {
            return -1;
        }

        errno = 0;
        guess = strtol(input, &end, 10);
        if (end == input || errno == ERANGE) {
            puts("Please enter a whole number.");
            continue;
        }

        while (*end == ' ' || *end == '\t' || *end == '\n' || *end == '\r') {
            end++;
        }
        if (*end != '\0') {
            puts("Please enter a whole number.");
            continue;
        }

        if (guess < MIN_NUMBER || guess > MAX_NUMBER) {
            printf("Choose a number from %d to %d.\n", MIN_NUMBER, MAX_NUMBER);
            continue;
        }

        return (int)guess;
    }
}

static void play_round(void)
{
    int answer = rand() % (MAX_NUMBER - MIN_NUMBER + 1) + MIN_NUMBER;
    int attempts = 0;
    int guess;

    puts("\nI'm thinking of a number from 1 to 100.");
    while ((guess = read_guess()) != -1) {
        attempts++;
        if (guess < answer) {
            puts("Too low!");
        } else if (guess > answer) {
            puts("Too high!");
        } else {
            printf("You got it in %d %s!\n", attempts,
                   attempts == 1 ? "guess" : "guesses");
            return;
        }
    }

    printf("The number was %d.\n", answer);
}

int main(void)
{
    char again[INPUT_SIZE];

    srand((unsigned int)time(NULL));
    puts("=== Number Guessing Game ===");

    do {
        play_round();
        printf("Play again? (y/n): ");
        if (fgets(again, sizeof again, stdin) == NULL) {
            break;
        }
    } while (again[0] == 'y' || again[0] == 'Y');

    puts("Thanks for playing!");
    return 0;
}
