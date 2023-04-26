/*

Author: Javad Ibrahimli 
School No: 040210932
Course: EHB 208 E 
Given by: Bora Doken and Muhammed Yasin Adıyaman
Date: 26 March 2023

*/



//header files used to provide various input/output, memory allocation, and string manipulation functions to the program.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//  C code that defines two structs, "myDict" and "Node",
struct myDict{
    int data;
    int count;
    struct myDict* next;
};

// a struct that\ a node in a two-dimensional linked list
struct Node {
    int data; // the data type that stored in the node
    struct Node* right;  // a pointer to the next node in the same row
    struct Node* down;  // a pointer to the next node in the same column
};

// Function that adds a new node to a linked list of myDict structs
struct myDict* addmyDict(struct myDict* head, int data) {
    // Allocating memory for new node
    struct myDict* newNode = (struct myDict*) malloc(sizeof(struct myDict));
    // Initializing the new node's data and count members with the given data
    newNode->data = data;
    newNode->count = 1;
    // Setting the new node's next member to NULL
    newNode->next = NULL;

    // Setting the new node the head, if the matrix is empty.
    if (head == NULL) {
        head = newNode;
    }
    else {
        // Adding the new node to the right of the last node in the related row
        struct myDict* temp = head;
        while (temp->next != NULL) {
        
            temp = temp->next;
        }
        temp->next = newNode;
    }

    return head; // return the updated head of the linked list
}
// Function that adds a new node to related matrix
struct Node* addNode(struct Node* head, int data) {
    // Allocating memory for a new node
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->right = NULL;
    newNode->down = NULL;

    // If the matrix is empty, make the new node the head
    if (head == NULL) {
        head = newNode;
    }
    else {
        // Add the new node to the right of the last node in the row
        struct Node* temp = head;
        while (temp->right != NULL) {
            temp = temp->right;
        }
        temp->right = newNode;
    }
    // return the updated head of the linked list
    return head;
}

// Function that prints created matrix to a file
void print_matrix(struct Node* head, char* fileName) {
    // FILE command to open the output file  with "w" parameter
    FILE* file = fopen(fileName, "w");
    // Traversing the matrix and print every part of the row
    struct Node* row = head;
    while (row != NULL) {
        struct Node* col = row;
        while (col->right != NULL) {
            fprintf(file, "%d,", col->data); // Printing the our data of node with commas
            col = col->right;
        }
        // Prints the data of the last node, but without comma seperation
        fprintf(file, "%d", col->data);
        if(row->down!=NULL){
            fprintf(file, "\n");
        }
        row = row->down; //moving to the next row
    }

    // fclose command to close the opened file in w parameter.
    fclose(file);
}
// Function to count the number of zeros in the matrix
int countZeros(struct Node* head) {
    // integer variable to track the count of the zeros in the matrix	
    int count = 0;
    //Setting a pointer to the row
    struct Node* row = head;
    // Allocating a pointer to the first element of the row
    while (row != NULL) {
        struct Node* col = row;
        while (col != NULL) {
            if (col->data == 0) {  //checink if the element is 0 
                count++;  //increasing count variable with increment 
            }
            col = col->right; //Moves to the next column
        }
        row = row->down; // Moves the next row
    }
    return count;  // Returns count of zeros
}


// checkforDublicate function that updates the count of current nodes and adds a new node to the dictionary.
struct myDict* checkforDublicate(int data, struct myDict* dictHead){
    if(dictHead==NULL){   // Add the new data as the head node, if dictHead is empty
        dictHead = addmyDict(dictHead,data);
    }else{  //look for the data if dictHead is not empty
        struct myDict* traverse = dictHead;
        while(traverse->next!= NULL && traverse->data!= data){   // Loops through each node
            traverse=traverse->next;
        }
        if(traverse->data==data){ // If the data is found, increase the count
            traverse->count = traverse->count+1; //+1 shows the increment 
        }else{
            // if not found, add new data to my dict
            addmyDict(dictHead,data); 
        }
    }
    return dictHead; // Returns the last version dictionary
}
// writeDublicates2File function that writes duplicate elements to the File
void writeDublicates2File(struct myDict* Dicthead,char* fileName){
    FILE* file = fopen(fileName, "w"); //open file with write mode 
    //traversing the linked list
    struct myDict* traverse = Dicthead;
    int count_dublicates=0;  // setting integer in order to save counted duplicates 
    //starts the process to find duplicates in the linked list 
    while(traverse!=NULL){
        if(traverse->count > 1){      // Checking if the element is greater than 1 
            if(count_dublicates>0){
                fprintf(file, ",");  // Starting from second duplicate, code adds comma between duplicates 
            }
            count_dublicates = count_dublicates+1;
            fprintf(file, "%d", traverse->data);  //writing duplicate elements to the file 
        }
        traverse = traverse->next; //go to the next element in the linked list
    }
   
    fclose(file); // Closes the file 
}

// generateDuplicates function that finds duplicate elements
struct myDict* generateDuplicates(struct Node* head) {
    // Initializing linked list to store the duplicates
    struct myDict* Dicthead = NULL; //setting a linked list to store the duplicates
    // Search the matrix for every duplicate element.
    struct Node* traverse_row = head;
    while (traverse_row != NULL) {
        struct Node* traverse_col = traverse_row;
        while (traverse_col != NULL) {
            if(traverse_col==head){  // Add the node to the dictionary if it is the head of the current node.
                Dicthead = checkforDublicate(traverse_col->data, Dicthead);
            }else{   // If the current node is not a duplicate, verify it and add it to the dictionary.
                checkforDublicate(traverse_col->data, Dicthead);
            }
            traverse_col = traverse_col->right;     // Go to the next node in the current row
        }
        traverse_row = traverse_row->down;          // Go to the next row
    }


