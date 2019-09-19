/***************************************************************
Fundamentals of C Programming - Assessment 3

Project Name: Secure Restaurant Database System (Placeholder)
Authors: Cameron Wang (13202320), Brendan Huynh, Peter Phan,
          David Ung, Daming Luo
Date of Submission: -
***************************************************************/
#include <stdio.h>

/***************************************************************
Function Prototypes
**NOTE** - At current stage in development, function prototypes
            are subject to change.
***************************************************************/
void menu(void);
void customer_detail_input(void);
void display_all_customers(void);
int encrypt_customer_password(char[] database_file, char[] customer_password);
int decrypt_customer_password(char[] database_file, char[] customer);
int compress_database_file(char[] database_file);
int decompress_database_file(char[] compressed_database_file);

/***************************************************************
Main Function
***************************************************************/
int main(void)
{
  return 0;
}
