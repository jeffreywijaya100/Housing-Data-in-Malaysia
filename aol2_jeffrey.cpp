#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct var{
	char loc1[255];
	char loc2[255];
	char price[255];
	char rooms[255];
	char bathrooms[255];
	char carparks[255];
	char type[255];
	char area[255];
	char furnish[255];
}arr[5000];

int size = 0;
int a = 0;

void function(var i){
	printf("%-25s| %-20s| %-8s| %-3s| %-3s| %-3s| %-10s| %-5s| %-10s\n"
			, i.loc1
			, i.loc2
			, i.price
			, i.rooms
			, i.bathrooms
			, i.carparks
			, i.type
			, i.area
			, i.furnish);
}

void read(){	
	FILE *fread = fopen("file.csv", "r");
	
	char scan[255];
	fscanf(fread, "%[^\n]\n", scan);
	
	while(!feof(fread)){
		fscanf(fread, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n"
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
	
	char angka[255];
	char a[255][255];
	int b = 0;
	
	printf("Display what do you want to search and the location(lower and uper case are different)!\n");
	printf("Input: ");
	scanf("%[^\n]", angka); 
	getchar();
	
	char *tok = strtok(angka, " ");
	
	while(tok != NULL){
		strcpy(a[b], tok);
		tok = strtok(NULL, " ");
		b++;
	}
	char temp[255];
	char count[255];
	
	strcpy(temp, a[0]);
	strcpy(count, a[2]);
	
	int wrong = 1;

	for(int i = 0; i < size; i++){
		if(strcmp(count, "loc1") == 0 || strcmp(count, "Loc1") == 0 || strcmp(count,"Location 1") == 0){
			if(strcmp(temp, arr[i].loc1) == 0){
				function(arr[i]);
			}
		}
		else if(strcmp(count,"loc2") == 0 || strcmp(count,"Loc2") == 0 || strcmp(count,"Location 2") == 0){
			if(strcmp(temp, arr[i].loc2) == 0){
				function(arr[i]);
			}
	    }
	    else if(strcmp(count,"price") == 0 || strcmp(count,"Price") == 0){
			if(strcmp(temp, arr[i].price) == 0){
				function(arr[i]);
			}
	    }
		else if(strcmp(count, "rooms") == 0 || strcmp(count, "Rooms") == 0){
	        if(strcmp(temp, arr[i].rooms) == 0){
				function(arr[i]);
			}
	    }
		else if(strcmp(count, "bathrooms") == 0 || strcmp(count, "Bathrooms") == 0){
	        if(strcmp(temp, arr[i].bathrooms) == 0){
				function(arr[i]);
			}
	    }
		else if(strcmp(count, "carparks") == 0 || strcmp(count, "CarParks") == 0 || strcmp(count, "Carparks") == 0){
	        if(strcmp(temp, arr[i].carparks) == 0){
				function(arr[i]);
			}
	    }
		else if(strcmp(count, "type") == 0 || strcmp(count, "Type") == 0){
	        if(strcmp(temp, arr[i].type) == 0){
				function(arr[i]);
			}
	    }
		else if(strcmp(count, "area") == 0 || strcmp(count, "Area") == 0){
	        if(strcmp(temp, arr[i].area) == 0){
				function(arr[i]);
			}
	    }
		else if(strcmp(count, "furnish") == 0 || strcmp(count, "Furnish") == 0){
	        if(strcmp(temp, arr[i].furnish) == 0){
				function(arr[i]);
			}
	    }
	}
	if(wrong == 0)
		printf("Data doesnt exist, try another substring\n");
	return 0;
}
