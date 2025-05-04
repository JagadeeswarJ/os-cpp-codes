#include <stdio.h>

int findLRU(int time[], int frame_size)
{
    int min = time[0], pos = 0;
    for (int i = 1; i < frame_size; i++)
    {
        if (time[i] < min)
        {
            min = time[i];
            pos = i;
        }
    }
    return pos;
}

int main()
{
    int frame_size = 3, frames[3] = {-1, -1, -1}, time[3] = {0};
    int page_faults = 0, counter = 0;
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int n = sizeof(pages) / sizeof(pages[0]);

    for (int i = 0; i < n; i++)
    {
        int found = 0;
        for (int j = 0; j < frame_size; j++)
        {
            if (frames[j] == pages[i])
            {
                counter++;
                time[j] = counter;
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
                counter++;
                frames[empty] = pages[i];
                time[empty] = counter;
            }
            else
            {
                int pos = findLRU(time, frame_size);
                counter++;
                frames[pos] = pages[i];
                time[pos] = counter;
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
