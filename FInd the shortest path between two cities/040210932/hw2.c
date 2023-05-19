/*
 _    _  ____  __  __ ________          ______  _____  _  __ 
| |  | |/ __ \|  \/  |  ____\ \        / / __ \|  __ \| |/ / 
| |__| | |  | | \  / | |__   \ \  /\  / / |  | | |__) | ' /
|  __  | |  | | |\/| |  __|   \ \/  \/ /| |  | |  _  /|  <
| |  | | |__| | |  | | |____   \  /\  / | |__| | | \ \| . \
|_|  |_|\____/|_|  |_|______|   \/  \/   \____/|_|  \_\_|\_\
   
Name: Javad Ibrahimli
ID: 040210932
Facult: Electrical and Electronics Engineering
Date: 10.05.2023
Course code: EHB 208E Data Structures and Programming
Course given by: Prof. Bora Döken and Res. Asst. Muhammed Yasin Adıyaman
Assignment: 2
Topic: Path Finder ALgorithm in order to find the shortest path between two locations.
Github link for this assignment: https://github.com/cavadibrahimli1/ITU-homeworks./tree/main/FInd%20the%20shortest%20path%20between%20two%20cities


FOR MORE INFORMATION PLEASE VISIT THE GITHUB LINK ABOVE OR READ THE ASSIGNMENT2.Pdf file in the zip file I uploaded to the Ninova system.

*/

// Standart header files in C
#include <stdio.h>   // input and output functions library 
#include <stdlib.h>  // general purpose standard library 
#include <string.h>  // string handling and memory handling functions library 
#include <stdbool.h>  // in order to using boolean type and values

//  The data structure that holds the difference from city A to city B, and city names A and B.
struct maph {           // Generated a ds named 'maph'
  int difference;         // integer to hold the difference between two LocationName
  char start_point[1000];  // char array that stores the name of the start point 
  char end_point[1000] ;   // char array that stores the name of the end point
};  // I used 1000 as the size of arrays. For this assignment, it is enough. ( For university projects I usually use 1000 or 10000.)

//  The constant value named MAX_VAL is defined to indicate positive infinity.
const int MAX_VAL = 99999999; // 99999999 is the maximum value that an integer can hold. For this assignment I declared it as a constant that holds positive infinity. WIth this my code with work with any length of the matrix.(accepted rate)
typedef struct maph mapH; // Generated a typedef for the maph. ( It simplifies the code and make it more readable.)

