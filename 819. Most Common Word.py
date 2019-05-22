# 819. Most Common Word.py
class Solution(object):
    def mostCommonWord(self, paragraph, banned):
        words = re.split(r'\W+', paragraph)
        # words = paragraph.split(' ')
        print words
        counts = {}
        for i,word in enumerate(words):
            words[i] = words[i].lower()
           
        for word in words:
            if word in counts.keys():
                counts[word]  = counts[word] + 1
            else:
                counts[word] = 1
            if word == '':
                counts[''] = 0
        res = '' 
        most = 0
        print counts
        for key in counts:
            if counts[key] > most and key not in banned:
                most = counts[key]
                res = key
        return res      
        """
        :type paragraph: str
        :type banned: List[str]
        :rtype: str
        """
        