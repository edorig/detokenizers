#/usr/bin/sed -f 
# This sed script converts ATASCII accented characters to UTF-8
# Be aware that 8-bit Atari can switch from the font with accented
# characters to the font with graphical characters with a POKE 756,224.
# I am not aware of an UTF-8 encoding for such graphical characters.
# Some of them are similar to the graphical characters of xterm
# but the match is not perfect.
# Finally, character redefinition is possible on the 8-bit Ataris with some
# more pokes, so character appearance may have been quite different when the 
# program was running.

s/\d001/ù/g
s/\d002/ñ/g
s/\d003/É/g
s/\d004/ç/g
s/\d005/ô/g
s/\d006/ð/g
s/\d007/i/g 
s/\d008/£/g
s/\d009/ï/g
s/\d010/ä/g
s/\d012/Ö/g
s/\d013/'u/g
s/\d014/'o/g
s/\d015/ö/g
s/\d016/Ü/g
s/\d017/â/g
s/\d018/û/g
s/\d019/î/g
s/\d020/é/g
s/\d021/è/g
s/\d022/ñ/g
s/\d023/ê/g 
s/\d024/å/g
s/\d025/à/g
s/\d026/Å/g 