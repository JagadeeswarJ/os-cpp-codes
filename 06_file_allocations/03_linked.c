#include <stdio.h>

int main()
{
    int files[10], start, n, i, blocks[10];
    for (i = 0; i < 10; i++)
        files[i] = 0;
    printf("Enter starting block: ");
    scanf("%d", &start);
    if (files[start] == 1)
    {
        printf("Starting block already allocated\n");
        return 0;
    }
    printf("Enter number of blocks: ");
    scanf("%d", &n);
    blocks[0] = start;
    files[start] = 1;
    printf("Enter next %d blocks:\n", n - 1);
    for (i = 1; i < n; i++)
    {
        scanf("%d", &blocks[i]);
        if (files[blocks[i]] == 1)
        {
            printf("Block %d already allocated\n", blocks[i]);
            i--;
        }
        else
        {
            files[blocks[i]] = 1;
        }
    }
    printf("File blocks: ");
    for (i = 0; i < n; i++)
        printf("%d -> ", blocks[i]);
    printf("NULL\n");
    return 0;
}
