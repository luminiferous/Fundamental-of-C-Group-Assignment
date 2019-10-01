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
#include "huffman_coding.h"

#define MAX_USER 5
#define ITEMS_IN_DATABASE 50
#define USER "database"
#define ITEM_DB "item_db"
#define ITEM_NAME_SIZE 30

/* struct node
{
	char letter;
	int weight;
	struct node* nextp;
};
typedef struct node node_t; */

struct customer
{
	char customer_id[10];
	char customer_password[20];
	int encrypt_password;
};
typedef struct customer customer_t;

struct item
{
	char name[ITEM_NAME_SIZE + 1];
	char sex;
	int size;
	double price;
};
typedef struct item item_t;

/* typedef struct compress_code
{
	char letter;
	int letter_f;
	unsigned int code;
	struct compress_code* st;
	struct compress_code* nd;
	struct compress_code* rd;
} compress_code_c;

typedef struct compress_table
{
	char letter;
	int letter_f;
	unsigned int code;
} compress_table_t; */

/*******************************************************************************
Function Prototypes
*******************************************************************************/
/* Displays main menu options.
Author: Daming Luo, Cameron Wang */
void account_menu(void);

/* Displays menu options for customers.
Author: Daming Luo, Cameron Wang */
void customer_menu(void);

/* Displays menu options for admin.
Author: Cameron Wang */
void admin_menu(void);

/* Gets an input from the user.
Author: Cameron Wang */
int get_input(void);

/* Gets an input from the customer.
Author: Cameron Wang */
void customer_input(void);

/* Gets an input from the system admin.
Author: Cameron Wang */
void admin_input(void);

/* Allows customers to provide their details.
Author: Daming Luo */
void customer_detail_input(void);

/* Adds customer to the system.
Author: Daming Luo */
void add_customer(customer_t* add, int count);

/* Saves all customers to the database.
Author: Brendan Huynh */
void save_customer(customer_t* save, int count);

void check_customer(customer_t* check);

/* Allows a customer to log into the system.
Author: Daming Luo */
void login(customer_t* log, int logged_customer, int count);

/* Displays all customers in the database.
Author: Brendan Huynh */
void display_all_customers(void);

/* Encrypts the customer's password before being stored in the database.
Author: David Ung */
int encrypt_customer_password(char database_file[], char customer_password[]);

/* Decrypts the customer's password.
Author: David Ung */
int decrypt_customer_password(char database_file[], char customer[]);

/* Compresses the database file.
Author: Cameron Wang */
int compress_database_file(char database_file[]);

/* Decompresses the database file.
Author: Cameron Wang */
int decompress_database_file(char compressed_database_file[]);

/* Displays all products.
Author: Peter Phan */
int view_items(void);

/* Allows customers to search the items for specific products.
Author: Cameron Wang */
int search_items(void);

/* Adds an item / items to the product database.
Author: Brendan Huynh */
item_t add_items(void);

/* Removes an item / items from the product database.
Author: Brendan Huynh */
int remove_items(void);

/* Allows a customer to purchase items from the store.
Author: Brendan Huynh */
void purchase_items(void);

/* Displays a customer's purchase history.
Author: Peter Phan */
void view_purchase_history(void);

/* Display the help screen.
Author: Peter Phan */
void help(void);

/*Display the help screen for admin.
Author: Peter Phan*/
void help_admin(void);

/* Function for debugging. */
void debug(void);


/*******************************************************************************
Main Function
Author(s): Cameron Wang, Daming Luo
*******************************************************************************/
int main(void) {
	int input;
	/* customer_t* wu = NULL;
	wu = (customer_t*) malloc(MAX_USER* sizeof(customer_t)); */
	while (1)
	{
		account_menu();
		input = get_input();
		switch (input)
		{
			case 1:
				printf("Add Customer Function currently Unavailable\n");
				/*add_customer();*/
				break;
			case 2:
				printf("Login Function currently Unavailable\n");
				/*login();*/
				break;
			case 3:
				exit(0);
				break;
			case 9:
				debug();
				break;
			default:
				printf("Invalid input\n");
		}
	}
}

/* int main(void)
{

	int count = 0, customer_number = 0;
	int logged_customer;

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
						"This program lets multiple customers sign up and "
						"login\n"
						"Customer will be able to add, view, search, remove "
						"items\n"
						"Customer can also view the purchase history\n"
						"The encrypted password of Customers makes more safety "
						\n");
		}
	}

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
					add_customer(&wu, count);
					break;

				case 2:
					login(&wu, count);
					break;

				case 3:
					display_all_customers();
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
} */

