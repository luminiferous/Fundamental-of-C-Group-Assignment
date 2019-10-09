/*******************************************************************************
Fundamentals of C Programming - Assessment 3
Project Name: Secure Clothing Store Database System
Authors: Cameron Wang (13202320), Brendan Huynh (13202155),
	Peter Phan (13202268), David Ung (13245547), Daming Luo (13160039)
Date of Submission: -
*******************************************************************************/

/*******************************************************************************
C Libraries
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "huffman_coding.h"

#define MAX_USER 5
#define ITEMS_IN_DATABASE 50
#define USER_DB "customer_db"
#define ITEM_DB "item_db"
#define PURCHASE_DB "p_db"
#define ITEM_NAME_SIZE 30

/*******************************************************************************
Structures
*******************************************************************************/
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
	char username[101];
	char password[101];
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

typedef struct compress_code
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
} compress_table_t;

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

/*Display introduction of this program.
Author: Daming Luo*/
void Introduction_menu(void);

/* Gets an input from the user.
Author: Cameron Wang */
int get_input(void);

/* Gets an input from the customer.
Author: Cameron Wang */
void customer_input(char customer[]);

/* Gets an input from the system admin.
Author: Cameron Wang */
void admin_input(void);

/* Allows customers to provide their details.
Author: Daming Luo */
int login(char name[]);

/* Signs up customer to the system.
Author: Daming Luo */
int signup(char name[]);

/* Saves all customers to the database.
Author: Brendan Huynh */
/*void save_customer(customer_t* save, int count); */

void check_customer(customer_t* check);

/* Allows a customer to log into the system.
Author: Daming Luo */
/*void login(customer_t* log, int logged_customer, int count);*/

/* Displays all, or a specific customer in the database.
Author: Brendan Huynh */
void display_customers(void);

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

void add_cart(void);

void remove_cart(void);

/* Adds an item / items to the product database.
Author: Brendan Huynh */
int add_items(void);

/* Removes an item / items from the product database.
Author: Brendan Huynh */
int remove_items(void);

/* Allows a customer to purchase items from the store.
Author: Brendan Huynh */
int purchase_items(void);

/* Displays a customer's purchase history.
Author: Peter Phan */
int view_purchase_history(void);

/* Display the help screen.
Author: Peter Phan */
void help(void);

/*Display the help screen for admin.
Author: Peter Phan*/
void help_admin(void);

/* Function for debugging. */
void debug(void);

/* Checks if a character is an integer.
Author: Daming Luo */
int check_digit_char(char c);

/* Checks if a character is a letter.
Author: Daming Luo */
int check_letter_char(char c);

/* Checks if a character is a special character (not letter or digit).
Author: Daming Luo */
int check_special_char(char c);

