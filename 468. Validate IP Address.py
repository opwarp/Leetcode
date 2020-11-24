# 468. Validate IP Address.py
class Solution:
    def checkIPv4(self, ip):
        secs = ip.split('.')
        if len(secs) != 4:
            return False
        for sec in secs:
            if len(sec) == 0:
                return False
            try:
                n = int(sec)
            except ValueError:
                return False
            if n == 0 and sec != '0':
                return False
            if n !=0 and sec[0] == '0':
                return False
            if n < 0 or n > 255:
                return False
        return True
    def checkIPv6(self, ip):
        secs = ip.split(':')
        if len(secs) != 8:
            return False
        for sec in secs:
            if len(sec) > 4 or len(sec) == 0:
                return False
            try:
                n = int(sec, 16)
            except ValueError:
                return False
            if n == 0 and sec[0] != '0':
                return False
            if n < int('0000', 16) or n > int('ffff', 16):
                return False
        return True
    def validIPAddress(self, IP: str) -> str:
        if self.checkIPv4(IP):
            return 'IPv4'
        elif self.checkIPv6(IP):
            return 'IPv6'
        else:
            return 'Neither'