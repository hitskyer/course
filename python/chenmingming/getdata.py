import json as js
datafile = 'data.txt'
resultfile = 'result.txt'
result = open(resultfile,'w',encoding='utf-8')
with open(datafile,'r',encoding='utf-8') as file:
    data = js.load(file)
for data_i in data:
    strline = ''
    for v in data_i:
            strline = strline + str(v) + '    '
    result.write(strline+'\n')
result.close()

################

# import json as js
# datafile = 'data1.txt'
# resultfile = 'result.txt'
# result = open(resultfile,'w',encoding='utf-8')
# with open(datafile,'r',encoding='utf-8') as file:
#     data = js.load(file)
# for data_i in data:
#     for k,v in data_i.items():
#         if k == 'x':
#             strline = v[0:10] + '   '
#         if k == 'y':
#             strline = strline + str(v)
#     result.write(strline+'\n')
# result.close()