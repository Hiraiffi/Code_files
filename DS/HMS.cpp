#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>


void login();
void RoomFeatures();
void BookRoom();
float priceRoom();
float priceFacilities();
void roomType();
void a();
void View();
void Edit();
void Delete();

//For keeping track of number of rooms available
FILE *total,*standard,*premium,*deluxe;
int n,nmax=26; //nmax is total number of all the rooms in hotel
int S,smax=12; //smax is maximum number of standard rooms in hotel 
int P,pmax=8; //pmax is maximum number of premium rooms in hotel 
int D,dmax=6; //dax is maximum number of deluxe rooms in hotel 


struct duration
{ 
	char checkin[12];
	int no_of_days;
}d;


struct Customer
{
	char name[20];
	char CNIC[17];
	char phone[13];
	char email[30];
	struct duration d;
	char room[4];
	char facilities[7];
	float totalbill;
}c;



int main()
{   	
    char option;
    //reading number of total rooms and each type of rooms in order update availability
    total=fopen("total.txt","r");
	fscanf(total,"%d",&n);
	fclose(total);
	standard=fopen("standard.txt","r");
	fscanf(standard,"%d",&S);
	fclose(standard);
	premium=fopen("premium.txt","r");
	fscanf(premium,"%d",&P);
	fclose(premium);
	deluxe=fopen("deluxe.txt","r");
	fscanf(deluxe,"%d",&D);
	fclose(deluxe);
	
	system("cls");
	printf("\n\n\t    H O T E L\n\n\tM A N A G M E N T\n\n\t  S Y S T E M");
	printf("\n\n\n\t  loading....");
	Sleep(3000);
    login();
    system("cls");
    
    while(1)
    {
    	system("cls");
    	printf("\n---------------- M A I N  M E N U ----------------\n");
    	printf("____________________________________________________\n");
    	printf("\n\t\t1 Rooms Features\n\t\t2 Book a room\n\t\t3 View Customer Details\n\t\t4 Edit Customer Details\n\t\t5 Delete Customer details\n\t\t6 Log out\n");
    	printf("____________________________________________________\n");
    	printf("\n\t\tTotal Rooms-> 26");
    	printf("\n\t\tRooms Occupied-> %d",n);
    	printf("\n____________________________________________________");
    	option=getch();
    
		switch (option)
		{
			case '1':
				RoomFeatures();
			break;
			
			case '2':
				BookRoom();
			break;
		
			case '3':
				View();
			break;
			
			case '4' :
				Edit();
			break;
			
			case '5' :
				Delete();
			break;
			
			case '6':
				system("cls");
				puts("\n\n\n\n\n\n\t\tL O G G I N G   O F F.....");
				Sleep(3000);
				login();
				break;
		}
	}
	return 0;
}

//MAJOR FUNCTIONS----------------------------------------------------------------------------------------------------------------------------------

//Main and Case 6
void login()
{
	printf("\a");
	char username[30],password[20];
	char ch;
	int i;
	
	do
	{
		system("cls");
		printf("  \n\n\n\t----------L O G I N----------");
		printf("\n\n\tEnter Username : ");
		fflush(stdin);
		gets(username);
		printf("\tEnter Password : ");
     	for(i=0; i<10; i++)
     	{
            ch=getch();
            password[i]=ch;
            if(ch!=13)      
            printf("*");
            if(ch == 13)
            break;
        }
      	password[i]='\0';

		if (strcmp(username,"managementhotel")!=0 || strcmp(password,"!@#456yui")!=0)
		{
			Beep(750,400);
			puts("\n\tEither username or password is incorrect!");
			printf("\n\n\tPress ENTER to try again");
			getch();
		}
	}while(strcmp(username,"managementhotel")!=0 || strcmp(password,"!@#456yui")!=0);
}


//Case 1	 
void RoomFeatures()
{
	system("cls");
	int roomtype;
	printf("____________________________________________________\n");
	printf("\n\t\t[S]Standard Room\n\t\t-Single Bed\n\t\t-Window\n\t\t-Iron\n\t\tPrice : PKR 10000\n\t\tAvailable Rooms : %d\n\n",smax-S);
	printf("____________________________________________________\n");
	printf("\n\t\t[P]Premium Room\n\t\t-Double Bed\n\t\t-Window\n\t\t-Balcony\n\t\tPrice : PKR 20000\n\t\tAvailable Rooms : %d\n\n",pmax-P);
	printf("____________________________________________________\n");
	printf("\n\t\t[D]Deluxe Twin Room\n\t\t-Queen Sized Bed\n\t\t-Air Conditioning\n\t\t-Road Facing Balcony\n\t\tPrice : PKR 35000\n\t\tAvailable Rooms : %d\n\n",dmax-D);
	printf("____________________________________________________\n");
	printf("\n\n\t\tPress ESC to go back to Main Menu");
	char ch=getch();
}


