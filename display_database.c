#include"inverted_search.h"

 void display_database(Wlist *head[])
{
	printf("----------------------------------Display - Database-------------------------------------------\n");
	printf("%-9s %-11s %-20s %-18s %-14s\n","[ index ]", "[ word ]", "[ file_count ]file/s", "[ File:file_name ]", "[ word_count ]");

	for(int i = 0 ; i < 27 ; i++)
	{
		if(head[i] != NULL)
		{
			print_word_count(head[i]);
		}
	}
	printf("------------------------------------------------------------------------------------------------\n");
}

int print_word_count(Wlist *head)
{
	//Traverse through the Wlist last node
	while(head != NULL)
	{
		printf("[%d]      [ %s ]       [%d]  ",tolower(head->word[0])%97, head->word, head->file_count);

		Ltable *Thead = head->Tlink;
		while(Thead)
		{
			printf("   File:%s  [%d]",Thead->file_name, Thead->word_count);
			Thead = Thead->table_link;
		}
		printf("\n");
		head = head->link;
	}
}
