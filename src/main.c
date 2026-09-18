#include <stdio.h>
#include <stdlib.h>

#include "../include/mystrfunctions.h"
#include "../include/myfilefunctions.h"

int main()
{
    printf("--- Testing String Functions ---\n");

    char str1[100] = "Hello";
    char str2[] = " World";
    char copy[100];
    char limited[100];

    printf("Length of \"%s\": %d\n",
           str1,
           mystrlen(str1));

    mystrcpy(copy, str1);
    printf("After mystrcpy: %s\n", copy);

    mystrncpy(limited, "Operating System", 10);
    printf("After mystrncpy: %s\n", limited);

    mystrcat(str1, str2);
    printf("After mystrcat: %s\n", str1);


    printf("\n--- Testing File Functions ---\n");

    FILE* file = tmpfile();

    if (file == NULL)
    {
        printf("Could not create temporary file.\n");
        return 1;
    }

    fprintf(file, "Operating Systems is important.\n");
    fprintf(file, "We study OS in this course.\n");
    fprintf(file, "Linux is an operating system.\n");

    rewind(file);

    int lines;
    int words;
    int chars;

    if (wordCount(file, &lines, &words, &chars) == 0)
    {
        printf("Lines: %d\n", lines);
        printf("Words: %d\n", words);
        printf("Characters: %d\n", chars);
    }

    rewind(file);

    char** matches;

    int count = mygrep(file, "OS", &matches);

    if (count >= 0)
    {
        printf("\nLines containing \"OS\": %d\n", count);

        for (int i = 0; i < count; i++)
        {
            printf("%s", matches[i]);
            free(matches[i]);
        }

        free(matches);
    }

    fclose(file);

    return 0;
}