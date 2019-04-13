def city_country(city, country, population = ''):
    if not population:
        return str(city) + ',' + str(country)
    else:
        return str(city) + ',' + str(country) + " - " + "population " + str(population)