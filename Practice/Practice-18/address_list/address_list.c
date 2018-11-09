#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct AddressList{
	char name[32];
	char sex[8];
	int age;
	char tele[15];
	char address[128];
}AddressList, *pAddressList;

typedef struct ConnectList{
	AddressList Addr[1000];
	int _size;
}ConnectList, *pConnectList;

void meum(){
	printf("******************************************\n");
	printf("***            Contacts List           ***\n");
	printf("******************************************\n");
	printf("1. Add Contacts Infomation\n");
	printf("2. Delete Appointed Contacts Infomation\n");
	printf("3. Search Appointed Contacts Infomation\n");
	printf("4. Modify Appointed Contacts Infomation\n");
	printf("5. Display All Contacts\n");
	printf("6. Delete All Contacts\n");
	printf("7. Sort By Name\n");
	printf("8. Export Contacts To File\n");
	printf("9. Load Contacts To File\n");
	printf("0. Exit\n");
}

void InitConnectList(pConnectList Contacts){	
	Contacts->_size = 0;
}


void ShowContacts(pConnectList Contacts ,int  num){
	printf("%s  %s  %d  %s  %s\n",(Contacts->Addr[num]).name,(Contacts->Addr[num]).sex,
									(Contacts->Addr[num]).age, (Contacts->Addr[num].tele),
									(Contacts->Addr[num].address));	
}

void Delete(pConnectList Contacts , int num){
	int count = num;
	for( ; num < Contacts->_size - 1; num++){
		memcpy(&Contacts->Addr[num], &Contacts->Addr[num + 1],sizeof(AddressList));
	}
	Contacts->_size --;	
}

void AddContact(pConnectList Contacts){
	printf("\n<<Add Contacts>>\n");
	printf("Please Enter Contacts Name:");
	scanf("%s", ((Contacts->Addr[Contacts->_size]).name));
	printf("Please Enter Contacts Sex:");
	scanf("%s", ((Contacts->Addr[Contacts->_size]).sex));
	printf("Please Enter Contacts Age:");
	scanf("%d", &((Contacts->Addr[Contacts->_size]).age));
	printf("Please Enter Contacts Tel:");
	scanf("%s", ((Contacts->Addr[Contacts->_size]).tele));
	printf("Please Enter Contacts Addr:");
	scanf("%s", ((Contacts->Addr[Contacts->_size]).address)); 
	
	Contacts->_size++;
}


int SearchContact(pConnectList Contacts){
	printf("\n<<Search>>\n");
	char Name[32];
	int count = 0;
	if(Contacts->_size){
		printf("Empty List! Can't Search!\n");
		return 0;	
	}
	printf("Please Enter Contact Name:");
	scanf("%s", Name);
	for(; count < Contacts->_size ; count++){
		if(strcmp(Contacts->Addr[count].name , Name) == 0){
			printf("Name    Sex   Age    Tel          Addr\n");
			ShowContacts(Contacts, count);
			return count + 1;
		}
	}
	printf("Not Find\n");
	return count + 1;
}

int DeleteContact(pConnectList Contacts){
	printf("\n<<Delete>>\n");
	if(Contacts->_size){
		printf("Empty List!");
		return -1;
	}
	char choice ; 
	int num = 0;
	if(num = SearchContact(Contacts)){
		printf("Are You Sure to Delete ? <Y/N>:");
		scanf("%c" , &choice);
		if(choice == 'Y' || choice == 'y'){
			Delete(Contacts , num - 1);
		}
	}
	return 1;
}

void ModifyContact(pConnectList Contacts){
	printf("\n<<Modify>>\n");
	int num;
	if(num = SearchContact(Contacts)){
		num = num - 1;
		printf("Please Enter Contacts Name:");
		scanf("%s", ((Contacts->Addr[num]).name));
		printf("Please Enter Contacts Sex:");
		scanf("%s", ((Contacts->Addr[Contacts->_size]).sex));
		printf("Please Enter Contacts Age:");
		scanf("%d", &((Contacts->Addr[Contacts->_size]).age));
		printf("Please Enter Contacts Tel:");
		scanf("%s", ((Contacts->Addr[Contacts->_size]).tele));
		printf("Please Enter Contacts Addr:");
		scanf("%s", ((Contacts->Addr[Contacts->_size]).address)); 	
	}
}

