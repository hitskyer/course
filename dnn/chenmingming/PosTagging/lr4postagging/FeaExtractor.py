import sys
# from pandas import DataFrame


class FeaExtractor:
    def __init__(self, fig_file=None, fnumber=1024):
        self.__feaKeyList = None
        if fig_file != None:
            self.__feaKeyList = []
            self.__setFeaKeyList(fig_file, fnumber, self.__feaKeyList)

    def getFeaKeyList(self, feaKeyList):
        if self.__feaKeyList == None:
            sys.stderr.write("FeaExtractor::getFeaKeyList(..) failed.\n")
            sys.exit(-1)
        for fkey in self.__feaKeyList:
            feaKeyList.append(fkey)

    # def getFeaDataFrame(self, wps):
    #     tmpDict = {}
    #     for windx in range(len(wps)):
    #         feaList = []
    #         self.getFeaList(wps, windx, feaList)
    #         for findx in range(len(feaList)):
    #             mykey = self.__feaKeyList[findx]
    #             myval = feaList[findx]
    #             if mykey not in tmpDict:
    #                 tmpDict[mykey] = []
    #             tmpDict[mykey].append(myval)
    #     df = DataFrame(tmpDict)
    #     return df

    def getFeaList(self, wps, indx, feaList):
        if self.__feaKeyList == None:
            sys.stderr.write("FeaExtractor::getFeaList(....) failed.\n")
            sys.exit(-1)
        feaDict = {}
        self.getFeaDict(wps, indx, feaDict)
        for fea in self.__feaKeyList:
            if fea in feaDict:
                feaList.append("1")
            else:
                feaList.append("0")

    def getFeaDict(self, wps, indx, feaDict):
        word = wps[indx][0]
        # 当前词特征
        cur_word = "cw_%s" % (word)
        feaDict[cur_word] = 1
        # 当前词第一个字符特征
        if word != "":
            cur_word_start_char = "cwsc_%s" % (word[0])
        else:
            cur_word_start_char = "cwsc_"
        feaDict[cur_word_start_char] = 1
        # 当前词最后一个字符特征
        if word != "":
            cur_word_end_char = "cwec_%s" % (word[len(word) - 1])
        else:
            cur_word_end_char = "cwec_"
        feaDict[cur_word_end_char] = 1
        # 前一词特征
        if indx > 0:
            word = wps[indx - 1][0]
        else:
            word = "__start__"
        pre_word = "p1w_%s" % (word)
        feaDict[pre_word] = 1
        # 后一词特征
        if indx + 1 < len(wps):
            word = wps[indx + 1][0]
        else:
            word = "__end__"
        suf_word = "s1w_%s" % (word)
        feaDict[suf_word] = 1

    # 特征可以持续扩充...
    def __setFeaKeyList(self, fig_file, fnumber, feaKeyList):
        fdi = open(fig_file, 'r', encoding='utf-8')
        indx = -1
        for line in fdi:
            indx += 1
            if indx < fnumber:
                fea, ig = line.strip().split()
                feaKeyList.append(fea)
            else:
                break
        fdi.close()
