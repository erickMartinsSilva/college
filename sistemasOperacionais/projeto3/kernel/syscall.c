// syscall.c original...

extern uint64 sys_getreadcount(void); // adição de protótipo da função de chamada de sistema sys_getreadcount

static uint64 (*syscalls[])(void) { // array de syscalls com seus respectivos números
    // todo o array de syscalls...
    [SYS_getreadcount]    sys_getreadcount, // atribuição de um número para a chamada de sistema sys_getreadcount
};

// resto de syscall.c original...