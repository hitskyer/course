from restaurant import Restaurant
class IceCreamStand(Restaurant):
    def __init__(self, restaurant_name, cuisine_type):
        super().__init__(restaurant_name, cuisine_type)
        self.flavors = ["strawberry", "chocolate"]
    def showIceCream(self):
        print("we offer the following IceCream: \n")
        for i in self.flavors:
            print(i,"\n")

myIceCream = IceCreamStand("snow of winter","ice cream stand")
myIceCream.open_restaurant()
myIceCream.describe_restaurant()
myIceCream.get_served_number()
myIceCream.increment_number_served(10)
myIceCream.showIceCream()
