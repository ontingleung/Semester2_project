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

// Option 5

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

                break;
            } // end case 4

            case 5:
            {


                break;
            } // end case 5

            case 6:
            {
                printf("Are you sure you want to exit?\n (y/n)");

                break;
            } // end case 6

            // If any other number
            default:
            {
                printf("\nInvaild Option\n");

                break;
            } // end default

            } // end switch

    } while (options != 6);
    // end do while
    return 0;
}

void EnterNums(int *userguess)
{
    printf("Please enter 6 numbers between 1 - 42 (inclusive):\n");

    for (int i = 0; i < SIZE; i++)
    {
        scanf("%d", userguess + i);
    }
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

void SortNums(int *userguess)
{
    int i, key, j;
    for (i = 1; i < SIZE; i++) 
    {
        key = userguess[i];
        j = i - 1;
 
        /* Move elements of [0..i-1], that are
          greater than key, to one position ahead
          of their current position */
        while (j >= 0 && userguess[j] > key) 
        {
            userguess[j + 1] = userguess[j];
            j = j - 1;
        }
        userguess[j + 1] = key;
    }
}