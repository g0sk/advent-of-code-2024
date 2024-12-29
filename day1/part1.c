#include <stdio.h>
#include <stdlib.h>

#define MAX_LINES 1000

int main() {

  FILE* file = fopen("input.txt", "r");
  
  if (file == NULL) {
    printf("Error while opening file\n ");
    return 1;
  }

  int first_column[MAX_LINES];
  int second_column[MAX_LINES];
  int line_count = 0;

  while(fscanf(file, "%d %d", &first_column[line_count], &second_column[line_count] ) == 2) {
    //printf("%d %d\n", first_column[line_count], second_column[line_count]);
    line_count++;
    if (line_count >= MAX_LINES) {
      break;
    }
  }
  
  int sum = 0;
  for (int i = 0; i < line_count; i++) {
    int count = 0;
    for (int j = 0; j < line_count; j++) {
      if (first_column[i] == second_column[j]) {
        count++;
      }
    }
    sum += count * first_column[i];
  }
  printf("The result is %d\n", sum);
  return 0;
}