void DisplayAllContact(pConnectList Contacts){
	printf("\n<<Display All>>\n");
	int count = 0;
	printf("Name  Sex  Age  Tel      Addr\n");
	for(;count < Contacts->_size ; count++){
		ShowContacts(Contacts , count);
	}
	printf("Please Enter AnyKey To Go Back Neum\n");
	getchar();
}

void EmptyContact(pConnectList Contacts){
	printf("<<Empty>>\n");
	char choice;
	printf("Are You Sure clean ? <Y/N>");
	scanf("%c" , &choice);
	if(choice == 'Y' || choice == 'y'){
		Contacts->_size = 0;
	}
}

void SortByName(pConnectList Contacts){
	printf("\n<<Sort By Name>>\n");
	
	int count = 0;
	int count_2 = 0;
	for(count = 0 ; count < Contacts->_size - 1; count++){
		for(count_2 = 0 ; count_2 < Contacts->_size - count - 2; count_2++){
			if(strcmp(Contacts->Addr[count].name, Contacts->Addr[count + 1].name) > 0){
				AddressList Temp;
				memcpy(&Temp, &Contacts->Addr[count_2], sizeof(AddressList));
				memcpy(&Contacts->Addr[count_2],&Contacts->Addr[count_2 + 1], sizeof(AddressList));
				memcpy(&Contacts->Addr[count_2 + 1] , &Temp , sizeof(AddressList));
			}
		}
	}
	printf("Sort Complete!\n");
	DisplayAllContact(Contacts);
}

int ExportToFile(pConnectList Contacts){
	printf("<<\nExport File>>\n");
	int count = 0;
	FILE* fp = fopen("myvcf.vcf","wb+");
	if(fp == NULL){
		perror("fopen");
		return -1;
	}

	fprintf(fp, "%d\n" , Contacts->_size);	

	for( ; count < Contacts->_size ; count++){
		fprintf(fp,"%s %s %d %s %s\n",(Contacts->Addr[count]).name,
			(Contacts->Addr[count]).sex,(Contacts->Addr[count]).age, 
			(Contacts->Addr[count].tele),(Contacts->Addr[count].address));	
	}
	fclose(fp);
	return 1;
}

int LoadToFile(pConnectList Contacts){
	printf("\n<<Load File>>\n");
	int count = 0;
	
	FILE* fp = fopen("myvcf.vcf" , "r");
	if(fp == NULL){
		perror("fopen");
		return -1;
	}
	
	fscanf(fp , "%d\n" , &Contacts->_size);
	
	for(; count < Contacts->_size ; count++){
		fscanf(fp,"%s %s %d %s %s",(Contacts->Addr[count]).name,
			(Contacts->Addr[count]).sex,&(Contacts->Addr[count]).age, 
			(Contacts->Addr[count].tele),(Contacts->Addr[count].address));	
	}
	fclose(fp);
	return 1;
}


int main(){
	ConnectList Contacts;
	
	InitConnectList(&Contacts);

	system("clear");	
	while(1){
		int choice = -1;
		meum();
		printf("Please Enter Choice<0~9>:");
		scanf("%d", &choice);
		getchar();
		switch(choice){
			case 1 : AddContact(&Contacts);
					break;
			case 2 : DeleteContact(&Contacts);
					break;
			case 3 : SearchContact(&Contacts);
					break;
			case 4 : ModifyContact(&Contacts);
					break;
			case 5 : DisplayAllContact(&Contacts);
					break;
			case 6 : EmptyContact(&Contacts);
					break;
			case 7 : SortByName(&Contacts);
					break;
			case 8 : ExportToFile(&Contacts);
					break;
			case 9 : LoadToFile(&Contacts);
					break;
			case 0 : exit(0);
					break;
			default : printf("\nYour Choice Wrong , please retry\n\n");
					break;
		}
	}
}