//  Function Definitons
int* dijkstra_algo(const int* border_set, int start_index, int destination, int matrix_sizer) 
{ //I used One of the most famous algorithms in graph theory - Dijkstra's algorithm.
    int difference[matrix_sizer];
    int founder_part[matrix_sizer];
    int passed[matrix_sizer];

    // I initialized the difference, founder_part and passed arrays
    for (int i = 0; i < matrix_sizer; i++) 
    {
        difference[i] = MAX_VAL;  // I evaluated differences variable to MAX_VAL. (largest value that an integer can hold)
        founder_part[i] = -1; // I evaluated founder_part to -1.
        passed[i] = 0;   // I evaluated passed city count to 0.
    }
    // I evaluated the difference of the start index point to 0.
    difference[start_index] = 0;

    // loop until all vertices have been passed
    for (int number = 0; number < matrix_sizer - 1; number++) 
    {
        int minimum_value_ind;  // I declared the minimum value index.
        int minimum_value = MAX_VAL;  // I declared the minimum value to MAX_VAL.
        for (int k = 0; k < matrix_sizer; k++) // I looped through the matrix_size
        {
            if (!passed[k] && difference[k] <= minimum_value) // if k is not passed and difference[k] is less than or equal to minimum_value
            { 
                minimum_value = difference[k]; // I assigned the minimum value to difference[k]
                minimum_value_ind = k; // I assigned the minimum value index to k
            }
        }
        passed[minimum_value_ind] = 1;  // I assigned the passed[minimum_value_ind] to 1

        for (int k = 0; k < matrix_sizer; k++) // I looped through the matrix_sizer
        {
            // I checked if the passed[k] is not passed and border_set + minimum_value_ind * matrix_sizer + k is not equal to MAX_VAL and difference[minimum_value_ind] is not equal to MAX_VAL and difference[minimum_value_ind] + border_set + minimum_value_ind * matrix_sizer + k is less than difference[k]
            if (!passed[k] && *(border_set + minimum_value_ind * matrix_sizer + k) != MAX_VAL && difference[minimum_value_ind] != MAX_VAL && difference[minimum_value_ind] + *(border_set + minimum_value_ind * matrix_sizer + k) < difference[k]) 
            {
                difference[k] = difference[minimum_value_ind] + *(border_set + minimum_value_ind * matrix_sizer + k);   // I assigned the difference[k] to difference[minimum_value_ind] + border_set + minimum_value_ind * matrix_sizer + k
                founder_part[k] = minimum_value_ind;  // I assigned the founder_part[k] to minimum_value_ind
            }
        }
    }

    int* final_array = calloc(matrix_sizer + 2, sizeof(int));    // I allocated the memory for the final_array
    int switch_pointer = 1;    
    int roads[matrix_sizer];    
    int indexofroad = 0;        
    int livestate;  
    if(destination!=start_index)  // if destination is not equal to start_index
    {
        final_array[0] = difference[destination];  // I assigned the final_array[0] to difference[destination]
        livestate = destination;
    }
    else
    {
        int find_min = MAX_VAL;
        int find_min_index=0;
        for(int i=0;i<matrix_sizer;i++)
        {
            int colcol = *(border_set+i*matrix_sizer+destination);
            if(colcol!=MAX_VAL && difference[i]+colcol < find_min)
            {
                find_min = difference[i]+colcol;
                find_min_index=i;
            }
        }
        final_array[0] = find_min;
        livestate = find_min_index; 

    }    
    while (livestate != -1) 
    {        // I looped until livestate is not equal to -1
        roads[indexofroad++] = livestate;    // I assigned the roads[indexofroad++] to livestate
        livestate = founder_part[livestate];   // I assigned the livestate to founder_part[livestate]
    }
    
    for (int i = indexofroad - 1; i >= 0; i--) // I looped through the indexofroad - 1 
    {
        if (i == indexofroad - 1)  // if i is equal to indexofroad - 1 
        {
            final_array[switch_pointer] = roads[i];   // I assigned the final_array[switch_pointer] to roads[i]
        }
        else 
        {
            switch_pointer++;    // I incremented the switch_pointer
            final_array[switch_pointer] = roads[i];  // I assigned the final_array[switch_pointer] to roads[i]
        }
    }

    final_array[++switch_pointer] = 99;    // I assigned the final_array[++switch_pointer] to 99
    return final_array;   // I returned the final_array
}
int* proximityMatrixGenerator(mapH* proximityRecord, int matrix_sizer, int proximityCount, char LocationName[][10]) // proximityMatrixGenerator function
{
    int *matrix = calloc(matrix_sizer * matrix_sizer, sizeof(int)); // calloc is used to allocate the memory for the matrix

    for (int i = 0; i < matrix_sizer; i++) // I looped through the matrix_sizer
    {
        for (int j = 0; j < matrix_sizer; ++j) 
        {
            *(matrix + (i * matrix_sizer) + j) = MAX_VAL;  // I assigned the matrix + (i * matrix_sizer) + j to MAX_VAL
        }
    }

    for (int i = 0; i < proximityCount; i++) // I looped through the proximityCount
    {
        mapH maph = proximityRecord[i];  // I assigned the maph to proximityRecord[i]
        int from_index = -1;             // I assigned the from_index to -1
        int to_index = -1;              // I assigned the to_index to -1
        for (int j = 0; j < matrix_sizer; j++)  // I looped through the matrix_sizer
        {
            if (strcmp(LocationName[j], maph.start_point) == 0) // if LocationName[j] is equal to maph.start_point
            {
                from_index = j;  // I assigned the from_index to j
            }
            if (strcmp(LocationName[j], maph.end_point) == 0)  // if LocationName[j] is equal to maph.end_point
            {
                to_index = j;   // I assigned the to_index to j
            }
        }
        *(matrix + from_index * matrix_sizer + to_index) = maph.difference;  // I assigned the matrix + from_index * matrix_sizer + to_index to maph.difference
    }

    return matrix; 
}

