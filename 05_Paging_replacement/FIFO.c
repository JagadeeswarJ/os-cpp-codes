#include <stdio.h>

int main()
{
    int frame_size = 3, frames[3] = {-1, -1, -1}, page_faults = 0;
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};
    int n = sizeof(pages) / sizeof(pages[0]), i, j, k;

    for (i = 0; i < n; i++)
    {
        int found = 0;
        for (j = 0; j < frame_size; j++)
        {
            if (frames[j] == pages[i])
            {
                found = 1;
                printf("Page Hit: %d\n", pages[i]);
                break;
            }
        }
        if (!found)
        {
            printf("Page Fault: %d\n", pages[i]);
            page_faults++;
            for (j = 0; j < frame_size; j++)
            {
                if (frames[j] == -1)
                    break;
            }
            if (j < frame_size)
                frames[j] = pages[i];
            else
            {
                for (k = 1; k < frame_size; k++)
                    frames[k - 1] = frames[k];
                frames[frame_size - 1] = pages[i];
            }
        }
        printf("Frames: ");
        for (j = 0; j < frame_size; j++)
            printf("%d ", frames[j]);
        printf("\n");
    }
    printf("Total Page Faults: %d\n", page_faults);
    printf("Total Page Hits: %d\n", n - page_faults);
    return 0;
}
