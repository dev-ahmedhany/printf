#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <limits.h>
#include "main.h"

int print_to_file(char *filename,void (*func)());
int compare(char *filename1, char *filename2);

void c0() {_printf("Let's print a simple sentence.\n");}
void e0() { printf("Let's print a simple sentence.\n");}
void c1() {_printf("%c", 'S');}
void e1() { printf("%c", 'S');}
void c2() {_printf("A char inside a sentence: %c. Did it work?\n", 'F');}
void e2() { printf("A char inside a sentence: %c. Did it work?\n", 'F');}
void c3() {_printf("Let'see if the cast is correctly done: %c. Did it work?\n", 48);}
void e3() { printf("Let'see if the cast is correctly done: %c. Did it work?\n", 48);}
void c4() {_printf("%s", "This sentence is retrieved from va_args!\n");}
void e4() { printf("%s", "This sentence is retrieved from va_args!\n");}
void c5() {_printf("Complete the sentence: You %s nothing, Jon Snow.\n", "know");}
void e5() { printf("Complete the sentence: You %s nothing, Jon Snow.\n", "know");}
void c6() {_printf("Complete the sentence: You %s nothing, Jon Snow.\n", (char *)0);}
void e6() { printf("Complete the sentence: You %s nothing, Jon Snow.\n", (char *)0);}
void c7() {_printf("%c%cth %s%s a%cg%s: Y%sou %s no%ching%s Snow.%c", 'W', 'i', "some ", "more", 'r', "s", "", "know", 't', ", Jon", '\n');}
void e7() { printf("%c%cth %s%s a%cg%s: Y%sou %s no%ching%s Snow.%c", 'W', 'i', "some ", "more", 'r', "s", "", "know", 't', ", Jon", '\n');}
void c8() {_printf("%%");}
void e8() { printf("%%");}
void c9() {_printf("Should print a single percent sign: %%\n");}
void e9() { printf("Should print a single percent sign: %%\n");}
void c10() {_printf("%s%c%c%c%s%%%s%c", "Loading ", '.', '.', '.', " 99", " Please wait", '\n');}
void e10() { printf("%s%c%c%c%s%%%s%c", "Loading ", '.', '.', '.', " 99", " Please wait", '\n');}
void c11() {_printf("css%ccs%scscscs", 'T', "Test");}
void e11() { printf("css%ccs%scscscs", 'T', "Test");}
void c12() {_printf("%c", '\0');}
void e12() { printf("%c", '\0');}
void c13() {_printf("%");}
void e13() { printf("");}

