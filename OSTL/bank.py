class Bank:
	def __init__(self):
		op = 0
		self.accounts = dict()
		self.currentAccount = None
		while not op == 6:
			print("\nWelcome to pyBank")
			if self.currentAccount != None:
				print("Account No: %s"%self.currentAccount.accountNo)
			print("1. Create an account")
			print("2. Switch account")
			print("3. Withdraw Amount")
			print("4. Deposit Amount")
			print("5. Check Account Status\n")
			print("6. Exit Terminal")
			op = int(input("> "))
			if op == 1:
				self.createAccount()
			elif op == 2:
				self.switchAccount()
			elif op == 3:
				amount = int(input("Withdrawal Amount > "))
				if amount > 0:
					self.currentAccount.withdrawAmount(amount)
			elif op == 4:
				amount = int(input("Deposit Amount > "))
				self.currentAccount.depositAmount(amount)
			elif op == 5:
				self.currentAccount.showAccountDetails()
			elif op == 6:
				print("Have a Good Day")
				break
			else:
				print("\nInvalid Choice\n")


	def createAccount(self):
		actype = int(input("Account Type (Savings 0 / Current 1) > "))
		acno = input("Account No > ")
		if actype == 0:
			bal = int(input("Balance (Minimum 3000) > "))
			while bal < 3000:
				print("\nPlease deposit a higher amount\n")
				bal = int(input("Balance (Minimum 3000) > "))
			self.currentAccount = SavingsAccount(acno, bal)
		elif actype == 1:
			bal = int(input("Balance (Minimum 1000) > "))
			while bal < 1000:
				print("\nPlease deposit a higher amount\n")
				bal = int(input("Balance (Minimum 1000) > "))
			self.currentAccount = CurrentAccount(acno, bal)
		else:
			print("Invalid Account type. Aborting\n")
			return

		self.accounts[acno] = self.currentAccount
		print("Account Created Successfully\n")

	def switchAccount(self):
		acno = input("Specify the Account No > ")
		if acno in self.accounts.keys():
			self.currentAccount = self.accounts[acno]
		print("Switched to account %s"%acno)

	def getCustomerCount():
		return count

class Account():

	def __init__(self, accountNo, initBalance):
		self.accountNo = accountNo
		self.balance = initBalance

	def showAccountDetails(self):
		print("Account No > %s"%self.accountNo)
		print("Balance    > %d"%self.balance)

	def withdrawAmount(self, amount):
		pass

	def depositAmount(self, amount):
		print("Account %s:\nDepositing Rs.%d"%(self.accountNo, amount))
		self.balance += amount

class SavingsAccount(Account):
	def __init__(self, accountNo, initBalance):
		super().__init__(accountNo, initBalance)
		self.interest = 5
		self.limit = 3000
		self.withdrawalLimit = 10

	def showAccountDetails(self):
		print("\nSavings Account")
		super().showAccountDetails()
		if self.balance < self.limit:
			print("\nWARNING: Balance lower than the %d Limit\nDeposit Immediately\n"%self.limit)

	def withdrawAmount(self, amount):
		interestAmount = self.balance * self.interest / 100
		if self.balance > amount + interestAmount:
			print("Account %s:\nWithdrawing Rs.%d"%(self.accountNo, amount))
			self.balance -= amount + interestAmount
			print("\nWithdrawal Successful")
			print("5pc Interest = %d"%interestAmount)
			print("Remaining Balance = Rs. %d"%(self.balance))
			if self.balance < self.limit:
	                        print("\nWARNING: Balance lower than the %d Limit\nDeposit Immediately\n"%self.limit)
			self.withdrawalLimit -= 1
			print("%d Transactions remaining\n"%self.withdrawalLimit)

class CurrentAccount(Account):
	def __init__(self, accountNo, initBalance):
		super().__init__(accountNo, initBalance)
		self.interest = 0
		self.limit = 1000

	def showAccountDetails(self):
		print("\nCurrent Account")
		super().showAccountDetails()
		if self.balance < self.limit:
			print("WARNING: Balance lower than the %d Limit\nDeposit Immediately\n"%self.limit)

	def withdrawAmount(self, amount):
		if self.balance > amount:
			print("Account %s:\nWithdrawing Rs.%d"%(self.accountNo, amount))
			self.balance -= amount
			print("Transaction Successful")
			print("Remaining Balance = Rs. %d\n"%(self.balance))
			if self.balance < self.limit:
	                        print("\nWARNING: Balance lower than the %d Limit\nDeposit Immediately\n"%self.limit)

pyBank = Bank()

