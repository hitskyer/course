def make_album(singer, disc_name, nums_of_songs = ''):
	if nums_of_songs:
		return {'singer':singer,'disc_name':disc_name,'nums_of_songs':nums_of_songs}
	else:
		return {'singer':singer,'disc_name':disc_name}
while True:
	print("(enter 'q' at any time to quit)")
	singer = input('enter singer name: ')
	if singer == 'q':
		break
	disc_name = input('enter disc name: ')
	if disc_name == 'q':
		break
	album = make_album(singer,disc_name)
	print(album)