int LocationRecordGenerator(char* name,char LocationName[][10], int matrix_sizer) 
{   // LocationRecordGenerator function is used to find the index of the city name
    int index; 
    int isExist = 0;
    for (int i = 0; i < matrix_sizer; i++)
    {
        if ((strcmp(name, LocationName[i]) == 0) && isExist == 0) //strcmp is used to compare the strings with each other
        {
            index = i;
            isExist = 1;
        }
    }
    if (!isExist)
    {
        printf("[ERROR MESSAGE ]: There is no such city name which named %s", name);  // if there is no such city name which named %s error message is printed
        exit(1); // exit(1) is used to exit the program
    }
    return index;
}

void WriteFileOperation(const int * final_array, int matrix_sizer, char LocationName[][10], char* outputFileName, int which, int initial_city_index, int dest_index_verify) // Function that writes the results of the algorithm to a file
{
    bool isSame=false;
    if(initial_city_index==dest_index_verify){
            isSame = true;
    }
    FILE *fptr;  // Declaring File pointer
    if(which==0)
    {
        fptr = fopen(outputFileName, "w");    // Open output file in write mode. THis mode is used to write the data to the file. Different from append mode is that it deletes the previous data in the file
    }else
    {
        fptr = fopen(outputFileName, "a");  // Open output file in append mode. THis mode is used to add the new data to the end of the file
    }
    int stop_value = 99;  
    int difference;    // I declared the difference that will be used in the function to find the distance between the cities
    difference = final_array[0];   
    printf("Path (%s %s): ", LocationName[initial_city_index], LocationName[dest_index_verify]);  // I printed the Path (%s %s) : CITY NAME -> CITY NAME
    if(which!=0)
    {
        fprintf(fptr,"\n");
    }
    fprintf(fptr,"%s(%s %s): ", "Path", LocationName[initial_city_index], LocationName[dest_index_verify]);
    if(difference!=MAX_VAL){
        for (int i = 1; i < matrix_sizer; i++)
        {
            if (*(final_array + i) == stop_value)
            {
                break;
            }
            else if (i == 1)
            {
                printf("%s", LocationName[*(final_array + i)]);
                fprintf(fptr,"%s", LocationName[*(final_array + i)]);
            }
            else if (i > 1)
            {
                printf(" -> %s", LocationName[*(final_array + i)]);
                fprintf(fptr," -> %s", LocationName[*(final_array + i)]);
            }

        }
        if(isSame) //this function is true if the initial city and destination city are the same.(for example, Prague Prague;London London)
        {
            printf(" -> %s", LocationName[dest_index_verify]);
            fprintf(fptr," -> %s", LocationName[dest_index_verify]);
        }
        printf("\nDistance: %d km\n", difference); 

        fprintf(fptr,"\nDistance: %d km", difference);
    }else{
        printf("Path not found");
        printf("\nDistance: Path not found\n");
        fprintf(fptr,"Path not found");
        fprintf(fptr,"\nDistance: Path not found\n");
    }
    fclose(fptr);
}

