# Housing-Data-in-Malaysia
I am required to write a program that can read a file and perform several functions. The file needed can be downloaded from given csv: 

File description: 
This file is a csv file; therefore, each column is separated with comma. This file consists of 3939 rows of Housing Data in Malaysia with no missing value for each row.  This file also has a header. Therefore, when your program loads the data, your program should be able to skip this header before passing the data into your record variable. A glimpse of the data: 
![image](https://github.com/user-attachments/assets/45e5f8b9-ec13-47d3-85a5-12d8988eefda)


## 1) Describe
This function explains the information from each column. When running this function, give a prompt to get input from the user as the name of the column you want to describe. Then, display: 

a.	For column loc1, loc2, room, bathrooms, carparks, type, or furnish, display: 

i.	Frequency for each unique value

ii.	Maximum frequency 

iii.	Minimum frequency 

For example, if we call describe function followed with loc1 as column name, the program should display like this: 
![image](https://github.com/user-attachments/assets/0b9cc6ab-a685-4550-9367-8df6458b5e86)

b.	For area and price column, display only: 

i.	Minimum value 

ii.	Maximum value

iii.	Average value

Because area and price value are not discrete, therefore there isn’t a need to perform frequency check for each of it. 

## 2) Search Data
To be able to handle search function, ask user to give input with format: 

_DataX in ColumnName_

The program should be able to parse above input. It is prohibited to use 3 string input. Then, display all data that has that DataX. 

For example: 

_Partly in furnish_

Above command will result in: 
![image](https://github.com/user-attachments/assets/f685ed92-ab74-491d-8ff1-3bbf5b30a0ca)

However, your program also should be able to search using only sub-string, for example: 

_pong in loc1_

will result in:
![image](https://github.com/user-attachments/assets/be57fa99-4502-4375-bd63-fdf9bc292cf1)
 
Give information if data searched doesn’t exist in the record. 

I ONLY HAVE TO DO SEARCH IN THE COLUMN OTHER THAN AREA AND PRICE.
.