//Case 2
void BookRoom()
{
	system("cls");
	FILE *fptr;
	fptr=fopen("CustomerDetails.txt","a+");
	while(1)
	{
		system("cls");
		if(n>=nmax)
		{
			printf("\n\n\n\n\n\t\t\tA L L    R O O M S    A R E    O C C U P I E D");
			printf("\n\n\t\t\tRedirecting to Main Menu....");
			Sleep(2000);
			break;
		}
		else
		{
			printf("  \n\n\n\t\t----------B O O K   A   R O O M----------");
			printf("\n\t\t_________________________________________");
			printf("\n\n  \t\t\tName : ");
			fflush(stdin);
			gets(c.name);
			printf("  \t\t\tCNIC : ");
			fflush(stdin);
			gets(c.CNIC);
			printf("  \t\t\tPhone : ");
			fflush(stdin);
			gets(c.phone);
			printf("  \t\t\tEmail : ");
			fflush(stdin);
			gets(c.email);
			printf("  \t\t\tCheck in date(dd\\mm\\yyyy) : ");
			fflush(stdin);
			gets(c.d.checkin);
			printf("  \t\t\tDuration(days) : ");
			scanf("%d",&c.d.no_of_days);
			printf("  \t\t\tRoom Type : ");
			roomType();
			c.totalbill=(c.d.no_of_days*500)+priceRoom(c.room)+priceFacilities();
			fwrite(&c,sizeof(c),1,fptr);
			printf("\n\t\t\t--------Total Bill : PKR %.2f",c.totalbill);
			printf("\n\t\t_________________________________________");
			n++;
			total=fopen("total.txt","w");
			fprintf(total,"%d",n);
			fclose(total);
			printf("\n\n\n\tPress ESC to go back to Main Menu...Press ENTER to book Another Room");
			char ch=getch();
			if(ch==27)
			{
				break;
			}
		}
	}
	fclose(fptr);
}


//Case 3
void View()
{
	FILE *fptr;
	fptr=fopen("CustomerDetails.txt","r");
	if(fptr==NULL)
	{
		exit(0);
	}
	
	system("cls");
	printf("NAME\t\t");
	printf("\tCNIC");
	printf("\t\t\tPHONE NUMBER");
	printf("\t\tEMAIL");
	printf("\t\t\t\tCHECK IN DATE ");
	printf("\t\tDAYS");
	printf("\tROOM");
	printf("\tFACILITIES");
	printf("\tTOTAL BILL\n");
	printf("_____________________________________________________________________________________________________________________________________________________________________________________");

	while(fread(&c,sizeof(c),1,fptr)==1)
	{
		printf("\n%-20s\t%-17s\t%-13s\t\t%-30s\t%-12s\t\t %d  \t%-3s\t%-11s\t%.2f",c.name, c.CNIC , c.phone ,c.email ,c.d.checkin,c.d.no_of_days,c.room,c.facilities,c.totalbill);
	}
	fclose(fptr);
	getch();
}


//Case 4
void Edit()
{
	system("cls");
	FILE *fptr,*temp;
	int found=0;
	char room[4];
	if((fptr=fopen("CustomerDetails.txt","r"))==NULL)
	exit(0);
	if((temp=fopen("tempedit.txt","w"))==NULL)
	exit(0);
	system("cls");
	while(1)
	{
		system("cls");
		printf("\t\t_________________________________________________\n");
		printf("\n  \t\t\tEnter Room Number Of Customer: ");
		fflush(stdin);
		scanf("%s",room);
		printf("\t\t_________________________________________________\n");
		while(fread(&c,sizeof(c),1,fptr)==1)
		{
			if(strcmp(c.room,room)==0)
			{      
				found=1;
				if(found==1)
				{
					a();
				}
				printf("\n  \t\t\tName : ");
				fflush(stdin);
				scanf("%s",&c.name);
				printf("  \t\t\tCNIC : ");
				scanf("%s",c.CNIC);
				printf("  \t\t\tPhone : ");
				scanf("%s",&c.phone);
				printf("  \t\t\tEmail : ");
				scanf("%s",c.email);
				printf("  \t\t\tCheck in date(dd\\mm\\yyyy) : ");
				scanf("%s",&c.d.checkin);
				printf("  \t\t\tDuration(days) : ");
				scanf("%d",&c.d.no_of_days);
				c.totalbill=(c.d.no_of_days*500)+priceRoom(c.room)+priceFacilities();
				fwrite(&c,sizeof(c),1,temp);
				printf("\n\t\t\t--------Total Bill : PKR %.2f",c.totalbill);
				continue;
			}
			else
			{
				fwrite(&c,sizeof(c),1,temp);
			}
		}
		if(found==0)
		{
			Beep(750,400);
			printf("\n\n\t  The Room Either Does Not Exist Or Has Not Been Booked Yet!!");
			printf("\n\n\t\t_________________________________________________\n");
			fclose(fptr);
			fclose(temp);
			printf("\n\n\t\t\tRedirecting to Main Menu....");
			Sleep(3000);
			break;
		}
		else if (found==1)
		{
			fclose(fptr);
			fclose(temp);
			remove("CustomerDetails.txt");
			rename("tempedit.txt","CustomerDetails.txt");
			printf("\n\n\t\t\t\t...");
			Sleep(2000);
			printf("Record Edited");
			printf("\n\n\t\t_________________________________________________\n");
			fclose(fptr);
			fclose(temp);
			printf("\n\n\t\t\tRedirecting to Main Menu....");
			Sleep(3000);
			break;
		}
	}
}