/*******************************************************************************
Menu Functions - Lists all the menu options avaliable.
Author(s): Daming Luo, Cameron Wang
*******************************************************************************/
void account_menu(void)
{
	printf("Welcome to the Online Clothing Store.\n"
		"1: Sign Up\n"
		"2. Log In\n"
		"3. Exit\n");
}

void customer_menu(void)
{
	printf("Welcome to the Online Clothing Store\n"
		"1: View items\n"
		"2: Search items\n"
		"3: Add items\n"
		"4: Remove items\n"
		"5: View purchase history\n"
		"6: Help\n");
}

void admin_menu(void)
{
	printf("Welcome to the Admin Controls."
		"1: Display all customers\n"
		"2: Compress database\n"
		"3: Decompress database\n"
		"4: Help\n");
}

int get_input(void)
{
	int input;
	printf("Select an Option> ");
	scanf("%d", &input);
	printf("\n");
	return input;
}

void customer_input(void)
{
	int input, exitFlag = 0;
	/* item_t items[100];
	int counter = ITEMS_IN_DATABASE; */
	while (1) {
		customer_menu();
		input = get_input();
		switch (input)
		{
			case 1:
				/* printf("View Items is currently Unavailable\n");
				printf("\n"); */
				view_items();
				break;
			case 2:
				search_items();
				break;
			case 3:
				printf("Add Items is currently Unavailable\n");
				printf("\n");
				/* items[counter] = add_items();
				counter++; */
				break;
			case 4:
				remove_items();
				break;
			case 5:
				view_purchase_history();
				break;
			case 6:
				help();
				break;
			case 0:
				exitFlag = 1;
				break;
			default:
				printf("Invalid input\n");
		}

		if (exitFlag)
		{
			break;
		}
	}
}

void admin_input(void)
{
	int input, exitFlag = 0;

	while (1)
	{
		admin_menu();
		input = get_input();
		switch (input)
		{
			case 1:
				display_all_customers();
				break;
			case 2:
				printf("Compress Database File Function currently "
				"Unavailable\n");
				printf("\n");
				/* compress_database_file(); */
				break;
			case 3:
				printf("Decompress Database File Function currently "
				"Unavailable\n");
				printf("\n");
				/* decompress_database_file(); */
				break;
			case 4:
				help();
				break;
			case 0:
				exitFlag = 1;
				break;
			default:
				printf("Invalid input\n");
		}

		if (exitFlag)
		{
			break;
		}
	}
}

/*******************************************************************************
Add Customer Function - Adds a customer to the system.
Author(s): Daming Luo
*******************************************************************************/

/****************************ADD_CUSTOMER FUNCTION*****************************/
void add_customer(customer_t* add, int count)
{

}

/********************************LOGIN FUNCTION********************************/
void login(customer_t* log, int logged_customer, int count)
{

}

void save_customer(customer_t* save, int count)
{

}

void check_customer(customer_t* check)
{

}



/*******************************************************************************
Display Function - Displays all the selected data fetched from
the database.
Author(s):
*******************************************************************************/
void display_all_customers(void)
{

}

int encrypt_customer_password(char database_file[], char customer_password[])
{
	return 0;
}

int decrypt_customer_password(char database_file[], char customer[])
{
	return 0;
}

int compress_database_file(char database_file[])
{
	return 0;
}

int decompress_database_file(char compressed_database_file[])
{
	return 0;
}

/*******************************************************************************
View Item Function - Lists the items on the item catalogue.
Author(s): Peter Phan
*******************************************************************************/
int view_items()
{
	FILE *fp = fopen(ITEM_DB, "r");
	long fileSize;
	item_t item;

    if(fp == NULL)
    {
        printf("Read error\n");
		return 1;
    }

    fseek(fp, 0, SEEK_END);
    fileSize = ftell(fp);

    if (fileSize == 0)
	{
        printf("There are no items in the catalogue.\n");
    }

	else
	{
		fseek(fp, 0, SEEK_SET);
		while (fscanf(fp, "%s %c %d %lf",
				item.name, &item.sex, &item.size, &item.price) != EOF)
		{
			printf("-------------------------\n");
        	printf("Clothing Name: %s\n"
				"Sex: %c\n"
                "Size: %d\n"
                "Price: $%0.2lf\n",
                item.name, item.sex, item.size, item.price);
			printf("-------------------------\n");
		}
	}

	printf("\n");
	return 0;
}

