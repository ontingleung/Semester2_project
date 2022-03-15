/*



*/

#include <stdio.h>


#define SIZE 6

// Option 1
void EnterNums(int *);

// Option 2
void DisplayNums(int *);

// Option 3
void SortNums(int *);

// Option 4
void WinningNums(int *);
// Option 5
void Frequency();

// Option 6
int ExitGame();

// Start of Main()
int main()
{
    int options;
    int userguess[SIZE] = {0};

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
                EnterNums(userguess);

                break;
            } // end case 1

            case 2:
            {
                DisplayNums(userguess);

                break;
            } // end case 2

            case 3:
            {
                SortNums(userguess);

                break;
            } // end case 3

            case 4:
            {
                WinningNums(userguess);

                break;
            } // end case 4

            case 5:
            {


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
//End of Main

void EnterNums(int *userguess)
{
    int guess, i = 0;

    printf("Please enter 6 numbers between 1 - 42 (inclusive):\n");

    do
    {
        scanf("%d", &guess);

        if (guess < 1 || guess > 42)
        {
            printf("\nInvaid\n\n");
            printf("Please enter 6 numbers between 1 - 42 (inclusive):\n");

        } // end if
        for (int j = 0; j < SIZE; j++)
        {
            if (guess != *(userguess + j))
            {
                *(userguess + i) = guess;
                i++;
            }
        }

        if (guess == *(userguess + i))
        {
            printf("\nInvaid\n\n");
            printf("You can't enter duplicates\n");
        }

    } while (i < SIZE);
    
}

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
void SortNums(int *userguess)
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
}

// Compares with winning numbs
void WinningNums(int *userguess)
{
    int winning[6] = {2, 10, 27, 30, 33, 41};



    {
        printf("\nPlease select first option [3] to sort your guesses\n");
    }
}

// 5

// 6
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