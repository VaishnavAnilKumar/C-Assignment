#include<stdio.h>
#include<string.h>
struct full_name//name
{
	char first_name[100];
	char middle_name[100];
	char last_name[100];
};
struct dv //date of visit
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
struct patient p[100];

void append()//adding new patients
{
	int i;
	char c1[5],c2[5]="y";
	/*struct patient p[100];*/
	for(i=0;i<100;i++)
	{
		printf("\nEnter the Patient's Full Name: ");
		scanf("%s %s %s",p[i].f1.first_name,p[i].f1.middle_name,p[i].f1.last_name);//%s is used instead of gets() because it doesn't work with multiple string inputs		
		
		
		printf("\nEnter the Patient's Customer id(a number): ");
		scanf("%d",&p[i].id);
		
		printf("\nEnter the Patient's Hometown: ");
		scanf("%s",p[i].place);
		
	
		
		printf("\nEnter the Patient's Phone Number: +91 ");
		scanf("%d",&p[i].phno);
		
		
		
		printf("\nEnter the Patient's Date Of Birth(dd/mm/yy): ");
		scanf("%d%d%d",&p[i].d1.day,&p[i].d1.month,&p[i].d1.year);
	
		printf("\nDo you want to add more?(y/n): ");
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
/*void display(){
	printf("Patient name : %s",)
}*/
int main()
{
	int c,i=1;
	
	printf("   Welcome to VK Hospitals");
	printf("\n\n");
	printf("1.Add a new patient ");
	printf("\n2.Update details of old patient ");
	printf("\n3.Delete a patient account ");
	printf("\n4.Exit the program");
	printf("\n\n");

	while(i!=0)
	{
		printf("Enter your choice \n");
		scanf("%d",&c);
	
		if(c==1)
		{
			append();
		}
		/*else if(c==2);
		else if(c==3);*/
		else if(c==4)
		{
			printf("Saving Changes......\n");
			printf("Ending program..\n\n");
			printf("..Thank you..\n");
			break;
		}
		else
		{
			printf("Invalid response!!!!\n");
			printf("Please try again!!!!\n\n");
			continue;
		}
		i++;
	}
	
	
}