//Case 5
void Delete()
{
	system("cls");
	FILE *fptr,*temp;
	int found=0;
	char room[4];
	if((fptr=fopen("CustomerDetails.txt","r"))==NULL)
	exit(0);
	if((temp=fopen("temp.txt","w"))==NULL)
	exit(0);
	system("cls");
	while(1)
	{
		system("cls");
		printf("\t\t_________________________________________________\n");
		printf("\n  \t\t\tEnter Room Number Of Customer: ");
		fflush(stdin);
		scanf("%s",room);
		printf("\t\t_________________________________________________\n");
		while(fread(&c,sizeof(c),1,fptr)==1)
		{
			if(strcmp(c.room,room)==0)
			{       
				found=1;
				n--;
				total=fopen("total.txt","w");
				fprintf(total,"%d",n);
				fclose(total);
				if(strchr(c.room,'S')!=NULL)
				{
					S--;
					standard=fopen("standard.txt","w");
					fprintf(standard,"%d",S);
					fclose(standard);
				}
				else if(strchr(c.room,'P')!=NULL)
				{
					P--;
					premium=fopen("premium.txt","w");
					fprintf(premium,"%d",P);
					fclose(premium);
				}
				else if(strchr(c.room,'D')!=NULL)
				{
					D--;
					deluxe=fopen("deluxe.txt","w");
					fprintf(deluxe,"%d",D);
					fclose(deluxe);
				}
				continue;
			}
			else
			{
				fwrite(&c,sizeof(c),1,temp);
			}
		}
		if(found==0)
		{
			Beep(750,400);
			printf("\n\n\t  The Room Either Does Not Exist Or Has Not Been Booked Yet!!");
			printf("\n\n\t\t_________________________________________________\n");
			fclose(fptr);
			fclose(temp);
			printf("\n\n\t\t\tRedirecting to Main Menu....");
			Sleep(3000);
			break;	
		}
		else if(found==1)
		{
			fclose(fptr);
			fclose(temp);
			remove("CustomerDetails.txt");
			rename("temp.txt","CustomerDetails.txt");
			fclose(fptr);
			fclose(temp);
			printf("\n\n\t\t\t\t...");
			Sleep(2000);
			printf("Record Deleted");
			printf("\n\n\t\t_________________________________________________\n");
			printf("\n\n\t\t\tRedirecting to Main Menu....");
			Sleep(3000);
			break;
		}	
	}
}

//-------------------------------------------------------------------------------------------------------------------------------------------------



//SUB FUNCTIONS-------------------------------------------------------------------------------------------------------------------------------------------------


