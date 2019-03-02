class Restaurant():
	def __init__(self, restaurant_name, cuisine_type):
		self.restaurant_name = restaurant_name 
		self.cuisine_type = cuisine_type
		self.number_served = 0
	def describe_restaurant(self):
		print('this restaurant\'name is '+ self.restaurant_name.title())
		print('and it is a '+self.cuisine_type+' restaurant.')
	def open_restaurant(self):
		print(self.restaurant_name.title() + ' is opening.')
	def get_served_number(self):
		print('It had served '+ str(self.number_served) + ' peoples.')
	def set_number_served(self, number_served):
		if self.number_served <= number_served:
			self.number_served = number_served
			self.get_served_number()
		else:
			print('You can not roll back number!')
			self.get_served_number()
	def increment_number_served(self, incr_number):
		if incr_number < 0:
			print('You cannot cheat me ! number < 0')
		else:
			self.number_served += incr_number
			self.get_served_number()
restaurant = Restaurant('restaurant of lake & moonlight', 'chinese food')
print(restaurant.restaurant_name)
print(restaurant.cuisine_type)
restaurant.describe_restaurant()
restaurant.open_restaurant()
restaurant.set_number_served(10)
restaurant.set_number_served(5)
restaurant.increment_number_served(-1)
restaurant.increment_number_served(100)
