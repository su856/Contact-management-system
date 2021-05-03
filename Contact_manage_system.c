#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct person{
	char name[40];
	char address[60];
	char phone_no[20];
	char email_no[20];
}add,check,upd;
void menu();
void add_contact();
void contact_list();
void searching();
void Delete_contact();
void edit_contact();
int main()
{
	menu();
	getch();
}
void add_contact()
{
	system("cls");
	FILE *ptr;
	system("color 9");
	printf("\n\n\t\t\t\xb2\xb2\xb2 Add Record \xb2\xb2\xb2");
	printf("\n\t\t---------------------------------");
	ptr=fopen("contact.dat","a+");
	printf("\n\n\t\tEnter Name:");
	scanf("%s",&check.name);
	printf("\n\t\tEnter phone number:");
	scanf("%s",&check.phone_no);
	printf("\n\t\tEnter address:");
	scanf("%s",&check.address);
	printf("\n\t\tEnter email_id:");
	scanf("%s",&check.email_no);
	printf("\n\t\t----------------------------------");
	while(fscanf(ptr,"%s %s %s %s",&add.name,&add.phone_no,&add.address,&add.email_no)!=EOF)
	{
		if(strcmp(check.phone_no,add.phone_no)==0)
		{
			printf("\n\n\t\tMESSAGE:This phone number already exist!");
			printf("\n\n\t\t\t\tPlease enter valid Phone_number......");
			getch();
			add_contact();
		}
	}
	if((strlen(check.phone_no)>10)||(strlen(check.phone_no)<10))
	{
		printf("\n\n\t\tMESSAGE:This phone number is wrong!");
		printf("\n\n\t\t\t\tPlease check your Phone_number......");
		getch();
		add_contact();
	}
	strcpy(add.phone_no,check.phone_no);
	strcpy(add.name,check.name);
	strcpy(add.address,check.address);
	strcpy(add.email_no,check.email_no);
	printf("\n\n\tMESSAGE: Contact Management System has been Updated!");
	getch();
	fprintf(ptr,"\n%s %s %s %s\n",add.name,add.phone_no,add.address,add.email_no);
	fclose(ptr);
	system("color 7");
	menu();
}
void contact_list()
{
	system("cls");
	FILE *ptr;
	system("color 3");
	ptr=fopen("contact.dat","r");
	printf("\n\n\t\t\t\xb2\xb2\xb2 CONTACT LIST  \xb2\xb2\xb2");
	printf("\n\t\t-------------------------------------\n");
	while(fscanf(ptr,"%s %s %s %s",&add.name,&add.phone_no,&add.address,&add.email_no)!=EOF)
	{
	  printf("\n\t\t NAME:%s",add.name);
	  printf("\n\t\t PHONE NO:%s",add.phone_no);
	  printf("\n\t\t ADDRESS:%s",add.address);
	  printf("\n\t\t EMAIL ID:%s",add.email_no);
	  printf("\n\t\t-------------------------------------\n");
	}
	fclose(ptr);
	printf("\n\n\tPress any key to go menu section..................");
	getch();
	system("color 7");
	menu();
}
void searching()
{
	system("cls");
	FILE *ptr;
	int temp=0;
	system("color 6");
	ptr=fopen("contact.dat","r");
	printf("\n\n\tEnter phone number of that person to search:");
	scanf("%s",&check.phone_no);
	if((strlen(check.phone_no)>10)||(strlen(check.phone_no)<10))
	{
		printf("\n\n\t\tMESSAGE:This phone number is wrong!");
		printf("\n\n\t\t\t\tPlease check your Phone_number......");
		printf("\n\t\t-------------------------------------------------");
		printf("\n\n\tMESSAGE:Press any key to go menu section..................");
		getch();
		system("color 7");
		menu();
	}
	while(fscanf(ptr,"%s %s %s %s",&add.name,&add.phone_no,&add.address,&add.email_no)!=EOF)
	{
		if(strcmp(check.phone_no,add.phone_no)==0)
		{
		  temp=1;
		  printf("\n\n\t\t MESSAGE:SEARCHING SUCCESSFULLY!\n");
		  printf("\n\n\t\t\t\xb2\xb2\xb2 SEARCH LIST  \xb2\xb2\xb2");
	      printf("\n\t\t-------------------------------------\n");
		  printf("\n\t\t NAME:%s",add.name);
		  printf("\n\t\t PHONE NO:%s",add.phone_no);
		  printf("\n\t\t ADDRESS:%s",add.address);
		  printf("\n\t\t EMAIL ID:%s",add.email_no);
		  printf("\n\t\t-------------------------------------\n");
		  break;
	    }
	}
	if(temp==0){
	  printf("\n\n\t\t MESSAGE:SEARCHING UNSUCCESSFULLY!");
	  printf("\n\t\t-----------------------------------\n");
	}
	 fclose(ptr);
	 printf("\n\n\tPress any key to go menu section..................");
	 getch();
	 system("color 7");
	 menu();
}
void Delete_contact()
{
	system("cls");
	FILE *ptr,*fp;
	int temp=0;
	ptr=fopen("contact.dat","r");
	fp=fopen("base.dat","w");
	system("color 2");
	printf("\n\n\t\t\t\xb2\xb2\xb2 Delete Contact \xb2\xb2\xb2");
	printf("\n\t\t-------------------------------------");
	printf("\n\n\tEnter phone number of that person to delete:");
	scanf("%s",&check.phone_no);
	if((strlen(check.phone_no)>10)||(strlen(check.phone_no)<10))
	{
		printf("\n\n\t\tMESSAGE:This phone number is wrong!");
		printf("\n\n\t\t\t\tPlease check your Phone_number......");
		printf("\n\t\t-------------------------------------------------");
		printf("\n\n\tMESSAGE:Press any key to go menu section..................");
		getch();
		system("color 7");
		menu();
	}
	while(fscanf(ptr,"%s %s %s %s",&add.name,&add.phone_no,&add.address,&add.email_no)!=EOF)
	{
		if(strcmp(check.phone_no,add.phone_no)==0)
		{
			temp=1;
			printf("\n\n\t\tMESSAGE: Deletion successfull!");
			getch();
			printf("\n\n\tPress any key to go menu section..................");
		}
		else
		{
			fprintf(fp,"\n%s %s %s %s\n",add.name,add.phone_no,add.address,add.email_no);
		}
	}
	if(temp==0)
	{
		printf("\n\n\t\tMESSAGE:This Contact are not found!");
		getch();
		printf("\n\n\tPress any key to go menu section..................");
	}
	fclose(ptr);
	fclose(fp);
	remove("contact.dat");
	rename("base.dat","contact.dat");
	system("color 7");
	menu();
}
void edit_contact()
{
	system("cls");
	FILE *ptr,*fp;
	int temp=0,choice;
	system("color 8");
	ptr=fopen("contact.dat","r");
	fp=fopen("base.dat","w");
	printf("\n\n\tEnter phone number of that person to update contact:");
	scanf("%s",&check.phone_no);
	if((strlen(check.phone_no)>10)||(strlen(check.phone_no)<10))
	{
		printf("\n\n\t\tMESSAGE:This phone number is wrong!");
		printf("\n\n\t\t\t\tPlease check your Phone_number......");
		printf("\n\t\t-------------------------------------------------");
		printf("\n\n\tMESSAGE:Press any key to go menu section..................");
		getch();
		system("color 7");
		menu();
	}
	while(fscanf(ptr,"%s %s %s %s",&add.name,&add.phone_no,&add.address,&add.email_no)!=EOF)
	{
		if(strcmp(check.phone_no,add.phone_no)==0)
		{
		  temp=1;
		  virat:
		  printf("\n\n\t\t********MENU********");
	      printf("\n\t\t========================\n\t\t|                      |");
	      printf("\n\t\t|\t1.NAME         |");
	      printf("\n\t\t|\t2.PHONE NUMBER |");
	      printf("\n\t\t|\t3.ADDRESS      |");
	      printf("\n\t\t|\t4.EMAIL ID     |");
	      printf("\n\t\t========================");
	        printf("\n\n\tEnter your choice to edit:");
	        scanf("%d",&choice);
	     system("cls");
	     switch(choice)
         {
	    	case 1:{
	    		printf("\n\n\tEnter new name:");
	    		scanf("%s",&upd.name);
	    		fprintf(fp,"\n%s %s %s %s\n",upd.name,add.phone_no,add.address,add.email_no);
	    		printf("\n\tMESSAGE:EDITION SUCCESSFULLY!");
	    		getch();
				break;
			}
			case 2:{
	    		printf("\n\n\tEnter new Phone number:");
	    		scanf("%s",&upd.phone_no);
	    		if((strlen(upd.phone_no)>10)||(strlen(upd.phone_no)<10))
	            {
					printf("\n\n\t\tMESSAGE:This phone number is wrong!");
					printf("\n\n\t\t\t\tPlease check your Phone_number......");
					printf("\n\t\t-------------------------------------------------");
					fprintf(fp,"\n%s %s %s %s\n",add.name,add.phone_no,add.address,add.email_no);
					break;
	            }
	    		fprintf(fp,"\n%s %s %s %s\n",add.name,upd.phone_no,add.address,add.email_no);
	    		printf("\n\tMESSAGE:EDITION SUCCESSFULLY!");
	    		getch();
				break;
			}
			case 3:{
	    		printf("\n\n\tEnter new Address:");
	    		scanf("%s",&upd.address);
	    		fprintf(fp,"\n%s %s %s %s\n",add.name,add.phone_no,upd.address,add.email_no);
	    		printf("\n\tMESSAGE:EDITION SUCCESSFULLY!");
	    		getch();
				break;
			}
			case 4:{
	    		printf("\n\n\tEnter new Email id:");
	    		scanf("%s",&upd.email_no);
	    		fprintf(fp,"\n%s %s %s %s\n",add.name,add.phone_no,add.address,upd.email_no);
	    		printf("\n\tMESSAGE:EDITION SUCCESSFULLY!");
	    		getch();
				break;
			}
			default:{
				printf("\n\n\t\tMESSAGAE:INVALID CHOICE!");
				printf("\n\n\t\tPress any key to Try again.............");
				getch();
				goto virat;
				break;
			}
	      }
	    }
	    else
	    {
	    	fprintf(fp,"\n%s %s %s %s\n",add.name,add.phone_no,add.address,add.email_no);
		}
	}
	if(temp==0){
	  printf("\n\n\t\t MESSAGE:Contact Number are not found!");
	  printf("\n\t\t--------------------------------------\n");
	} 
	 fclose(ptr);
	 fclose(fp);
	 remove("contact.dat");
	 rename("base.dat","contact.dat");
	 printf("\n\n\tPress any key to go menu section..................");
	 getch();
	 system("color 7");
	 menu();
}
void menu()
{
	system("cls");
	int choice;
	printf("\n\n\t****** WELCOME TO CONTACT MANAGEMENT SYSTEM ******");
	printf("\n\t--------------------------------------------------");
	printf("\n\n\t\t***************MENU*****************");
	printf("\n\t\t====================================\n\t\t|                                  |");
	printf("\n\t\t|\t1.Add a new Contact        |");
	printf("\n\t\t|\t2.List of all Contact      |");
	printf("\n\t\t|\t3.Search a Contact         |");
	printf("\n\t\t|\t4.Edit a Contact           |");
	printf("\n\t\t|\t5.Delete a Contact         |");
	printf("\n\t\t|\t6.Exit                     |");
	printf("\n\t\t====================================");
        printf("\n\n\t\tEnter your choice:");
        scanf("%d",&choice);
    switch(choice)
    {
    	case 1:{
    		add_contact();
			break;
		}
		case 2:{
			contact_list();
			break;
		}
		case 3:{
			searching();
			break;
		}
		case 4:{
			edit_contact();
			break;
		}
		case 5:{
			Delete_contact();
			break;
		}
		case 6:{
			printf("\n\n\tMESSAGE:Thankyou for visiting contact management system!");
			exit(1);
			break;
		}
		default:{
			printf("\n\n\t\tMESSAGAE:INVALID CHOICE!");
			printf("\n\n\t\tPress any key to Try again.............");
			getch();
			menu();
			break;
		}
	}
}
