class Solution:
    def minTransfers(self, transactions: List[List[int]]) -> int:
        result=0

        hashmap=dict()

        for (person_giving_money, person_receiving_money, money) in transactions:
            if person_giving_money not in hashmap.keys():
                hashmap[person_giving_money]=0

            #The balance of the person loaning out the money decreases
            #So, they are owed amount==money to bring their balance to zero
            hashmap[person_giving_money]-=money

            if person_receiving_money not in hashmap.keys():
                hashmap[person_receiving_money]=0

            #The balance of the person receiving the money increases
            #So, they have to repay amount==money to bring their balance to zero
            hashmap[person_receiving_money]+=money

        #Only care about non-zero balances
        #Positive == person owes money
        #Negative == person is owed money
        debt_amounts=[balance for balance in hashmap.values() if balance!=0]

        d=len(debt_amounts)

        person=0

        result=self.helper(debt_amounts, d, person)

        return result

    def helper(self, debt_amounts: List[int], d: int, person: int) -> int:
        if person==d:
            return 0

        #If the current person has a zero balance then they are neither owed nor owe money so skip them
        if debt_amounts[person]==0:
            return self.helper(debt_amounts, d, person + 1)

        subproblem_solution=(2**53) - 1

        for other_person in range(person + 1, d):
            person_amount=debt_amounts[person]

            other_person_amount=debt_amounts[other_person]

            balance_product=person_amount * other_person_amount

            #If the balance_product is less than zero, then we have found one person with a negative blanace and another person with a positive balance
            if balance_product < 0:
                #Assume that the other person is owed money and person owes money
                #Person who owes money gives debts_amount[person] amount to the other person in an attempt to settle debt
                debt_amounts[other_person]+=debt_amounts[person]

                #Recursive step
                subproblem_solution=min(subproblem_solution, 1 + self.helper(debt_amounts, d, person + 1))

                #Undo the earlier money transfer so that person "person" and another person can try to same debt settlement transaction
                debt_amounts[other_person]-=debt_amounts[person]

        return subproblem_solution