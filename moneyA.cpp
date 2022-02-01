/*
Hanna Zelis
CSC 1710 - 01
3/25/2021
/home/students/hzelis/csc1710/prog2/moneyA.cpp

This program creates a table to show the total invested and current
value (based off the interest rate) per month based off the user's 
input of their initial amount, monthly deposit, number of years they wish to see
in the table, the interest rate, and if there are any changes in the interest rate
per year. If there is any annual change in the interest rate, the table
will reflect that. Finally, the capital gain will be shown at the bottom of the graph.

*/





#include <iostream>
#include <iomanip>





using namespace std;





int main()
{





  //Declare variables

  double monthlyDeposit, years, annualInterestRate, yearChangeIR, currentValue, totalInvested, rateMoneyIncrease, capitalGain;
  int month = 0;





  //Warning users at the beginning of any warnings in regards to decimal places

  cout << fixed << showpoint;

  cout << "***If for any of the following you have to input a decimal, only input up to 2 decimal places.***" << endl;

  cout << " " << endl;

  cout << "**If you can enter in more than 2 decimal places, but the third decimal place will not round the second decimal place.**" << endl;

  cout << " " << endl;

  cout << "*Only the first two decimal places will be used in the calculation of this table*: " << endl;

  cout << " " << endl;





  //Asking user for all necessary values and included input validation for all variables that are being asked for

  cout << "Enter initial investment: ";
  cin >> totalInvested;

    while ((totalInvested < 0) || (!cin))
    {
      cout << "Invalid Input. Try again. Enter inital Investment: ";
      cin >> totalInvested;
    } 



  cout << "Enter monthly deposit: ";
  cin >> monthlyDeposit;

    while ((monthlyDeposit < 0) || (!cin))
    {
      cout << "Invalid Input. Try again. Enter monthly deposit: ";
      cin >> monthlyDeposit;
    }



  cout << "Enter number of years: ";
  cin >> years;

    while ((years < 0) || (!cin))
    {
      cout << "Invalid input. Try again. Enter number of years: ";
      cin >> years;
    }



  cout << setprecision(4) << "Annual interest rate as a decimal: ";
  cin >> annualInterestRate;

    while ((annualInterestRate < 0) || (!cin))
    {
      cout << "Invalid input. Try again. Annual interest rate as a decimal: ";
      cin >> annualInterestRate;
    }



  cout << setprecision(4) <<  "Enter change in interest rate per year as a decimal: ";
  cin >> yearChangeIR;

    while (!cin)
    {
      cout << "Invalid input. Try again. Enter change in interest rate per year as a decimal: ";
      cin >> yearChangeIR;
    }





 //Creating title and column rows for table
  
  cout << " " << endl;

  cout << " " << endl;

  cout << setw(29) << "Investment Table" << endl;

  cout << " " << endl;

  cout << setw(7) << "  Month" << setw(18) << "    Total Invested" << setw(17) << "  Current Value  " << endl; 

  cout << setw(20) << "($)" << setw(13) << "($)" << endl;

  cout << " " << endl; 

  cout << setw(42) << "------------------------------------------" << endl;





  //Start of formatting the table

  currentValue = totalInvested;
    
  cout << setw(4) << month << setw(17) << setprecision(2) << totalInvested << setw(15) << setprecision(2) << currentValue << endl;
    
  month++;

  



  //This while loop helps to calculate all parts necessary until the user asks the computer to stop (based off of the month (year they input))

  while (month <= years * 12)
  {

    rateMoneyIncrease = (annualInterestRate / 12) * currentValue;

    totalInvested += monthlyDeposit;

    currentValue = currentValue + monthlyDeposit + rateMoneyIncrease;

    cout << setprecision(0) << setw(4) << month << setw(17) << setprecision(2) << totalInvested << setw(15) << setprecision(2) << currentValue << endl;

    month++;

  
  
    //These if statements help determine whether or not an annual interest rate change has to be considered
    //Because January is month = 1 and not month = 0, the annual rate will change at January of the following year, meaning 13, hence, the month
    //Has to be greater or equal to 13 and month % 2 = a remainder of 1

    if (yearChangeIR > 0)
    {
      if ((month >= 13) && (month % 12 == 1))
        annualInterestRate += yearChangeIR;
    }   

  }





  //Calculating Capital Gain 
  
  capitalGain = currentValue - totalInvested;

  cout << " " << endl;

  cout << " " << endl;

  cout << setw(18) << "Capital Gain:  $" << capitalGain << endl;

  cout << " " << endl;





return 0;
} 
