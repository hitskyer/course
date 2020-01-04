import sys
pDict = {'apple': {'n': 100, 'v': 30}, 'pear': {'p': 100, 'v': 30}, 'banana': {'v': 200, 'n': 30}}
a = sum(pDict['apple'].values())
print(a)
print(pDict['apple']['n'])
pDict['pear']['p'] = 200
pDict['banana']['v'] = 300
# print(sum(pDict.values()))

word2posDict = {'apple':{ 'n' : 10}}
print(word2posDict['apple']['n'])

staDict={'pos':['pos', 1,2,1], 'pos1':['pos1', 3,2,2], 'pos2':['pos2', 3,2,2]}
print(staDict['pos'][0])
staList = list(staDict.values())
print(staList)
staList.sort(key=lambda infs: (infs[1]), reverse=True)
print(staList)

transDict = {'n': {'v': 10, 'n': 10, 'a': 10}}
num = sum(transDict['n'].values())
print(num)

pnList = [['n', 10], ['v', 20]]
total = sum([num for pos, num in pnList])
print(total)

pList = [['pos1',10], ['pos2', 20]]
print(len(pList))

emitDict = {'pos1':{'word1': 10, 'word2':5}, 'pos2':{'word2': 10}}
wnList = list(emitDict['pos1'].items())
print(wnList)