

import zlib
import struct
def get_hwp_recoard(val):
    b = 0b1111111111
    c = 0b111111111111

    tag_id = (val & b)
    level = ((val >> 10) & b)
    size = (val >> 20) & c

    return tag_id, level, size
    
def get_uint32(buf, off, be=False):
    endian = '<'
    if be:
        endian = '>'

    return struct.unpack(endian + 'L', buf[off:off+4])[0]
    
def scan_hwp_recoard(buf, lenbuf):
    pos = 0
    tagid = 0

    while pos < lenbuf:
        extra_size = 4
        val = get_uint32(buf, pos)
        tagid, level, size = get_hwp_recoard(val)
        #print ('2tag : %02X\tlevel : %02X\tsize : %02X' % (tagid, level, size))

        if size == 0xfff:
            extra_size = 8
            size = get_uint32(buf, pos + 4)

        if tagid == 0x43 and size > 4000:  # PARA_TEXT
            t_buf = buf[pos:pos+size+extra_size]
            d_buf = zlib.compress(t_buf)
            if len(d_buf) / float(len(t_buf)) < 0.02:
                print("1");
                return False, 0x43

        pos += (size + extra_size)

    if pos == lenbuf:
        return True, -1

    return False, tagid
import zlib
if __name__ == '__main__':
    
    with open('D:\\git\\study1\\test2\\BodyText\\Section0', 'rb') as handle:
        mm = handle.read();
    
    data = zlib.decompress( mm , -15)


    val = get_uint32(data, 0)
    tagid, level, size = get_hwp_recoard(val)    
    print ('1tag : %02X\tlevel : %02X\tsize : %02X' % (tagid, level, size))
    if tagid == 0x42 or tagid == 0x10:
        print(len(data))
        ret, tagid = scan_hwp_recoard(data, len(data))
        if ret is False:
            print("g")
 
   