void c14() {_printf("%d", 1024);}
void e14() { printf("%d", 1024);}
void c15() {_printf("%d", -1024);}
void e15() { printf("%d", -1024);}
void c16() {_printf("%d", 0);}
void e16() { printf("%d", 0);}
void c17() {_printf("%d", INT_MAX);}
void e17() { printf("%d", INT_MAX);}
void c18() {_printf("%d", INT_MIN);}
void e18() { printf("%d", INT_MIN);}
void c19() {_printf("%d", INT_MAX + 1024); }
void e19() { printf("%d", INT_MAX + 1024); }
void c20() {_printf("%d", INT_MIN - 1024); }
void e20() { printf("%d", INT_MIN - 1024); }
void c21() {_printf("There is %d bytes in %d KB\n", 1024, 1);}
void e21() { printf("There is %d bytes in %d KB\n", 1024, 1);}
void c22() {_printf("%d - %d = %d\n", 1024, 2048, -1024);}
void e22() { printf("%d - %d = %d\n", 1024, 2048, -1024);}
void c23() {_printf("%d + %d = %d\n", INT_MIN, INT_MAX, (INT_MIN + INT_MAX));}
void e23() { printf("%d + %d = %d\n", INT_MIN, INT_MAX, (INT_MIN + INT_MAX));}
void c24() {_printf("%i", 1024);}
void e24() { printf("%i", 1024);}
void c25() {_printf("%i", -1024);}
void e25() { printf("%i", -1024);}
void c26() {_printf("%i", 0);}
void e26() { printf("%i", 0);}
void c27() {_printf("%i", INT_MAX);}
void e27() { printf("%i", INT_MAX);}
void c28() {_printf("%i", INT_MIN);}
void e28() { printf("%i", INT_MIN);}
void c29() {_printf("%i", INT_MAX + 1024); }
void e29() { printf("%i", INT_MAX + 1024); }
void c30() {_printf("%i", INT_MIN - 1024); }
void e30() { printf("%i", INT_MIN - 1024); }
void c31() {_printf("There is %i bytes in %i KB\n", 1024, 1);}
void e31() { printf("There is %i bytes in %i KB\n", 1024, 1);}
void c32() {_printf("%i - %i = %i\n", 1024, 2048, -1024);}
void e32() { printf("%i - %i = %i\n", 1024, 2048, -1024);}
void c33() {_printf("%i + %i = %i\n", INT_MIN, INT_MAX, (INT_MIN + INT_MAX));}
void e33() { printf("%i + %i = %i\n", INT_MIN, INT_MAX, (INT_MIN + INT_MAX));}
void c34() {_printf("%d == %i\n", 1024, 1024);}
void e34() { printf("%d == %i\n", 1024, 1024);}
void c35() {_printf("iddi%diddiiddi\n", 1024);}
void e35() { printf("iddi%diddiiddi\n", 1024);}
void c36() {_printf("%d", 10000);}
void e36() { printf("%d", 10000);}
void c37() {_printf("%i", 10000);}
void e37() { printf("%i", 10000);}
void c38() {_printf("%b", 1024);}
void e38() { printf("10000000000");}
void c39() {_printf("%b", -1024);}
void e39() { printf("11111111111111111111110000000000");}
void c40() {_printf("%b", 0);}
void e40() { printf("0");}
void c41() {_printf("%b", UINT_MAX);}
void e41() { printf("11111111111111111111111111111111");}
void c42() {_printf("%b", UINT_MAX + 1024); }
void e42() { printf("1111111111"); }
void c43() {_printf("There is %b bytes in %b KB\n", 1024, 1);}
void e43() { printf("There is 10000000000 bytes in 1 KB\n");}
void c44() {_printf("%b - %b = %b\n", 2048, 1024, 1024);}
void e44() { printf("100000000000 - 10000000000 = 10000000000\n");}
void c45() {_printf("%b + %b = %b\n", INT_MAX, INT_MAX, INT_MAX * 2); }
void e45() { printf("1111111111111111111111111111111 + 1111111111111111111111111111111 = 11111111111111111111111111111110\n"); }
void c46() {_printf("%u", 1024);}
void e46() { printf("%u", 1024);}
void c47() {_printf("%u", -1024);}
void e47() { printf("%u", -1024);}
void c48() {_printf("%u", 0);}
void e48() { printf("%u", 0);}
void c49() {_printf("%u", UINT_MAX);}
void e49() { printf("%u", UINT_MAX);}
void c50() {_printf("%u", UINT_MAX + 1024); }
void e50() { printf("%u", UINT_MAX + 1024); }
void c51() {_printf("There is %u bytes in %u KB\n", 1024, 1);}
void e51() { printf("There is %u bytes in %u KB\n", 1024, 1);}
void c52() {_printf("%u - %u = %u\n", 2048, 1024, 1024);}
void e52() { printf("%u - %u = %u\n", 2048, 1024, 1024);}
void c53() {_printf("%u + %u = %u\n", INT_MAX, INT_MAX, INT_MAX * 2); }
void e53() { printf("%u + %u = %u\n", INT_MAX, INT_MAX, INT_MAX * 2); }
void c54() {_printf("%o", 1024);}
void e54() { printf("%o", 1024);}
void c55() {_printf("%o", -1024);}
void e55() { printf("%o", -1024);}
void c56() {_printf("%o", 0);}
void e56() { printf("%o", 0);}
void c57() {_printf("%o", UINT_MAX);}
void e57() { printf("%o", UINT_MAX);}
void c58() {_printf("%o", UINT_MAX + 1024); }
void e58() { printf("%o", UINT_MAX + 1024); }
void c59() {_printf("There is %o bytes in %o KB\n", 1024, 1);}
void e59() { printf("There is %o bytes in %o KB\n", 1024, 1);}
void c60() {_printf("%o - %o = %o\n", 2048, 1024, 1024);}
void e60() { printf("%o - %o = %o\n", 2048, 1024, 1024);}
void c61() {_printf("%o + %o = %o\n", INT_MAX, INT_MAX, INT_MAX * 2); }
void e61() { printf("%o + %o = %o\n", INT_MAX, INT_MAX, INT_MAX * 2); }
void c62() {_printf("%x", 1024);}
void e62() { printf("%x", 1024);}
void c63() {_printf("%x", -1024);}
void e63() { printf("%x", -1024);}
void c64() {_printf("%x", 0);}
void e64() { printf("%x", 0);}
void c65() {_printf("%x", UINT_MAX);}
void e65() { printf("%x", UINT_MAX);}
void c66() {_printf("%x", UINT_MAX + 1024); }
void e66() { printf("%x", UINT_MAX + 1024); }
void c67() {_printf("There is %x bytes in %x KB\n", 1024, 1);}
void e67() { printf("There is %x bytes in %x KB\n", 1024, 1);}
void c68() {_printf("%x - %x = %x\n", 2048, 1024, 1024);}
void e68() { printf("%x - %x = %x\n", 2048, 1024, 1024);}
void c69() {_printf("%x + %x = %x\n", INT_MAX, INT_MAX, INT_MAX * 2); }
void e69() { printf("%x + %x = %x\n", INT_MAX, INT_MAX, INT_MAX * 2); }
void c70() {_printf("%X", 1024);}
void e70() { printf("%X", 1024);}
void c71() {_printf("%X", -1024);}
void e71() { printf("%X", -1024);}
void c72() {_printf("%X", 0);}
void e72() { printf("%X", 0);}
void c73() {_printf("%X", UINT_MAX);}
void e73() { printf("%X", UINT_MAX);}
void c74() {_printf("%X", UINT_MAX + 1024); }
void e74() { printf("%X", UINT_MAX + 1024); }
void c75() {_printf("There is %X bytes in %X KB\n", 1024, 1);}
void e75() { printf("There is %X bytes in %X KB\n", 1024, 1);}
void c76() {_printf("%X - %X = %X\n", 2048, 1024, 1024);}
void e76() { printf("%X - %X = %X\n", 2048, 1024, 1024);}
void c77() {_printf("%X + %X = %X\n", INT_MAX, INT_MAX, INT_MAX + 1024); }
void e77() { printf("%X + %X = %X\n", INT_MAX, INT_MAX, INT_MAX + 1024); }
void c78() {_printf("%u == %o == %x == %X\n", 1024, 1024, 1024, 1024);}
void e78() { printf("%u == %o == %x == %X\n", 1024, 1024, 1024, 1024);}
void c79() {_printf("uuoxxX%xuoXo\n", 1024);}
void e79() { printf("uuoxxX%xuoXo\n", 1024);}
//test 4
//test 5
void c80() {_printf("%S", "No special character.");}
void e80() { printf("%S", "No special character.");}
void c81() {_printf("%S", "\n");}
void e81() { printf("%S", "\n");}
void c82() {_printf("%S", "\x01\x02\x03\x04\x05\x06\x07");}
void e82() { printf("%S", "\x01\x02\x03\x04\x05\x06\x07");}
void c83() {_printf("Could you print some non-prntable characters?\n%S\nThanks!\n", "Sure:\x1F\x7F\n");}
void e83() {  printf("Could you print some non-prntable characters?\nSure:\\x1F\\x7F\\x0A\nThanks!\n");}
void c84() {_printf("");}
void e84() { printf("");}
void c85() {_printf("- What did you say?\n- %S\n- That's what I thought.\n", "");}
void e85() { printf("- What did you say?\n- %s\n- That's what I thought.\n", "");}
//test 6
void c86() {_printf("%p", (void *)0x7fff5100b608);}
void e86() { printf("%p", (void *)0x7fff5100b608);}
void c87() {_printf("%p", NULL);}
void e87() { printf("(nil)");}
void c88() {_printf("Can you print an address?\n%p\nNice!\n", (void *)0x7fff5100b6f8);}
void e88() { printf("Can you print an address?\n%p\nNice!\n", (void *)0x7fff5100b6f8);}
void c89() {_printf("Can you print several addresses?\n%p,%p,%p,%p\nNice!\n", (void *)0x7fff5100b6f8, (void *)0x7faf51f0f608, (void *)0x6ff42510b6f8, (void *)0x7fff510236f8);}
void e89() { printf("Can you print several addresses?\n%p,%p,%p,%p\nNice!\n", (void *)0x7fff5100b6f8, (void *)0x7faf51f0f608, (void *)0x6ff42510b6f8, (void *)0x7fff510236f8);}
void c90() {_printf("");}
void e90() { printf("");}
void c91() {_printf("Can you print an address?\n%p\nNice!\n", (void *)-1);}
void e91() { printf("Can you print an address?\n%p\nNice!\n", (void *)-1);}
void c92() {_printf("%pppp", (void *)0x7fff5100b6f8);}
void e92() { printf("%pppp", (void *)0x7fff5100b6f8);}
//test 7
void c93() {_printf("%+d", 1024);}
void e93() { printf("%+d", 1024);}
void c94() {_printf("%+d", -1024);}
void e94() { printf("%+d", -1024);}
void c95() {_printf("%+d", 0);}
void e95() { printf("%+d", 0);}
void c96() {_printf("%+d", INT_MAX);}
void e96() { printf("%+d", INT_MAX);}
void c97() {_printf("%+d", INT_MIN);}
void e97() { printf("%+d", INT_MIN);}
void c98() {_printf("%+d", INT_MAX + 1024);};
void e98() { printf("%+d", INT_MAX + 1024);};
void c99() {_printf("%+d", INT_MIN - 1024);};
void e99() { printf("%+d", INT_MIN - 1024);};
void c100() {_printf("There is %+d bytes in %+d KB\n", 1024, 1);}
void e100() { printf("There is %+d bytes in %+d KB\n", 1024, 1);}
void c101() {_printf("%+d - %+d = %+d\n", 1024, 2048, -1024);}
void e101() { printf("%+d - %+d = %+d\n", 1024, 2048, -1024);}
void c102() {_printf("%+d + %+d = %+d\n", INT_MIN, INT_MAX, (INT_MIN + INT_MAX));}
void e102() { printf("%+d + %+d = %+d\n", INT_MIN, INT_MAX, (INT_MIN + INT_MAX));}
void c103() {_printf("%+i", 1024);}
void e103() { printf("%+i", 1024);}
void c104() {_printf("%+i", -1024);}
void e104() { printf("%+i", -1024);}
void c105() {_printf("%+i", 0);}
void e105() { printf("%+i", 0);}
void c106() {_printf("%+i", INT_MAX);}
void e106() { printf("%+i", INT_MAX);}
void c107() {_printf("%+i", INT_MIN);}
void e107() { printf("%+i", INT_MIN);}
void c108() {_printf("%+i", INT_MAX + 1024);}
void e108() { printf("%+i", INT_MAX + 1024);}
void c109() {_printf("%+i", INT_MIN - 1024);}
void e109() { printf("%+i", INT_MIN - 1024);}
void c110() {_printf("There is %+i bytes in %+i KB\n", 1024, 1);}
void e110() { printf("There is %+i bytes in %+i KB\n", 1024, 1);}
void c111() {_printf("%+i - %+i = %+i\n", 1024, 2048, -1024);}
void e111() { printf("%+i - %+i = %+i\n", 1024, 2048, -1024);}
void c112() {_printf("%+i + %+i = %+i\n", INT_MIN, INT_MAX, (INT_MIN + INT_MAX));}
void e112() { printf("%+i + %+i = %+i\n", INT_MIN, INT_MAX, (INT_MIN + INT_MAX));}
void c113() {_printf("% d", 1024);}
void e113() { printf("% d", 1024);}
void c114() {_printf("% d", -1024);}
void e114() { printf("% d", -1024);}
void c115() {_printf("% d", 0);}
void e115() { printf("% d", 0);}
void c116() {_printf("% d", INT_MAX);}
void e116() { printf("% d", INT_MAX);}
void c117() {_printf("% d", INT_MIN);}
void e117() { printf("% d", INT_MIN);}
void c118() {_printf("% d", INT_MAX + 1024);}
void e118() { printf("% d", INT_MAX + 1024);}
void c119() {_printf("% d", INT_MIN - 1024);}
void e119() { printf("% d", INT_MIN - 1024);}
void c120() {_printf("There is % d bytes in % d KB\n", 1024, 1);}
void e120() { printf("There is % d bytes in % d KB\n", 1024, 1);}
void c121() {_printf("% d - % d = % d\n", 1024, 2048, -1024);}
void e121() { printf("% d - % d = % d\n", 1024, 2048, -1024);}
void c122() {_printf("% d + % d = % d\n", INT_MIN, INT_MAX, (INT_MIN + INT_MAX));}
void e122() { printf("% d + % d = % d\n", INT_MIN, INT_MAX, (INT_MIN + INT_MAX));}
void c123() {_printf("% i", 1024);}
void e123() { printf("% i", 1024);}
void c124() {_printf("% i", -1024);}
void e124() { printf("% i", -1024);}
void c125() {_printf("% i", 0);}
void e125() { printf("% i", 0);}
void c126() {_printf("% i", INT_MAX);}
void e126() { printf("% i", INT_MAX);}
void c127() {_printf("% i", INT_MIN);}
void e127() { printf("% i", INT_MIN);}
void c128() {_printf("% i", INT_MAX + 1024);}
void e128() { printf("% i", INT_MAX + 1024);}
void c129() {_printf("% i", INT_MIN - 1024);}
void e129() { printf("% i", INT_MIN - 1024);}
void c130() {_printf("There is % i bytes in % i KB\n", 1024, 1);}
void e130() { printf("There is % i bytes in % i KB\n", 1024, 1);}
void c131() {_printf("% i - % i = % i\n", 1024, 2048, -1024);}
void e131() { printf("% i - % i = % i\n", 1024, 2048, -1024);}
void c132() {_printf("% i + % i = % i\n", INT_MIN, INT_MAX, (INT_MIN + INT_MAX));}
void e132() { printf("% i + % i = % i\n", INT_MIN, INT_MAX, (INT_MIN + INT_MAX));}
void c133() {_printf("%+i + %+ i = % +d\n", INT_MIN, INT_MAX, (INT_MIN + INT_MAX));}
void e133() { printf("%+i + %+ i = % +d\n", INT_MIN, INT_MAX, (INT_MIN + INT_MAX));}
void c134() {_printf("%+d + %+ d = % +i\n", INT_MIN, INT_MAX, (INT_MIN + INT_MAX));}
void e134() { printf("%+d + %+ d = % +i\n", INT_MIN, INT_MAX, (INT_MIN + INT_MAX));}
void c135() {_printf("%#o", 1024);}
void e135() { printf("%#o", 1024);}
void c136() {_printf("%#o", 0);}
void e136() { printf("%#o", 0);}
void c137() {_printf("%#o", UINT_MAX);}
void e137() { printf("%#o", UINT_MAX);}
void c138() {_printf("%#x", 1024);}
void e138() { printf("%#x", 1024);}
void c139() {_printf("%#x", 0);}
void e139() { printf("%#x", 0);}
void c140() {_printf("%#x", UINT_MAX);}
void e140() { printf("%#x", UINT_MAX);}
void c141() {_printf("%#X", 1024);}
void e141() { printf("%#X", 1024);}
void c142() {_printf("%#X", 0);}
void e142() { printf("%#X", 0);}
void c143() {_printf("%#X", UINT_MAX);}
void e143() { printf("%#X", UINT_MAX);}
void c144() {_printf("% "); }
void e144() { printf("% "); }
void c145() {_printf("% % % % ");}
void e145() { printf("% % % % ");}
//test 8
void c146() {_printf("%ld", 1024L);}
void e146() { printf("%ld", 1024L);}
void c147() {_printf("%ld", -1024L);}
void e147() { printf("%ld", -1024L);}
void c148() {_printf("%ld", 0L);}
void e148() { printf("%ld", 0L);}
void c149() {_printf("%ld", LONG_MAX);}
void e149() { printf("%ld", LONG_MAX);}
void c150() {_printf("%ld", LONG_MIN);}
void e150() { printf("%ld", LONG_MIN);}
void c151() {_printf("There is %ld bytes in %ld KB\n", 1024L, 1L);}
void e151() { printf("There is %ld bytes in %ld KB\n", 1024L, 1L);}
void c152() {_printf("%ld - %ld = %ld\n", 1024L, 2048L, -1024L);}
void e152() { printf("%ld - %ld = %ld\n", 1024L, 2048L, -1024L);}
void c153() {_printf("%ld + %ld = %ld\n", LONG_MIN, LONG_MAX, (LONG_MIN + LONG_MAX));}
void e153() { printf("%ld + %ld = %ld\n", LONG_MIN, LONG_MAX, (LONG_MIN + LONG_MAX));}
void c154() {_printf("%li", 1024L);}
void e154() { printf("%li", 1024L);}
void c155() {_printf("%li", -1024L);}
void e155() { printf("%li", -1024L);}
void c156() {_printf("%li", 0L);}
void e156() { printf("%li", 0L);}
void c157() {_printf("%li", LONG_MAX);}
void e157() { printf("%li", LONG_MAX);}
void c158() {_printf("%li", LONG_MIN);}
void e158() { printf("%li", LONG_MIN);}
void c159() {_printf("There is %li bytes in %li KB\n", 1024L, 1L);}
void e159() { printf("There is %li bytes in %li KB\n", 1024L, 1L);}
void c160() {_printf("%li - %li = %li\n", 1024L, 2048L, -1024L);}
void e160() { printf("%li - %li = %li\n", 1024L, 2048L, -1024L);}
void c161() {_printf("%li + %li = %li\n", LONG_MIN, LONG_MAX, (LONG_MIN + LONG_MAX));}
void e161() { printf("%li + %li = %li\n", LONG_MIN, LONG_MAX, (LONG_MIN + LONG_MAX));}
void c162() {_printf("%lu", 1024UL);}
void e162() { printf("%lu", 1024UL);}
void c163() {_printf("%lu", 0UL);}
void e163() { printf("%lu", 0UL);}
void c164() {_printf("%lu", ULONG_MAX);}
void e164() { printf("%lu", ULONG_MAX);}
void c168() {_printf("there is %lu bytes in %lu KB\n", 1024UL, 1UL);}
void e168() { printf("there is %lu bytes in %lu KB\n", 1024UL, 1UL);}
void c169() {_printf("%lu - %lu = %lu\n", ULONG_MAX, 2048UL, ULONG_MAX - 2048UL);}
void e169() { printf("%lu - %lu = %lu\n", ULONG_MAX, 2048UL, ULONG_MAX - 2048UL);}
void c165() {_printf("%lo", 1024UL);}
void e165() { printf("%lo", 1024UL);}
void c166() {_printf("%lo", 0UL);}
void e166() { printf("%lo", 0UL);}
void c167() {_printf("%lo", ULONG_MAX);}
void e167() { printf("%lo", ULONG_MAX);}
void c170() {_printf("there is %lo bytes in %lo KB\n", 1024UL, 1UL);}
void e170() { printf("there is %lo bytes in %lo KB\n", 1024UL, 1UL);}
void c171() {_printf("%lo - %lo = %lo\n", ULONG_MAX, 2048UL, ULONG_MAX - 2048UL);}
void e171() { printf("%lo - %lo = %lo\n", ULONG_MAX, 2048UL, ULONG_MAX - 2048UL);}
void c172() {_printf("%lx", 1024UL);}
void e172() { printf("%lx", 1024UL);}
void c173() {_printf("%lx", 0UL);}
void e173() { printf("%lx", 0UL);}
void c174() {_printf("%lx", ULONG_MAX);}
void e174() { printf("%lx", ULONG_MAX);}
void c175() {_printf("there is %lx bytes in %lx KB\n", 1024UL, 1UL);}
void e175() { printf("there is %lx bytes in %lx KB\n", 1024UL, 1UL);}
void c176() {_printf("%lx - %lx = %lx\n", ULONG_MAX, 2048UL, ULONG_MAX - 2048UL);}
void e176() { printf("%lx - %lx = %lx\n", ULONG_MAX, 2048UL, ULONG_MAX - 2048UL);}
void c177() {_printf("%lX", 1024UL);}
void e177() { printf("%lX", 1024UL);}
void c178() {_printf("%lX", 0UL);}
void e178() { printf("%lX", 0UL);}
void c179() {_printf("%lX", ULONG_MAX);}
void e179() { printf("%lX", ULONG_MAX);}
void c180() {_printf("there is %lX bytes in %lX KB\n", 1024UL, 1UL);}
void e180() { printf("there is %lX bytes in %lX KB\n", 1024UL, 1UL);}
void c181() {_printf("%lX - %lX = %lX\n", ULONG_MAX, 2048UL, ULONG_MAX - 2048UL);}
void e181() { printf("%lX - %lX = %lX\n", ULONG_MAX, 2048UL, ULONG_MAX - 2048UL);}
void c182() {_printf("%hd", 1024);}
void e182() { printf("%hd", 1024);}
void c183() {_printf("%hd", -1024);}
void e183() { printf("%hd", -1024);}
void c184() {_printf("%hd", 0);}
void e184() { printf("%hd", 0);}
void c185() {_printf("%hd", SHRT_MAX);}
void e185() { printf("%hd", SHRT_MAX);}
void c186() {_printf("%hd", SHRT_MIN);}
void e186() { printf("%hd", SHRT_MIN);}
void c187() {_printf("There is %hd bytes in %hd KB\n", 1024, 1);}
void e187() { printf("There is %hd bytes in %hd KB\n", 1024, 1);}
void c188() {_printf("%hd - %hd = %hd\n", 1024, 2048, -1024);}
void e188() { printf("%hd - %hd = %hd\n", 1024, 2048, -1024);}
void c189() {_printf("%hd + %hd = %hd\n", SHRT_MIN, SHRT_MAX, (SHRT_MIN + SHRT_MAX));}
void e189() { printf("%hd + %hd = %hd\n", SHRT_MIN, SHRT_MAX, (SHRT_MIN + SHRT_MAX));}
void c190() {_printf("%hi", 1024);}
void e190() { printf("%hi", 1024);}
void c191() {_printf("%hi", -1024);}
void e191() { printf("%hi", -1024);}
void c192() {_printf("%hi", 0);}
void e192() { printf("%hi", 0);}
void c193() {_printf("%hi", SHRT_MAX);}
void e193() { printf("%hi", SHRT_MAX);}
void c194() {_printf("%hi", SHRT_MIN);}
void e194() { printf("%hi", SHRT_MIN);}
void c195() {_printf("There is %hi bytes in %hi KB\n", 1024, 1);}
void e195() { printf("There is %hi bytes in %hi KB\n", 1024, 1);}
void c196() {_printf("%hi - %hi = %hi\n", 1024, 2048, -1024);}
void e196() { printf("%hi - %hi = %hi\n", 1024, 2048, -1024);}
void c197() {_printf("%hi + %hi = %hi\n", SHRT_MIN, SHRT_MAX, (SHRT_MIN + SHRT_MAX));}
void e197() { printf("%hi + %hi = %hi\n", SHRT_MIN, SHRT_MAX, (SHRT_MIN + SHRT_MAX));}
void c198() {_printf("%hu", 1024);}
void e198() { printf("%hu", 1024);}
void c199() {_printf("%hu", 0);}
void e199() { printf("%hu", 0);}
void c200() {_printf("%hu", USHRT_MAX);}
void e200() { printf("%hu", USHRT_MAX);}
void c201() {_printf("There is %hu bytes in %hu KB\n", 1024, 1);}
void e201() { printf("There is %hu bytes in %hu KB\n", 1024, 1);}
void c202() {_printf("%hu - %hu = %hu\n", USHRT_MAX, 2048, USHRT_MAX - 2048);}
void e202() { printf("%hu - %hu = %hu\n", USHRT_MAX, 2048, USHRT_MAX - 2048);}
void c203() {_printf("%ho", 1024);}
void e203() { printf("%ho", 1024);}
void c204() {_printf("%ho", 0);}
void e204() { printf("%ho", 0);}
void c205() {_printf("%ho", USHRT_MAX);}
void e205() { printf("%ho", USHRT_MAX);}
void c206() {_printf("There is %ho bytes in %ho KB\n", 1024, 1);}
void e206() { printf("There is %ho bytes in %ho KB\n", 1024, 1);}
void c207() {_printf("%ho - %ho = %ho", USHRT_MAX, 2048, USHRT_MAX - 2048);}
void e207() { printf("%ho - %ho = %ho", USHRT_MAX, 2048, USHRT_MAX - 2048);}
void c208() {_printf("%hx", 1024);}
void e208() { printf("%hx", 1024);}
void c209() {_printf("%hx", 0);}
void e209() { printf("%hx", 0);}
void c210() {_printf("%hx", USHRT_MAX);}
void e210() { printf("%hx", USHRT_MAX);}
void c211() {_printf("There is %hx bytes in %hx KB\n", 1024, 1);}
void e211() { printf("There is %hx bytes in %hx KB\n", 1024, 1);}
void c212() {_printf("%hx - %hx = %hx\n", USHRT_MAX, 2048, USHRT_MAX - 2048);}
void e212() { printf("%hx - %hx = %hx\n", USHRT_MAX, 2048, USHRT_MAX - 2048);}
void c213() {_printf("%hX", 1024);}
void e213() { printf("%hX", 1024);}
void c214() {_printf("%hX", 0);}
void e214() { printf("%hX", 0);}
void c215() {_printf("%hX", USHRT_MAX);}
void e215() { printf("%hX", USHRT_MAX);}
void c216() {_printf("There is %hX bytes in %hX KB\n", 1024, 1);}
void e216() { printf("There is %hX bytes in %hX KB\n", 1024, 1);}
void c217() {_printf("%hX - %hX = %hX\n", USHRT_MAX, 2048, USHRT_MAX - 2048);}
void e217() { printf("%hX - %hX = %hX\n", USHRT_MAX, 2048, USHRT_MAX - 2048);}
void c218() {_printf("%h\n");}
void e218() { printf("%%\n");}
void c219() {_printf("%l\n");}
void e219() { printf("%%\n");}
// test 9

