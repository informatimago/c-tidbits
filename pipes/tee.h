
enum {
    tee_thread=1, // use pthreads instead of processes.
    tee_first=2,  // exit at the first output closed. else exit at the last.
};

int tee(int input,int outputs_count,int* outputs,int flags);
/*
Forks a process !(flag & TEE_THREAD) or a thread (flag & TEE_THREAD)
Reads the input file descriptor until SIGPIPE, 
copying the data to the outputs file descriptors.
Stops at the first SIGPIPE output, (flag & tee_first), 
at the last !(flag & tee_first).
Returns the pid of the successful created of the process 
or the pid of the process containing the successfully created thread).
Returns -1 on error.
*/



