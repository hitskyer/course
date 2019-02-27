def sandwich(*materials):
	print('you want a sandwich with following:')
	for material in materials:
		print(material)

sandwich('potato','apple',"pear")

def build_profile(lastname,firstname,**profiles):
	user_profile = {}
	user_profile['lastname'] = lastname
	user_profile['firstname'] = firstname
	for key, value in profiles.items():
		user_profile[key] = value
	print(id(user_profile))
	return user_profile
cmm = build_profile('chen','mingming',height='178cm')
print('\n',id(cmm))
