/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    if (value < 0)
    {
        return false;
    }
    
    if (n % 2 == 0)
    {
        if (value == values[n / 2] || value == values[n / 2 - 1])
        {
            return true;
        }
        else
        {
            if (n == 2)
            {
                return false;
            }
            else
            {
                if (value < values[n / 2 - 1])
                {
                    return (search(value, values, n / 2 - 1));
                }
                else if (value > values[n / 2])
                {
                    return (search(value, &values[n / 2 + 1], n / 2 - 1));
                }
            }
        }
        
    }
    else
    {
        if (value == values[n / 2])
        {
            return true;
        }
        else
        {
            if (n == 1)
            {
                return false;
            }
            else
            {
                if (value < values[n / 2])
                {
                    return (search(value, values, n / 2));  
                }
                else
                {
                    return (search(value, &values[n / 2 + 1], n / 2));
                }
            }
        }
    }
    
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    static int box[65536];
    int j, i;
    for (i = 0; i < n; i++)
    {
        j = values[i];
        box[j]++;
    }
    i = 0;
    
    for (j = 0; j < 65536; j++)
    {
        if (box[j] == 0)
        {
            continue;
        }
        else
        {
            while(box[j] > 0)
            {
                values[i] = j;
                i++;
                box[j]--;
            }
        }
    }
    return;
}
