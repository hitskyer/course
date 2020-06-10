import os
print(os.getcwd())
import openpyxl
wb = openpyxl.load_workbook('workbook.xlsx')
print(type(wb))
print(wb.sheetnames)

sheet = wb['Sheet1']
print(type(sheet))
print(sheet.title)

print(wb.active)

print(sheet['A2'].value)
