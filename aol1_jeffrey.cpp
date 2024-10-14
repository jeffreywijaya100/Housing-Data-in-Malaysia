#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct data{
	char loc1[255];
	char loc2[255];
	char type[255];
	char furnish[255];
	int price, rooms, bathrooms, carparks, area;
}arr[5000];

int size = 0; 

void read(){
	FILE *fread = fopen("file.csv", "r");

    char scan[255];
    fscanf(fread, "%[^\n]\n", &scan);
    
    while(!feof(fread)){
        fscanf(fread, "%[^,],%[^,],%d,%d,%d,%d,%[^,],%d,%[^\n]\n"
					 , &arr[size].loc1
					 , &arr[size].loc2
					 , &arr[size].price
					 , &arr[size].rooms
					 , &arr[size].bathrooms
					 , &arr[size].carparks
					 , &arr[size].type
					 , &arr[size].area
					 , &arr[size].furnish);
        size++;
    }
}

int main(){
	
	read();
	char kalimat[100];
	
	while(1){
		
		printf("\nColumn List\n\n");
		printf("1.Location 1 (loc1)\n");
		printf("2.Location 2 (loc2)\n");
		printf("3.Price (price)\n");
		printf("4.Rooms (rooms)\n");
		printf("5.Bathrooms (bathrooms)\n");
		printf("6.CarParks (carparks)\n");
		printf("7.Type (type)\n");
		printf("8.Area (area)\n");
		printf("9.Furnish (furnish)\n");
		printf("10.Close (close)\n");
		printf("\nType column name:  ");
		
		scanf("%[^\n]", &kalimat);
		getchar();
		
		for (int i = 0; i<strlen(kalimat); i++){
			if (kalimat[i] <= 'Z' && kalimat[i] >= 'A'){
				kalimat[i] += 32;
			}
		}
		
		if(strcmp(kalimat, "loc1") == 0 || strcmp(kalimat, "loc2") == 0 || strcmp(kalimat, "type") == 0|| strcmp(kalimat, "furnish") == 0){	
			struct aw{
				char array[255];
				int temp;
			}aww[5000];
			
			int a = 0;
		
			for(int i = 0; i < size; i++){
				int b = 0;
				for(int j = 0; j < a; j++){
					if(strcmp(kalimat, "loc1") == 0){
						if(strcmp(aww[j].array, arr[i].loc1) == 0){
							aww[j].temp++; 
							b = 1;
							break;
						}
					}
					else if(strcmp(kalimat, "loc2") == 0 ){
						if(strcmp(aww[j].array, arr[i].loc2) == 0){
							aww[j].temp++; 
							b = 1;
							break;
						}
					}
					else if(strcmp(kalimat, "type") == 0 ){
						if(strcmp(aww[j].array, arr[i].type) == 0){
							aww[j].temp++; 
							b = 1;
							break;
						}
					}
					else if(strcmp(kalimat, "furnish") == 0){
						if(strcmp(aww[j].array, arr[i].furnish) == 0){
							aww[j].temp++; 
							b = 1;
							break;
						}
					}
				}
				if(b == 0){
					if(strcmp(kalimat, "loc1") == 0){
						strcpy(aww[a].array, arr[i].loc1);
					} if(strcmp(kalimat, "loc2") == 0){
						strcpy(aww[a].array, arr[i].loc2);
					} if(strcmp(kalimat, "type") == 0){
						strcpy(aww[a].array, arr[i].type);
					} if(strcmp(kalimat, "furnish") == 0){
						strcpy(aww[a].array, arr[i].furnish);
					}
						aww[a].temp = 1;
						a++;
				}
			}
			
			int max = -1, max1 = -1;
			int min = 9999, min1 = -1;
		
			for(int i = 0; i < a; i++){
				printf("%s : %d\n", aww[i].array, aww[i].temp);
				if(aww[i].temp >= max){
					max = aww[i].temp; 
					max1 = i;
				}
				if(aww[i].temp <= min){
					min = aww[i].temp; 
					min1 = i;
				}
			}
			printf("Maximum value: %s with frequency: %d\n", aww[max1].array, aww[max1].temp);
			printf("Minimum value: %s with frequency: %d\n", aww[min1].array, aww[min1].temp);			
		}
		else if(strcmp(kalimat, "rooms") == 0 || strcmp(kalimat, "bathrooms") == 0 || strcmp(kalimat, "carparks") == 0){
			struct aw{
				int size;
				int temp;
			}aww[5000];

			int a = 0;
			
			for(int i = 0; i < size; i++){
				int b = 0;
				for(int j = 0; j < a; j++){
					if(strcmp(kalimat, "rooms") == 0 ){
						if(arr[i].rooms == aww[j].size){
							aww[j].temp++;
							b = 1;
							break;
						}
					}
					else if(strcmp(kalimat, "bathrooms") == 0){
						if(aww[j].size == arr[i].bathrooms){
							aww[j].temp++; 
							b = 1;
							break;
						}
					}
					else if(strcmp(kalimat, "carparks") == 0){
						if(aww[j].size == arr[i].carparks){
							aww[j].temp++; 
							b = 1;
							break;
						}
					}
				}
				if(b == 0){
					if(strcmp(kalimat, "rooms") == 0){
						aww[a].size = arr[i].rooms;
					} if(strcmp(kalimat, "bathrooms") == 0){
						aww[a].size = arr[i].bathrooms;
					} if(strcmp(kalimat, "carparks") == 0){
						aww[a].size = arr[i].carparks; 
					}
						aww[a].temp = 1; 
						a++;
				}
			}
			int max = -1, max1 = -1;
			int min = 9999, min1 = -1;
			
			for(int i = 0; i<a; i++){
				printf("%d : %d\n", aww[i].size, aww[i].temp);
				if(aww[i].temp >= max){
					max = aww[i].temp; max1 = i;
				}
				if(aww[i].temp <= min){
					min = aww[i].temp; min1 = i;
				}
			}
			printf("Maximum value: %d with frequency: %d\n", aww[max1].size, aww[max1].temp);
			printf("Minimum value: %d with frequency: %d\n", aww[min1].size, aww[min1].temp);
		}
		else if(strcmp(kalimat, "price") == 0 || strcmp(kalimat, "area") == 0){
			int max = -1;
			long long int min = 99999999;
			long long int  tot = 0;
			
			if(strcmp(kalimat, "price") == 0){
				for(int i =0 ; i < size; i++){
					if(arr[i].price < min){
						min = arr[i].price;
					}
					if(arr[i].price > max){
						max = arr[i].price;
					}
					tot = tot + arr[i].price;
				}
			}
			else if(strcmp(kalimat, "area") == 0){
				for(int i = 0 ; i < size; i++){
					if(arr[i].area < min){
						min = arr[i].area;
					}
					if(arr[i].area > max){
						max = arr[i].area;
					}
					tot = tot + arr[i].area;
				}
			}
			printf("Maximum value : %d\n", max);
			printf("Minimum value : %d\n", min);
			printf("Average value : %.2lf\n", (double)tot/(double)size);
		}
		else if(strcmp(kalimat, "close") == 0){
			break;
		}
		else{
			printf("Try again\n");
		}
	}
	return 0;			
}
