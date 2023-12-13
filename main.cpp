#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::string s = R"(
The weather is so sunny nowadays

Life is so beautiful
)";

std::vector<std::string> temp;

std::string delimiter1 = "\n";
std::string delimiter2 = " ";

int main() {
    size_t pos1 = 0;
    size_t pos2 = 0;
    
    std::string token1;
    std::string token2;
    
    // loop for lines
    while ((pos1 = s.find(delimiter1)) != std::string::npos) {
        std::vector<std::string> temp; // temp vector for storing words
        token1 = s.substr(0, pos1);
        
        // loop for words
        while ((pos2 = token1.find(delimiter2)) != std::string::npos) {
            token2 = token1.substr(0, pos2);
            temp.push_back(token2);
            token1.erase(0, pos2 + delimiter2.length());
        }
        
        // add last element
        temp.push_back(token1);
        
        
        for (auto it = temp.rbegin(); it != temp.rend(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
        
        s.erase(0, pos1 + delimiter1.length());
    }
}
