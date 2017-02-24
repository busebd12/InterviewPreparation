#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstdlib>
#include <utility>
using namespace std;

class FiringEmployees
{
	private:
		multimap<int, pair<int, int>> employeeMap;

	public:
		int fire(vector<int> Managers, vector<int> Salaries, vector<int> Productivities, int N)
		{
			int companyProfitWithoutFiringAnyone{};

			for(int employee=0;employee<N;++employee)
			{
				int employeeNumber=employee+1;

				int employeeManager=Managers[employee];

				int employeeSalary=Salaries[employee];

				int employeeProductivity=Productivities[employee];

				int employeeProfit=employeeProductivity-employeeSalary;

				cout << "Profit for employee " << employeeNumber << ": " << employeeProfit << endl;

				cout << endl;

				pair<int, int> employeeNumberAndProfit=make_pair(employeeNumber, employeeProfit);

				employeeMap.emplace(make_pair(employeeManager, employeeNumberAndProfit));

				companyProfitWithoutFiringAnyone+=employeeProfit;
			}

			int maximumCompanyProfit{};

			for(const auto & employee : employeeMap)
			{
				int profit=companyProfitWithoutFiringAnyone;

				cout << "Companies starting profit: " << companyProfitWithoutFiringAnyone << endl;

				cout << endl;

				int employeeNumber=employee.second.first;

				cout << "Going to check to see if employee " << employeeNumber << " manages anyone..." << endl;

				cout << endl;

				int employeeProfit=employee.second.second;

				profit-=employeeProfit;

				profit=getCompanyProfit(employeeNumber, profit);

				cout << "Profit gained from firing employee " << employeeNumber << " --> " << profit << endl;

				cout << endl;

				if(profit > maximumCompanyProfit)
				{
					maximumCompanyProfit=profit;
				}
			}

			if(companyProfitWithoutFiringAnyone > maximumCompanyProfit)
			{
				maximumCompanyProfit=companyProfitWithoutFiringAnyone;
			}

			int companyProfitFromFiringNonManagerEmployees{};

			for(auto employee : employeeMap)
			{
				int employeeNumber=employee.second.first;

				cout << "Checking to see if employee: " << employeeNumber << " manages anyone..." << endl;

				cout << endl;

				auto managedEmployees=employeeMap.equal_range(employeeNumber);

				if(managedEmployees.first==managedEmployees.second)
				{
					cout << "Employee " << employeeNumber << " does not manage anyone" << endl;

					cout << endl;

					int employeeProfit=employee.second.second;

					if(employeeProfit < 0)
					{
						cout << "Employee " << employeeNumber << "'s profit: " << employeeProfit << endl;

						cout << endl;

						companyProfitFromFiringNonManagerEmployees+=employeeProfit;

						cout << "companyProfitFromFiringNonManagerEmployees: " << companyProfitFromFiringNonManagerEmployees << endl;

						cout << endl;
					}
				}
			}

			companyProfitFromFiringNonManagerEmployees=companyProfitWithoutFiringAnyone-companyProfitFromFiringNonManagerEmployees;

			if(companyProfitFromFiringNonManagerEmployees > maximumCompanyProfit)
			{
				maximumCompanyProfit=companyProfitFromFiringNonManagerEmployees;
			}

			return maximumCompanyProfit;
		}

		int getCompanyProfit(int EmployeeNumber, int Profit)
		{
			auto managedEmployees=employeeMap.equal_range(EmployeeNumber);

			if(managedEmployees.first==managedEmployees.second)
			{
				cout << "Employee " << EmployeeNumber << " doesn't manage anyone" << endl;

				cout << endl;

				return Profit;
			}

			cout << "Employee " << EmployeeNumber << " manages the following employees: " << endl;

			cout << endl;

			for(auto employee=managedEmployees.first;employee!=managedEmployees.second;++employee)
			{
				int employeeProfit=employee->second.second;

				Profit-=employeeProfit;

				int employeeNumber=employee->second.first;

				cout << "Employee " << employeeNumber << endl;

				cout << endl;

				return getCompanyProfit(employeeNumber, Profit);
			}

			return Profit;
		}
};

int main(int argc, char** argv)
{
	FiringEmployees F;


	vector<int> managers={0, 0, 0};

	vector<int> salaries={1, 2, 3};

	vector<int> productivities={3, 2, 1};

	int n=3;

	//returns 2



	
	vector<int> managers={0, 1, 2, 3};

	vector<int> salaries={4, 3, 2, 1};

	vector<int> productivities={2, 3, 4, 5};

	int n=4;

	//returns 4
	


	
	vector<int> managers={0, 1};

	vector<int> salaries={1, 10};

	vector<int> productivities={5, 5};

	int n=2;

	//returns 4
	


	
	vector<int> managers={0, 1, 2, 1, 2, 3, 4, 2, 3};

	vector<int> salaries={5, 3, 6, 8, 4, 2, 4, 6, 7};

	vector<int> productivities={2, 5, 7, 8, 5, 3, 5, 7, 9};

	int n=9;

	//returns 6



	
	vector<int> managers={0, 0, 1, 1, 2, 2};

	vector<int> salaries={1, 1, 1, 2, 2, 2};

	vector<int> productivities={2, 2, 2, 1, 1, 1};

	int n=6;

	//Returns: 3

	cout << F.fire(managers, salaries, productivities, n) << endl;
}