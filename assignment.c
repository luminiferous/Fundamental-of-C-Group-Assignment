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
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

#define MAX_USER 5
#define USER "database"
/*******************************************************************************
Function Prototypes
**NOTE** - At current stage in development, function prototypes
            are subject to change.
*******************************************************************************/
typedef struct customer{
	char customer_id[10];
	char customer_password[20];
	int encrypt_password;
}customer_t;

typedef struct compress_code{
	char letter;
	int letter_f;
	unsigned int code;
	struct compress_code* st;
	struct compress_code* nd;
	struct compress_code* rd;
}compress_code_c;

typedef struct compress_table{
	char letter;
	int letter_f;
	unsigned int code;
}compress_table_t;


void menu(void);
void menu2(void);
void checkpoint(void);
void customer_detail_input(void);
void add_customer(customer_t** add, int count);
void check_customer(customer_t** check);
void login(customer_t** log, int logged_customer, int count);
void display_all_customers(void);
int encrypt_customer_password(char[] database_file, char[] customer_password);
int decrypt_customer_password(char[] database_file, char[] customer);
int compress_database_file(char[] database_file);
int decompress_database_file(char[] compressed_database_file);
void view_items(void);
void search_items(void);
int add_items(void);
int remove_items(void);
void view_purchase_history(void);
void help(void);

/*******************************************************************************
Main Function
*******************************************************************************/
int main(void)
{
	int count = 0, customer_number = 0;
	int logged_customer;

	customer_t* wu = NULL;

	wu = (customer_t*) malloc(MAX_USER* sizeof(customer_t));
	while(1){
		if (wu == NULL){
			printf("Error\n");
			return 1;
		}else{
		count = load_customer(&wu);
		printf("\n INTRODUCTION OF THIS PROGRAM OF MARKET\n"
		"This program lets multiple customers sign up and login\n"
      	"Then customer will be able to add, view, search, remove items\n"
      	"Customer can also view the purchase history\n"
      	"The encrypted password of Customers makes more safety \n");
		}
	}
	int count = 0, customer_number = 0;
	int logged_customer;
	int success_exit = 0;
	int choice = -1;
	while(1){
		while(count == 0){
		menu(void);
		scanf("%d", &choice);
		switch(choice){
			case 1:
			add_customer(&wu, count);
			break;
			case 2:
			login(&wu, count);
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
		while(count == 1){
			menu2(void);
			scanf("%d", &choice);
			switch(choice){
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

void add_customer(customer_t** add, int count)
{
	int i, k;
	char name[10];
	char password[20];
	char cust_dir[30] = "mkdir -p USER/";

	printf("Please enter an username with 6 more characters.\n"
		"Letters (a-z, A-Z, numbers(0-9)\n"
		"> ");
	fgets(name, 100, stdin);
	fgets(name, 100, stdin);

	for (i = 0; name[i] != '\0'; i++){
		if (name[0] == '\n' || name[0] <= 6 || name[0] == ' '){
			printf("\nInvaild input.\n"
				   "The username must start by character or number\n"
				   "Please enter a username\n"
				   ">  ");
			fgets(name, 100, stdin);
			i = -1;
			continue;
		}else if(name[i] == 96){
			continue;
		}else if(_isdigit(name[i])){
			continue;
		}else if(_isaplha(name[i])){
			continue;
		}else if(_isupper(name[i])){
			continue;
		}else if(_islower(name[i])){
			continue;
		}else if(name[i] == '\n' && count != 0 && i > 2){
			name[i] = '\0';
			for (k = 0; k != count; k++){
				if(strcmp(name, (*add + k)->customer_id)){
					printf("\nUsername already exsits\n"
						   "\nPlease enter a username\n> ");
					fgets(name, 100, stdin);
					i = -1;
					break;
				}else{continue;}
			}
			i--;
			continue;
		}else{
			printf("\nInvaild input\n"
				   "Please enter another username\n> ");
			fgets(name, 100, stdin);
			i = -1;
			continue;
		}
	}

	strcpy((*au+count)->customer_id, name);
	printf("\nPlease enter password\n> ");
	fgets(password, 100, stdin);
	int i;
	for (i = 0; password[i] != '0'; i++)
	{
		if(_isSpecial(password[i])){
			continue;
		}else if(password[i] == '\n' && i > 6){
			password[i] = '\0';
			i--;
			continue;
		}else if(password[i] == '\n' && i <= 6){
			printf("\nPassword too short\n"
				   "\nPlease enter another password\n> ");
			fgets(password[i], 100, stdin);
			i = -1;
			continue;
		}else{
			printf("\nInvaild input\n"
				   "\nPlease enter another password\n> ");
			fgets(password[i], 100, stdin);
			i = -1;
			continue;
		}
	}

	strcpy((*add+count)->cust_password, password);
	srand(count);
	(*add+count)->encrypt_password = rand() % 3 + 1;
	stract(cust_dir, name);
	system(cust_dir);
	count++;
	return count;
}
/*******************************************************************************
Menu Function - Lists all the menu options avaliable.
*******************************************************************************/
void menu(void)
{
	printf("Please enter vaild number for sign up or log in\n"
		"1: Sign up\n"
		"2: Log in\n"
		"3: Display all customers\n"
		"4: Exit");
}

void menu2(void)
{
	printf("Welcome to the supermarket\n"
		"1: View items\n"
		"2: Add items\n"
		"3: Search items\n"
		"4: Remove items\n"
		"5: View purchase history");
}

/*******************************************************************************
Display Function - Displays all the selected data fetched from
the database.
*******************************************************************************/
void display_all_customers(void)
{

}


/*******************************************************************************
View Item Function - Lists the items on the item catalogue.
*******************************************************************************/
void view_items(void)
{

}


/*******************************************************************************
Search Item Function - Searches for specific items on the item catalogue.
*******************************************************************************/
void search_items(void)
{

}





int _isdigit(char c){
    if (c >= 48 && c <= 57){
        return 1;
    }return 0;
}
int _isalpha(char c){ 
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
        return 1;
    }return 0;
}
int _isupper(char c){
    if (c >= 'A' && c <= 'Z'){
        return 1;
    }return 0;
}
char _toupper(char c){
    if(_isalpha(c)){
        if(_isupper(c)) return c; 
        return c - 32;
    }printf("Input is not an alphabet.");
    return c;
}
int _islower(char c){
	if(c <= 'z' && c >='a'){
		return 1;
	}return 0;
}
int _isSpecial(char c){
	if(c => 36 && c <= 126){
		return 1;
	}return 0;
}
