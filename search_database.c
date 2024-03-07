#include"inverted_search.h"

int search(Wlist *head, char *word)
{
	if(head == NULL)
	{
		printf("Search is not possible, list is empty\n");
		return 1;
	}

	//Traverse
	while(head)
	{
		//Compare the search word with each word in a list
		if(!(strcmp(head->word,word)))
		{
			printf("Word [ %s ] is present in %d file/s\n", word, head->file_count);

			Ltable *Thead = head->Tlink;
			while(Thead)
			{
				printf("In file: %s %d time/s\n", Thead->file_name, Thead->word_count);
				Thead = Thead->table_link;
			}
			printf("\n");
			return 1;
		}
		head = head->link;
	}
	printf("Search word is not present in the list\n");
}