/*******************************************************************************
Main Function
Author(s): Cameron Wang, Daming Luo
*******************************************************************************/
int main(void) {
	int input;
	char username[101];
	/* int count = 0;
	customer_number = 0;

	customer_t* wu = NULL;
	wu = (customer_t*) malloc(MAX_USER* sizeof(customer_t));
	if (wu == NULL)
	{
		printf("Memory error\n");
		return 1;
	}
	else
	{
		count = load_customer(&wu);
	} */
	while (1)
	{
		Introduction_menu();
		account_menu();
		input = get_input();
		switch (input)
		{
			case 1:
				signup(username);
				customer_input(username);
				break;
			case 2:
				if (login(username))
				{
					customer_input(username);
				}
				break;
			case 0:
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

/*******************************************************************************
Menu Functions - Lists all the menu options avaliable.
Author(s): Daming Luo, Cameron Wang
*******************************************************************************/
void account_menu(void)
{
	printf("\nWelcome to the Online Clothing Store.\n"
		"1. Sign Up\n"
		"2. Log In\n"
		"0. Exit\n");
}

void customer_menu(void)
{
	printf("\nWelcome to the Online Clothing Store\n"
		"1. View items\n"
		"2. Search items\n"
		"3. Add items to cart\n"
		"4. Remove items from cart\n"
		"5. View purchase history\n"
		"0. Help\n");
}

void admin_menu(void)
{
	printf("\nWelcome to the Admin Controls.\n"
		"1. Display all customers\n"
		"2. Add items to database\n"
		"3. Remove items from database\n"
		"2. Compress database\n"
		"3. Decompress database\n"
		"0. Help\n");
}

void Introduction_menu(void)
{
	printf("\n--------------------------------------------------------\n"
			"INTRODUCTION OF THIS PROGRAM OF MARKET\n"
			"This program lets multiple customers sign up and "
			"login\n"
			"Customer will be able to add, view, search, remove "
			"items\n"
			"Customer can also view the purchase history\n"
			"The encrypted password of Customers makes more safety \n"
			"-------------------------------------------------------- \n");
}

int get_input(void)
{
	int input;
	printf("Select an Option> ");
	scanf("%d", &input);
	return input;
}

void customer_input(char username[])
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
				view_items();
				break;
			case 2:
				search_items();
				break;
			case 3:
				purchase_items();
				break;
			case 4:
				remove_cart();
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
				display_customers();
				break;
			case 2:
				add_items();
				break;
			case 3:
				printf("Remove Items Function currently Unavailable\n");
				/* remove_items(); */
				break;
			case 4:
				printf("Compress Database File Function currently "
				"Unavailable\n");
				/* compress_database_file(); */
				break;
			case 5:
				printf("Decompress Database File Function currently "
				"Unavailable\n");
				/* decompress_database_file(); */
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

/*******************************************************************************
Add Customer Function - Adds a customer to the system.
Author(s): Daming Luo
*******************************************************************************/

/****************************ADD_CUSTOMER FUNCTION*****************************/
int signup(char name[])
{
	char password[101];
	char existingName[101];

	FILE *fp = fopen(USER_DB, "a");
	FILE *fp2 = fopen(USER_DB, "r");

	if(fp == NULL)
	{
		printf("Write error\n");
		return 1;
	}

	else
	{
		printf("Enter a Username> ");
		scanf("%s", name);
		int i, count = 0;
		for (i = 0; name[i] != '\0'; i++)
		{
			/*Detect if input number or letter*/
			if (check_digit_char(name[i]) || check_letter_char(name[i]))
			{
				continue;
			}
			else if(name[0] == '\n' || check_special_char(name[i]))
			{
				printf("\nInvaild input.\n"
				   		"The username must start by character or number\n"
				   		"Please enter a username\n> ");
				scanf("%s",name);
				i = -1;
				continue;
			/*Checks if the input name same with another customer's*/
			}
			else if(name[i] == '\n' && count != 0 && i > 2){
				/*Replaces '\n' with '\0'*/
				name[i] = '\0';
				while (fscanf(fp2, "%s %s", existingName, password) != EOF)
				{
					/*Customer name already exists*/
					if(strcmp(name, existingName)  == 0)
					{
						printf("\nUsername already exists\n"
						   		"\nPlease enter a username\n> ");
					   	scanf("%s", name);
						i = -1;
						break;
					}
					else
					{
						continue;
					}
				}
				i--;
				continue;
			}

			if(name[i] == '\n' && count == 0 && i > 2)
			{
				name[i] = '\0';
				i--;
				continue;
			}
			else
			{
				printf("\nInvaild input, customer name too short wuwuwuwuuw.\n"
				   		"Please enter another username\n> ");
			  	scanf("%s", name);
				i = -1;
				continue;
			}
		}/*Customer name for loop end*/

		printf("\n Please enter password \n> ");
		scanf("%s", password);
		/*Check password*/
		for (i = 0; password[i] != '\0'; i++)
		{
			/*Password can be number, letter and special characters*/
			if(check_special_char(password[i]) || check_letter_char(password[i]))
			{
				continue;
			}
			else if(check_digit_char(password[i]))
			{
				continue;
			}
			else if(password[i] == '\n' && i > 6)
			{
				password[i] = '\0';
				i--;
				continue;
			}
			else if(password[i] == '\n' && i < 6){
				printf("\nPassword too short\n"
				     	"\nPlease enter another password\n> ");
				scanf("%s", name);
				i = -1;
				continue;
			}
			else
			{
				printf("\nInvaild input\n"
				   		"\nPlease enter another password\n> ");
				scanf("%s", name);
				i = -1;
				continue;
			}
		}/*Password loop end*/
	}

	fprintf(fp, "%s %s\n", name, password);
	fclose(fp);

	return 0;
}

/********************************LOGIN FUNCTION********************************/
int login(char name[])
{
	char cust_pass[50];
	char cust_name[50];
	char existingName[101];
	char password[101];
	int flag = 0, attempts = 3;
	FILE *fp = fopen(USER_DB, "r");

	if (fp == NULL)
	{
		printf("Write error\n");
		return 1;
	}

	while(1)
	{
		printf("Enter your username\n");
		scanf("%s", cust_name);
		/* cust_name[strlen(cust_name) - 1] = '\0'; */
		while (fscanf(fp, "%s %s", existingName, password) != EOF)
		{
			if(strcmp(cust_name, existingName) == 0)
			{
				flag = 1;
			}
			else
			{
				printf("Username does not exsits");
				break;
			}
		}

		if (flag)
		{
			break;
		}
	}

	/***CHECK PASSWORD***/
	while(attempts > 3)
	{
		printf("Enter your password.\n> ");
		scanf("%s", cust_pass);

		if (strcmp(cust_pass, password) == 0)
		{
			printf("\nLogged in.\n");
			return 0;
		}
		else
		{
			printf("Incorrect password.\n");
			attempts--;
		}
	}

	printf("Login Failed\n");
	return 1;
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
void display_customers(void)
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
	fclose(fp);
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

void add_cart(void)
{

}

void remove_cart(void)
{

}

int add_items(void)
{
	item_t item;
	int sex, flag = 1;

	FILE *fp = fopen(ITEM_DB, "a");

	if(fp == NULL)
	{
		printf("Write error\n");
		return 1;
	}

	printf("Enter Clothing Name> ");
	scanf("%s", item.name);

	while(flag)
	{
		printf("1: Male (M)\n"
				"2: Female (F)\n"
				"3: Unisex (U)\n"
				"Select Clothing Gender> ");
		scanf("%d", &sex);
		switch(sex)
		{
			case 1:
				item.sex = 'M';
				flag = 0;
				break;
			case 2:
				item.sex = 'F';
				flag = 0;
				break;
			case 3:
				item.sex = 'U';
				flag = 0;
				break;
			default:
				printf("Invalid input\n");
		}
	}

	printf("Enter Clothing Size> ");
	scanf("%d", &item.size);

	printf("Enter Clothing Price> ");
	scanf("%lf", &item.price);

	fprintf(fp, "%s %c %d %lf\n", item.name, item.sex, item.size, item.price);

	fclose(fp);
	return 0;
}

int remove_items(void)
{
	return 0;
}


int purchase_items(void)
{
	 item_t item;
	 char input[ITEM_NAME_SIZE + 1];
     FILE *fp = fopen(ITEM_DB, "r");
	 FILE *fp2 = fopen(PURCHASE_DB,"a");
	 if (fp == NULL)
	 {
		printf("Write Error");
		return 1;
	 }
	printf("Enter Clothing Name> ");
	scanf("%s", input);
	/* fprintf(fp2, "%s\n", input); */
	while(fscanf(fp, "%s %c %d %lf\n", item.name, &item.sex, &item.size, &item.price) != EOF)
	{
		if (strcmp(input, item.name) == 0)
		{

			fprintf(fp2, "%s %c %d %0.2lf\n", item.name, item.sex, item.size, item.price);

		}
	}

	fclose(fp);
	fclose(fp2);
    return 0;
}


int view_purchase_history(void)
{
	FILE *fp = fopen(PURCHASE_DB, "r");
	FILE *fp2 = fopen(USER_DB, "r");
	long fileSize;
	/*item_t item;*/
	int i;

    if(fp == NULL)
    {
        printf("Read error\n");
		return 1;
    }

    fseek(fp, 0, SEEK_END);
    fileSize = ftell(fp);

    if (fileSize == 0)
	{
		i = 0;
        printf("You current have %d purchases.\n", i);
    }

	fclose(fp);
	fclose(fp2);

	return 0;
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
	char username[101] = "debug";
	int input, exitFlag = 0, existingFlag;
	int test3flag = 0;
	char string[101];
	node_t characters[30];
	node_t letter;
	int arraySize, j, i;
	while (1)
	{
		printf("\nDebug Menu:\n"
				"1. Force Customer Menu\n"
				"2. Force Admin Menu\n"
				"3. Frequency Count + Output Debugging / Testing\n"
				"4. Bubble Sort + Output Debugging / Testing\n"
				"5. Create Node + Output Debugging / Testing\n"
				"6. Build Huffman Tree + Output Debugging / Testing\n"
				"0. Exit\n");
		input = get_input();

		switch (input)
		{
			case 0:
				exitFlag = 1;
				break;
			case 1:
				customer_input(username);
				break;
			case 2:
				admin_input();
				break;
			case 3:
				printf("Enter a debug string (Max 100 Characters)> ");
				fgets(string, 100, stdin);
				fgets(string, 100, stdin);
				arraySize = 0;
				i = 0;
				while (string[i] != '\0')
				{
					existingFlag = 0;
					for (j = 0; j < arraySize; j++)
					{
						if (characters[j].character == string[i])
						{
							existingFlag = 1;
							break;
						}
					}

					if (!existingFlag && string[i] != '\n')
					{
						letter = debug_frequency_count(string[i], string, i);
						characters[j].character = letter.character;
						characters[j].freq = letter.freq;
						arraySize++;
					}
					i++;
				}

				character_output_loop(characters, arraySize);
				test3flag = 1;
				break;
			case 4:
				if (test3flag)
				{
					bubble_sort(characters, arraySize);
					character_output_loop(characters, arraySize);
				}
				else
				{
					printf("Must Run Test 3 before Performing This Test\n");
				}

				break;
			case 5:
				printf("Enter a debug string (Max 100 Characters)> ");
				fgets(string, 100, stdin);
				fgets(string, 100, stdin);
				arraySize = 0;
				i = 0;
				while (string[i] != '\0')
				{
					existingFlag = 0;
					for (j = 0; j < arraySize; j++)
					{
						if (characters[j].character == string[i])
						{
							existingFlag = 1;
							break;
						}
					}
					if (!existingFlag && string[i] != '\n')
					{
						character_output(create_node(string[i], frequency_count(string[i], string, i), NULL, NULL));
						characters[j].character = string[i];
						arraySize++;
					}
					i++;
				}
				break;
			case 6:
				if (test3flag)
				{
					node_t rootNode;
					rootNode = build_tree(characters, arraySize);
					huffman_tree_output(&rootNode);
				}
				else
				{
					printf("Must Run Test 3 before Performing This Test\n");
				}

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

int check_digit_char(char c)
{
    if (c >= '0' && c <= '9')
		{
        return 1;
    }
		return 0;
}

int check_letter_char(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		{
        return 1;
    }
		return 0;
}

int check_special_char(char c)
{
	if((c >= 32 && c <= 47) &&
	(c >= 58 && c <= 64) &&
	(c >= 91 && c <= 96) &&
	(c >=123 && c <=  126)){
		return 1;
	}
	return 0;
}

/*char isupper(char c)
{
    if (c >= 'A' && c <= 'Z')
		{
        return 1;
    }
		return 0;
}

char toupper(char c)
{
    if(_isalpha(c))
		{
        if(_isupper(c)) return c;
        return c - 32;
    }
		printf("Input is not an alphabet.");
    return c;
}

char islower(char c)
{
	if(c <= 'z' && c >='a'){
		return 1;
	}
	return 0;
}*/