//void BookRoom() and void Edit()
float priceFacilities()
{
	int option,x;
	float price=0;
	char choice1, choice2,choice3;
	printf("\n\n\t\t\tHotel Facilities Available");
	printf("\n\t\t\tS - Swimming Pool\n\t\t\tI - Internet Access\n\t\t\tH - Hotel Transport");
	printf("\n\t\t\tHow many would you like to Avail?(0/1/2/3) : ");
	do
	{
		fflush(stdin);
 		scanf("%d",&option);
		if(option==0||option==1||option==2||option==3)
		{	
 			break;
		}
		else
		{
			Beep(750,400);
			printf("\n\t\t\tInvalid Input, Kindly Select from the Available Options : ");
			x=0;
		}
	}while(x==0);
	switch(option)
	{
		case 0:
			price=0;
			strcpy(c.facilities,"----------");
		break;
		
		case 1:
			printf("\n\t\t\tKindly Select the Facility you would like to Avail : ");
			
			do
			{
				fflush(stdin);
				scanf("\n%c",&choice1);
				if(choice1=='S'||choice1=='I'||choice1=='H')
				{
					break;
				}
				else
				{
					Beep(750,400);
					printf("\t\t\tInvalid Choice, Kindly Re-enter the Correct Choice : ");
					x=0;
				}
          	}while(x==0);
			switch(choice1)
			{
			    case 'S':
			        price=price+1500;
			        strcpy(c.facilities,"S");
			        break;
		        case 'I':
			        price=price+3000;
			        strcpy(c.facilities,"I");
		            break;
		        case 'H':
			        price=price+5000;
			        strcpy(c.facilities,"H");
			        break;
			}
			
		break;
		 
		case 2:
			printf("\n\t\t\tKindly Select the First Facility you would like to Avail : ");
			
			do
			{
				fflush(stdin);
				scanf("\n%c",&choice1);
				if(choice1=='S'||choice1=='I'||choice1=='H')
				{
					break;
				}
				else
				{
					Beep(750,400);
					printf("\n\t\t\tInvalid Choice, Kindly Re-enter the Correct Choice : ");
					x=0;
				}
			}while(x==0);
			switch(choice1)
			{
			    case 'S':
			        price=price+1500;
			        break;
		        case 'I':
			        price=price+3000;
		            break;
		        case 'H':
			        price=price+5000;
			        break;
			}
			printf("\n\t\t\tKindly Select the Second Facility you would like to Avail : ");
			
			do
			{
				fflush(stdin);
				scanf("\n%c",&choice2);
				if(choice1!=choice2&&(choice2=='S'||choice2=='I'||choice2=='H'))
				{
					break;
				}
				else
				{
					Beep(750,400);
					printf("\n\t\t\tInvalid Choice, Kindly Re-enter the Correct Choice : ");
					x=0;
				}
			}while(x==0);
			switch(choice2)
			{
			    case 'S':
			        price=price+1500;
			        break;
		        case 'I':
			        price=price+3000;
		            break;
		        case 'H':
			        price=price+5000;
			        break;
			}
		
		if(choice1=='S'&&choice2=='I' || choice1=='I'&&choice2=='S')
		strcpy(c.facilities,"S + I");
		if(choice1=='S'&&choice2=='H' || choice1=='H'&&choice2=='S')
		strcpy(c.facilities,"S + H");
		if(choice1=='I'&&choice2=='H' || choice1=='H'&&choice2=='I')
		strcpy(c.facilities,"I + H");
		break;
		
		case 3:
			price=1500+3000+5000;
			strcpy(c.facilities,"S + I + H");
			break;
	}
	
	return price;	
} 

//void BookRoom() and void Edit() 
float priceRoom(char roomNumber[])
{
	float price;
	
	if(strchr(roomNumber,'S')!=NULL)
	{
		price=10000;//for Standard Room
		S++;
		standard=fopen("standard.txt","w");
		fprintf(standard,"%d",S);
		fclose(standard);
	}
	if(strchr(roomNumber,'P')!=NULL)
	{
		price=20000;//for Premium Room
		P++;
		premium=fopen("premium.txt","w");
		fprintf(premium,"%d",P);
		fclose(premium);
	}
	if(strchr(roomNumber,'D')!=NULL)
	{
		price=35000;//for Deluxe Twin Room
		D++;
		deluxe=fopen("deluxe.txt","w");
		fprintf(deluxe,"%d",D);
		fclose(deluxe);	
	}
	return price;	
}

//void Edit()
void a()//assists in updating availability
{
	if(strchr(c.room,'S')!=NULL)
	{
		S--;
		standard=fopen("standard.txt","w");
		fprintf(standard,"%d",S);
		fclose(standard);
	}
	if(strchr(c.room,'P')!=NULL)
	{
		P--;
		premium=fopen("premium.txt","w");
		fprintf(premium,"%d",P);
		fclose(premium);
	}
	if(strchr(c.room,'D')!=NULL)
	{
		D--;
		deluxe=fopen("deluxe.txt","w");
		fprintf(deluxe,"%d",D);
		fclose(deluxe);	
	}	
}


//void BookRoom()
void roomType()//assists in updating availability
{ 
	int a;
	do
	{
		a=1;
		fflush(stdin);
		gets(c.room);
		if(strchr(c.room,'S')==NULL && strchr(c.room,'P')==NULL && strchr(c.room,'D')==NULL)
		{
			Beep(750,400);
			a=0;
			printf("  \t\t\tKindly Choose from the given Options : ");
		}
		else if(strchr(c.room,'S')!=NULL && S>=smax)
		{
			printf("\n\t\tAll Standard Rooms Are Occupied.Choose Another Type: ");
			a=0;
		}
		else if(strchr(c.room,'P')!=NULL && P>=pmax)
		{
			printf("\n\t\tAll Premium Rooms Are Occupied.Choose Another Type: ");
			a=0;
		}
		else if(strchr(c.room,'D')!=NULL && D>=dmax)
		{
			printf("\n\t\tAll Deluxe Rooms Are Occupied.Choose Another Type: ");
			a=0;
		}
	}
	while(a!=1);
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------