void c220() {_printf("%6d", 102498402);}
void e220() { printf("%6d", 102498402);}
void c221() {_printf("%6d", -102498402);}
void e221() { printf("%6d", -102498402);}
void c222() {_printf("%6d", 0);}
void e222() { printf("%6d", 0);}
void c223() {_printf("%6d", 1024);}
void e223() { printf("%6d", 1024);}
void c224() {_printf("%6d", -1024);}
void e224() { printf("%6d", -1024);}
void c225() {_printf("In the middle %6d of a sentence.\n", 1024);}
void e225() { printf("In the middle %6d of a sentence.\n", 1024);}
void c226() {_printf("%6i", 102498402);}
void e226() { printf("%6i", 102498402);}
void c227() {_printf("%6i", -102498402);}
void e227() { printf("%6i", -102498402);}
void c228() {_printf("%6i", 0);}
void e228() { printf("%6i", 0);}
void c229() {_printf("%6i", 1024);}
void e229() { printf("%6i", 1024);}
void c230() {_printf("%6i", -1024);}
void e230() { printf("%6i", -1024);}
void c231() {_printf("In the middle %6i of a sentence.\n", 1024);}
void e231() { printf("In the middle %6i of a sentence.\n", 1024);}
void c232() {_printf("%6u", 102498402);}
void e232() { printf("%6u", 102498402);}
void c233() {_printf("%6u", 0);}
void e233() { printf("%6u", 0);}
void c234() {_printf("%6u", 1024);}
void e234() { printf("%6u", 1024);}
void c235() {_printf("In the middle %6u of a sentence.\n", 1024);}
void e235() { printf("In the middle %6u of a sentence.\n", 1024);}
void c236() {_printf("%6o", 102498402);}
void e236() { printf("%6o", 102498402);}
void c237() {_printf("%6o", 0);}
void e237() { printf("%6o", 0);}
void c238() {_printf("%6o", 1024);}
void e238() { printf("%6o", 1024);}
void c239() {_printf("In the middle %6o of a sentence.\n", 1024);}
void e239() { printf("In the middle %6o of a sentence.\n", 1024);}
void c240() {_printf("%6x", 102498402);}
void e240() { printf("%6x", 102498402);}
void c241() {_printf("%6x", 0);}
void e241() { printf("%6x", 0);}
void c242() {_printf("%6x", 1024);}
void e242() { printf("%6x", 1024);}
void c243() {_printf("In the middle %6x of a sentence.\n", 1024);}
void e243() { printf("In the middle %6x of a sentence.\n", 1024);}
void c244() {_printf("%6X", 102498402);}
void e244() { printf("%6X", 102498402);}
void c245() {_printf("%6X", 0);}
void e245() { printf("%6X", 0);}
void c246() {_printf("%6X", 1024);}
void e246() { printf("%6X", 1024);}
void c247() {_printf("In the middle %6X of a sentence.\n", 1024);}
void e247() { printf("In the middle %6X of a sentence.\n", 1024);}
void c248() {_printf("%6c", 'A');}
void e248() { printf("%6c", 'A');}
void c249() {_printf("%6c", 0);}
void e249() { printf("%6c", 0);}
void c250() {_printf("In the middle %6c of a sentence.\n", 'H');}
void e250() { printf("In the middle %6c of a sentence.\n", 'H');}
void c251() {_printf("%6s", "Best School !\n");}
void e251() { printf("%6s", "Best School !\n");}
void c252() {_printf("%6s", "Hi!\n");}
void e252() { printf("%6s", "Hi!\n");}
void c253() {_printf("In the middle %6s of a sentence.\n", "Hey");}
void e253() { printf("In the middle %6s of a sentence.\n", "Hey");}
void c254() {_printf("%*d", 6, 102498402);}
void e254() { printf("%*d", 6, 102498402);}
void c255() {_printf("%*d", 6, -102498402);}
void e255() { printf("%*d", 6, -102498402);}
void c256() {_printf("%*d", 6, 0);}
void e256() { printf("%*d", 6, 0);}
void c257() {_printf("%*d", 6, 1024);}
void e257() { printf("%*d", 6, 1024);}
void c258() {_printf("%*d", 6, -1024);}
void e258() { printf("%*d", 6, -1024);}
void c259() {_printf("In the middle %*d of a sentence.\n", 6, 1024);}
void e259() { printf("In the middle %*d of a sentence.\n", 6, 1024);}
void c260() {_printf("%*i", 6, 102498402);}
void e260() { printf("%*i", 6, 102498402);}
void c261() {_printf("%*i", 6, -102498402);}
void e261() { printf("%*i", 6, -102498402);}
void c262() {_printf("%*i", 6, 0);}
void e262() { printf("%*i", 6, 0);}
void c263() {_printf("%*i", 6, 1024);}
void e263() { printf("%*i", 6, 1024);}
void c264() {_printf("%*i", 6, -1024);}
void e264() { printf("%*i", 6, -1024);}
void c265() {_printf("In the middle %*i of a sentence.\n", 6, 1024);}
void e265() { printf("In the middle %*i of a sentence.\n", 6, 1024);}
void c266() {_printf("%*u", 6, 102498402);}
void e266() { printf("%*u", 6, 102498402);}
void c267() {_printf("%*u", 6, 0);}
void e267() { printf("%*u", 6, 0);}
void c268() {_printf("%*u", 6, 1024);}
void e268() { printf("%*u", 6, 1024);}
void c269() {_printf("In the middle %*u of a sentence.\n", 6, 1024);}
void e269() { printf("In the middle %*u of a sentence.\n", 6, 1024);}
void c270() {_printf("%*o", 6, 102498402);}
void e270() { printf("%*o", 6, 102498402);}
void c271() {_printf("%*o", 6, 0);}
void e271() { printf("%*o", 6, 0);}
void c272() {_printf("%*o", 6, 1024);}
void e272() { printf("%*o", 6, 1024);}
void c273() {_printf("In the middle %*o of a sentence.\n", 6, 1024);}
void e273() { printf("In the middle %*o of a sentence.\n", 6, 1024);}
void c274() {_printf("%*x", 6, 102498402);}
void e274() { printf("%*x", 6, 102498402);}
void c275() {_printf("%*x", 6, 0);}
void e275() { printf("%*x", 6, 0);}
void c276() {_printf("%*x", 6, 1024);}
void e276() { printf("%*x", 6, 1024);}
void c277() {_printf("In the middle %*x of a sentence.\n", 6, 1024);}
void e277() { printf("In the middle %*x of a sentence.\n", 6, 1024);}
void c278() {_printf("%*X", 6, 102498402);}
void e278() { printf("%*X", 6, 102498402);}
void c279() {_printf("%*X", 6, 0);}
void e279() { printf("%*X", 6, 0);}
void c280() {_printf("%*X", 6, 1024);}
void e280() { printf("%*X", 6, 1024);}
void c281() {_printf("In the middle %*X of a sentence.\n", 6, 1024);}
void e281() { printf("In the middle %*X of a sentence.\n", 6, 1024);}
void c282() {_printf("%*c", 6, 'A');}
void e282() { printf("%*c", 6, 'A');}
void c283() {_printf("%*c", 6, 0);}
void e283() { printf("%*c", 6, 0);}
void c284() {_printf("In the middle %*c of a sentence.\n", 6, 'H');}
void e284() { printf("In the middle %*c of a sentence.\n", 6, 'H');}
void c285() {_printf("%*s", 6, "Best School !\n");}
void e285() { printf("%*s", 6, "Best School !\n");}
void c286() {_printf("%*s", 6, "Hi!\n");}
void e286() { printf("%*s", 6, "Hi!\n");}
void c287() {_printf("In the middle %*s of a sentence.\n", 6, "Hey");}
void e287() { printf("In the middle %*s of a sentence.\n", 6, "Hey");}
//test 10
void c288() {_printf("%.6d", 102498402);}
void e288() { printf("%.6d", 102498402);}
void c289() {_printf("%.6d", -102498402);}
void e289() { printf("%.6d", -102498402);}
void c290() {_printf("%.6d", 0);}
void e290() { printf("%.6d", 0);}
void c291() {_printf("%.6d", 1024);}
void e291() { printf("%.6d", 1024);}
void c292() {_printf("%.6d", -1024);}
void e292() { printf("%.6d", -1024);}
void c293() {_printf("In the middle %.6d of a sentence.\n", 1024);}
void e293() { printf("In the middle %.6d of a sentence.\n", 1024);}
void c294() {_printf("%.0d", 0);}
void e294() { printf("%.0d", 0);}
void c295() {_printf("%.d", 0);}
void e295() { printf("%.d", 0);}
void c296() {_printf("%.6i", 102498402);}
void e296() { printf("%.6i", 102498402);}
void c297() {_printf("%.6i", -102498402);}
void e297() { printf("%.6i", -102498402);}
void c298() {_printf("%.6i", 0);}
void e298() { printf("%.6i", 0);}
void c299() {_printf("%.6i", 1024);}
void e299() { printf("%.6i", 1024);}
void c300() {_printf("%.6i", -1024);}
void e300() { printf("%.6i", -1024);}
void c301() {_printf("In the middle %.6i of a sentence.\n", 1024);}
void e301() { printf("In the middle %.6i of a sentence.\n", 1024);}
void c302() {_printf("%.0i", 0);}
void e302() { printf("%.0i", 0);}
void c303() {_printf("%.i", 0);}
void e303() { printf("%.i", 0);}
void c304() {_printf("%.6u", 102498402);}
void e304() { printf("%.6u", 102498402);}
void c305() {_printf("%.6u", 0);}
void e305() { printf("%.6u", 0);}
void c306() {_printf("%.6u", 1024);}
void e306() { printf("%.6u", 1024);}
void c307() {_printf("In the middle %.6u of a sentence.\n", 1024);}
void e307() { printf("In the middle %.6u of a sentence.\n", 1024);}
void c308() {_printf("%.0u", 0);}
void e308() { printf("%.0u", 0);}
void c309() {_printf("%.u", 0);}
void e309() { printf("%.u", 0);}
void c310() {_printf("%.6o", 102498402);}
void e310() { printf("%.6o", 102498402);}
void c311() {_printf("%.6o", 0);}
void e311() { printf("%.6o", 0);}
void c312() {_printf("%.6o", 1024);}
void e312() { printf("%.6o", 1024);}
void c313() {_printf("In the middle %.6o of a sentence.\n", 1024);}
void e313() { printf("In the middle %.6o of a sentence.\n", 1024);}
void c314() {_printf("%.0o", 0);}
void e314() { printf("%.0o", 0);}
void c315() {_printf("%.o", 0);}
void e315() { printf("%.o", 0);}
void c316() {_printf("%.6x", 102498402);}
void e316() { printf("%.6x", 102498402);}
void c317() {_printf("%.6x", 0);}
void e317() { printf("%.6x", 0);}
void c318() {_printf("%.6x", 1024);}
void e318() { printf("%.6x", 1024);}
void c319() {_printf("In the middle %.6x of a sentence.\n", 1024);}
void e319() { printf("In the middle %.6x of a sentence.\n", 1024);}
void c320() {_printf("%.0x", 0);}
void e320() { printf("%.0x", 0);}
void c321() {_printf("%.x", 0);}
void e321() { printf("%.x", 0);}
void c322() {_printf("%.6X", 102498402);}
void e322() { printf("%.6X", 102498402);}
void c323() {_printf("%.6X", 0);}
void e323() { printf("%.6X", 0);}
void c324() {_printf("%.6X", 1024);}
void e324() { printf("%.6X", 1024);}
void c325() {_printf("In the middle %.6X of a sentence.\n", 1024);}
void e325() { printf("In the middle %.6X of a sentence.\n", 1024);}
void c326() {_printf("%.0X", 0);}
void e326() { printf("%.0X", 0);}
void c327() {_printf("%.X", 0);}
void e327() { printf("%.X", 0);}
void c328() {_printf("%.6s", "Best School !\n");}
void e328() { printf("%.6s", "Best School !\n");}
void c329() {_printf("%.6s", "Hi!\n");}
void e329() { printf("%.6s", "Hi!\n");}
void c330() {_printf("%.0s", "Hi!\n");}
void e330() { printf("%.0s", "Hi!\n");}
void c331() {_printf("%.s", "Hi!\n");}
void e331() { printf("%.s", "Hi!\n");}
void c332() {_printf("In the middle %.6s of a sentence.\n", "Best!");}
void e332() { printf("In the middle %.6s of a sentence.\n", "Best!");}
void c333() {_printf("%.*d", 6, 102498402);}
void e333() { printf("%.*d", 6, 102498402);}
void c334() {_printf("%.*d", 6, -102498402);}
void e334() { printf("%.*d", 6, -102498402);}
void c335() {_printf("%.*d", 6, 0);}
void e335() { printf("%.*d", 6, 0);}
void c336() {_printf("%.*d", 6, 1024);}
void e336() { printf("%.*d", 6, 1024);}
void c337() {_printf("%.*d", 6, -1024);}
void e337() { printf("%.*d", 6, -1024);}
void c338() {_printf("In the middle %.*d of a sentence.\n", 6, 1024);}
void e338() { printf("In the middle %.*d of a sentence.\n", 6, 1024);}
void c339() {_printf("%.*d", 0, 0);}
void e339() { printf("%.*d", 0, 0);}
void c340() {_printf("%.*i", 6, 102498402);}
void e340() { printf("%.*i", 6, 102498402);}
void c341() {_printf("%.*i", 6, -102498402);}
void e341() { printf("%.*i", 6, -102498402);}
void c342() {_printf("%.*i", 6, 0);}
void e342() { printf("%.*i", 6, 0);}
void c343() {_printf("%.*i", 6, 1024);}
void e343() { printf("%.*i", 6, 1024);}
void c344() {_printf("%.*i", 6, -1024);}
void e344() { printf("%.*i", 6, -1024);}
void c345() {_printf("In the middle %.*i of a sentence.\n", 6, 1024);}
void e345() { printf("In the middle %.*i of a sentence.\n", 6, 1024);}
void c346() {_printf("%.*i", 0, 0);}
void e346() { printf("%.*i", 0, 0);}
void c347() {_printf("%.*u", 6, 102498402);}
void e347() { printf("%.*u", 6, 102498402);}
void c348() {_printf("%.*u", 6, 0);}
void e348() { printf("%.*u", 6, 0);}
void c349() {_printf("%.*u", 6, 1024);}
void e349() { printf("%.*u", 6, 1024);}
void c350() {_printf("In the middle %.*u of a sentence.\n", 6, 1024);}
void e350() { printf("In the middle %.*u of a sentence.\n", 6, 1024);}
void c351() {_printf("%.*u", 0, 0);}
void e351() { printf("%.*u", 0, 0);}
void c352() {_printf("%.*o", 6, 102498402);}
void e352() { printf("%.*o", 6, 102498402);}
void c353() {_printf("%.*o", 6, 0);}
void e353() { printf("%.*o", 6, 0);}
void c354() {_printf("%.*o", 6, 1024);}
void e354() { printf("%.*o", 6, 1024);}
void c355() {_printf("In the middle %.*o of a sentence.\n", 6, 1024);}
void e355() { printf("In the middle %.*o of a sentence.\n", 6, 1024);}
void c356() {_printf("%.*o", 0, 0);}
void e356() { printf("%.*o", 0, 0);}
void c357() {_printf("%.*x", 6, 102498402);}
void e357() { printf("%.*x", 6, 102498402);}
void c358() {_printf("%.*x", 6, 0);}
void e358() { printf("%.*x", 6, 0);}
void c359() {_printf("%.*x", 6, 1024);}
void e359() { printf("%.*x", 6, 1024);}
void c360() {_printf("In the middle %.*x of a sentence.\n", 6, 1024);}
void e360() { printf("In the middle %.*x of a sentence.\n", 6, 1024);}
void c361() {_printf("%.*x", 0, 0);}
void e361() { printf("%.*x", 0, 0);}
void c362() {_printf("%.*X", 6, 102498402);}
void e362() { printf("%.*X", 6, 102498402);}
void c363() {_printf("%.*X", 6, 0);}
void e363() { printf("%.*X", 6, 0);}
void c364() {_printf("%.*X", 6, 1024);}
void e364() { printf("%.*X", 6, 1024);}
void c365() {_printf("In the middle %.*X of a sentence.\n", 6, 1024);}
void e365() { printf("In the middle %.*X of a sentence.\n", 6, 1024);}
void c366() {_printf("%.*X", 0, 0);}
void e366() { printf("%.*X", 0, 0);}
void c367() {_printf("%.*s", 6, "Best School !\n");}
void e367() { printf("%.*s", 6, "Best School !\n");}
void c368() {_printf("%.*s", 6, "Hi!\n");}
void e368() { printf("%.*s", 6, "Hi!\n");}
void c369() {_printf("%.*s", 0, "Hi!\n");}
void e369() { printf("%.*s", 0, "Hi!\n");}
void c370() {_printf("In the middle %.*s of a sentence.\n", 6, "Best!");}
void e370() { printf("In the middle %.*s of a sentence.\n", 6, "Best!");}


