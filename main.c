#include <stdio.h>
#include <string.h>
#include "StrList.h"

char* myGetLine()
{
    char* data = NULL;
    size_t len = 0;
    getline(&data, &len, stdin);
    data[strcspn(data, "\r\n")] = 0;
    return data;
}

enum
{
    INSERT_LAST = 1,
    INSERT_AT,
    PRINT,
    SIZE,
    PRINT_AT,
    PRINT_LEN,
    COUNT,
    REMOVE,
    REMOVE_AT,
    REVERSE,
    FREE,
    SORT,
    IS_SORTED
};

int main(int argc, char* argv[])
{
    StrList* list = StrList_alloc();
    int choice = -1;
    while (choice)
    {
        scanf("%d", &choice);getchar();
        if (choice == INSERT_LAST)
        {
            int n = 0;
            scanf("%d", &n);getchar();
            char* data = myGetLine();
            char* word = strtok(data, " ");
            while (word != NULL)
            {
                StrList_insertLast(list, word);
                word = strtok(NULL, " ");
                n--;
            }
            if (n != 0) return 1;
        }
        else if (choice == INSERT_AT)
        {
            int index;
            scanf("%d", &index);getchar();
            char* data = myGetLine();
            StrList_insertAt(list, data, index);
        }
        else if (choice == PRINT)
            StrList_print(list);
        else if (choice == SIZE)
            printf("%ld\n", StrList_size(list));
        else if (choice == 5)
        {
            int index;
            scanf("%d", &index);
            StrList_printAt(list, index);
        }
        else if (choice == PRINT_LEN)
            printf("%d\n", StrList_printLen(list));
        else if (choice == COUNT)
        {
            char* data = myGetLine();
            printf("%d\n", StrList_count(list, data));
        }
        else if (choice == REMOVE)
        {
            char* data = myGetLine();
            StrList_remove(list, data);
        }
        else if (choice == REMOVE_AT)
        {
            int index;
            scanf("%d", &index);
            StrList_removeAt(list, index);
        }
        else if (choice == REVERSE)
            StrList_reverse(list);
        else if (choice == FREE)
            StrList_free(list);
        else if (choice == SORT)
            StrList_sort(list);
        else if (choice == IS_SORTED)
            printf("%s\n", StrList_isSorted(list) ? "true" : "false");
    }

    return 0;
}