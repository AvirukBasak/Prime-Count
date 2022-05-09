/**
 * @name prime_plots.c
 * @author Aviruk Basak
 * @date 9-May-2022
 * @brief This code determines how many +ve integers will be needed to get 1 prime number in an interval of integers
 *
 * Ex: It take 1 number to get 1 prime number for the interval [2, 2]
 * Ex: It takes 4 numbers to get 1 prime number for the interval [14, 17]
 *
 * NOTE: Last integer of the interval is the prime number.
 */

# include <stdio.h>
# include <stdint.h>
# include <string.h>
# include <stdlib.h>

# define true  1
# define false 0

# define HIDE_CURSOR "\e[?25l"
# define SHOW_CURSOR "\e[?25h"

typedef uint64_t ui64;     // 8 bytes
typedef uint8_t bool;      // 1 byte
typedef FILE* File;

// check if a string is numeric
bool is_numeric (const char* str)
{
    ui64 i, len;
    len = strlen (str);
    for (i = 0; i < len; i++)
        if (str[i] < '0' || str[i] > '9')
            return false;
    return true;
}

// check if a number is prime
bool is_prime (ui64 num)
{
    if (num == 0 || num == 1)
        return false;
    if (num == 2 || num == 3)
        return true;
    for (ui64 i = 2; i <= num / 2; i++)
        if (num % i == 0)
            return false;
    return true;
}

int main (int argc, char **argv)
{
    ui64 limit, i, bkpi, count_of_nums;
    double percent;
    char *endptr;
    File fdata;

    // validate input
    if (argc < 2) {
        fprintf (stderr, "error: argument of limit not provided\n");
        printf ("USAGE: prime_plots \"[uint64_t]\"\n");
        return 1;
    } else if (!is_numeric (argv[1])) {
        fprintf (stderr, "error: invalid argument\n");
        printf ("USAGE: prime_plots \"[uint64_t]\"\n");
        return 1;
    }

    // convert argument to uint64_t
    limit = (ui64) strtoull (argv[1], &endptr, 10);

    i = 2;
    bkpi = i;
    count_of_nums = 0;

    // open the data storage file
    fdata = fopen ("./plot_data.txt", "wb");

    // hide cursor
    printf(HIDE_CURSOR);

    // loop from [2, limit]
    while (i <= limit) {

        // progress counter
        percent = (double) i / limit * 100;
        if ((ui64) percent % 10 == 0) {
            printf ("\rProgress: %.2lf %%", percent);
        }

        // main code
        if (is_prime (i)) {
            count_of_nums++;
            fprintf (fdata, "[%ld, %ld]: %ld\r\n", bkpi, i, count_of_nums);
            count_of_nums = 0;
            bkpi = i + 1;
        } else
            count_of_nums++;
        i++;
    }

    // show cursor, close file and return
    printf (SHOW_CURSOR "\n");
    fclose (fdata);
    return 0;
}
