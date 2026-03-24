#include <aio.h>
#include <sys/syscall.h>
#include <unistd.h>

int aio_cancel(struct aiocb *aiocbp) {
    return (int)syscall(SYS_aio_cancel, ((long)(aiocbp->aio_fildes)), (long)aiocbp);
}
