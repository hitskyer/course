class User():
	def __init__(self, first_name, last_name, **other_profile):
		self.first_name = first_name
		self.last_name = last_name
		self.user_profile = {}
		self.login_attempts = 0
		for k, v in other_profile.items():
			self.user_profile[k] = v
	def describe_user(self):
		print('the user\'name is '+ self.first_name + ' ' + self.last_name)
		print(self.user_profile)
	def greet_user(self):
		print("hello, " + self.first_name + " " + self.last_name)
	def increment_login_attempts(self):
		self.login_attempts += 1
		print(self.first_name + ' ' + self.last_name + ', you have login ' + str(self.login_attempts) + ' times.')
	def reset_login_attempts(self):
		self.login_attempts = 0
		print('login times has successfully reseted!')
# cmm = User('chen','mingiming',height=178,weight='70kg')
# cmm.describe_user()
# cmm.greet_user()
# for i in range(10):
# 	cmm.increment_login_attempts()
# cmm.reset_login_attempts()