int main() {
  int i,j;
  void (*checks[])() = { 
    &c0, &c1, &c2, &c3, &c4, &c5, &c6, &c7, &c8, &c9, &c10,
    &c11, &c12, &c13, &c14, &c15, &c16, &c17, &c18, &c19, &c20,
    &c21, &c22, &c23, &c24, &c25, &c26, &c27, &c28, &c29, &c30,
    &c31, &c32, &c33, &c34, &c35, &c36, &c37, &c38, &c39, &c40,
    &c41, &c42, &c43, &c44, &c45, &c46, &c47, &c48, &c49, &c50,
    &c51, &c52, &c53, &c54, &c55, &c56, &c57, &c58, &c59, &c60,
    &c61, &c62, &c63, &c64, &c65, &c66, &c67, &c68, &c69, &c70,
    &c71, &c72, &c73, &c74, &c75, &c76, &c77, &c78, &c79, &c80,
    &c81, &c82, &c83, &c84, &c85, &c86, &c87, &c88, &c89, &c90,
    &c91, &c92, &c93, &c94, &c95, &c96, &c97, &c98, &c99, &c100,
    &c101, &c102, &c103, &c104, &c105, &c106, &c107, &c108, &c109, &c110,
    &c111, &c112, &c113, &c114, &c115, &c116, &c117, &c118, &c119, &c120,
    &c121, &c122, &c123, &c124, &c125, &c126, &c127, &c128, &c129, &c130,
    &c131, &c132, &c133, &c134, &c135, &c136, &c137, &c138, &c139, &c140,
    &c141, &c142, &c143, &c144, &c145, &c146, &c147, &c148, &c149, &c150,
    &c151, &c152, &c153, &c154, &c155, &c156, &c157, &c158, &c159, &c160,
    &c161, &c162, &c163, &c164, &c165, &c166, &c167, &c168, &c169, &c170,
    &c171, &c172, &c173, &c174, &c175, &c176, &c177, &c178, &c179, &c180,
    &c181, &c182, &c183, &c184, &c185, &c186, &c187, &c188, &c189, &c190,
    &c191, &c192, &c193, &c194, &c195, &c196, &c197, &c198, &c199, &c200,
    &c201, &c202, &c203, &c204, &c205, &c206, &c207, &c208, &c209, &c210,
    &c211, &c212, &c213, &c214, &c215, &c216, &c217, &c218, &c219, &c220,
    &c221, &c222, &c223, &c224, &c225, &c226, &c227, &c228, &c229, &c230,
    &c231, &c232, &c233, &c234, &c235, &c236, &c237, &c238, &c239, &c240,
    &c241, &c242, &c243, &c244, &c245, &c246, &c247, &c248, &c249, &c250,
    &c251, &c252, &c253, &c254, &c255, &c256, &c257, &c258, &c259, &c260,
    &c261, &c262, &c263, &c264, &c265, &c266, &c267, &c268, &c269, &c270,
    &c271, &c272, &c273, &c274, &c275, &c276, &c277, &c278, &c279, &c280,
    &c281, &c282, &c283, &c284, &c285, &c286, &c287, &c288, &c289, &c290,
    &c291, &c292, &c293, &c294, &c295, &c296, &c297, &c298, &c299, &c300,
    &c301, &c302, &c303, &c304, &c305, &c306, &c307, &c308, &c309, &c310,
    &c311, &c312, &c313, &c314, &c315, &c316, &c317, &c318, &c319, &c320,
    &c321, &c322, &c323, &c324, &c325, &c326, &c327, &c328, &c329, &c330,
    &c331, &c332, &c333, &c334, &c335, &c336, &c337, &c338, &c339, &c340,
    &c341, &c342, &c343, &c344, &c345, &c346, &c347, &c348, &c349, &c350,
    &c351, &c352, &c353, &c354, &c355, &c356, &c357, &c358, &c359, &c360,
    &c361, &c362, &c363, &c364, &c365, &c366, &c367, &c368, &c369, &c370};
                           
  void (*expects[])() = {
    &e0,&e1, &e2, &e3, &e4, &e5, &e6, &e7, &e8, &e9, &e10,
    &e11, &e12, &e13, &e14, &e15, &e16, &e17, &e18, &e19, &e20,
    &e21, &e22, &e23, &e24, &e25, &e26, &e27, &e28, &e29, &e30,
    &e31, &e32, &e33, &e34, &e35, &e36, &e37, &e38, &e39, &e40,
    &e41, &e42, &e43, &e44, &e45, &e46, &e47, &e48, &e49, &e50,
    &e51, &e52, &e53, &e54, &e55, &e56, &e57, &e58, &e59, &e60,
    &e61, &e62, &e63, &e64, &e65, &e66, &e67, &e68, &e69, &e70,
    &e71, &e72, &e73, &e74, &e75, &e76, &e77, &e78, &e79, &e80,
    &e81, &e82, &e83, &e84, &e85, &e86, &e87, &e88, &e89, &e90,
    &e91, &e92, &e93, &e94, &e95, &e96, &e97, &e98, &e99, &e100,
    &e101, &e102, &e103, &e104, &e105, &e106, &e107, &e108, &e109, &e110,
    &e111, &e112, &e113, &e114, &e115, &e116, &e117, &e118, &e119, &e120,
    &e121, &e122, &e123, &e124, &e125, &e126, &e127, &e128, &e129, &e130,
    &e131, &e132, &e133, &e134, &e135, &e136, &e137, &e138, &e139, &e140,
    &e141, &e142, &e143, &e144, &e145, &e146, &e147, &e148, &e149, &e150,
    &e151, &e152, &e153, &e154, &e155, &e156, &e157, &e158, &e159, &e160,
    &e161, &e162, &e163, &e164, &e165, &e166, &e167, &e168, &e169, &e170,
    &e171, &e172, &e173, &e174, &e175, &e176, &e177, &e178, &e179, &e180,
    &e181, &e182, &e183, &e184, &e185, &e186, &e187, &e188, &e189, &e190,
    &e191, &e192, &e193, &e194, &e195, &e196, &e197, &e198, &e199, &e200,
    &e201, &e202, &e203, &e204, &e205, &e206, &e207, &e208, &e209, &e210,
    &e211, &e212, &e213, &e214, &e215, &e216, &e217, &e218, &e219, &e220,
    &e221, &e222, &e223, &e224, &e225, &e226, &e227, &e228, &e229, &e230,
    &e231, &e232, &e233, &e234, &e235, &e236, &e237, &e238, &e239, &e240,
    &e241, &e242, &e243, &e244, &e245, &e246, &e247, &e248, &e249, &e250,
    &e251, &e252, &e253, &e254, &e255, &e256, &e257, &e258, &e259, &e260,
    &e261, &e262, &e263, &e264, &e265, &e266, &e267, &e268, &e269, &e270,
    &e271, &e272, &e273, &e274, &e275, &e276, &e277, &e278, &e279, &e280,
    &e281, &e282, &e283, &e284, &e285, &e286, &e287, &e288, &e289, &e290,
    &e291, &e292, &e293, &e294, &e295, &e296, &e297, &e298, &e299, &e300,
    &e301, &e302, &e303, &e304, &e305, &e306, &e307, &e308, &e309, &e310,
    &e311, &e312, &e313, &e314, &e315, &e316, &e317, &e318, &e319, &e320,
    &e321, &e322, &e323, &e324, &e325, &e326, &e327, &e328, &e329, &e330,
    &e331, &e332, &e333, &e334, &e335, &e336, &e337, &e338, &e339, &e340,
    &e341, &e342, &e343, &e344, &e345, &e346, &e347, &e348, &e349, &e350,
    &e351, &e352, &e353, &e354, &e355, &e356, &e357, &e358, &e359, &e360,
    &e361, &e362, &e363, &e364, &e365, &e366, &e367, &e368, &e369, &e370};
  int breakpoints[] = {0,13,38,46,80,80,86,93,146,220,288,371};
  int count = sizeof(checks) / sizeof(checks[0]);
  int breakpointsCount = sizeof(breakpoints) / sizeof(breakpoints[0]);
  for (i = 0; i < count; i++)
  {
    for (j = 0; j < breakpointsCount; j++)
    {
      if (breakpoints[j] == i)
      {
        printf("-------------------");
        printf("check %d", j);
        printf("-------------------\n");
      }
    }

    printf("check %d ", i);
    print_to_file("expected_output.txt", expects[i]);
    print_to_file("output.txt", checks[i]);
    compare("output.txt", "expected_output.txt");


  }
}


