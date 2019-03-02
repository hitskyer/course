def car(manufacturer, style, **kv):
	car_info = {}
	car_info['manufacturer'] = manufacturer
	car_info['style'] = style
	for k, v in kv.items():
		car_info[k] = v
	return car_info
