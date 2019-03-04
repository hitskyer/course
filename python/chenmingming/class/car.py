class Car():
	def __init__(self,make,model,year):
		self.make = make
		self.model = model
		self.year = year
		self.odometer_reading = 0
	def get_descriptive_name(self):
		long_name = str(self.year) + ' ' + self.make + ' ' + self.model
		return long_name.title()
	def read_odometer(self):
		print('This car has ' + str(self.odometer_reading) + ' miles on it.')
	def update_odometer(self,mileage):
		if mileage >= self.odometer_reading:
			self.odometer_reading = mileage
		else:
			print('You can not roll back an odometer！')
	def increment_odometer(self, miles):
		if miles < 0:
			print('You can cheat me！ driving miles < 0')
		else:
			print('driving this car ' + str(miles) + 'miles')
			self.odometer_reading += miles
	def fill_gas_tank(self):
		print('This car need fill gas !')
my_new_car = Car('audi','a4',2019)
print(my_new_car.get_descriptive_name())
my_new_car.update_odometer(2300)
my_new_car.read_odometer()
my_new_car.increment_odometer(99)
my_new_car.read_odometer()