It is tested in Ubuntu environment. You should put evaluate.sh alongside the folder in which your code file is held. 
The directory structure should be like

-parent_folder
    -sample_input.csv
    -sample_output_print.txt
    -sample_output_duplicates.txt
    -sample_output_nzeros.txt
    -evaluate.sh
    -040110229 (The folder's name is your student ID)
        -yourcode.cpp (c files are also accepted)

Come to the parent_folder and basically run 
    ./evaluate.sh

This will give you your grade in notlar.txt file.

The grade will be given according to tests below:
    1. Compile successfully -> 10p
    2. Generate output files for sample input which is given to you -> 15p
    3. Generate correct results for the sample input which is given to you -> 15p
    4. Generate correct results for 2 other inputs which are not given to you -> 60p

Note that 3 test inputs will be applied instead of the one that is given to you. 
Your code should work properly for each test case to get full credit.