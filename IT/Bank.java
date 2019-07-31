//import java.util.*;
import java.util.List;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

class BankAccount {
	int AccountNumber;
	float Balance;

	BankAccount(int AccountNumber, float Balance) {
		this.AccountNumber = AccountNumber;
		this.Balance = Balance;
	}

	float deposit(float x) {
		System.out.println("Deposited a sum of " + x);
		Balance += x;
		return Balance;
	}

	float withdraw(float x) {
		System.out.println("Withdrew a sum of " + x);
		Balance -= x;
		return Balance;
	}

	int getAccountNo() {
		return AccountNumber;
	}

	float getBalance() {
		return Balance;
	}

	float deductTax() {
		Balance -= (0.2 * Balance);
		return Balance;
	}

	public String toString() {
		return "AccountNumber: " + this.AccountNumber + ", " + "Balance: " + this.Balance;
	}
}

class Bank {
	String name;
	ArrayList<BankAccount> accounts;

	Bank(String name) {
		this.name = name;
		accounts = new ArrayList<BankAccount>();
	}

	void AddAccount(BankAccount account) {
		accounts.add(account);
	}

	float totalBalance() {
		float sum = 0;
		for (int i = 0; i < accounts.size(); i++) {
			sum += accounts.get(i).getBalance();
		}
		return sum;	
	}

	int[] getMinMaxBalanceAccountNumber() {
		List<BankAccount> acc = accounts;
		Collections.sort(acc, new Comparator<BankAccount>(){
			@Override
			public int compare(BankAccount b1, BankAccount b2) {
				return (int)b1.getBalance()-(int)b2.getBalance();
			}
		});

		int[] minmax = {accounts.get(0).AccountNumber, accounts.get(accounts.size()-1).AccountNumber};
		return minmax;
	}

	BankAccount findAccount(int acnum) {
		for (BankAccount b : accounts) {
			if(b.AccountNumber == acnum) {
				return b;
			}	
		}
		return null;
	}

	int numAccountsWithBalance(float balance) {
		int count = 0;
		for (BankAccount b : accounts) {
			if (b.getBalance() >= balance) count++;
		}
		return count;
	}

	public static void main(String[] args) {
		Bank bank = new Bank("yes bank");
		
		BankAccount account1 = new BankAccount(123456789, 2000);
		BankAccount account2 = new BankAccount(987654321, 10000);
		BankAccount account3 = new BankAccount(101019181, 102);
		BankAccount account4 = new BankAccount(786871222, 10023);
		bank.AddAccount(account1);
		bank.AddAccount(account2);
		bank.AddAccount(account3);
		bank.AddAccount(account4);

		System.out.println("All accounts:\n" + bank.accounts + "\n");
		System.out.println("Total balance in " + bank.name + ": " +  bank.totalBalance() + "\n");

		int[] minmax = bank.getMinMaxBalanceAccountNumber();
		System.out.println("Minimum balance account number: " + minmax[0]);
		System.out.println("Maximum balance account number: " + minmax[1] + "\n");

		int acnum = 101019181;
		if(bank.findAccount(acnum) != null) {
			System.out.println("Found account with account number: " + acnum + "\n");
		} else System.out.println("No account with account number " + acnum + " exists!\n");

		acnum = 101010101;
		if(bank.findAccount(acnum) != null) {
			System.out.println("Found account with account number: " + acnum + "\n");
		} else System.out.println("No account with account number " + acnum + " exists!\n");

		int balance = 1000;
		System.out.println("Number of accounts with atleast " + balance + " " + bank.numAccountsWithBalance(balance) + "\n");
	}
}
