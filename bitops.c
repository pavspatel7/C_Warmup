/*
* Add NetID and names of all project partners
*
* Pavitra Patel - php51
* Kush Patel - kp1085
* CS 416
* ilab2
*
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define NUM_TOP_BITS 4 //top bits to extract
#define BITMAP_SIZE 4 //size of the bitmap array
#define SET_BIT_INDEX 17 //bit index to set 
#define GET_BIT_INDEX 17 //bit index to read

static unsigned int myaddress = 4026544704;   // Binary  would be 11110000000000000011001001000000
/* 
 * Function 1: EXTRACTING OUTER (TOP-ORDER) BITS
 */
static unsigned int get_top_bits(unsigned int value,  int num_bits)
{
	//Implement your code here
    return value >> ((BITMAP_SIZE*8) - num_bits);

    // int result=0;
    // int x=num_bits;
    // for(int i=31; i>31-num_bits; i--)
    // {
    //     //int j = (int)pow(2, i);
    //     int j = 1;
    //     j = j << i;

    //     if(j <= value && value >= 0)
    //     {
    //         //k += (int)pow(2, --x);
    //         int a = 1;
    //         a = a << --x;
    //         result += a;
            
    //         value -= j;
    //     }
    // }
    // return result;
}


/* 
 * Function 2: SETTING A BIT AT AN INDEX 
 * Function to set a bit at "index" bitmap
 */
static void set_bit_at_index(char *bitmap, int index)
{
    //Implement your code here	
    if(index >= 0 && index <= ((BITMAP_SIZE*8)-1))
    {
        int byte_index = index / 8;
        byte_index = (BITMAP_SIZE-1) - byte_index;
        int bit_position = index % 8;
        bitmap[byte_index] = bitmap[byte_index] | (1 << bit_position);
    }
}


/* 
 * Function 3: GETTING A BIT AT AN INDEX 
 * Function to get a bit at "index"
 */
static int get_bit_at_index(char *bitmap, int index)
{
    //Get to the location in the character bitmap array
    //Implement your code here
    int byte_index = index / 8;
    byte_index = (BITMAP_SIZE-1) - byte_index;
    int bit_position = index % 8;
    int result = ((bitmap[byte_index] & (1 << bit_position)) >> bit_position);
    // char a = bitmap[byte_index] & (1 << bit_position);
    // int x = atoi(&a);
    // int result = x >> bit_position;
    return result;
}


int main () {

    /* 
     * Function 1: Finding value of top order (outer) bits Now let’s say we
     * need to extract just the top (outer) 4 bits (1111), which is decimal 15  
    */
    unsigned int outer_bits_value = get_top_bits (myaddress , NUM_TOP_BITS);
    printf("Function 1: Outer bits value %u \n", outer_bits_value); 
    printf("\n");

    /* 
     * Function 2 and 3: Checking if a bit is set or not
     */
    char *bitmap = (char *)malloc(BITMAP_SIZE);  //We can store 32 bits (4*8-bit per character)
    memset(bitmap,0, BITMAP_SIZE); //clear everything
    
    /* 
     * Let's try to set the bit 
     */
    set_bit_at_index(bitmap, SET_BIT_INDEX);
    
    /* 
     * Let's try to read bit)
     */
    printf("Function 3: The value at %dth location %d\n", 
            GET_BIT_INDEX, get_bit_at_index(bitmap, GET_BIT_INDEX));

    return 0;
}
