// Libraries that will be used
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
// Function to merge and sort two input files and write to an output file
void sortAndMergeNumbersInNewFile(ifstream &file1InputData, ifstream &file2InputData, ofstream &file_sorted_output) {
    double number1_of_file1, number2_of_file2;
    // + mean file have number
    // - mean file does not have number
    char number_isthere_in_file1 = '-';
    char number_isthere_infile2 = '-';

    // Read the first number from each file
    if (file1InputData >> number1_of_file1)
    
    {
        number_isthere_in_file1 = '+';
        
    }
    if (file2InputData >> number2_of_file2) {
        number_isthere_infile2 = '+';
        
    }
    // When either one of file has number, condition will remain true
    // While loop to sort and store numbers in output file
    while( ( (number_isthere_in_file1 == '+') || (number_isthere_infile2 == '+') ))  {
        
        if (  number_isthere_in_file1=='+' && ( number_isthere_infile2=='-' || (  !(number1_of_file1 > number2_of_file2) ) ) ) {
           
            file_sorted_output << number1_of_file1 << " ";
            number_isthere_in_file1 = '-';
            
        if (file1InputData >> number1_of_file1) {
            
            number_isthere_in_file1 = '+';
        } 
        
        }
        else if ( number_isthere_infile2 == '+' ) {
             
            file_sorted_output << number2_of_file2 << " ";
            number_isthere_infile2 = '-';
            if (file2InputData >> number2_of_file2){ 
            
            number_isthere_infile2 = '+';
           
            
            }
            
            }
        }
    }
    
// Main function

int main() {
    // Create string type variables for holding file names
    string inputFileName1, inputFileName2, outputFileName;

    // Prompt the user to enter the names of two input files and one output file
    cout << "Hey there!, Please Enter the name of the first input file: ";
    cin >> inputFileName1;
    cout << "Thank you for first file name!, onto Please Enter the name of the second input file: ";
    cin >> inputFileName2;
    cout << "Again Thanks for second file name, now Please Enter the name of the output file: ";
    cin >> outputFileName;
   
    // Open the input files
    // ifstream for reading input stream of bytes
    // ofstream for writing output bytes
    
    ifstream inputFile1(inputFileName1);
    // Check file name exists or not
    // In case file cannot be opened ( Wrong file name or wrong file extension case)
    if (!inputFile1.is_open()) {
        cerr << "Error opening first input file : " << inputFileName1 << endl;
        return 1; // 1 for error
    }
    ifstream inputFile2(inputFileName2);
    
    // Check file name exists or not
    // In case file cannot be opened ( Wrong file name or wrong file extension case)
    if (!inputFile2.is_open()) {
         cerr << "Error opening first input file : "<<inputFileName2<<endl;
        return 1; // 1 for error
    }
    // Output File
    ofstream outputFile(outputFileName);
    
    // Check file name created or not
    // In case file cannot be opened ( Wrong file name or wrong file extension case)

    if (!outputFile.is_open()) {
        cerr << "Error opening one of the files."<<outputFileName<<endl;
        return 1; // 1 for error
    }

    // Merge and sort the numbers from the input files and write to the output file
    sortAndMergeNumbersInNewFile(inputFile1, inputFile2, outputFile);
    // Close the input and output files
    inputFile1.close();
    inputFile2.close();
    outputFile.close();
    cout << "Oh thank you!!! The numbers from your provided files have been merged and sorted into your provided name " << outputFileName << endl;
    return 0;
}
