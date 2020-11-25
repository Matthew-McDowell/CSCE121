#include <iostream>
#include <string>
#include "./string_calculator.h"

using std::cout;
using std::endl; 
using std::string;

unsigned int digit_to_decimal(char digit) {
    // TODO(student): implement
    
    if ((digit <= 47) || (digit >= 58)) {
       throw std::invalid_argument("Invalid argument1");
       return 0;
    }
    else {
        digit = digit - '0';
    }
    //digit = static_cast<double>(digit);
    return digit;
}
char decimal_to_digit(unsigned int decimal) {
    // TODO(student): implement
   char digit = decimal + '0';
   if ((digit <= 47) || (digit >= 58)) {
       throw std::invalid_argument("Invalid argument2");
       return 0;
    }
   return digit;
    
}

string trim_leading_zeros(string num) {
    // TODO(student): implement
   bool zero_num = true;
   int index_num = 0;

   //Checking all zero number
   if (num.at(0) == '-') {
      num = num.substr(1,num.length());
      index_num = 1;
   }
   
   //Checking zero string 
   for (string::size_type i = 0; i <= (num.size()-1); ++i){
      if ((num.at(i)) != '0') {
            zero_num = false;
            break;
         }     
   }
   if (zero_num == true) {
         num = "0";
         return num;
      }

   //Main function trimming zero
     for ( string::size_type i = 0; i <= (num.size()); ++i) {
         if (num.at(i) == '0'){
              num.replace(i,1,"*");
         }
         
         else {
            num = num.substr(i,num.size());
            if (index_num == 1) {
               num.insert(0,"-"); //add '-' for negative number
            }
         return num;
         }
   }   
return num;
}

string add(string lhs, string rhs) {
   //Copy lhs and rhs 
    string copy_lhs = lhs;
    string copy_rhs = rhs;

   lhs = trim_leading_zeros(lhs);
   rhs = trim_leading_zeros(rhs);
   string result_add ="";
   int carry = 0;
   int sum;
   
   //Checking lhs and rhs are negative number
   if ((lhs.at(0) == '-') && (rhs.at(0) == '-')) {
      lhs = lhs.substr(1,lhs.length());
      rhs = rhs.substr(1,rhs.length());
   }
   //Regarrange length of string, adding 2 postive number
   if ((lhs.at(0) != '-') && (rhs.at(0) !='-')) {
   if (lhs.length() != rhs.length()) {
      if (lhs.length() > rhs.length()) {
         while (lhs.length() != rhs.length()){
            rhs.insert(0,"0" );  //add '0' in the string 
         }
      }
      else if (lhs.length() < rhs.length()) 
         while (lhs.length() != rhs.length()){
            lhs.insert(0,"0" );  //add '0' in the string 
            }
    }
        //Main function adding number, changing to decimal
      for (int i = (lhs.length()-1) ; i >= 0 ; i--) {
         sum = digit_to_decimal(lhs.at(i)) + digit_to_decimal(rhs.at(i)) + carry;
         carry = 0;
         if(sum > 9) {
            result_add.insert(0, string (1, decimal_to_digit (sum % 10))); 
            carry = 1; 
         }
         else if (sum <= 9) {
            result_add.insert(0, string (1, decimal_to_digit (sum))); 
         }
         sum = 0;
     
      }
      //Checking last number
      if (carry != 0) {
         result_add.insert(0,"1");
         }
      
    if ((copy_lhs.at(0) == '-') || (copy_rhs.at(0) == '-'))  {
        result_add.insert(0,"-");
    }
   }

      //Adding number with one positive and one negative
    if ((lhs.at(0) == '-') ^ (rhs.at(0) =='-')) {
        if (lhs.at(0) == '-') {
           lhs = lhs.substr(1,lhs.length());
            result_add = subtract (rhs, lhs);
        }
        else if (rhs.at(0) =='-') {
           rhs = rhs.substr(1,rhs.length());
             result_add = subtract (lhs, rhs);
        }        
    }
   return result_add;
}


