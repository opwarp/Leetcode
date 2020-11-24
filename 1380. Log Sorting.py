class Solution(object):
    def content(self, log):
        return (' ').join(log.split(' ')[1:])
    def addlog(self, log, logsSorted):
        if logsSorted == []:
            logsSorted.append(log)
        elif self.content(log) > self.content(logsSorted[-1]):
            logsSorted.append(log)
        else:
            for i, orderd in enumerate(logsSorted):
                if self.content(log) < self.content(logsSorted[i]):
                    logsSorted.insert(i, log)
                    break
                if self.content(log) == self.content(logsSorted[i]):
                    if log.split(' ')[0] < logsSorted[i].split(' ')[0]:
                        logsSorted.insert(i, log)
                        break
                    else:
                        while(self.content(log) == self.content(logsSorted[i])):
                            if log.split(' ')[0] > logsSorted[i].split(' ')[0]:
                                i+=1
                                continue
                            break
                        logsSorted.insert(i, log)
                    break
    def reorderLogFiles(self, logs):
        """
        :type logs: List[str]
        :rtype: List[str]
        """
        logsSortedC = []
        logsSortedN = []
        for log in logs:
            arr = log.split(' ')
            if len(arr) < 1 :
                pass
            if len(arr) > 1 :
                if arr[1][0] > "9":
                    self.addlog(log, logsSortedC)
                else:
                    logsSortedN.append(log)
                
        return logsSortedC + logsSortedN