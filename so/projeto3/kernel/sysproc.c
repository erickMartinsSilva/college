// sysproc.c original...

extern int read_count; // declaração de variável global externa contador

uint64 sys_getreadcount(void) {
    return read_count; // retorna o valor total de chamadas read() feitas desde o início do boot
}

// resto de sysproc.c original...