    return Dicthead; //return collected Dicthead values
    
}

// the main function of a C program that takes command-line arguments to do various arguments
int main(int argc, char* argv[]) {

    // Checking the number of arg(uments) for the code
    if (argc < 6 || argc > 7) { // if the number of arguments is less than 6 or greater than 7
        printf("Invalid arguments\n"); // these lines print error message
        printf("Usage: %s [OPTION] -i INPUTFILE -o OUTPUTFILE\n", argv[0]);
        printf("Options:\n");
        printf(" --print print the matrix to an output text file\n");
        printf(" --nzeros calculate the number of zeros in the matrix and print the result to an output text file\n");
        printf(" --duplicates find the duplicated element values in the matrix and print the result to an output text file\n");
        exit(1);
    }
    //these code lines declares three char pointers 
    char* input_file; // input file
    char* output_file; // output file
    char* option; // command-line option
    
    
    // Code that iterate over all command-line options         
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-i") == 0) { // Set the input file to the next argument if the current argument is "-i".
            input_file = argv[i+1];
        } else if (strcmp(argv[i], "-o") == 0) { // Set the output file to the next argument if the current argument is "-o".
            output_file = argv[i+1];
        } else if(strcmp(argv[i], "--print") == 0 || strcmp(argv[i], "--nzeros") == 0 || strcmp(argv[i], "--duplicates") == 0 ){ //If the current argument is "—print," "—nzeros," or "—duplicates," set the option to the current argument.
            option = argv[i];
        }
    }

    // Opening the input file to read with "r" parameter
    FILE* fp = fopen(input_file, "r");
    if (fp == NULL) { //checking if rhe file is NULL
        printf("Error opening input file\n"); //error message 
        exit(1); // Exit the program (status code = 1)
    }

    
    // Configuring variables
    char ch;
    int data = 0;
    struct Node* head = NULL; // initialized to NULL
    struct Node* currentRow = NULL;  // initialized to NULL
    struct Node* prevRow = NULL; // initialized to NULL

    // Read characters till the last one are present in the file.
    while ((ch = fgetc(fp)) != EOF) {
        // If it's a digit, adds the value of the character to the current number.
        if (ch >= '0' && ch <= '9') {
            data = data * 10 + (ch - '0');
        }
        //Adds the current number as a new node to the current row if the character is a comma.
        else if (ch == ',') {
            currentRow = addNode(currentRow, data);
            data = 0;
        }
        //Adds the current row to the matrix and begin a new row if the character is a newline
        else if (ch == '\n') {
            currentRow = addNode(currentRow, data);
            if (prevRow != NULL) {          //checks if there is a previous row
                prevRow->down = currentRow; // Sets the preceding row's down pointer to point at the current row
            } else {
                head = currentRow;      // Make the current row the head pointer's destination.
            }
            prevRow = currentRow;     // Make the prior row the current row
            currentRow = NULL;       // Prepare for the following row by setting the current row reference to NULL.
            data = 0;               //in order to be ready for the following element in the row, set the data variable to 0.
        }
    }

    if(ch!='\n'){ //Unless it's a new line character
        currentRow = addNode(currentRow, data); // Uses the addNode method
        if (prevRow != NULL) { //checks if there is a previous row
            prevRow->down = currentRow; // Sets the preceding row's down pointer to point at the current row
        } else {
            head = currentRow;  // Make the current row the head pointer's destination.
        }
        prevRow = currentRow;  // Make the prior row the current row
        currentRow = NULL;    // Prepare for the following row by setting the current row reference to NULL.
        data = 0;            //in order to be ready for the following element in the row, set the data variable to 0.
    }

    // Close the input file
    fclose(fp);
    // Verify the user's selection and carry out the necessary action.
    if (strcmp(option, "--print") == 0) { // "--print" option
        print_matrix(head, output_file); // print_matrix function
    } else if (strcmp(option, "--nzeros") == 0) { // "--nzeros" option 
        int zero_count = countZeros(head); /// Determine the matrix's total number of zeros.
        if (output_file != NULL) { // If the user specifies an output file
            FILE* fp = fopen(output_file, "w"); //Opening file in Write mode
            if (fp == NULL) {
                printf("Error opening output file\n"); //If there is a problem opening the output file, this code displays a notice.
                exit(1); //exit with error code 
            }
            fprintf(fp, "%d", zero_count); /// Updates the output file with the number of zeros.
            fclose(fp); //Close the file 
        }
    } else if (strcmp(option, "--duplicates") == 0) {  // "--duplicates" option
        //find_duplicates(head, output_file);
        struct myDict* dicthead = generateDuplicates(head); // Calls the generateDuplicates 
        writeDublicates2File(dicthead, output_file); //Calls the writeDublicates
    } else { //if invalid option is called 
        printf("Invalid option\n"); //sets error message 
        exit(1); //exits the program with error code 
    }

    return 0; //returns output if it compiled succesfully(0) 
}

