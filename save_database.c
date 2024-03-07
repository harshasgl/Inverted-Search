#include"inverted_search.h"

 void save_database(Wlist *head[])
{
	//prompt the user for filename to save the database
	char filename[FNAME_SIZE];
	printf("Enter the file name: ");
	scanf("%s",filename);

	FILE *fptr = fopen(filename, "w");
	
	fprintf(fptr, "%s", "[index] [word] [file_count] [file_name] [word_count]\n");

	for(int i = 0 ; i < 27 ; i++)
	{
		if(head[i] != NULL)
		{
			write_databasefile(head[i], fptr);
		}
	}
	printf("-------------------------------Database saved------------------------------\n");
}

void write_databasefile(Wlist *head, FILE *databasefile)
{
	while(head)
	{
		fprintf(databasefile, "# : %d\n %s : %d file/s : ",tolower(head->word[0])%97, head->word, head->file_count);

        Ltable *Thead = head->Tlink;
        while(Thead)
        {
            fprintf(databasefile, "File:%s : %d : #",Thead->file_name, Thead->word_count);
            Thead = Thead->table_link;
        }
        fprintf(databasefile, "\n");

		head = head->link;
	}
}
