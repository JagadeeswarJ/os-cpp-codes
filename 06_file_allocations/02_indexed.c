#include <stdio.h>

int main()
{
    int files[10], index_block, n, blocks[10], i;
    for (i = 0; i < 10; i++)
        files[i] = 0;
    printf("Enter index block: ");
    scanf("%d", &index_block);
    if (files[index_block] == 1)
    {
        printf("Index block already allocated\n");
        return 0;
    }
    files[index_block] = 1;
    printf("Enter number of blocks needed: ");
    scanf("%d", &n);
    printf("Enter blocks:\n");
    for (i = 0; i < n; i++)
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
    printf("File Allocated with index block %d\n", index_block);
    printf("Blocks are: ");
    for (i = 0; i < n; i++)
        printf("%d ", blocks[i]);
    printf("\n");
    return 0;
}
