f=open('e:/cmm/test.txt')
cmm = []
nhl= []
count=1
for each_line in f:
    if(each_line[:6]) != '======':
        (role,line_spoken) = each_line.split(':',1)
        if role == 'cmm':
            cmm.append(line_spoken)
        if role == 'nhl':
            nhl.append(line_spoken)
    else:
        file_name_cmm = 'cmm_'+str(count)+'.txt'
        file_name_nhl = 'nhl_'+str(count)+'.txt'
        cmm_file = open(file_name_cmm,'w')
        nhl_file = open(file_name_nhl,'w')
        cmm_file.writelines(cmm)
        nhl_file.writelines(nhl)
        cmm_file.close()
        nhl_file.close()
        cmm = []
        nhl = []
        count += 1
file_name_cmm = 'cmm_'+str(count)+'.txt'
file_name_nhl = 'nhl_'+str(count)+'.txt'
cmm_file = open(file_name_cmm,'w')
nhl_file = open(file_name_nhl,'w')
cmm_file.writelines(cmm)
nhl_file.writelines(nhl)
cmm_file.close()
nhl_file.close()
f.close()
