tt = (1, 2, (30, 40))
print(hash(tt))  # 8027212646858338501

t1 = (1, 2, [30, 40])
# hash(t1)  # unhashable type: 'list'

t2 = (1, 2, frozenset([30, 40]))
print(hash(t2))  # 985328935373711578

a = dict(one=1, two=2, three=3)
print(a)
b = {'one': 1, 'two': 2, 'three': 3}
print(b)
c = dict(zip(['one', 'two', 'three'], [1, 2, 3]))
print(c)
d = dict([('two', 2), ('one', 1), ('three', 3)])
print(d)
e = dict({'three': 3, 'one': 1, 'two': 2})
print(e)
print(a == b == c == d == e) # True

DIAL_CODES = [
    (86, 'China'),
    (91, 'India'),
    (1, 'United States'),
    (62, 'Indonesia'),
    (55, 'Brazil'),
    (92, 'Pakistan'),
    (880, 'Bangladesh'),
    (234, 'Nigeria'),
    (7, 'Russia'),
    (81, 'Japan'),
]
country_code = {country: code for code, country in DIAL_CODES}
print(country_code)
# {'China': 86, 'India': 91, 'United States': 1, 'Indonesia': 62, 'Brazil': 55, 'Pakistan': 92, 'Bangladesh': 880, 'Nigeria': 234, 'Russia': 7, 'Japan': 81}

d = {code : country.upper() for country, code in country_code.items() if code < 66}
print(d)

