#!/bin/bash
SAMPLE_INPUT="./sample_input.csv"
SAMPLE_OUTPUT_PRINT="./sample_output_print.txt"
SAMPLE_OUTPUT_NZEROS="./sample_output_nzeros.txt"
SAMPLE_OUTPUT_DUPLICATES="./sample_output_duplicates.txt"
rm notlar.txt 2>/dev/null 1>/dev/null
for f in $(find . -mindepth 2 -maxdepth 2 -type f -name "*.cpp" -o -name "*.c")
do
    puan=0
    numara=${f%/*}
    numara=${numara##*/}
    compiledfile=${f%/*}/compiled
    outfile_print=${f%/*}/sample_output_print.txt
    outfile_duplicates=${f%/*}/sample_output_duplicates.txt
    outfile_nzeros=${f%/*}/sample_output_nzeros.txt
    if [[ $f == *.cpp ]]; then
        g++ $f -o $compiledfile 
    else
        gcc $f -o $compiledfile 
    fi
    if test -f "$compiledfile"; then
        ((puan=puan+10))
        chmod +x $compiledfile
        timeout 3s $compiledfile --print -i $SAMPLE_INPUT -o ${outfile_print} 
        if test -f "$outfile_print"; then
            ((puan=puan+5))
            if [[ ! $(diff $SAMPLE_OUTPUT_PRINT $outfile_print) ]]; then
                ((puan=puan+5))
            fi
        fi
        timeout 3s $compiledfile --nzeros -i $SAMPLE_INPUT -o ${outfile_nzeros} 
        if test -f "$outfile_nzeros"; then
            ((puan=puan+5))
            if [[ ! $(diff $SAMPLE_OUTPUT_NZEROS $outfile_nzeros) ]]; then
                ((puan=puan+5))
            fi
        fi
        timeout 3s $compiledfile --duplicates -i $SAMPLE_INPUT -o ${outfile_duplicates} 
        if test -f "$outfile_duplicates"; then
            ((puan=puan+5))
            if [[ ! $(diff $SAMPLE_OUTPUT_DUPLICATES $outfile_duplicates) ]]; then
                ((puan=puan+5))
            fi
        fi 
    fi
    echo $numara ": " $puan >> notlar.txt 
done

