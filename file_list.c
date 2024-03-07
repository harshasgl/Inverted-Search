#include"inverted_search.h"

int file_validation_n_file_list(Flist **f_head, char *argv[])
{
	/*declaring variables*/
	int empty, i = 1;

	/*run loop to access all the arguments*/
	while(argv[i] != NULL)
	{
		/*check if the file is empty and file has content or not*/
		empty = isFileEmpty(argv[i]);
		
		if(empty == FILE_NOT_AVAILABLE)
		{
			printf("File: %s is not available.\n", argv[i]);
			printf("Hence we are not adding that file to file linked list.\n");
			i++;
			continue;
		}
		else if(empty == FILE_EMPTY)
		{
			printf("File: %s is not having any contents in it.\n", argv[i]);
			printf("Hence we are not adding that file to file linked list.\n");
			i++;
			continue;
		}
		else
		{
			int ret = to_create_list_of_files(f_head, argv[i]);
			if(ret == REPETITION)
			{
				printf("File: %s is repeated.\n", argv[i]);
				printf("Hence we are not adding that file to file linked list.\n");
				i++;
				continue;
			}
			else
			{
				printf("Successfull: Inserting file name : %s into the linked list\n", argv[i]);
				i++;
			}
		}
	}
	return SUCCESS;
}

/*function is used to check whether file is available or not*/
/*also check for file content*/
int isFileEmpty(char *filename)
{
	/*open file in read mode*/
	FILE *fptr = fopen(filename, "r");
	if(fptr == NULL)
	{
		if(errno == ENOENT)
		{
			return FILE_NOT_AVAILABLE;
		}
	}

	/*check for contents*/
	fseek(fptr, 0 , SEEK_END);
	if(ftell(fptr) == 0)
		return FILE_EMPTY;
}

/*function to create a file linked list*/
int to_create_list_of_files(Flist **f_head, char *name)
{
	/*check if the list is empty*/
	if(*f_head == NULL)
	{
		/*create a new node*/
		Flist *new = malloc(sizeof(Flist));
		/*check if the node is created*/
		if(new == NULL)
			return FAILURE;

		/*update data and link part*/
		strcpy(new->fname,name);
		new->link = NULL;

		/*link node to head*/
		*f_head = new;
		return SUCCESS;
	}
	
	/*create a temporary pointer*/
	Flist *temp = *f_head;
	/*traverse through the list to find if the file already exist or not*/
	while(temp != NULL)
	{
		/*Compare the strings*/
		if(strcmp(temp->fname,name) == 0)
			return REPETITION;
		temp = temp->link;
	}
	
	/*new file name found, insert at last*/

	/*create a new node*/
    Flist *new = malloc(sizeof(Flist));
    /*check if the node is created*/
    if(new == NULL)
    	return FAILURE;

	/*update data and link part*/
    strcpy(new->fname,name);
    new->link = NULL;
	
	/*traverse through the list*/
	temp = *f_head;
	while(temp->link != NULL)
		temp = temp->link;
	
	/*link new node to the linked list*/
	temp->link = new;
	return SUCCESS;
}
