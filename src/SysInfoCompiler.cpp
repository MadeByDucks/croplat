#include "SysInfoCompiler.h"
#include <vector>


//https://sourceforge.net/p/predef/wiki/OperatingSystems/


SysInfoCompiler::SysInfoCompiler()
{
}

SysInfoCompiler::~SysInfoCompiler()
{
}


std::string SysInfoCompiler::getCompilerDef()
{
    std::vector<std::string> sysinfo;

//Windows
#ifdef __WINDOWS__
    sysinfo.push_back("__WINDOWS__");
#endif
#ifdef _WIN16
    sysinfo.push_back("_WIN16");
#endif
#ifdef WIN32
    sysinfo.push_back( "WIN32");
#endif
#ifdef _WIN32
    sysinfo.push_back( "_WIN32");
#endif
#ifdef __WIN32__
    sysinfo.push_back( "__WIN32__)";
#endif
#ifdef _WIN64
    sysinfo.push_back( "_WIN64");
#endif
#ifdef __TOS_WIN__
    sysinfo.push_back("__TOS_WIN__");
#endif
#ifdef __NT__
    sysinfo.push_back( "__NT__");
#endif


//MacOS
#ifdef macintosh
    sysinfo.push_back("macintosh");
#endif
#ifdef Macintosh
    sysinfo.push_back("Macintosh");
#endif
#ifdef __APPLE__
    sysinfo.push_back("__APPLE__");
#endif
#ifdef __MACH__
    sysinfo.push_back( "__MACH__");
#endif


//Apple - #include <TargetConditionals.h>
#ifdef TARGET_OS_MAC
    sysinfo.push_back( "TARGET_OS_MAC");
#endif
#ifdef TARGET_OS_WIN32
    sysinfo.push_back("TARGET_OS_WIN32");
#endif
#ifdef TARGET_OS_UNIX
    sysinfo.push_back("TARGET_OS_UNIX");
#endif
#ifdef TARGET_OS_EMBEDDED
    sysinfo.push_back("TARGET_OS_EMBEDDED");
#endif
#ifdef TARGET_OS_IPHONE
    sysinfo.push_back("TARGET_OS_IPHONE");
#endif
#ifdef TARGET_IPHONE_SIMULATOR
    sysinfo.push_back("TARGET_IPHONE_SIMULATOR");
#endif
#ifdef TARGET_OS_LINUX
    sysinfo.push_back("TARGET_OS_LINUX");
#endif


//Android
#ifdef __ANDROID__
    sysinfo.push_back( "__ANDROID__");
#endif
#ifdef __ANDROID_API__
    sysinfo.push_back("__ANDROID_API__");
#endif


//linux kernal
#ifdef __linux__
    sysinfo.push_back( "__linux__");
#endif

#ifdef linux
    sysinfo.push_back("linux (Obsolete - not POSIX compliant)");
#endif

#ifdef __linux
    sysinfo.push_back( "__linux (Obsolete - not POSIX compliant)");
#endif


///////////////////////////////////////


#ifdef __unix__
    sysinfo.push_back( "__unix__");
#endif
#ifdef _POSIX_VERSION
    sysinfo.push_back( "_POSIX_VERSION");
#endif
#ifdef __unix
    sysinfo.push_back( "__unix");
#endif
#ifdef __posix
    sysinfo.push_back( "__posix");
#endif


    std::string sysinfostr;
    for (int i = 0; i < sysinfo.size(); i++)
    {
        sysinfostr += sysinfo[i] + " / ";
    }
    return sysinfostr;
}





/*


Pre-defined Compiler Macros
https://sourceforge.net/p/predef/wiki/OperatingSystems/





AIX
Type	Macro	Description
Identification	_AIX
Version	_AIX'VR'	V = Version
R = Revision
Identification	__TOS_AIX__	Defined by xlC
Example
If _AIX is defined, then the following macros can be used to determine the version.Notice that the macros indicates the mentioned version or higher.For example, if _AIX43 is defined, then _AIX41 will also be defined.

AIX Version	Macro
3.2.x	_AIX3
_AIX32
4.1	_AIX41
4.3	_AIX43
Android
Type	Macro	Format	Description
Identification	__ANDROID__
Version	__ANDROID_API__	V	V = API Version

Must be included from <android / api - level.h>
Notice that Android is based on Linux, and that the Linux macros also are defined for Android.

Example
Android Version	__ANDROID_API__
1.0	1
1.1	2
1.5	3
1.6	4
2.0	5
2.0.1	6
2.1	7
2.2	8
2.3	9
2.3.3	10
3.0	11
Amdahl UTS
Type	Macro
Identification	UTS
AmigaOS
Type	Macro	Description
Identification	AMIGA
Identification	__amigaos__	Defined by GNU C
Apollo AEGIS
Type	Macro
Identification	aegis
Apollo Domain / OS
Type	Macro
Identification	apollo
Bada
Based on Nucleus OS.

BeOS
Type	Macro
Identification	__BEOS__
Blue Gene
Type	Macro	Description
Identification	__bg__	All Blue Gene systems

Defined by XL C / C++ and GNU C
Version	__bgq__	Blue Gene / Q

Defined for XL C / C++ and GNU C
Identification	__THW_BLUEGENE__	All Blue Gene systems

Defined by XL C / C++
Version	__TOS_BGQ__	Blue Gene / Q

Defined by XL C / C++
BSD Environment
Type	Macro	Format	Description
Identification	__FreeBSD__
__NetBSD__
__OpenBSD__
__bsdi__
__DragonFly__
Version	BSD	YYYYMM	YYYY = Year
MM = Month

Must be included from <sys / param.h>
Version	BSD4_2
BSD4_3
BSD4_4		Must be included from <sys / param.h>
Identification	_SYSTYPE_BSD		Defined by DEC C
Example
Version	BSD	Macro
4.3 Net2	199103
4.4	199306	BSD4_4
4.4BSD - Lite2	199506
BSD / OS
Type	Macro
Identification	__bsdi__
ConvexOS
Type	Macro
Identification	__convex__
Cygwin Environment
Type	Macro
Identification	__CYGWIN__
DG / UX
Type	Macro
Identification	DGUX
Identification	__DGUX__
Identification	__dgux__
DragonFly
Type	Macro
Identification	__DragonFly__
DYNIX / ptx
Type	Macro
Identification	_SEQUENT_
Identification	sequent
eCos
Type	Macro
Identification	__ECOS
EMX Environment
Type	Macro
Identification	__EMX__
FreeBSD
Type	Macro	Format	Description
Identification	__FreeBSD__
Identification	__FreeBSD_kernel__		From FreeBSD 8.3, 9.1, and 10.0.1
Version	BSD
Version	__FreeBSD__	V	V = Version
Version	__FreeBSD_version ? Must be included from <osreldate.h>
Example
FreeBSD	__FreeBSD__	__FreeBSD_version
1.x	1
2.0 - RELEASE	2	119411
2.2 - RELEASE	2	220000
3.0 - RELEASE	3	300005
4.0 - RELEASE	4	400017
4.5 - RELEASE	4	450000
For more information see the FreeBSD porters handbook.

GNU aka GNU / Hurd
The official name of this operating system is GNU.Hurd is the kernel in the GNU operating system.It is often listed as GNU / Hurd since there is also GNU / Linux and GNU / kFreeBSD, which are most of the GNU operating system with the Linux and FreeBSD kernels respectively.

Type	Macro
Identification	__GNU__ 1
Identification	__gnu_hurd__ 1
GNU / kFreeBSD
GNU / kFreeBSD is one of the Debian distros that is based on the FreeBSD kernel rather than the Linux or Hurd kernels.

Type	Macro
Identification	__FreeBSD_kernel__ && __GLIBC__
Notice that FreeBSD also defines __FreeBSD_kernel__ so the __GLIBC__ macro must be checked to distinguish it.

GNU / Linux
Type	Macro
Identification	__gnu_linux__
HI - UX MPP
Type	Macro
Identification	__hiuxmpp
HP - UX
Type	Macro	Description
Identification	_hpux	Defined by HP UPC
Identification	hpux
Identification	__hpux
IBM OS / 400
Type	Macro	Format	Description
Identification	__OS400__
Version	__OS400_TGTVRM__	VRM	V = Version
R = Revision
M = Modification
INTEGRITY
Type	Macro
Identification	__INTEGRITY
Interix Environment
Type	Macro	Description
Identification	__INTERIX	Defined by GNU C and Visual Studio
IRIX
Type	Macro
Identification	sgi
Identification	__sgi
Linux kernel
Systems based on the Linux kernel define these macros.There are two major Linux - based operating systems : GNU / Linux and Android, and numerous others like �ngstr�m or OpenEmbedded

Type	Macro	Description
Identification	__linux__	1
Identification	linux	Obsolete(not POSIX compliant)
Identification	__linux	Obsolete(not POSIX compliant)
LynxOS
Type	Macro
Identification	__Lynx__
MacOS
Type	Macro	Description
Identification	macintosh	Mac OS 9
Identification	Macintosh	Mac OS 9
Identification	__APPLE__ && __MACH__	Mac OS X

Defined by GNU C and Intel C++
Microware OS - 9
Type	Macro	Description
Identification	__OS9000	Defined by Ultimate C / C++
Identification	_OSK	Defined by Ultimate C / C++
MINIX
Type	Macro
Identification	__minix
MorphOS
Type	Macro
Identification	__MORPHOS__
MPE / iX
Type	Macro
Identification	mpeix
Identification	__mpexl
MSDOS
Type	Macro
Identification	MSDOS
Identification	__MSDOS__
Identification	_MSDOS
Identification	__DOS__
NetBSD
Type	Macro	Format	Description
Identification	__NetBSD__
Version	BSD
Version	NetBSD'V'_'R'		V = Version
R = Revision

Must be included from <sys / param.h>
Version	__NetBSD_Version__	VVRRAAPP00	VV = Version
RR = Revision
AA = Release
PP = Patch

From NetBSD 1.2D(? ) until NetBSD 2.0H

Must be included from <sys / param.h>
Version	__NetBSD_Version__	VVRR00PP00	VV = Version
RR = Revision
PP = Patch

From NetBSD 2.99.9

Must be included from <sys / param.h>
Example
NetBSD	__NetBSD_Version__	Macro
0.8		NetBSD0_8
0.9		NetBSD0_9
1.0		NetBSD1_0 = 1
1.0A		NetBSD1_0 = 2
1.2D	102040000
1.2.1	102000100
NonStop
Type	Macro
Identification	__TANDEM
Nucleus RTOS
Type	Macro
Identification	__nucleus__
OpenBSD
Type	Macro	Format	Description
Identification	__OpenBSD__
Version	BSD
Version	OpenBSD'V'_'R'		V = Version
R = Revision

Must be included from <sys / param.h>
Example
OpenBSD	Macro
3.1	OpenBSD3_1
3.9	OpenBSD3_9
OS / 2
Type	Macro
Identification	OS2
Identification	_OS2
Identification	__OS2__
Identification	__TOS_OS2__
Palm OS
Type	Macro	Description
Identification	__palmos__	Defined by GNU C in PRC - Tools
Plan 9
Type	Macro
Identification	EPLAN9
Pyramid DC / OSx
Type	Macro
Identification	pyr
QNX
Type	Macro	Format	Description
Identification	__QNX__		QNX 4.x
Identification	__QNXNTO__		QNX 6.x
Version	_NTO_VERSION	VRR	V = Version
RR = Revision

Only available when __QNXNTO__ is defined.

Must be included from <sys / neutrino.h>
Version	BBNDK_VERSION_CURRENT	VVRRRRPPPP	V = Version
RRRR = Revision
PPPP = Patch

Only available on Blackberry 10

From Blackberry 10.1.0

Must be included from <bbndk.h>
Example
QNX	_NTO_VERSION
6.2	620
Reliant UNIX
Type	Macro
Identification	sinux
SCO OpenServer
Type	Macro	Description
Identification	M_I386	Defined by GNU C
Identification	M_XENIX	Defined by GNU C
Identification	_SCO_DS
Solaris
Type	Macro	Description
Identification	sun
Identification	__sun
Version	__'System'_'Version'	System = uname - s
Version = uname - r
Any illegal character is replaced by an underscore.

Defined by Sun Studio
Use the SVR4 macros to distinguish between Solaris and SunOS.

#if defined(sun) || defined(__sun)
# if defined(__SVR4) || defined(__svr4__)
// Solaris
# else
// SunOS 
# endif
#endif
Example
Solaris	Macro
2.7	__SunOS_5_7
8	__SunOS_5_8
Stratus VOS
Type	Macro	Format	Description
Identification	__VOS__
Version	__VOS__	V	V = Version
Notice that the __VOS__ macro is defined by the compiler, but as several compilers can co - exist in the same OS release, the version number is not reliable.

SVR4 Environment
Type	Macro	Description
Identification	__sysv__
Identification	__SVR4
Identification	__svr4__
Identification	_SYSTYPE_SVR4	Defined on IRIX
Syllable
Type	Macro
Identification	__SYLLABLE__
Symbian OS
Type	Macro
Identification	__SYMBIAN32__
Tru64(OSF / 1)
Type	Macro
Identification	__osf__
Identification	__osf
Ultrix
Type	Macro
Identification	ultrix
Identification	__ultrix
Identification	__ultrix__
Identification	unix & vax
UNICOS
Type	Macro	Format	Description
Identification	_UNICOS
Version	_UNICOS	V	V = Version
UNICOS / mp
Type	Macro	Description
Identification	_CRAY
__crayx1
UNIX Environment
Type	Macro
Identification	__unix__
Identification	__unix
Notice that not all compilers defines these macros, e.g.the xlC or the DEC C / C++ compiler, so it may be better to use the POSIX or X / Open standard macros instead.

UnixWare
Type	Macro
Identification	sco
Identification	_UNIXWARE7
U / Win Environment
Type	Macro
Identification	_UWIN
VMS
Type	Macro	Format	Description
Identification	VMS
Identification	__VMS
Version	__VMS_VER	VVRREPPTT	VV = Version
RR = Revision
E = Edit number
PP = Patch(01 = A, ... 26 = Z)
TT = Type(22 = official)
Example
VMS	__VMS_VER
6.1	60100022
6.2	60200022
6.2 - 1I	60210922
VxWorks
Type	Macro	Description
Identification	__VXWORKS__	Defined by GNU C and Diab(from ? )
Identification	__vxworks	Defined by GNU C and Diab(from ? )
Version	_WRS_VXWORKS_MAJOR	Version

Must be included from <version.h>
Version	_WRS_VXWORKS_MINOR	Revision

Must be included from <version.h>
Version	_WRS_VXWORKS_MAINT	Patch / maintenance

Must be included from <version.h>
Mode	__RTP__	For real - time mode
Mode	_WRS_KERNEL	For kernel mode
Example
VxWorks	_WRS_VXWORKS_MAJOR	_WRS_VXWORKS_MINOR	_WRS_VXWORKS_MAINT
6.2	6	2	0
Windows
Type	Macro	Description
Identification	_WIN16	Defined for 16 - bit environments 1
Identification	_WIN32	Defined for both 32 - bit and 64 - bit environments 1
Identification	_WIN64	Defined for 64 - bit environments 1
Identification	__WIN32__	Defined by Borland C++
Identification	__TOS_WIN__	Defined by xlC
Identification	__WINDOWS__	Defined by Watcom C / C++
Windows CE
Type	Macro	Format	Description
Identification	_WIN32_WCE		Defined by Embedded Visual Studio C++
Version	_WIN32_WCE	VRR	V = Version
R = Revision
Identification	WIN32_PLATFORM_'P'		P = Platform
Version	WIN32_PLATFORM_'P'	V	P = Platform
V = Version
Example
Version	_WIN32_WCE
2.01	201
2.11	211
3.0	300
4.0	400
4.1	410
4.2	420
5.0	501
Platform	Macro	Value
H / PC 2000	WIN32_PLATFORM_HPC2000
H / PC Pro 2.11	WIN32_PLATFORM_HPCPRO	211
H / PC Pro 3.0	WIN32_PLATFORM_HPCPRO	300
Pocket PC	WIN32_PLATFORM_PSPC	1
Pocket PC 2002	WIN32_PLATFORM_PSPC	310
Windows Mobile 2003	WIN32_PLATFORM_PSPC	400
Smartphone 2002	WIN32_PLATFORM_WFSP	100
Wind / U Environment
Type	Macro	Format	Description
Identification	_WINDU_SOURCE
Version	_WINDU_SOURCE	0xVVRRPP	VV = Version
RR = Revision
PP = Patch
Example
Wind / U	_WINDU_SOURCE
3.1.2	0x030102
z / OS
Type	Macro	Description
Identification	__MVS__	Host
Identification	__HOS_MVS__	Host
Identification	__TOS_MVS__	Target

*/