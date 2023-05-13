	#include <stdio.h>
	#include <stdlib.h>
	#include <windows.h>
	#include <string.h>
		struct hasta {
	    	char hastaadi[50];
	    	char hastasoyadi[50];
	   		char hastaTC[11];
	    	char cinsiyet;
	    	int yas;
	};
	
		struct hasta h1;
		void cocukhasta_kayit()
		{
			system("cls");
			FILE  *dosya;
			dosya = fopen("cocuk.txt","a");
			if(dosya == NULL){
	        printf("File is missing or non-existent");
			}
	        else{
			fflush(stdin); // Boþaltma
			
			printf("Please Enter Patient’s Name: ");
			scanf("%[^\n]s",&h1.hastaadi);
			printf("Please Enter Patient’s Surname: ");
			scanf("%s",&h1.hastasoyadi);
			printf("Please Enter Patient’s Identity Number: ");
			scanf("%s",&h1.hastaTC);
			printf("Please Enter Patient’s Gender: ");
			scanf("%s",&h1.cinsiyet);
			printf("Please Enter Patient’s Age: ");
			scanf("%d",&h1.yas);
			
			fwrite(&h1, sizeof(h1), 1, dosya);
			printf("--->Patient Added Successfully<---");
			printf("\n");
			getchar();
			system("pause");
			}
			fclose(dosya);
	    	return;
	            
		}
		
		void hasta_Kayit()
		{	
			system("cls");
			FILE  *dosya;
			dosya = fopen("Hastalar.txt","a");
			if(dosya == NULL){
	        printf("File is missing or non-existent");
			}
	        else{
			fflush(stdin); // Boþaltma
			
			printf("Please Enter Patient’s Name: ");
			scanf("%s",&h1.hastaadi);
			printf("Please Enter Patient’s Surname: ");
			scanf("%s",&h1.hastasoyadi);
			printf("Please Enter Patient’s Identity Number: ");
			scanf("%s",&h1.hastaTC);
			printf("Please Enter Patient’s Gender: ");
			scanf("%s",&h1.cinsiyet);
			printf("Please Enter Patient’s Age: ");
			scanf("%d",&h1.yas);
			
			fwrite(&h1, sizeof(h1), 1, dosya);
			printf("--->Patient Added Successfully<---");
			printf("\n");
			getchar();
			system("pause");
			}
			fclose(dosya);
	    	return;
	            
	}
	
		void hasta_Goruntuleme() {
		system("cls");
    	char id[11];
    	int patates = 0;
   		struct hasta h1;
    	FILE *dosya;

    	while(1) {
        system("cls");
        printf("Please Enter an Identity Number to Search: ");
        scanf(" %[^\n]%*c", id);
        dosya = fopen("Hastalar.txt", "rb");

        if (dosya == NULL) {
            printf("File could not be opened or does not exist!\n");
            return;
        }

        while(fread(&h1, sizeof(h1), 1, dosya) == 1) {
            if(strcmp(id, h1.hastaTC) == 0) {
                patates = 1;
                printf("Record Found\n");
                printf("Identity Number: %s\n", h1.hastaTC);
                printf("Name: %s\n", h1.hastaadi);
                printf("Surname: %s\n", h1.hastasoyadi);
                printf("Age: %d\n",h1.yas);
                printf("Gender: %c\n",h1.cinsiyet);
                break;
            }
        }
        if(patates == 0) {
            printf("Record could not be found\n");
        }

        printf("Do you want to search again? (Y/N)");
        char c = getchar();
        if(c == 'N' || c == 'n') break;
        fclose(dosya);
    }
    fclose(dosya);
}

	void cocuk_hasta_goruntuleme(){
		system("cls");
			 FILE *dosya = fopen("cocuk.txt", "r");
	      	if (dosya == NULL) 
			{
	        	printf("File cannot be opened or empty!\n");
	        	
	      	}
			while (fread(&h1, sizeof(h1), 1, dosya) == 1)
	
			{
				printf("Name: %s\n",h1.hastaadi);
	        	printf("Surname: %s\n", h1.hastasoyadi);
	        	printf("Identity Number: %s\n",h1.hastaTC);
	        	printf("Age: %d\n", h1.yas);
	        	printf("Gender: %c\n", h1.cinsiyet);
	        	printf("\n\n");
			
	        }getchar();	
	        fclose(dosya);
	        printf("\nEnter any key to continue...");
			getchar();
	
			}
	
		
		
		
		void tum_hasta_goruntuleme(){
			system("cls");
			 FILE *dosya = fopen("Hastalar.txt", "r");
	      	if (dosya == NULL) 
			{
	        	printf("File cannot be opened or empty!\n");
	        	
	      	}
			while (fread(&h1, sizeof(h1), 1, dosya) == 1)
	
			{
				printf("Name: %s\n",h1.hastaadi);
	        	printf("Surname: %s\n", h1.hastasoyadi);
	        	printf("Identity Number: %s\n",h1.hastaTC);
	        	printf("Age: %d\n", h1.yas);
	        	printf("Gender: %c\n", h1.cinsiyet);
	        	printf("\n\n");
			
	        }getchar();	
	        fclose(dosya);
	        printf("\nEnter any key to continue...");
			getchar();
	
			}
	
		void cocuk_hasta_silme(){
				system("cls");
			
			printf("Patient Record Deletion");
			char id[15];
			int isFound=0;
			
			fflush(stdin);
			printf("Enter Patient’s Identity Number to Delete: "); 
			scanf("%c",&id);
			
			FILE *dosya, *temp;
			dosya = fopen("cocuk.txt","rb");
			temp = fopen("cocuk2.txt", "wb");
			while(fread(&h1, sizeof(h1),1,dosya) == 1){
	        if(strcmp(id, h1.hastaadi) == 0){
	        fwrite(&h1,sizeof(h1),1,temp);
	        }
	    }
	    	fclose(dosya);
	    	fclose(temp);
	    	remove("cocuk.txt");
	    	rename("cocuk2.txt","cocuk.txt");
	    	getchar();
	    	system("pause");
		}
		
		void hasta_kayit_silme(){
			system("cls");
			
			printf("Patient Record Deletion");
			char id[15];
			int isFound=0;
			
			fflush(stdin);
			printf("Enter Patient’s Identity Number to Delete: "); 
			scanf("%c",&id);
			
			FILE *dosya, *temp;
			dosya = fopen("Hastalar.txt","rb");
			temp = fopen("temp.txt", "wb");
			while(fread(&h1, sizeof(h1),1,dosya) == 1){
	        if(strcmp(id, h1.hastaadi) == 0){
	        fwrite(&h1,sizeof(h1),1,temp);
	        }
	    }
	    	fclose(dosya);
	    	fclose(temp);
	    	remove("Hastalar.txt");
	    	rename("temp.txt","Hastalar.txt");
	    	getchar();
	    	system("pause");
		}
		
		int main() {
			
			
			
			while(1){
			int secim;
			int secim2;
			int secim3;
			int secim4;
				system("cls");
				printf("\t\t\t");
        printf("********************************************************\n");
        printf("\t\t\t");
        printf("*************** Welcome to Proceed System **************\n");
        printf("\t\t\t");
        printf("********************************************************\n");
        getchar();
				printf("1-Patient Record Creation\n");
				printf("2-Patient viewing\n");
				printf("3-Patient Record Deletion\n");
				printf("4-Exit\n");
				printf("Please Select to Proceed: ");
				scanf("%d",&secim);
			
		
			
				
				switch(secim){
					case 1:
							system("cls");
						printf("1-Pediatric Patient Registration\n");
						printf("2-Adult Patient Registration\n");
						printf("Type of Patient");
						scanf("%d",&secim3);
						if(secim3==1){
						cocukhasta_kayit();	
						}
						else if(secim3==2){
						hasta_Kayit();
						}
					
					break;
					case 2:
							system("cls");
						printf("1-List All Patient\n");
						printf("2-Search for a Patient\n");
						printf("3-Pediatric Patient Registration\n");
						printf("Make your choice");
						scanf("%d",&secim2);
						if (secim2 == 3)
						{
							
						tum_hasta_goruntuleme();
						
						continue;	
										}
						else if (secim2 == 2)
						{
							hasta_Goruntuleme();
					
					 continue;
						}
						else if (secim2 == 1){
					
						
							cocuk_hasta_goruntuleme();
						}
					continue;	
					break;
					case 3:
							system("cls");
						printf("1-Adult Patient Record Deletion\n");
						printf("2-Pediatric Patient Record Deletion\n");
						scanf("%d",&secim4);
						if(secim4==1){
						
						hasta_kayit_silme();
						continue;
					}
					else if (secim4==2){
						cocuk_hasta_silme();
						continue;
					}
					break;
					case 4:
						exit(0);
					break;
					  default: 
					  printf("Invalid choice. Please try again.\n"); 
					  getchar();	
					  break;	
				}
			}
			

			return 0;
		}

