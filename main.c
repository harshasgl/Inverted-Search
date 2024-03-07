#include"inverted_search.h"

int main(int argc, char *argv[])
{
	system("clear");

	/*validate CLA*/
	if(argc <= 1)
	{
		printf("Enter the valid number of arguments.\n");
		printf("Eg: ./Slist.exe f1.txt f2.txt ...\n");
		return 0;
	}

	/*Create list of filenames*/
	/*Declare head pointer*/
	Flist *f_head = NULL;
	Wlist *head[27] = { NULL };

	/*Validate the files and create linked list*/
	if(file_validation_n_file_list(&f_head, argv) == SUCCESS)
	{
		/*To check whether list isb created*/
		if(f_head == NULL)
		{
			printf("No files are available in the file linked list\n");
			printf("Hence process is terminating\n");
			return FAILURE;
		}
	
		while(1)
		{
			int option;
			printf("Select your choice among following options:\n");
			printf("1. Create DATABASE\n2. Display DATABASE\n3. update DATABASE\n4. Search\n5. Save DATABASE\nEnter your choice: ");
			scanf("%d",&option);
		
			switch(option)
			{
				case 1:
					/*function call to create the database*/
					create_database(f_head, head);
					break;
				case 2:
					display_database(head);
					break;
				case 3:
					update_database(head, &f_head);
					break;
				case 4:
					/*search database*/
					/*prompt the user to enter the word*/
					char word[WORD_SIZE];
					printf("Enter the word to search: ");
					scanf("%s",word);
					search(head[tolower(word[0]) % 97], word);
					break;
				case 5:
					save_database(head);
					break;
			}
			char op;
			getchar();
			printf("Do you want to continue(y/Y):");
			scanf("%c",&op);
			if(!(op == 'y' || op == 'Y'))
				return 1;
		}
	}
	else
	{
		printf("Validation is failure\n");
		return FAILURE;
	}
}
