#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000

int sort_asc(const void* a, const void* b) {
  return (*(int*)a - *(int*)b);
}

int main()
{
  FILE* file_stream;

  file_stream = fopen("input.txt", "r");

  if (file_stream == NULL)
  {
    printf("Error while opening file\n");
    return 1;
  }

  int first_column[MAX_LINES];
  int second_column[MAX_LINES];
  int line_count = 0;

  while (fscanf(file_stream, "%d %d", &first_column[line_count], &second_column[line_count]) == 2)
  {
    //printf("%d %d\n", first_column[line_count], second_column[line_count]);
    line_count++;
    if (line_count >= MAX_LINES)
    {
      break;
    }
  }
  fclose(file_stream);

  qsort(first_column, line_count, sizeof(first_column[0]), sort_asc);
  qsort(second_column, line_count, sizeof(second_column[0]), sort_asc);

  int diff = 0;
  for (int i = 0; i < line_count; i++) {
    diff += abs(first_column[i] - second_column[i]);
  }

  printf("The result is %d\n", diff);
  return 0;
}