// I USED THE SIMILAR SYSTEM IN "ASSIGNMENT #1"  - LINK - https://github.com/cavadibrahimli1/ITU-homeworks./tree/main/Cities%20Shortest%20Path
static void how_to_use_message(char* name)  // function that doesn't return a value with file scope
{                                         // I used the static keyword to make the function visible only in its own file
    fprintf(stderr, "HOW TO RUN THIS CODE:\n\n %s [OPTION] -i INPUTFILE -o OUTPUTFILE\n\
\t\nParameters:\n\
\t\t-i    --infile INPUT FILE\t\n\
\t\t-o    --outfile OUTPUT FILE\t\n", name); // I used fprintf function to print the error message
}

// Functions and their parameters.
int* dijkstra_algo(const int* border_set, int start_index, int destination, int matrix_sizer); //  "Dijkstra Algorithm" FUNCTION
int* proximityMatrixGenerator(mapH* proximityRecord, int matrix_sizer, int proximityCount, char LocationName[][10]);  //  "Proximity Matrix Generator" FUNCTION
int LocationRecordGenerator(char* name,char LocationName[][10], int matrix_sizer);   //  "Location Record Generator" FUNCTION
void WriteFileOperation(const int * final_array, int matrix_sizer, char LocationName[][10], char* outputFileName, int which,int initial_city_index,int dest_index_verify);   //  "Write the file operation" FUNCTION
static void how_to_use_message(char* name);   //  "How to use message" FUNCTION