/*******************************************************************************
Search Item Function - Searches for specific items on the item catalogue.
Author(s): Cameron Wang
*******************************************************************************/
int search_items(void)
{
	item_t item;
	int existingFlag = 0;
	char input[ITEM_NAME_SIZE + 1];
	FILE *fp = fopen(ITEM_DB, "r");

	if (fp == NULL)
	{
		printf("Read error\n");
		return 1;
	}

	printf("Enter Clothing Name You Wish To Find> ");
	scanf("%s", input);
	while (fscanf(fp, "%s %c %d %lf",
			item.name, &item.sex, &item.size, &item.price) != EOF)
	{
		if (!strcmp(input, item.name))
		{
			existingFlag = 1;
			printf("-------------------------\n");
			printf("Clothing Name: %s\n"
					"Gender: %c\n"
					"Size: %d\n"
					"Price: $%0.2lf\n",
					item.name, item.sex, item.size, item.price);
			printf("-------------------------\n");
		}
	}

	if (!existingFlag)
	{
		printf("No Matching Results\n");
	}
	printf("\n");

	fclose(fp);
	return 0;
}

/* int add_items()
{
	item_t items;
	int i;

	FILE *fp;
	fp = fopen(USER, "w");

	if(fp == NULL)
	{
		printf("Write error\n");
		return 1;
	}

	for(i = 0; i < counter; i++)
	{
		fprintf(fp, "%s %c %d %0.2lf\n", &items[i].name, &items[i].sex,
			&items[i].size, &items[i].price););
	}

	fclose(fp);
	return 0;
} */

int remove_items(void)
{
	return 0;
}

void puchase_items(void)
{

}

void view_purchase_history(void)
{

}

void help(void)
{
	printf("Below is a detailed explanation on how to use the menu\n\n"
		"View items - Display all products available on the catalogue.\n"
		"Search items - User can search up key words to find specific products"
			"or categories on the catalogue.\n"
		"Add items - Add an item / items to the shopping cart.\n"
		"Remove items - Remove an item / items from the shopping cart.\n"
		"View purchase history - Allows user to see what products they have "
			"bought in the past.\n");
}

void help_admin(void)
{
	printf("Below is a detailed explanation on how to use the admin menu.\n\n"
		"Display all customers - Retrieves and displays a list of customers and"
			" their details from the database.\n"
		"Compress database - Compresses database.\n"
		"Decompress database - Decompresses database.\n");
}

void debug(void)
{
	int input, exitFlag = 0, existingFlag;
	char string[101];
	weight_t characters[30];
	weight_t letter;
	while (1)
	{
		printf("Debug Menu:\n"
				"1. Weight Count + Output Debugging / Testing\n"
				"2. Force Customer Menu\n"
				"3. Force Admin Menu\n"
				"0. Exit\n");
		input = get_input();

		switch (input)
		{
			case 0:
				exitFlag = 1;
				break;
			case 1:
				printf("Enter a debug string (Max 100 Characters)> ");
				scanf("%s", string);
				int arraySize = 0, j, i = 0;
				while (string[i] != '\0')
				{
					existingFlag = 0;
					for (j = 0; j < arraySize; j++)
					{
						if (characters[j].letter == string[i])
						{
							existingFlag = 1;
							break;
						}
					}

					if (!existingFlag)
					{
						letter = weight_count(string[i], string, i);
						characters[j].letter = letter.letter;
						characters[j].weight = letter.weight;
						arraySize++;
					}
					i++;
				}

				for (j = 0; j < arraySize; j++)
				{
					letter.letter = characters[j].letter;
					letter.weight = characters[j].weight;
					weight_output(&letter);
				}
				break;
			case 2:
				customer_input();
				break;
			case 3:
				admin_input();
				break;
			default:
				printf("Invalid input\n");
		}

		if (exitFlag)
		{
			break;
		}
	}
}

/* int _isdigit(char c)
{
    if (c >= 48 && c <= 57)
		{
        return 1;
    }
		return 0;
}

int _isalpha(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		{
        return 1;
    }
		return 0;
}

int _isupper(char c)
{
    if (c >= 'A' && c <= 'Z')
		{
        return 1;
    }
		return 0;
}

char _toupper(char c)
{
    if(_isalpha(c))
		{
        if(_isupper(c)) return c;
        return c - 32;
    }
		printf("Input is not an alphabet.");
    return c;
}

int _islower(char c)
{
	if(c <= 'z' && c >='a'){
		return 1;
	}
	return 0;
}

int _isSpecial(char c)
{
	if(c => 36 && c <= 126)
	{
		return 1;
	}
	return 0;
} */
