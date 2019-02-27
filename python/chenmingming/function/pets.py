def describe_pet(animal_type = 'dog', pet_name = 'pets'):
	print('\nI have a ',animal_type,'.')
	print("My ", animal_type,"'s name is "+pet_name.title(),'.')
describe_pet('hamster',"Mary")
describe_pet(pet_name = 'Joy',animal_type = "hamster")
describe_pet('hamster')
describe_pet()