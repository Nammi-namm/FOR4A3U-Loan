#include <iostream>
#include <math.h>
#include <string>
#include <iomanip>

using namespace std;

// Benedikt M. Scheving-Thorsteinsson


class Loan {
private:
	double principalAmount;
	int numberOfInstalments;
	double annualInterestRate;
	
public:	
	Loan(double princ, double interest, int numbinstaments) {
		principalAmount = princ;
		annualInterestRate = interest;
		numberOfInstalments = numbinstaments;
	}
	
private:
	double computeInstalment(){
		return principalAmount/numberOfInstalments;
	}
	double computeBalance(int numPayment) {
		return principalAmount - (numPayment-1)* computeInstalment();
		
	}
	double computeInterest(int numPayment) {
		return computeBalance(numPayment) * (annualInterestRate/12) / 100;
		
	}
	
public:
	void displaySchedule() {
		cout << "No.	Principal	Instalment	Interest	TotalPayment" << endl << "----------------------------------------------------------------------" << endl;
		for (int i = 1; i <= numberOfInstalments; i++){
			cout << fixed;
			cout << setprecision(2);
			cout << setw(4) << right << i 
			<< setw(13) << right << computeBalance(i) 
			<< setw(17) << right << computeInstalment() 
			<< setw(14) << right << computeInterest(i) 
			<< setw(20) << right << (computeInstalment() + computeInterest(i))
			<< endl;
		}
		cout << "----------------------------------------------------------------------" << endl;
		double totalnumbs1 = 0;
		double totalnumbs2 = 0;
		double totalnumbs3 = 0;
		for (int i = 1; i <= numberOfInstalments; i++){
			totalnumbs1 += computeInstalment();
			totalnumbs2 += computeInterest(i);
			totalnumbs3 += (computeInstalment() + computeInterest(i));
		}
		cout << fixed;
		cout << setprecision(2);
		cout 
		<< setw(34) << totalnumbs1 
		<< setw(14) << totalnumbs2
		<< setw(20) << totalnumbs3 << endl;
	
		
	}
};

int main() {
	double principal, interest;
	int instalments;
	cout << "principal: ";
	cin >> principal;
	cout << endl << "Interest rate: ";
	cin >> interest;
	cout << endl << "Number of payments: ";
	cin >> instalments;
	cout << endl;
	
	Loan l(principal, interest, instalments);
	l.displaySchedule();
	
	return 0;
}
