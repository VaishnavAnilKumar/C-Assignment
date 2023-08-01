#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct full_name//structure for full name
{
	char first_name[100];
	char middle_name[100];
	char last_name[100];
};
struct dv //structure for date of birth
{
	int day;
	int month;
	int year;

};
struct patient//structure for patient 
{
	struct full_name f1;
	char place[500];
	int id;
	int phno;
	struct dv d1;
	
};
struct patient *p;

void appendToFile(struct patient *y) 
{
    FILE *file ;
	file=fopen("patientlist.txt", "ab"); // Open the file in binary append mode

    if (file != NULL)
	{
        fwrite(y, sizeof(struct patient), 1, file); // Write the patient structure to the file
        fclose(file); // Close the file
        printf("Patient added successfully!\n");
    } 
	else 
	{
        printf("Error: Unable to open the file.\n");
    }
}

void ispatientAdded(int x) 
{
	struct patient y;
    FILE *file ;
	file= fopen("patientlist.txt", "rb"); // Open the file in binary read mode
	int i=1;
	system("cls");
    if (file != NULL)
	{
        int found =0;
        while (fread(&y, sizeof(struct patient), 1, file)) 
		{
			
            if (y.id == x) 
			{
                fclose(file);
                printf("Patient is added to the file\n\n");
                printf("Patient Id          :  %d",y.id);
				printf("\nPatient name       :  %s %s %s",y.f1.first_name,y.f1.middle_name,y.f1.last_name);
				printf("\nPatient's hometown :  %s",y.place);
				printf("\nPatient phno.      :  +91 %d",y.phno);
				printf("\n\n");
				found=1;
				break;// patient with given id is found in the file
            }
            
        }
        if(found==0)
            {
            	printf("Patient's Id not found!!");
            	
			}
			
        fclose(file);
    } 
	else 
	{
        printf("Error: Unable to open the file / File not found!! \n");
         return ; // patient with given id is not found in the file
    }

   
}


void append(struct patient *x)//adding new patients
{
	int i;
	system("cls");
	char c1[5],c2[5]="y",c3[5];
	for(i=1;i!=0;i++)
	{
		printf("\nEnter the Patient's Full Name with space (First Name / Middle Name/ Last Name): ");
		scanf("%s %s %s",x->f1.first_name,x->f1.middle_name,x->f1.last_name);//%s is used instead of gets() because it doesn't work with multiple string inputs	
		
		
		printf("\nEnter the Patient id(a number): ");
		scanf("%d",&x->id);
		
		printf("\nEnter the Patient's Hometown: ");
		scanf("%s",x->place);
		
	
		
		printf("\nEnter the Patient's Phone Number: +91 ");
		scanf("%d",&x->phno);
		
		
		
		printf("\nEnter the Patient's Date Of Birth(dd/mm/yy): ");
		scanf("%d%d%d",&x->d1.day,&x->d1.month,&x->d1.year);
		
		printf("\nDo you want to add this Patient's Details?(y/n):  ");//confirming to add the data
		scanf("%s",c3);
		if (strcmp(c3,c2)==0)
		{
			appendToFile(x);//call function to write data into file
			printf("\n\n");
		}
	
		printf("\nDo you want to add Another Patient?(y/n):  ");
		scanf("%s",c1);
		if(strcmp(c1,c2)==0)
		{
	
			continue;
		}
		else
		{
			printf("Saving changes... \n\n");
			break;
		}
		
	}
	return;
	
}

