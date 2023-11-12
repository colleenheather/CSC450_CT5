//===========================================================================
// Name        : ct5 (Critical Thinking 5)
// Author      : Colleen Ammons
// Description :(a) write to a file without changing previous content
//              (b) reverse file contents and store in another file

// Pseudocode  :	(a)
//					    if cant open file
//                          output("failed") & exit
//                      else
//						    writeToFile("some text")
//                  (b)
//                      if cant open file
//                          output("failed") & exit)
//                      else
//                          string str
//                          for char in file
//                              str + char
//                          reverse(str) =>
//                              l = len of str -1, r = 0
//                              while(r > l) { swap , l--, r++}
//                          writeToFile(str)
//============================================================================

#include <iostream>
#include <fstream>
#include <string>

void reverseString(std::string& s) {
    int left = 0;
    int right = s.length() - 1;

    while (left < right) {
        std::swap(s[left], s[right]); // or can use temp var
        left++;
        right--;
    }
}


int append_to_file(std::string &filePath) {
    // Open the file in append mode
    std::ofstream file(filePath, std::ios::app);

    if (!file) {
        std::cerr << "Failed to open " << filePath << std::endl;
        return 1;
    }

    file << "This is a new line - Colleen\n";
    file.close();
    std::cout << "Text appended to" << filePath << " successfully" << std::endl;
    return 0;   
}

// recommended to use binary 
int reverse_file(std::string &filePath, std::string& newFile){
    std::ifstream ifs(filePath, std::ios::binary);
    if (!ifs)
        //import errorhandling?
        //throw std::runtime_error("Can't open input file.");
        std::cerr << "Error opening input file: " << std::endl;

    std::string s;
    for(char ch; ifs.get(ch);)
       s.push_back(ch);

    //OR 
    // #include <algorithms>
    //std::reverse(s.begin(), s.end());

    reverseString(s);

    std::ofstream ofs(newFile, std::ios::binary);
    if (!ofs) throw std::runtime_error("Couldn't open output file.");

    for(char ch: s)
        ofs.put(ch);
    
    return 0;
}


int main() {
    std::string filePath = "file_folder/CSC450_CT5_mod5.txt";
    std::string newFilePath = "file_folder/new_reversed_file.txt";

    append_to_file(filePath);
    reverse_file(filePath, newFilePath);
    return 0;
}

