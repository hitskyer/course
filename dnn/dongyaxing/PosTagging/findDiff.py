def outDifferent(infile, predict_file, outfile):
    inf_1 = open(infile)
    inf_2 = open(predict_file)
    out_f = open(outfile, "w")
    line1 = [i for i in inf_1]  # 一行一行的内容
    line2 = [j for j in inf_2]
    err_cnt = 0
    right_cnt = 0
    for x in zip(line1, line2):  # 均取出一行，进行分割
        infs_1 = x[0].strip().split()
        infs_2 = x[1].strip().split()
        wpList_1 = [s.split("/") for s in infs_1]
        wpList_2 = [s.split("/") for s in infs_2]
        results = []
        if(len(wpList_1) != len(wpList_2)):
            continue
        else:
            for i in zip(wpList_1, wpList_2):
                if (i[0][1] != i[1][1]):  # pos 不同时
                    results.append(i[0][0] + '/' + i[0][1] + "-->" + i[1][1])
                    err_cnt += 1
                else:  # pos相同时
                    results.append(i[0][0] + '/' + i[0][1])
                    right_cnt += 1
            out_f.write(" ".join(results) + "\n")
    out_f.write("err_cnt = " + str(err_cnt) + "\n")
    out_f.write("right_cnt = " + str(right_cnt) + "\n")
    out_f.write(", total_cnt= " + str(err_cnt+right_cnt) + "\n")
    out_f.close()
    inf_1.close()
    inf_2.close()


import sys

try:
    infile = sys.argv[1]
    predict_file = sys.argv[2]
    outfile = sys.argv[3]
except:
    sys.stderr.write("\tpython " + sys.argv[0] + "infile predict_file outfile\n")
    sys.exit(-1)

outDifferent(infile, predict_file, outfile)
