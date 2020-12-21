// Malachy Mroch Project 2

#include <iostream>
#include <cstdio>


using namespace std;



void showReports(double initInvest, double monthlyDeposit, double interestRate, int numYears) {
    
    double total = initInvest;
    
    cout << "   Balance and Interest Without Additional Monthly Depositis\n";
    cout << "===============================================================\n";
    cout << " Year \t Year End Balance \t Year End Earned Interest\n";
    cout << "---------------------------------------------------------------\n";
    for(int i = 1; i < numYears + 1; ++i) {
        double yearEarnedInterest = total * (interestRate / 100);//calculating interest earned per year
        total = total + yearEarnedInterest; //total balance equals invested amount + interest
        printf("   %d    \t%.2f  \t\t%.2f\n", i, total, yearEarnedInterest);//formatting output
    }
    
    //doing same thing w/ monthly deposits
    
    //resetting total to initial amount invested
    total = initInvest;
    
    cout << endl << endl << endl; //new lines between the charts
    cout << "   Balance and Interest With Additional Monthly Depositis\n";
    cout << "===============================================================\n";
    cout << " Year \t Year End Balance \t Year End Earned Interest\n";
    cout << "---------------------------------------------------------------\n";
    for(int i = 1; i < numYears + 1; ++i) {
        double yearEarnedInterest = 0; // holds the total interest earned in a year
       
        //i just compounded the interest monthly in another for loop 
        for(int i = 0; i < 12; i++) {
            double interestPerMonth = (total + monthlyDeposit) * ((interestRate / 100)/12);
            total = total + interestPerMonth + monthlyDeposit;
            yearEarnedInterest = yearEarnedInterest + interestPerMonth;
        }
        
        printf("   %d    \t%.2f  \t\t%.2f\n", i, total, yearEarnedInterest);//formatting output
    }
}



int main()
{
    while(true) {
        double initInvest;
        double monthlyDeposit;
        double interestRate;
        int numYears;
        
        //tell user what to input
        cout<<"**********************************************\n";
        cout<<"************** Data Input ********************\n";
        cout << "Initial Investement Amount: \n";
        cout << "Monthly Deposit: \n";
        cout << "Annual Interest: \n";
        cout << "Number of years: \n";
        cout << "Press any key to continue . . .\n\n";
        
        //store user input in variables
        cin >> initInvest;
        cin >> monthlyDeposit;
        cin >> interestRate;
        cin >> numYears;
        
        //show user what they input
        cout<<"**********************************************\n";
        cout<<"************** Data Input ********************\n";
        printf("Initial Investement Amount: $%.2f\n", initInvest);
        printf("Monthly Deposit: $%.2f\n", monthlyDeposit);
        printf("Annual Interest: %%%.2f\n",interestRate);//%5 looks like a typo but is how the example is
        cout << "Number of years: " << numYears << endl;
        cout << "Press any key to continue . . .\n\n";
        
    
        
        
        //breaking this up abit
        showReports(initInvest, monthlyDeposit, interestRate, numYears);
        cout << "Do you wish to coninue (y/n)\n";
        char response;
        cin >> response;
        if(response == 'n')
            return 1;
    }

    return 0;
}