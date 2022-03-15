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