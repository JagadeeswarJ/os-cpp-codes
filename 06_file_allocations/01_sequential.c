#include <stdio.h>

int main()
{
    int files[10], start, length, i, n;
    for (i = 0; i < 10; i++)
        files[i] = 0;
    printf("Enter number of files: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter start block and length of file %d: ", i + 1);
        scanf("%d%d", &start, &length);
        int j, flag = 0;
        for (j = start; j < start + length; j++)
        {
            if (files[j] == 1)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            for (j = start; j < start + length; j++)
                files[j] = 1;
            printf("File %d allocated\n", i + 1);
        }
        else
        {
            printf("File %d cannot be allocated\n", i + 1);
        }
    }
    printf("Final Allocation:\n");
    for (i = 0; i < 10; i++)
        printf("%d ", files[i]);
    printf("\n");
    return 0;
}