//  Our main functions starts 
int main(int argc, char* argv[])  // it takes 2 arguments - argc and argv[] 
{
	if(argc<5)
    {
		how_to_use_message(argv[0]);     // I used the how_to_use_message function to print the error message ( Read the line 20)
		return 2;       // I used the return 2 to exit the program  

	}
	char getIn[100], getOut[100];    // I created the getIn and getOut variables
	for (int i = 1; i < argc; ++i)   // I used the for loop to check the arguments
    {
        char arg[15];     // I created the arg variable
        strcpy(arg, argv[i]);    // I used the strcpy function to copy the argv[i] to arg
        if (!strcmp(arg,"-h") || !strcmp(arg,"--help")) // I used the strcmp function to compare the arg and "-h" or "--help"
        {
            how_to_use_message(argv[0]);   // I used the how_to_use_message function to print the error message ( Read the line 20)
            return 0;  // I used the return 0 to exit the program
        } else if (!strcmp(arg,"-i") || !strcmp(arg,"--getIn")) // I used the strcmp function to compare the arg and "-i" or "--getIn"
        {
            if (i + 1 < argc) // I used the if statement to check the i + 1 < argc
            { 
                strcpy(getIn, argv[++i]);  // I used the strcpy function to copy the argv[++i] to getIn
            } else 
            {
                fprintf(stderr, "--getIn needs one arg");  // I used the fprintf function to print the error message
                return 1;
            }
		} else if (!strcmp(arg,"-o") || !strcmp(arg,"--getOut")) // I used the strcmp function to compare the arg and "-o" or "--getOut"
        {
            if (i + 1 < argc) // I used the if statement to check the i + 1 < argc
            { 
                strcpy(getOut, argv[++i]);    // I used the strcpy function to copy the argv[++i] to getOut
            } else 
            { 
                fprintf(stderr, "--getOut needs one arg");     // I used the fprintf function to print the error message
                return 1;
            }   
        } else 
        {
            how_to_use_message(argv[0]);   // I used the how_to_use_message function to print the error message ( Read the line 20)
			return 1;
        }
    } 
	int proximityDistance;  // I created the proximityDistance variable to hold the proximity distance value 
	char FounderRecordString[100], PathPlanString[100];  // I created the FounderRecordString and PathPlanString variables to hold the FounderRecordString and PathPlanString values
	char FirstPoint[100], LastPoint[100]; // I created the FirstPoint and LastPoint variables 
	char LocationClass[100];   // I created the LocationClass variable
    
    FILE* fp = fopen(getIn, "r");   // I created the fp variable and assigned the fopen function to it that takes the getIn and "r" as arguments ( "r" mode is used to read the file)
    fgets(LocationClass, 100, fp);  // I used the fgets function to read the LocationClass from the fp
	int proximityCount, matrix_sizer;  // I created the proximityCount and matrix_sizer variables
	sscanf(LocationClass, "%d %d", &matrix_sizer, &proximityCount);  // I used the sscanf function to read the LocationClass and assign the matrix_sizer and proximityCount values to it
    mapH borders[proximityCount];  // I created the borders variable and assigned the mapH function to it that takes the proximityCount as argument
    int countofborders=0;  // I created the countofborders variable and assigned the 0 to it

    for(int i=0; i < proximityCount; i++) // I used the for loop to check the proximityCount
    {
        fgets(LocationClass,100,fp);        // I used the fgets function to read the LocationClass from the fp
        sscanf(LocationClass, "%s %s %d", FounderRecordString, PathPlanString, &proximityDistance);  // sscanf function to read the LocationClass and assign the FounderRecordString, PathPlanString and proximityDistance values to it
        strcpy(borders[countofborders].start_point, FounderRecordString); // strcpy function to copy the FounderRecordString to borders[countofborders].start_point
        strcpy(borders[countofborders].end_point, PathPlanString); // strcpy function to copy the PathPlanString to borders[countofborders].end_point
        borders[countofborders].difference = proximityDistance; 
        countofborders++;  // I used the countofborders++ to increment the countofborders
    }

    
    int which=0;
    while(1){
        if (fgets(LocationClass,100,fp) == NULL) {
            break;  // Break the loop if input was successfully read
        }
        sscanf(LocationClass, "%s %s", FirstPoint, LastPoint);  // sscanf function to read the LocationClass and assign the FirstPoint and LastPoint values to it

         // Closes the file that I opened using Fopen function
        //  in order to identify unique cities in a graph represented by a set of borders.
        char LocationName[matrix_sizer][10];  
        int num_cities = 0;
        //a simple implementation of a graph traversal algorithm that identifies unique nodes (in this case, cities) in the graph.
        for (int i = 0; i < proximityCount; i++) 
        {
            mapH maph = borders[i];   
            int from_real_location = 0;  
            int to_real_location = 0;
            for (int j = 0; j < num_cities; j++) 
            {
                if (strcmp(LocationName[j], maph.start_point) == 0) 
                {
                    from_real_location = 1;  // I used the from_real_location to assign the 1 to it
                }
                if (strcmp(LocationName[j], maph.end_point) == 0) 
                {
                    to_real_location = 1;   // I used the to_real_location to assign the 1 to it
                }
            }
            if (!from_real_location)  // If start point does not exist, add it to array of unique locations
            {
                strcpy(LocationName[num_cities], maph.start_point);   
                num_cities++; //increment opeartion for num_cities
            }
            if (!to_real_location)   // If end point does not exist, add it to array of unique locations
            { 
                strcpy(LocationName[num_cities], maph.end_point);
                num_cities++;   // Increment number of unique locations
            }
        }

        int* cityNetworkMatrix = proximityMatrixGenerator(borders, matrix_sizer, proximityCount, LocationName);  // I created the cityNetworkMatrix variable and assigned the proximityMatrixGenerator function to it that takes the borders, matrix_sizer, proximityCount and LocationName as arguments
        int initialCityIndex = LocationRecordGenerator(FirstPoint, LocationName, matrix_sizer);
        int finalCityIndex = LocationRecordGenerator(LastPoint, LocationName, matrix_sizer);
        int *results = dijkstra_algo(cityNetworkMatrix, initialCityIndex, finalCityIndex, matrix_sizer);
        WriteFileOperation(results, matrix_sizer, LocationName, getOut, which, initialCityIndex, finalCityIndex);
        which++;
    }
    fclose(fp);
	return 0; // successful program execution.
}