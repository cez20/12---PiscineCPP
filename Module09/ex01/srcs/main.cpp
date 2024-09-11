/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 19:41:03 by cemenjiv          #+#    #+#             */
/*   Updated: 2024/09/11 12:04:46 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <algorithm> // This is for std::remove_if
#include <cctype> // For isspace? 
#include <stack>

bool isOperator(char c){

  if(c == '+' || c == '-' || c == '*' || c == '/')
    return true;
  return false;
}

int calculate(int operand1, int operand2, char op){

    int total;

    switch(op) {
      case '+':
        total = operand1 + operand2;
        break;
      case '-':
        total = operand1 - operand2;
        break;
      case '*':
        total = operand1 * operand2;
        break;
      case '/':
        total = operand1 / operand2;
        break;
      default:
        std::cerr << "Error: Invalid operator" << std::endl;
        return 0;
    }
    return total;  
}

int main(int argc, char **argv)
{
    if (argc == 2){
      std::string str = argv[1];
      str.erase(std::remove_if(str.begin(), str.end(), ::isspace), str.end()); //TODO: Fix the problem of ::isspace vs std::isspace
      
      std::stack<char> mystack;
      int operand1 = 0;
      int operand2 = 0;
      int total = 0;
      int newTotal = 0;

      for (size_t i = 0; i != str.size(); ++i){
        if(isOperator(str[i])){
          operand2 = mystack.top() - '0'; // Takes element and converts it to int. 
          mystack.pop();  //Removes elements from stack
          if (mystack.empty())
            total = calculate(total, operand2, str[i]);
          else{
            operand1 = mystack.top() - '0';
            mystack.pop();
            newTotal = calculate(operand1, operand2, str[i]);
            if (newTotal >= 0)
              total += newTotal;
            else
              total -= newTotal;
          }
        }
        else {
          mystack.push(str[i]);
        }
      }

      std::cout << "The total of the RNP is: " << total << std::endl;

    } else {
        std::cout << "ERROR! Program needs RPN mathematical expression as an argument!" << std::endl;
        return 1;
    }
    return 0;
}
