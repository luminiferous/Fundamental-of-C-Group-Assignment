/*******************************************************************************
Fundamentals of C Programming - Assessment 3
Project Name: Secure Clothing Store Database System (Placeholder)
Authors: Cameron Wang (13202320), Brendan Huynh (13202155),
	Peter Phan (13202268), David Ung (13245547), Daming Luo (13160039)
Date of Submission: -
*******************************************************************************/

/*******************************************************************************
C Libraries
*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX_USER 5
#define USER "database"
/*******************************************************************************
Function Prototypes
**NOTE** - At current stage in development, function prototypes
            are subject to change.
*******************************************************************************/
typedef struct customer
{
	char customer_id[10];
	char customer_password[20];
	int encrypt_password;
}customer_t;

typedef struct compress_code
{
	char letter;
	int letter_f;
	unsigned int code;
	struct compress_code* st;
	struct compress_code* nd;
	struct compress_code* rd;
}compress_code_c;

typedef struct compress_table
{
	char letter;
	int letter_f;
	unsigned int code;
}compress_table_t;

// Displays main menu options.
void main_menu(void);
// Displays menu options for customers.
void customer_menu(void);
// Allows customers to prvide their details.
void customer_detail_input(void);
// Adds customer to the system.
void add_customer(customer_t** add, int count);
// Saves all customers to the database.
void save_customer(customer_t** save, int count);
void check_customer(customer_t** check);
// Allows a customer to log into the system.
void login(customer_t** log, int logged_customer, int count);
// Displays all customers in the database.
void display_all_customers(void);
// Encrypts the customer's password before being stored in the database.
int encrypt_customer_password(char[] database_file, char[] customer_password);
// Decrypts the customer's password.
int decrypt_customer_password(char[] database_file, char[] customer);
// Compresses the database file.
int compress_database_file(char[] database_file);
// Decompresses the database file.
int decompress_database_file(char[] compressed_database_file);
// Displays all products.
void view_items(void);
// Allows customers to search the items for specific products.
void search_items(void);
// Adds an item/s to the product database.
int add_items(void);
// Removes an item/s from the priduct database.
int remove_items(void);
// Displays a customer's purchase history.
void view_purchase_history(void);
// Display the help screen.
void help(void);

/*******************************************************************************
Main Function
Author(s): Daming Luo
*******************************************************************************/
int main(void)
{
	checkpoint(void);
	int count = 0, customer_number = 0;
	int logged_customer;
	int success_exit = 0;
	int choice = -1;
	while(1)
	{
		while(count == 0)
		{
			main_menu(void);
			scanf("%d", &choice);
			switch(choice)
			{
				case 1:
					add_customer(customer_t** add, int count);
					break;

				case 2:
					login(customer_t** log, int logged_customer, int count);
					break;

				case 3:
					display_all_customers(void);
					break;

				case 4:
					success_exit = 1;
					break;

				default:
					printf("Invaild input\n");
			}
			if (success_exit) break;
		}
		return 0;

		while(count == 1)
		{
			menu2(void);

			scanf("%d", &choice);
			switch(choice)
			{
				case 1:
					add_items(void);
					break;

				case 2:
					view_items(void);
					break;

				case 3:
					search_items(void);
					break;

				case 4:
					view_purchase_history(void);
					break;

				case 5:
					success_exit = 1;
					break;

				default:
					printf("Invaild input\n");
			}
		}
	}
	return 0;
}


void checkpoint(void)
{
	int count = 0, customer_number = 0;
	int logged_customer;

	customer_t* wu = NULL;
	wu = (customer_t*) malloc(MAX_USER* sizeof(customer_t));
	while(1)
	{
		if (wu == NULL)
		{
			printf("Error\n");
			return 1;
		}

		else
		{
			count = load_customer(&up);
			printf("\n INTRODUCTION OF THIS PROGRAM OF MARKET\n"
				"This program lets multiple customers sign up and login\n"
      			"Customer will be able to add, view, search, remove items\n"
      			"Customer can also view the purchase history\n"
      			"The encrypted password of Customers makes more safety \n");
		}
	}
}


void add_customer(customer_t** add, int count)
{

}

/*******************************************************************************
Menu Function - Lists all the menu options avaliable.
Author(s): Daming Luo
*******************************************************************************/
void main_menu(void)
{
	printf("Please enter vaild number for sign up or log in\n"
		"1: Sign up\n"
		"2: Log in\n"
		"3: Display all customers\n"
		"4: Exit");
}

void customer_menu(void)
{
	printf("Welcome to the Online Clothing Store\n"
		"1: View items\n"
		"2: Add items\n"
		"3: Search items\n"
		"4: Remove items\n"
		"5: View purchase history");
}

void customer_input(void) {
	int input;
	while(1) {
		customer_menu();
		printf("Input> ")
		scanf("%d", &input);
		switch(input) {
			case 1:

		}
	}
}

/*******************************************************************************
Display Function - Displays all the selected data fetched from
the database.
Author(s):
*******************************************************************************/
void display_all_customers(void)
{

}


/*******************************************************************************
View Item Function - Lists the items on the item catalogue.
Author(s):
*******************************************************************************/
void view_items(void)
{

}


/*******************************************************************************
Search Item Function - Searches for specific items on the item catalogue.
Author(s):
*******************************************************************************/
void search_items(void)
{

}
