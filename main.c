/*
 * main.c
 *
 * Author:
 * Copyright (c) 2020, Gaurav Kothari (gkothar1@binghamton.edu)
 * State University of New York at Binghamton
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "apex_cpu.h"

int get_num_from_string(const char *buffer) {
    return atoi(buffer);
}

int main(int argc, char const *argv[]) {
    APEX_CPU *cpu;

    fprintf(stderr, "APEX CPU Pipeline Simulator v%0.1lf\n", VERSION);

    if (argc < 2) {
        fprintf(stderr, "APEX_Help: Usage %s <input_file>\n", argv[0]);
        exit(1);
    }

    cpu = APEX_cpu_init(argv[1]);
    if (!cpu) {
        fprintf(stderr, "APEX_Error: Unable to initialize CPU\n");
        exit(1);
    }

    if (argc == 2) {
        APEX_cpu_run(cpu, -1);
        return 0;
    } else if (argc == 4 && strcmp(argv[2], "simulate") == 0) {
        int simulate = get_num_from_string(argv[3]);
        printf("argc 3 %d \n", simulate);

        APEX_cpu_run(cpu, simulate);

        

        return 0; 
    } 

    APEX_cpu_stop(cpu);
    return 0;
}
