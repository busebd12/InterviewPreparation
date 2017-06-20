#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <utility>
using namespace std;

class FiringEmployees
{
	public:
		void printEmployeeMap(map<int, pair<vector<int>, int>> EmployeeMap)
		{
			for(auto employee : EmployeeMap)
			{
				int employeeNumber=employee.first;

				vector<int> managedEmployees=employee.second.first;

				if(!managedEmployees.empty())
				{
					cout << "Employee " << employeeNumber << " manages employee(s): " << endl;

					for(auto employeeNumber : managedEmployees)
					{
						cout << employeeNumber << " ";
					}

					cout << endl;

					cout << endl;
				}
				else
				{
					cout << "Employee " << employeeNumber << " does not manage anyone" << endl;

					cout << endl;

					cout << endl;
				}
			}

			cout << endl;
		}

		int fire(vector<int> Managers, vector<int> Salaries, vector<int> Productivities, int N)
		{
			map<int, pair<vector<int>, int>> employeeMap;

			int companyProfitBeforeFiring{};

			for(int employee=0;employee<N;++employee)
			{
				int employeeNumber=employee+1;

				vector<int> managedEmployees;

				int totalEmployeeProfit{};

				pair<vector<int>, int> managedEmployeesAndTotalProfit=make_pair(managedEmployees, totalEmployeeProfit);

				employeeMap.emplace(make_pair(employeeNumber, managedEmployeesAndTotalProfit));
			}

			for(int employee=0;employee<N;++employee)
			{
				int employeeNumber=employee+1;

				if(Managers[employee]!=0)
				{
					int manager=Managers[employee];

					employeeMap[manager].first.emplace_back(employeeNumber);
				}
			}

			for(int employee=0;employee<N;++employee)
			{
				int employeeSalary=Salaries[employee];

				int employeeProductivity=Productivities[employee];

				int employeeProfit=employeeProductivity-employeeSalary;

				int employeeNumber=employee+1;

				employeeMap[employeeNumber].second+=employeeProfit;

				companyProfitBeforeFiring+=employeeProfit;
			}

			for(auto employee=employeeMap.rbegin();employee!=employeeMap.rend();++employee)
			{
				vector<int> managedEmployees=employee->second.first;

				if(!managedEmployees.empty())
				{
					for(auto managedEmployee : managedEmployees)
					{
						int managedEmployeeProfit=employeeMap[managedEmployee].second;

						employee->second.second+=managedEmployeeProfit;
					}
				}
			}

			int maximumCompanyProfit{};

			for(auto employee : employeeMap)
			{
				int currentProfit=companyProfitBeforeFiring;

				currentProfit-=employee.second.second;

				if(currentProfit > maximumCompanyProfit)
				{
					maximumCompanyProfit=currentProfit;
				}
			}

			int nonManagerNegativeProfitEmployees{};

			int nonManagerPositiveProfitEmployees{};

			int nonManagerEmployeesProfit{};

			for(auto employee : employeeMap)
			{
				vector<int> managedEmployees=employee.second.first;

				if(managedEmployees.empty())
				{
					int employeeProfit=employee.second.second;

					if(employeeProfit >= 0)
					{
						nonManagerPositiveProfitEmployees+=employeeProfit;
					}
					else if(employeeProfit < 0)
					{
						nonManagerNegativeProfitEmployees+=employeeProfit;
					}
					else
					{
						nonManagerEmployeesProfit+=employeeProfit;
					}
				}
			}

			nonManagerNegativeProfitEmployees=companyProfitBeforeFiring-nonManagerNegativeProfitEmployees;

			nonManagerPositiveProfitEmployees=companyProfitBeforeFiring-nonManagerPositiveProfitEmployees;

			nonManagerEmployeesProfit=companyProfitBeforeFiring-nonManagerEmployeesProfit;

			if(nonManagerNegativeProfitEmployees > maximumCompanyProfit)
			{
				maximumCompanyProfit=nonManagerNegativeProfitEmployees;
			}

			if(nonManagerPositiveProfitEmployees > maximumCompanyProfit)
			{
				maximumCompanyProfit=nonManagerPositiveProfitEmployees;
			}

			if(nonManagerEmployeesProfit > maximumCompanyProfit)
			{
				maximumCompanyProfit=nonManagerEmployeesProfit;
			}

			return maximumCompanyProfit;
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