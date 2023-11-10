//===========================================================================
// Name        : ct5 (Critical Thinking 5)
// Author      : Colleen Ammons
// Description : write to a file without changing previous content
// Pseudocode  :	obtain file(CSC450_CT5_mod5.txt)
//					if cant open
//                      output("unable to open file")
//                      exit
//                  else
//						write("some text")
//						file.close()
//					    output("finished")
//============================================================================

#include <iostream>
#include <fstream>

int main() {
    std::string filePath = "file_folder/CSC450_CT5_mod5.txt";

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