//print output to file

int print_to_file(char *filename,void (*func)()) {
  FILE *fp;
  int stdout_fd, redir_fd;

  // Delete the file if it exists
	remove(filename);

	 // Create a new file
	fp = fopen(filename, "w");
	if (fp == NULL) {
		printf("Failed to create output.txt file.\n");
		return 1;
	}

	// Close the file
	fclose(fp);

	fflush(stdout);
	stdout_fd = dup(STDOUT_FILENO);
	redir_fd = open(filename, O_WRONLY);

	dup2(redir_fd, STDOUT_FILENO);
	close(redir_fd);
	func();
	fflush(stdout);
	dup2(stdout_fd, STDOUT_FILENO);
	close(stdout_fd);
  return 0;
}

// compare output files

int compare(char *filename1, char *filename2){
  FILE *fp1, *fp2;
    char line1[100], line2[100];
    int line_num = 0;
    int result = 0;

    fp1 = fopen(filename1, "r");
    fp2 = fopen(filename2, "r");

    if (fp1 == NULL || fp2 == NULL) {
        printf("Error opening files.\n");
        return 1;
    }

    while (fgets(line1, 100, fp1) && fgets(line2, 100, fp2)) {
        line_num++;
        if (strcmp(line1, line2) != 0) {
            printf("line %d:\n[got]\n%s\n[expected]\n%s\n", line_num, line1, line2);
            result = 1;
        }
    }
    if (fgets(line1, 100, fp1)) {
        line_num++;
        printf("missing line %d:\n%s\n", line_num, line1);
        result = 1;
    }
    if (fgets(line2, 100, fp2)) {
        line_num++;
        printf("missing line %d:\n%s\n", line_num, line2);
        result = 1;
    }

    fclose(fp1);
    fclose(fp2);
	  remove(filename1);
	  remove(filename2);

    if(result == 0) {
        printf("Passed.\n");
    } else {
        printf("Failed.\n");

    }

    return 0;
}
