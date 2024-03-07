#include"inverted_search.h"

void create_database(Flist *f_head, Wlist *head[])
{
	/*traversing through file list until f_head is NULL*/
	while(f_head)
	{
		/*reading contents of file*/
		read_datafile(f_head, head, f_head->fname);
		printf("Database created for %s\n",f_head->fname);

		/*Move to next file node*/
		f_head = f_head->link;
	}
	printf("--------------------------Database created------------------------------\n");
}

 Wlist* read_datafile(Flist *file, Wlist *head[], char *filename)
{
	FILE *fptr = fopen(filename, "r");
	if(fptr == NULL)
	{
		printf("Error: opening file in create_database.c is failure.\n");
	}

	int flag = 1;
	char word[WORD_SIZE];

	while(fscanf(fptr, "%s", word) != EOF)
	{
		int index = tolower(word[0]) % 97;
		if(!(index >= 0 && index <= 25))
		{
			index = 26;
		}
		if(head[index] != NULL)
		{
			Wlist *temp = head[index];

			/*compare the words at each node with new word*/
			while(temp)
			{
				if(!(strcmp(temp->word, word)))
				{
					update_word_count(&temp, filename);
					flag = 0;
					break;
				}
				temp = temp->link;
			}
		}
		if(flag == 1)
		{
			insert_at_last(&head[index], word, filename);
		}
	}
}

/*todo*/
int update_word_count(Wlist **head, char *filename)
{
	/*Check filename same or not*/
	Ltable *temp = (*head)->Tlink;
	Ltable *prev = NULL;
	while(temp)
	{
		/*if filenames are same*/
		if(!(strcmp(temp->file_name, filename)))
		{
			/*increment word count*/
			temp->word_count = temp->word_count + 1;
			return SUCCESS;
		}
		prev = temp;
		temp = temp->table_link;
	}

	/*if files are different, create a new Ltable node*/
	Ltable *new = malloc(sizeof(Ltable));
	if(new == NULL)
		return FAILURE;

	/*Update data*/
	new->word_count = 1;
	strcpy(new->file_name,filename);
	new->table_link = NULL;

	/*link the node*/
	prev->table_link = new;

	/*increment file count*/
	(*head)->file_count = (*head)->file_count + 1;
	return SUCCESS;
}
