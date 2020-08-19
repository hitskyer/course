import sys
import pandas
def getStrFeatureKeys(train_file):
	train = pandas.read_csv(train_file)
	jobList = list(set(train['job']))
	jobList.sort()
	jobList = ['job_'+job for job in jobList]
	maritalList = list(set(train['marital']))
	maritalList.sort()
	maritalList = ['marital_'+marital for marital in maritalList]
	educationList = list(set(train['education']))
	educationList.sort()
	educationList = ['education_'+education for education in educationList]
	contactList = list(set(train['contact']))
	contactList.sort()
	contactList = ['contact_'+contact for contact in contactList]
	monthList = list(set(train['month']))
	monthList.sort()
	monthList = ['month_'+month for month in monthList]
	poutcomeList = list(set(train['poutcome']))
	poutcomeList.sort()
	poutcomeList = ['poutcome_'+poutcome for poutcome in poutcomeList]
	return jobList, maritalList, educationList, contactList, monthList, poutcomeList
def getOnehotFea(feaList, prefix, suffix):
	mykey = "%s_%s" % (prefix, suffix)
	olst = []
	for fea in feaList:
		if fea == mykey:
			olst.append('1')
		else:
			olst.append('0')
	return olst
def bool2int(fea):
	return '1' if fea == 'yes' else '0'
def myformat(infile, sfeaSet, jobList, maritalList, educationList, contactList, monthList, poutcomeList, outfile):
	fdi = open(infile)
	fdo = open(outfile, "w")
	for line in fdi:
		infs = line.strip().split(",")
		try:
			ID,age,job,marital,education,default,balance,housing,loan,contact,day,month,duration,campaign,pdays,previous,poutcome,y = infs
		except:
			ID,age,job,marital,education,default,balance,housing,loan,contact,day,month,duration,campaign,pdays,previous,poutcome = infs
			y = '-1'
		if infs[0] == "ID":
			y = 'y'
			olst = [ID, age] + jobList + maritalList + educationList + [default, balance, housing, loan] + contactList + [day] + monthList + [duration, campaign, pdays, previous] + poutcomeList + [y]
		else:
			olst = [ID, age] + getOnehotFea(jobList, "job", job) + getOnehotFea(maritalList, 'marital', marital) + getOnehotFea(educationList, 'education', education) + [bool2int(default), balance, bool2int(housing), bool2int(loan)] + getOnehotFea(contactList, 'contact', contact) + [day] + getOnehotFea(monthList, 'month', month) + [duration, campaign, pdays, previous] + getOnehotFea(poutcomeList, 'poutcome', poutcome) + [y]
		fdo.write(",".join(olst)+"\n")
	fdo.close()
	fdi.close()
try:
	train_file = sys.argv[1]
	infile     = sys.argv[2]
	outfile    = sys.argv[3]
except:
	sys.stderr.write("\tpython "+sys.argv[0]+" train_file infile outfile\n")
	sys.exit(-1)
sfeaSet = {'job', 'marital', 'education', 'contact', 'month', 'poutcome'}
jobList, maritalList, educationList, contactList, monthList, poutcomeList = getStrFeatureKeys(train_file)
myformat(infile, sfeaSet, jobList, maritalList, educationList, contactList, monthList, poutcomeList, outfile)
