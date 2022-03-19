/*
Assingment 2 
Lotto Game: User must enter 6 guesses to win a prize.

Author : Onting Leung (C21308733) TU858
Date: 14/03/2022
*/

#include <stdio.h>

#define SIZE 6
#define COUNT 42

// Option 1
void EnterNums(int *, int *);

// Option 2
void DisplayNums(int *);

// Option 3
void SortNums(int *, int *);

// Option 4
void WinningNums(int *, int *);
// Option 5
void Frequency(int *);

// Option 6
int ExitGame();

// Start of Main()
int main()
{
    int options;
    int userguess[SIZE] = {0};
    int guesscount[COUNT] = {0};
    static int sorted = 0, passedone = 0;

    do
    {
        // Menu of Options
        printf("\nMenu\n");
        printf("1. Enter Lotto Numbers\n");
        printf("2. Display Your Guesses\n");
        printf("3. Sort Lotto Numbers\n");
        printf("4. Winning Numbers\n");
        printf("5. Frequency of Guessed Numbers\n");
        printf("6. Exit\n\n");
        scanf("%d", &options);

        // while loop will use getchar() function to clear buffer if user inputs characters or special characters
        while (getchar() != '\n');

        // will jump to matching option
        switch (options)
        {

        case 1:
        {
            EnterNums(userguess, guesscount);
            passedone = 1;
            break;
        } // end case 1

        case 2:
        {
            if (passedone == 1)
            {
                DisplayNums(userguess);
            }
            break;
        } // end case 2

        case 3:
        {   
            if (passedone == 1)
            {
                SortNums(userguess, &sorted);
            }
            break;
        } // end case 3

        case 4:
        {
            if (passedone == 1)
            {
                WinningNums(userguess, &sorted);
            }
            break;
        } // end case 4

        case 5:
        {
            if (passedone == 1)
            {
                Frequency(guesscount);
            }
            break;
        } // end case 5

        case 6:
        {
            options = ExitGame();

            break;
        } // end case 6

        // If any other number
        default:
        {
            printf("\nInvaild Option\n");

            break;
        } // end default

        } // end switch

    } while (options != 7);
    // end do while
    return 0;
}
// End of Main

// Allows user to enter their guesses
void EnterNums(int *userguess, int *guesscount)
{
    int guess, d = 0, dups = 0;

    printf("Please enter 6 numbers between 1 - 42 (inclusive):\n");

    do
    {
        scanf("%d", &guess);

        do
        {
            if (guess < 1 || guess > 42)
            {
                printf("\nInvaid\n\n");
                printf("Please enter 6 numbers between 1 - 42 (inclusive):\n");

            } // end if
        } while (guess < 1 || guess > 42);

        *(userguess + d) = guess;

        d++;

        // frequency of inputed numbers 
        *(guesscount + guess) += 1;

        // checks for any duplicates in array
        if (d == SIZE)
        {
            printf("Duplicates: \n");

            for (int i = 0; i < SIZE; i++)
            {
                for (int j = i + 1; j < SIZE; j++)
                {
                    if (*(userguess + i) == *(userguess + j))
                    {
                        printf("%d\n", *(userguess + j));
                        dups = 1;
                    }
                }
            }

            if (dups == 0)
            {
                printf("No duplicates\n\n");
            }
        }
    } while (d < SIZE);
}

//  Displays the users guesses
void DisplayNums(int *userguess)
{

    printf("Your entered numbers:\n{");

    for (int i = 0; i < SIZE; i++)
    {
        printf(" %d", *(userguess + i));
    }

    printf(" }\n");
}

// Incersion Sort
void SortNums(int *userguess, int *sorted)
{
    int i, key, j;
    for (i = 1; i < SIZE; i++)
    {
        key = userguess[i];
        j = i - 1;

        while (j >= 0 && userguess[j] > key)
        {
            userguess[j + 1] = userguess[j];
            j = j - 1;
        }
        userguess[j + 1] = key;
    }
    *sorted = 1;
}

// Compares with winning numbs
void WinningNums(int *userguess, int *sorted)
{
    int winning[6] = {1, 2, 3, 8, 9, 10};
    int won = 1, matches = 6;

    if (*sorted == 1)
    {
        printf("\nPRIZES\n");
        printf("Match 6 : Jackpot\n");
        printf("Match 5 : New car\n");
        printf("Match 4 : Weekend Away\n");
        printf("Match 3 : Cinema Pass\n");

        for (int i = 0; i < SIZE; i++)
        {
            if (*(userguess + i) != winning[i])
            {
                won = 0;
                matches--;
            }
        }
        
        switch (matches)
        {
            case 3:
            {
                printf("\n\nYou won a Cinema Pass\n");

                break;
            }

            case 4:
            {
                printf("\n\nYou won a Weekend Away\n");

                break;
            }

            case 5:
            {
                printf("\n\nYou won a New Car\n");

                break;
            }

            case 6:
            {
                printf("\n\nYou won the Jackpot\n");

                break;
            }

            default:
            {
                printf("\n\nUnlucky better luck next time\n");

                break;
            }
        }
    }

    if (*sorted == 0)
    {
        printf("\nPlease select first option [3] to sort your guesses\n");
    }
}

// Displays the frequency of inputed numbers by the user
void Frequency(int *guesscount)
{
    for (int i = 0; i < COUNT; i++)
    {
        if (*(guesscount + i) != 0)
        {
            printf("number %d has been selected %d times.\n", i, *(guesscount + i));
        }
    }
}

// Exit Program Function
int ExitGame()
{
    char econ;

    printf("Are you sure you want to exit program? (y/n)\n");
    scanf("%c", &econ);

    if (econ == 'y' || econ == 'Y')
    {
        printf("\n\nExiting Program\n\n\n");

        return 7;
    }

    return 6;
}
