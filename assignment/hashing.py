#!/usr/bin/python
"""Calculate and manipulate CRC32.
http://en.wikipedia.org/wiki/Cyclic_redundancy_check
-- StalkR
"""
import struct
import sys

# Polynoms in reversed notation
POLYNOMS = {
    'CRC-32-IEEE': 0xedb88320,  # 802.3
    'CRC-32C': 0x82F63B78,  # Castagnoli
    'CRC-32K': 0xEB31D82E,  # Koopman
    'CRC-32Q': 0xD5828281,
}


class Error(Exception):
    pass


class CRC32(object):
    """A class to calculate and manipulate CRC32.
  
  Use one instance per type of polynom you want to use.
  Use calc() to calculate a crc32.
  Use forge() to forge crc32 by adding 4 bytes anywhere.
  """

    def __init__(self, type="CRC-32-IEEE"):
        if type not in POLYNOMS:
            raise Error("Unknown polynom. %s" % type)
        self.polynom = POLYNOMS[type]
        self.table, self.reverse = [0] * 256, [0] * 256
        self._build_tables()

    def _build_tables(self):
        for i in range(256):
            fwd = i
            rev = i << 24
            for j in range(8, 0, -1):
                # build normal table
                if (fwd & 1) == 1:
                    fwd = (fwd >> 1) ^ self.polynom
                else:
                    fwd >>= 1
                self.table[i] = fwd & 0xffffffff
                # build reverse table =)
                if rev & 0x80000000 == 0x80000000:
                    rev = ((rev ^ self.polynom) << 1) | 1
                else:
                    rev <<= 1
                rev &= 0xffffffff
                self.reverse[i] = rev

    def calc(self, s):
        """Calculate crc32 of a string.
    Same crc32 as in (binascii.crc32)&0xffffffff.
    """
        crc = 0xffffffff
        for c in s:
            crc = (crc >> 8) ^ self.table[(crc ^ ord(c)) & 0xff]
        return crc ^ 0xffffffff


if __name__ == '__main__':
    if len(sys.argv) > 1:
        arg = sys.argv[1]
    else:
        arg = "message"

    # CRC32 with default polynom
    crc = CRC32().calc(arg)
    print("0x%08x" % (crc))
