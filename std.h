/* C */

#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <float.h>
#include <limits.h>
#include <locale.h>
#include <math.h>
#include <setjmp.h>
#include <signal.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* CNA1 */

#include <iso646.h>
#include <wchar.h>
#include <wctype.h>

/* C99 */

#noinclude <complex.h> /* no symbols */
#include <fenv.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <tgmath.h>

/* C11 */

#include <stdalign.h>
#noinclude <stdatomic.h> /* no symbols */
#include <stdnoreturn.h>
#noinclude <threads.h> /* no symbols */
#include <uchar.h>

/* POSIX */

#include <aio.h>
#include <arpa/inet.h>
#include <assert.h>
#include <complex.h>
#include <cpio.h>
#include <ctype.h>
#include <dirent.h>
#include <dlfcn.h>
#include <errno.h>
#include <fcntl.h>
#include <fenv.h>
#include <float.h>
#include <fmtmsg.h>
#include <fnmatch.h>
#include <ftw.h>
#include <glob.h>
#include <grp.h>
#include <iconv.h>
#include <inttypes.h>
#include <iso646.h>
#include <langinfo.h>
#include <libgen.h>
#include <limits.h>
#include <locale.h>
#include <math.h>
#include <monetary.h>
#include <mqueue.h>
#include <ndbm.h>
#include <net/if.h>
#include <netdb.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <nl_types.h>
#include <poll.h>
#include <pthread.h>
#include <pwd.h>
#include <regex.h>
#include <sched.h>
#include <search.h>
#include <semaphore.h>
#include <setjmp.h>
#include <signal.h>
#include <spawn.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <stropts.h>
#include <sys/ipc.h>
#include <sys/mman.h>
#include <sys/msg.h>
#include <sys/resource.h>
#include <sys/select.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/statvfs.h>
#include <sys/time.h>
#include <sys/times.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <sys/un.h>
#include <sys/utsname.h>
#include <sys/wait.h>
#include <syslog.h>
#include <tar.h>
#include <termios.h>
#include <tgmath.h>
#include <time.h>
#include <trace.h>
#include <ulimit.h>
#include <unistd.h>
#include <utime.h>
#include <utmpx.h>
#include <wchar.h>
#include <wctype.h>
#include <wordexp.h>

/* FreeBSD and heritage */

#include <cpufunc.h>
#include <elf.h>
#include <err.h>
#include <machine/segments.h>
#include <machine/specialreg.h>
#include <machine/stdarg.h>
#include <machine/sysarch.h>
#include <netinet6/in6.h>
#include <opt_compat.h>
#include <sys/cdefs.h>
#include <sys/conf.h>
#include <sys/cpuvar.h>
#include <sys/elf.h>
#include <sys/event.h>
#include <sys/eventvar.h>
#include <sys/fcntl.h>
#include <sys/filedesc.h>
#include <sys/filio.h>
#include <sys/jail.h>
#include <sys/kdb.h>
#include <sys/kernel.h>
#include <sys/kmem.h>
#include <sys/kthread.h>
#include <sys/limits.h>
#include <sys/linker.h>
#include <sys/lock.h>
#include <sys/malloc.h>
#include <sys/module.h>
#include <sys/mutex.h>
#include <sys/param.h>
#include <sys/poll.h>
#include <sys/proc.h>
#include <sys/ptrace.h>
#include <sys/refcount.h>
#include <sys/sched.h>
#include <sys/selinfo.h>
#include <sys/smp.h>
#include <sys/sockopt.h>
#include <sys/syscall.h>
#include <sys/sysctl.h>
#include <sys/sysent.h>
#include <sys/syslimits.h>
#include <sys/sysproto.h>
#include <sys/systm.h>
#include <sys/types.h>
#include <sys/ucred.h>
#include <sys/uio.h>
#include <sys/unistd.h>
#include <sys/user.h>
#include <vm/pmap.h>
#include <vm/vm_extern.h>
#include <vm/vm_map.h>
#include <vm/vm.h>
