#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define INPUT_FILE "input.txt"
#define BUFFER_SIZE 100
#define CALIBRATION_VALUE_BUFFER_SIZE 3

int main()
{
    FILE* input_file = fopen(INPUT_FILE, "r");
    char buffer[BUFFER_SIZE];
    char calib_value_buffer[CALIBRATION_VALUE_BUFFER_SIZE];
    int calib_value_buffer_index = 0;
    int sum_calib_vals = 0;
    int i = 0;
    int line_num = 0;

    for(line_num = 1; fgets(buffer, BUFFER_SIZE, input_file) != NULL; line_num++) {
        printf("==Line %d== Buffer: %s", line_num, buffer);
        calib_value_buffer_index = -1;

        for(i = 0; buffer[i] != '\n' && buffer[i] != '\0' && buffer[i] != EOF; i++) {
            if(isdigit(buffer[i])) {
                if(calib_value_buffer_index <= 0) {
                    calib_value_buffer[++calib_value_buffer_index] = buffer[i];
                } else {
                    calib_value_buffer[calib_value_buffer_index] = buffer[i];
                }
            }
        }

        if(calib_value_buffer_index == 0) {
            calib_value_buffer[1] = calib_value_buffer[0];
        }

        calib_value_buffer[2] = '\0';
        sum_calib_vals += atoi(calib_value_buffer);
        printf("Calibration value: %s\n", calib_value_buffer);
        printf("\n");
    }

    printf("Sum: %d\n", sum_calib_vals);

    fclose(input_file);
    return 0;
}