string subtract(string lhs, string rhs) {
   
   //Making copy of lhs and rhs
   string copy_lhs = lhs;
   string copy_rhs = rhs;
   //eliminate 0 
   lhs = trim_leading_zeros(lhs);
   rhs = trim_leading_zeros(rhs);

   string result_sub = "";
   
   int carry = 0;
   int num_sub = 0;
    
  

   //Checking lhs and rhs are negative number
   if ((lhs.at(0) == '-') && (rhs.at(0) == '-')) {
      lhs = lhs.substr(1,lhs.length());
      rhs = rhs.substr(1,rhs.length());
   }

   //Checking lhs or rhs are negative number
   if ((lhs.at(0) == '-') ^ (rhs.at(0) == '-')) {
      if (lhs.at(0) == '-') {
         rhs.insert(0,"-");
      }
      else {
         rhs.replace(0, 1, "");
      }
      result_sub = add(lhs,rhs);
      return result_sub;
   }

    //Checking length
   if (lhs.length() != rhs.length()) {
      if (lhs.length() > rhs.length()) {
         while (lhs.length() != rhs.length()){
            rhs.insert(0,"0" );  //add '0' in the string 
         }
      }
      else if (lhs.length() < rhs.length()) {
         while (lhs.length() != rhs.length()){
            lhs.insert(0,"0" );
            }
      }
    }
   string new_lhs = lhs;
   
   //Swap lhs and rhs
   int swap_value = 0;
    for (unsigned long i = 0 ; i < lhs.length(); i++) {
       if ((lhs.at(i)) > rhs.at(i)) {
          
          break;
       }
       else if ((lhs.at(i)) < rhs.at(i)) {
          lhs = rhs;
          rhs = new_lhs;
          swap_value = 1;
          
          break;
       }
    }

   //Main function of subtract
   for (int i = (lhs.length()-1) ; i >= 0 ; i--) { //CHECKING AGAIN
         if ((lhs.at(i)) < rhs.at(i)){
            num_sub = (10 + digit_to_decimal(lhs.at(i))) - digit_to_decimal(rhs.at(i)) - carry;
            carry = 0; //reset carry
            carry = 1;
         }
         else if ((carry!= 0) && (rhs.at(i) == lhs.at(i))) {
            num_sub = 9;
         }
         else  {
            num_sub = digit_to_decimal(lhs.at(i)) - digit_to_decimal(rhs.at(i)) - carry;
            carry = 0;
         }
         result_sub.insert(0,string(1,decimal_to_digit(num_sub)));
         num_sub = 0;
      }
   if (((swap_value == 0) && (copy_lhs.at(0) == '-')) || ((swap_value ==1) && (copy_rhs.at(0) != '-'))) {
         result_sub.insert(0,"-");
   }
  
   result_sub = trim_leading_zeros(result_sub);
   return result_sub;
}

string multiply(string lhs, string rhs) {

   string copy_lhs = lhs;
   string copy_rhs = rhs;
   //eliminate 0 
   lhs = trim_leading_zeros(lhs);
   rhs = trim_leading_zeros(rhs);

   string temp_result = "";
   string multi_result = "0";
   int carry = 0;
   int result = 0;
   int number = 0;

   if (lhs.at(0) == '-') {
      lhs = lhs.substr(1,lhs.length());
   }
   if (rhs.at(0) == '-') {
      rhs = rhs.substr(1,rhs.length());
   }

   //Main function
   for ( int i = rhs.length()-1; i >= 0; --i){
         for ( int j = lhs.length()-1; j >= 0; --j){
            result = digit_to_decimal(lhs.at(j)) * digit_to_decimal(rhs.at(i)) + carry;
            carry = 0;
         if (result > 9) {
            temp_result.insert(0,string(1,decimal_to_digit(result % 10)));
            carry =  result / 10;
         }
         else {
         temp_result.insert(0,string(1,decimal_to_digit(result)));
         }
         result = 0;
         }
         if (carry != 0) {
            temp_result.insert(0,string(1,decimal_to_digit(carry)));
            carry = 0;
         }
         for (int k = 0; k < number; ++k){
            temp_result.append("0");
         }
         number ++;
         multi_result = add(multi_result,temp_result);
         temp_result = "";
   }
   if ((copy_lhs.at(0) == '-') ^ (copy_rhs.at(0) == '-')) {
      multi_result.insert(0,"-");
   }
    return multi_result;
}




