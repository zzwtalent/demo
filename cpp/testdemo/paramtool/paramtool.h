#include <map>

#define KCPD_STRNCPY_S(dest,dest_sz,src,count)	\
{                                               \
		if(dest_sz > count)                         \
		{                                           \
					strncpy(dest,src,count);                \
					(dest)[count]=0x00;                     \
				}                                           \
		else                                        \
		{                                           \
					strncpy(dest,src,dest_sz - 1);          \
					(dest)[dest_sz - 1]=0x00;               \
				}                                           \
}

#define KCPD_SNPRINTF_S(dest,dest_sz,count,format,...)		snprintf(dest,(count)+1,format,##__VA_ARGS__)

