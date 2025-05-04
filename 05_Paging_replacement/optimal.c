#include <stdio.h>

int findOptimal(int pages[], int frames[], int n, int frame_size, int index)
{
    int farthest = index, pos = -1;
    for (int i = 0; i < frame_size; i++)
    {
        int j;
        for (j = index; j < n; j++)
        {
            if (frames[i] == pages[j])
            {
                if (j > farthest)
                {
                    farthest = j;
                    pos = i;
                }
                break;
            }
        }
        if (j == n)
            return i; // Page not used again
    }
    return (pos == -1) ? 0 : pos;
}

int main()
{
    int frame_size = 3, frames[3] = {-1, -1, -1}, page_faults = 0;
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int n = sizeof(pages) / sizeof(pages[0]);

    for (int i = 0; i < n; i++)
    {
        int found = 0;
        for (int j = 0; j < frame_size; j++)
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
            page_faults++;
            int empty = -1;
            for (int j = 0; j < frame_size; j++)
            {
                if (frames[j] == -1)
                {
                    empty = j;
                    break;
                }
            }
            if (empty != -1)
            {
                frames[empty] = pages[i];
            }
            else
            {
                int pos = findOptimal(pages, frames, n, frame_size, i + 1);
                frames[pos] = pages[i];
            }
            printf("Page Fault: %d\n", pages[i]);
        }

        printf("Frames: ");
        for (int j = 0; j < frame_size; j++)
        {
            printf("%d ", frames[j]);
        }
        printf("\n");
    }

    printf("Total Page Faults: %d\n", page_faults);
    printf("Total Page Hits: %d\n", n - page_faults);

    return 0;
}
