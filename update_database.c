#include"inverted_search.h"

 void update_database(Wlist *head[], Flist **f_head)
{
	char file_name[FNAME_SIZE];
	printf("Enter the file name: ");
	scanf("%s",file_name);
	

	//validation
	int empty =  isFileEmpty(file_name);

	if(empty == FILE_NOT_AVAILABLE)
    {
		printf("File: %s is not available.\n", file_name);
        printf("Hence we are not adding that file to file linked list.\n");
    }
    else if(empty == FILE_EMPTY)
	{
        printf("File: %s is not having any contents in it.\n", file_name);
        printf("Hence we are not adding that file to file linked list.\n");
    }
    else
	{    
		int ret = to_create_list_of_files(f_head, file_name);
        if(ret == REPETITION)
        {
            printf("File: %s is repeated.\n", file_name);
            printf("Hence we are not adding that file to file linked list.\n");
        }
        else
        {
            printf("Successfull: Inserting file name : %s into the linked list\n", file_name);
        }
		
		read_datafile(*f_head, head, file_name);
		printf("---------------------Database updated successfully.------------------------\n");
	}
		

/*
		while(*f_head)
		{
			//compare file names present already in the list
			if(!(strcmp((*f_head)->fname,file_name)))
			{
				create_database(*f_head, head);
			}
			*f_head = (*f_head)->link;
		}
	}
 */
}
