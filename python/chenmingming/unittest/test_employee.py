from employee import Employee
import unittest

class test_employee(unittest.TestCase):
    def setUp(self) -> None:
        self.employee_default = Employee('michael', 'ming', 5000)
        self.employee_custom = Employee('kobe', 'bryant', 5000)
    def test_dafault(self):
        self.employee_default.give_raise()
        self.assertEqual(10000, self.employee_default.salary)
    def test_custom(self):
        self.employee_custom.give_raise(1000)
        self.assertEqual(6000, self.employee_custom.salary)

unittest.main()