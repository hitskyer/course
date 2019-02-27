def show_magic(magician):
	length = len(magician)
	while length:
		magic_name = 'magician '+ magician.pop()
		magician.insert(0,magic_name)
		length -= 1
	print(magician)	
	make_great(magician)

def make_great(magician):
	length = len(magician)
	while length:
		great_magic_name = 'the Great '+ magician.pop()
		magician.insert(0,great_magic_name)
		length -= 1
	print(magician)

magician = ['kobe','jordan','curry']
show_magic(magician[:])
print(magician)