void update(int x)//updating patient details
{
	struct patient y;
	system("cls");
	long int position=0;
    FILE *file ;
	file= fopen("patientlist.txt", "rb+"); // Open the file in binary read & write mode
	
    if (file != NULL)
	{
        int found=0;
        while (fread(&y, sizeof(struct patient), 1, file)) 
		{
			
            if (y.id == x)
			{			
            	position = ftell(file)-sizeof(struct patient);	// Store the current position in the file
				char co[5];
			    char c1[5],c2[5]="y";
			    printf("\n");
				
				int k=1;
				while(k!=0)
				{
					printf("What to change? \n");
					printf("\t1.Phone number");
					printf("\n\t2.Hometown");
					printf("\n\t3.Nothing to change");
					printf("\nEnter the choice ( The number corresponding to the actions )\t");
					scanf("%s",co);//enter the preferred action
				
					if(strcmp(co,"1")==0)
					{
						printf("Enter the new phone number : +91 ");
						scanf("%d",&y.phno);
						printf("\n\tprocessing...");
						printf("\nSuccessfully Updated");
						
						printf("\nDo you want to update anything else?(y/n): ");
						scanf("%s",c1);
						if(strcmp(c1,c2)!=0)
						{
				
						printf("Saving changes... \n\n");
						break;
						}
						else
						continue;
					}
					else if(strcmp(co,"2")==0)
					{
						printf("Enter the new hometown :  ");
						scanf("%s",y.place);
						printf("\n\tprocessing...");
						printf("\nSuccessfully Updated");
						
						printf("\nDo you want to update anything else?(y/n): ");
						scanf("%s",c1);
						if(strcmp(c1,c2)!=0)
						{
				
						printf("Saving changes... \n\n");
						break;
						}
						else
						continue;
					}
					else if(strcmp(co,"3")==0)
					{
						printf("\n");
						printf("Loading.... ");
						break;
					}
					else
					{
						printf("\n");
						printf("Invalid input!!! Please try again...");
						continue;
					}
				}
				//printing the updated data
				printf("\nPatient Id          :  %d",y.id);
				printf("\nPatient name       :  %s %s %s",y.f1.first_name,y.f1.middle_name,y.f1.last_name);
				printf("\nPatient's hometown :  %s",y.place);
				printf("\nPatient phno.      :  +91 %d",y.phno);
				fseek(file, position, SEEK_SET); // Move the file cursor back to the beginning of the record

	            // Write the updated student record back to the file
	            fwrite(&y, sizeof(struct patient), 1, file);
				fclose(file);
				printf("\n\n");
				found=1;
				break;
				
			
		
		 	}
		 
		 	
			
		}
		if(found==0)
		{
			printf("\n");
			printf("Patient Id not found....");//patient not found 
		}
		fclose(file);
	}
}


int main()//main programme
{
	p=malloc(sizeof(struct patient));
	char c[10];
	int i=1;
	int id1;
	printf("\t**	   Welcome to VK Hospitals		**\n\n");
	while(i!=0)//infinite loop
	{
		//Printing list of actions that are available
		
		printf("\n");
		printf("\t1.Add a new patient ");
		printf("\n\t2.Update details of old patient ");
		printf("\n\t3.Check if patient is added or not and Display them ");
		printf("\n\t4.Exit the program");
		printf("\n\n");
		printf("\tEnter your choice( The number corresponding to the action ) \n\t");
		scanf("%s",c);//enter preferred action
	
		if(strcmp(c,"1")==0)
		{
			append(p);//calling function to add data
		}
		else if(strcmp(c,"2")==0)
		{
			printf("Enter the Patient ID: \n");
			scanf("%d",&id1);
			update(id1);//calling function to update data
			
		}
		
		else if(strcmp(c,"3")==0)
		{
			printf("Enter the Patient ID: \n");
			scanf("%d",&id1);
			ispatientAdded(id1);//calling function to check the data 
		}
		
		else if(strcmp(c,"4")==0)
		{
			printf("Saving Changes......\n");//closing remarks
			printf("Ending program..\n\n");
			printf("..Thank you..\n");
			break;
		}
		
		else//Error response
		{
			
			
				printf("   !!!!	   Invalid response	   !!!!\n");//for other invalid input
				printf("   !!!!	   Please try again	   !!!!\n\n");
				continue;
		}
		i++;
	}
	
}

