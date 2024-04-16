#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <cctype>
#include <iostream>
#include <stack>
#include <math.h>


enum class Operator { ADD, SUB, MUL, DIV, POW, OPEN_PAREN, CLOSE_PAREN, NONE };
enum class TokenType { OPERATOR, OPERAND };
struct Token {
  TokenType type;
  float value;
  Operator op;
};

std::vector<std::string> split_string(std::string const& s);

bool is_floating(std::string const& s);

float npi_evaluate(std::vector<std::string> const& tokens);


Token makeToken(float value);
Token makeToken(Operator op);

std::vector<Token> tokenize(std::vector<std::string> const& words);

float npi_evaluate(std::vector<Token> const& tokens);


size_t operator_precedence(Operator const op);

std::vector<Token> infix_to_npi_tokens(std::string const& expression);

void infix_evaluate(std::string infix_expression);


int main() {
    std::string npi {};
    // std::getline(std::cin, npi);

    std::cout << npi_evaluate(tokenize(split_string("3 4 2 ^ 1 5 - 6 ^ / +"))) << std::endl;

    infix_evaluate("3 + 4 ^ 2 / ( 1 - 5 ) ^ 6");

    return 0;
}


/************ Exercice 1 ************/

std::vector<std::string> split_string(std::string const& s) {
    std::istringstream in(s); // transforme une chaîne en flux de caractères, cela simule un flux comme l'est std::cin
    // l’itérateur va lire chaque element de "in", comme un flux d'entrée, chaque élément est séparé par un espace
    return std::vector<std::string>(std::istream_iterator<std::string>(in), std::istream_iterator<std::string>()); 
}

bool is_floating(std::string const& s) {
    for (size_t i=0; i < s.size(); i++) {
        if (!(isdigit(s.at(i)) || s.at(i) == '.')) {
            return false;
        }
    }
    return true;
}

float operation(std::string op, float leftOperand, float rightOperand) {
    float result {};
    if (op == "+") result = leftOperand + rightOperand;
    else if (op == "-") result = leftOperand - rightOperand;
    else if (op == "*") result = leftOperand * rightOperand;
    else if (op == "/") result = leftOperand / rightOperand;
    else if (op == "^") result = std::pow(leftOperand, rightOperand);
    else result = (float)NULL;

    // std::cout << leftOperand << rightOperand << op;
    
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


/************ Exercice 2 ************/

Token makeToken(float value) {
    return {TokenType::OPERAND, value, Operator::NONE};
}
Token makeToken(Operator op) {
    return {TokenType::OPERATOR, (float)NULL, op};
}

Operator findOpFromStr(std::string s) {
    Operator result {};
    if (s == "+") result = Operator::ADD;
    else if (s == "-") result = Operator::SUB;
    else if (s == "*") result = Operator::MUL;
    else if (s == "/") result = Operator::DIV;
    else if (s == "^") result = Operator::POW;    
    else if (s == "(") result = Operator::OPEN_PAREN;
    else if (s == ")") result = Operator::CLOSE_PAREN;
    else result = Operator::NONE;

    return result;
}

std::vector<Token> tokenize(std::vector<std::string> const& words) {
    std::vector<Token> tokenList {};
    for (size_t i = 0; i < words.size(); i++) {
        if (is_floating(words[i])) {
            tokenList.push_back(makeToken(stof(words[i])));
        }
        else {
            tokenList.push_back(makeToken(findOpFromStr(words[i])));
        }
    }
    return tokenList;
}

float operation(Operator op, float leftOperand, float rightOperand) {
    float result {};
    if (op == Operator::ADD) result = leftOperand + rightOperand;
    else if (op == Operator::SUB) result = leftOperand - rightOperand;
    else if (op == Operator::MUL) result = leftOperand * rightOperand;
    else if (op == Operator::DIV) result = leftOperand / rightOperand;
    else if (op == Operator::POW) result = std::pow(leftOperand, rightOperand);
    else result = (float)NULL;

    // std::cout << leftOperand << rightOperand << op;
    
    return result;
}

float npi_evaluate(std::vector<Token> const& tokens) {
    std::stack<float> values;
    for (size_t i = 0; i < tokens.size(); i++) {
        if (tokens[i].type == TokenType::OPERAND) {
            values.push(tokens[i].value);
        }
        else {
            float rightOperand {values.top()};
            values.pop();
            float leftOperand {values.top()};
            values.pop();

            values.push(operation(tokens[i].op, leftOperand, rightOperand));
            
            // std::cout << leftOperand << tokens[i] << rightOperand;
        }
    }
    return values.top();    
}


/************ Exercice 3 ************/

size_t operator_precedence(Operator const op) {
    size_t result {0};
    if (op == Operator::ADD || op == Operator::SUB) result+=1;
    else if (op == Operator::MUL || op == Operator::DIV) result+=2;
    else if (op == Operator::POW) result+=3;

    return result;
}

std::vector<Token> infix_to_npi_tokens(std::string const& expression) {
    std::vector<Token> result {};
    std::stack<Token> stack_operators {};

    for (auto & token : tokenize(split_string(expression))) {
        // Si le token est un operateur
        if (token.type == TokenType::OPERATOR) {
            if (!stack_operators.empty()) {
                // Cas séparé d'une parenthèse fermente
                if (token.op == Operator::CLOSE_PAREN) {
                    while (stack_operators.top().op != Operator::OPEN_PAREN) {
                        result.push_back(stack_operators.top());
                        stack_operators.pop();
                    }
                    stack_operators.pop();
                }
                else if (token.op == Operator::OPEN_PAREN) {
                    stack_operators.push(token);
                }
                // Cas classique
                else {
                    while (operator_precedence(stack_operators.top().op) >= operator_precedence(token.op)) {
                        result.push_back(stack_operators.top());
                        stack_operators.pop();
                    }
                    stack_operators.push(token);
                }
            }
            else {
                stack_operators.push(token);
            }
        } 
        // Si le token est une opérande
        else {
            result.push_back(token);
        }
    }
    while (!stack_operators.empty()) {
        result.push_back(stack_operators.top());
        stack_operators.pop();
    }
    return result;
}

void infix_evaluate(std::string infix_expression) {
    std::cout << "Le resultat de l'expression vaut : " << npi_evaluate(infix_to_npi_tokens(infix_expression));
}