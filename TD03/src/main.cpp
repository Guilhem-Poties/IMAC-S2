#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <cctype>
#include <iostream>
#include <stack>
#include <math.h>


enum class Operator { ADD, SUB, MUL, DIV, OPEN_PAREN, CLOSE_PAREN};
enum class TokenType { OPERATOR, OPERAND };
struct Token {
  TokenType type;
  float value;
  Operator op;
};


std::vector<std::string> split_string(std::string const& s)
{
    std::istringstream in(s); // transforme une chaîne en flux de caractères, cela simule un flux comme l'est std::cin
    // l’itérateur va lire chaque element de "in", comme un flux d'entrée, chaque élément est séparé par un espace
    return std::vector<std::string>(std::istream_iterator<std::string>(in), std::istream_iterator<std::string>()); 
}

bool is_floating(std::string const& s);

float npi_evaluate(std::vector<std::string> const& tokens);


int main() {
    std::string npi {};
    // std::getline(std::cin, npi);

    std::cout << npi_evaluate(split_string("3 4 2 ^ 1 5 - 6 ^ / +")) << std::endl;

    return 0;
}

bool is_floating(std::string const& s) {
    for (size_t i=0; i < s.size(); i++) {
        if (isdigit(s.at(i)) || s.at(i) == '.') {
            return true;
        }
    }
    return false;
}

float operation(std::string operator_, float leftOperand, float rightOperand) {
    float result {};
    if (operator_ == "+") result = leftOperand + rightOperand;
    else if (operator_ == "-") result = leftOperand - rightOperand;
    else if (operator_ == "*") result = leftOperand * rightOperand;
    else if (operator_ == "/") result = leftOperand / rightOperand;
    else if (operator_ == "^") result = std::pow(leftOperand, rightOperand);

    // std::cout << leftOperand << rightOperand << operator_;
    
    return result;
}

float npi_evaluate(std::vector<std::string> const& tokens) {
    std::stack<float> values;
    for (size_t i = 0; i < tokens.size(); i++) {
        if (is_floating(tokens[i])) {
            values.push(stof(tokens[i]));
        }
        else {
            float rightOperand {values.top()};
            values.pop();
            float leftOperand {values.top()};
            values.pop();

            values.push(operation(tokens[i], leftOperand, rightOperand));
            
            // std::cout << leftOperand << tokens[i] << rightOperand;
        }
    }
    return values.top();
}
