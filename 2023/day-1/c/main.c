#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define INPUT_FILE "input_test.txt"
#define BUFFER_SIZE 100

int main()
{
    FILE *input_buf = fopen(INPUT_FILE, "r");
    char buffer[BUFFER_SIZE];
    char number_string[3];
    int number_string_index = -1;
    int extracted_number = 0;
    int sum = 0;
    int i = 0;
    int line_num = 0;

    number_string[2] = '\0';

    while (fgets(buffer, BUFFER_SIZE, input_buf))
    {
        number_string_index = -1;
        ++line_num;
        printf("==Line %d== ", line_num);

        for (int i = 0; buffer[i] != '\n' && buffer[i] != EOF && buffer[i] != '\0'; i++)
        {
            if(isdigit(buffer[i])) {
                if(i > 0)
                    printf(" ");
                printf("[%c] ", buffer[i]);
            } else {
                printf("%c", buffer[i]);
            }
        }

        printf(",\t0: %c, 1: %c\n", number_string[0], number_string[1]);
        if(number_string_index == 1) {
            printf("#### number_string_index is 1.\n");
            number_string[1] = number_string[0];
        }
        
        extracted_number = atoi(number_string);
        printf(" ==> %d\n", extracted_number);

        sum += extracted_number;
   }

    printf("Sum: %d\n", sum);
    fclose(input_buf);
    return 0;
}