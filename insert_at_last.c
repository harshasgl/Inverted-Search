#include"inverted_search.h"

int insert_at_last(Wlist **head, data_t *data, char *filename)
{
	Wlist *new = malloc(sizeof(Wlist));
	if(new == NULL)
		return FAILURE;
	
	/*update data*/
	new->file_count = 1;
	strcpy(new->word, data);
	new->Tlink = NULL;
	new->link = NULL;

	/*call function to update link table*/
	update_link_table(&new, filename);

	/*Check Wlist is empty or not*/
	if(*head == NULL)
	{
		*head = new;
		return SUCCESS;
	}
	Wlist *temp = *head;
	/*Traverse through the list*/
	while(temp->link)
	{
		temp = temp->link;
	}
	temp->link = new;
	return SUCCESS;
}

int update_link_table(Wlist **head, char *filename)
{
	Ltable *new = malloc(sizeof(Ltable));
	if(new == NULL)
		return FAILURE;

	/*update data*/
	new->word_count = 1;
	strcpy(new->file_name,filename);
	new->table_link = NULL;
	(*head)->Tlink = new;
	return SUCCESS;
}
