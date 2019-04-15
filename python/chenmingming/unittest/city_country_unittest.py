import unittest
from city_functions import city_country as cc
class citytest(unittest.TestCase):
    def test_city_country(self):
        returnValue = cc("Santiago", "Chile")
        self.assertEqual(returnValue, "Santiago,Chile") #运行结果是否和期待值相等
    def test_city_country_population(self):
        returnValue = cc("Santiago", "Chile", 5000000)
        self.assertEqual(returnValue, "Santiago,Chile - population 5000000")
unittest.main() #运行测试